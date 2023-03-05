#include "QAppletShmServer.h"

QAppletShmServer::QAppletShmServer(QString shmPath, QString appletName, QString sUuid, QWindow* parent): QQuickView(parent) {
    Q_UNUSED(parent);
    m_shmPath = shmPath;
    m_shmFd = shm_open(m_shmPath.toStdString().c_str(), O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);

    connect(this, &QQuickWindow::beforeRendering, this, &QAppletShmServer::beforeRendering, Qt::DirectConnection);
    connect(this, &QQuickWindow::afterRendering, this, &QAppletShmServer::afterRendering, Qt::DirectConnection);
    connect(this, &QQuickWindow::frameSwapped, this, &QAppletShmServer::frameSwapped, Qt::QueuedConnection);

    m_applet = new AppletContainer();
    m_applet->setParent(this);
    m_applet->setApplet(appletName);

    m_incubator = new QAppletShmIncubationController();
    m_incubator->setApplet(sUuid);
    m_engine = m_applet->getRootContext()->engine();
    m_engine->setIncubationController(m_incubator);
}
QAppletShmServer::~QAppletShmServer() {
    std::lock_guard<std::mutex> locker(m_mutex);
    releaseFrameBuffer();
    shm_close(m_shmFd);
    shm_unlink(m_shmPath.toStdString().c_str());
    m_applet->setParent(nullptr);
    m_engine->setIncubationController(nullptr);
    //m_applet->destroy();
    delete m_applet;
    delete m_incubator;
    QQuickView::~QQuickView();
}
void QAppletShmServer::releaseFrameBuffer() {
    if (m_frameBuffer) {
        m_frameBuffer->release();
        delete m_frameBuffer;
        m_frameBuffer = nullptr;
    }
}

// Render:
void QAppletShmServer::beforeRendering() {
    std::lock_guard<std::mutex> locker(m_mutex);
    if (!openglContext())
        return;
    if (!m_frameBuffer) {
        QOpenGLFramebufferObjectFormat format;
        m_frameBuffer = new QOpenGLFramebufferObject(m_width, m_height, format);
    }
    if (renderTarget() != m_frameBuffer) {
        setRenderTarget(m_frameBuffer);
    }
}
void QAppletShmServer::afterRendering() {
    std::lock_guard<std::mutex> locker(m_mutex);
    QOpenGLContext *context = openglContext();
    if (!context)
        return;
    QOpenGLFunctions *f = context->functions();

    m_frameBuffer->bind();
    f->glReadPixels(0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, m_pixelBuffer);
    m_frameBuffer->release();
}
void QAppletShmServer::frameSwapped() {
    Q_EMIT updated();
}
//

// Resize:
void QAppletShmServer::resizeBuffer(int size) {
    std::lock_guard<std::mutex> locker(m_mutex);

    if (size != m_bufferSize)
        return;
    ftruncate(m_shmFd, m_bufferSize);
}
void QAppletShmServer::resizeBuffer(int width, int height) {
    std::lock_guard<std::mutex> locker(m_mutex);

    int newPixelBufferSize = width*height*4;
    if (newPixelBufferSize < m_bufferSize) {
        munmap(&m_pixelBuffer[newPixelBufferSize], m_bufferSize-newPixelBufferSize);
    } else if (newPixelBufferSize > m_bufferSize) {
        if (m_pixelBuffer) {
            munmap(m_pixelBuffer, m_bufferSize);
        }
        ftruncate(m_shmFd, newPixelBufferSize);
        m_pixelBuffer = reinterpret_cast<GLubyte*>(mmap(nullptr, newPixelBufferSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_shmFd, 0));
    }
    m_width = width;
    m_height = height;
    m_bufferSize = newPixelBufferSize;
    releaseFrameBuffer();
}
void QAppletShmServer::resizeEvent(QResizeEvent* e) {
    if (e == nullptr)
        return;
    resizeBuffer(e->size().width(), e->size().height());
    Q_EMIT resized(m_width, m_height);
}
//

void QAppletShmServer::reload() {
    Q_EMIT resized(m_width, m_height);
}
