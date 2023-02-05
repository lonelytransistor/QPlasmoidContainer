#include "AppletReceiver.h"

void AppletReceiverPrivate::run() {
    mkfifo("/tmp/lonelytransistor:applet:com.github.payprog.control_centre", 0666);
    m_pipeFd = fopen("/tmp/lonelytransistor:applet:com.github.payprog.control_centre", "r");
    m_shmFd = shm_open("lonelytransistor:applet:com.github.payprog.control_centre", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IXUSR);
    readLoop();
}
void AppletReceiverPrivate::readLoop() {
    char buffer[sizeof(int)*3];
    while (true) {
        fread(buffer, sizeof(char), 1, m_pipeFd);
        switch (buffer[0]) {
            case 'C': {
                Q_EMIT clearReceived();
                break;
            }
            case 'S': {
                if (m_pixelBuffer) {
                    munmap((void*)m_pixelBuffer, m_pixelBufferSize);
                }
                fread(buffer, sizeof(int), 2, m_pipeFd);
                int* intBuffer = (int*)buffer;

                m_width = intBuffer[0];
                m_height = intBuffer[1];
                m_pixelBufferSize = m_width*m_height*4;

                void* mmappedBuffer = mmap(nullptr, m_pixelBufferSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_shmFd, 0);
                if (mmappedBuffer != (void*)(-1)) {
                    m_pixelBuffer = reinterpret_cast<const uchar*>(mmappedBuffer);
                } else {
                    qInfo() << "mmap has failed with error code " << strerror(errno) << ".";
                    m_pixelBuffer = nullptr;
                    m_width = 0;
                    m_height = 0;
                }
                Q_EMIT resizeReceived(m_width, m_height, m_pixelBuffer);
                break;
            }
            case 'U': {
                Q_EMIT updateReceived();
                break;
            }
            default: {
                //qInfo() << "Invalid command:" << buffer[0];
                break;
            }
        }
    }
}



AppletReceiverTexturePrivate::AppletReceiverTexturePrivate(AppletReceiver* p_parent) {
    m_parent = p_parent;
    m_resizing = &p_parent->m_resizing;
    m_test = QString::number((long)m_parent);
    updateTexture();
}
void AppletReceiverTexturePrivate::bind() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    if (!m_texture) {
        f->glGenTextures(1, &m_texture);
    }
    f->glBindTexture(GL_TEXTURE_2D, m_texture);
}
bool AppletReceiverTexturePrivate::updateTexture() {
    QOpenGLContext* c = QOpenGLContext::currentContext();
    if (!c)
        return false;
    QOpenGLFunctions* f = c->functions();
    if (!m_texture) {
        glGenTextures(1, &m_texture);
    }
    f->glBindTexture(GL_TEXTURE_2D, m_texture);
    f->glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    f->glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    if (!m_resizing->load()) {
        m_pixelBuffer = m_parent->m_pixelBuffer;
        m_height = m_parent->m_height;
        m_width = m_parent->m_width;
        f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pixelBuffer);
    }

    return true;
}

AppletReceiver::AppletReceiver(QQuickItem* parent): QQuickItem(parent){
    m_texture = new AppletReceiverTexturePrivate(this);
    m_cmdReader = new AppletReceiverPrivate();

    QObject::connect(m_cmdReader, &AppletReceiverPrivate::updateReceived, this, &AppletReceiver::updateReceived, Qt::BlockingQueuedConnection);
    QObject::connect(m_cmdReader, &AppletReceiverPrivate::resizeReceived, this, &AppletReceiver::resizeReceived, Qt::BlockingQueuedConnection);

    m_resizing = false;
    setFlag(QQuickItem::ItemHasContents);
    setAntialiasing(true);

    m_cmdReader->start();
}
QSGNode* AppletReceiver::updatePaintNode(QSGNode* node, QQuickItem::UpdatePaintNodeData* tnode) {
    QSGSimpleTextureNode* n = static_cast<QSGSimpleTextureNode*>(node);
    QSGTransformNode* t = tnode->transformNode;
    if (!n || !t) {
        n = new QSGSimpleTextureNode();
        n->setFiltering(QSGTexture::Nearest);
        n->setRect(boundingRect());
        n->setTexture(m_texture);
    }
    m_texture->updateTexture();
    n->setTexture(m_texture);
    n->setTextureCoordinatesTransform(QSGSimpleTextureNode::MirrorVertically);
    n->setRect(boundingRect());
    n->markDirty(QSGNode::DirtyForceUpdate);
    update();
    return n;
}
void AppletReceiver::resizeReceived(int p_width, int p_height, const uchar* p_pixelBuffer) {
    m_resizing = true;
    m_width = p_width;
    m_height = p_height;
    m_pixelBuffer = p_pixelBuffer;
    m_resizing = false;

    setSize(QSize(m_width, m_height));
}
void AppletReceiver::updateReceived() {
    if (!m_resizing.load()) {
        update();
    }
}
