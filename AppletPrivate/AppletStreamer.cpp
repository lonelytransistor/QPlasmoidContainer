#include "AppletStreamer.h"

AppletStreamer::AppletStreamer(UUID uuid, QWindow* parent): QQuickView(parent) {
    Q_UNUSED(parent);
    m_shmPath = QString(STREAMER_SERVER_NAME) + ":lonelytransistor:applet:" + uuid.toQString())shmPath.toStdString().c_str();
    m_shmFd = shm_open(m_shmPath, O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);

    connect(this, &QQuickWindow::beforeRendering, this, &AppletStreamer::beforeRendering, Qt::DirectConnection);
    connect(this, &QQuickWindow::afterRendering, this, &AppletStreamer::afterRendering, Qt::DirectConnection);
    connect(this, &QQuickWindow::frameSwapped, this, &AppletStreamer::frameSwapped, Qt::QueuedConnection);

    reloadFifo();
}
AppletStreamer::~AppletStreamer() {
    std::lock_guard<std::mutex> locker(m_mutex);
    releaseFrameBuffer();
    QQuickView::~QQuickView();
}
void AppletStreamer::releaseFrameBuffer() {
    if (m_frameBuffer) {
        m_frameBuffer->release();
        delete m_frameBuffer;
        m_frameBuffer = nullptr;
    }
}

// Render:
void AppletStreamer::beforeRendering() {
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
void AppletStreamer::afterRendering() {
    std::lock_guard<std::mutex> locker(m_mutex);
    QOpenGLContext *context = openglContext();
    if (!context)
        return;
    QOpenGLFunctions *f = context->functions();

    m_frameBuffer->bind();
    f->glReadPixels(0, 0, m_width, m_height, GL_RGBA, GL_UNSIGNED_BYTE, m_pixelBuffer);
    m_frameBuffer->release();
}
void AppletStreamer::frameSwapped() {
    Q_EMIT frameReady();
}
//

// Resize:
void AppletStreamer::resizeBuffer(int size) {
    std::lock_guard<std::mutex> locker(m_mutex);

    if (size != m_bufferSize)
        return;
    ftruncate(m_shmFd, m_bufferSize);
}
void AppletStreamer::resizeBuffer(int width, int height) {
    std::lock_guard<std::mutex> locker(m_mutex);

    int newPixelBufferSize = width*height*4;
    if (newPixelBufferSize < m_bufferSize) {
        munmap(&m_pixelBuffer[newPixelBufferSize], m_bufferSize-newPixelBufferSize);
    } else if (newPixelBufferSize > m_bufferSize) {
        if (m_pixelBuffer)
            munmap(m_pixelBuffer, m_bufferSize);
        ftruncate(m_shmFd, newPixelBufferSize);
        m_pixelBuffer = reinterpret_cast<GLubyte*>(mmap(nullptr, newPixelBufferSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_shmFd, 0));
    }
    m_width = width;
    m_height = height;
    m_bufferSize = newPixelBufferSize;
    releaseFrameBuffer();
}
void AppletStreamer::resizeEvent(QResizeEvent* e) {
    if (e == nullptr)
        return;
    resizeBuffer(e->size().width(), e->size().height());

    Q_EMIT resized(m_width, m_height);
}
//

void AppletStreamer::reload() {
    Q_EMIT resized(m_width, m_height);
}

// Events:
void AppletStreamer::newEvent(QEvent* e) {
    if (e == nullptr)
        return;
    QCoreApplication::postEvent(this, e);
}
