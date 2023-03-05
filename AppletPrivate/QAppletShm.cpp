#include "QAppletShm.h"



//
// Client:
//
QAppletShmPrivate::QAppletShmPrivate(QString p_serverName, const char* p_uuid, QObject* parent): QThread(parent) {
    m_serverName = p_serverName;
    m_uuid = UUID(p_uuid);
}
void QAppletShmPrivate::run() {
    m_packet = new QSPacket();
    m_socket = new QLocalSocket(this);
    m_socket->setServerName(m_serverName);

    connect(m_socket, &QLocalSocket::connected, [this]{ serverOpen(); });
    connect(m_socket, &QLocalSocket::readyRead, [this]{ serverRead(); });
    connect(m_socket, &QLocalSocket::disconnected, [this]{ serverClose(); });

    m_socket->connectToServer();
}
void QAppletShmPrivate::serverOpen() {
    qInfo() << "Connected to server.";
    Q_EMIT connected();
}
void QAppletShmPrivate::serverClose() {
    qInfo() << "Disconnected from server.";
    Q_EMIT disconnected();
}
void QAppletShmPrivate::serverRead() {
    char charBuff = 0;

    while (m_socket->isValid() && m_socket->bytesAvailable()) {
        m_socket->getChar(&charBuff);
        if (m_packetReader.append(charBuff, m_packet)) {
            if (m_uuid != m_packet->uuid) {
                qInfo() << "Invalid UUID: " << m_packet->uuid << " != " << m_uuid.toString();
                continue;
            }

            switch (m_packet->cmd) {
                case CMD_CREATE:{
                    QString buff = QString::fromLocal8Bit(m_packet->data, sizeof(QSPacket::data));
                    qInfo() << "Created applet: " << buff;
                    Q_EMIT appletCreated(buff);
                }break;
                case CMD_RESIZE:{
                    int* buff = reinterpret_cast<int*>(m_packet->.data);
                    qInfo() << "Resized: " << buff[0] << "x" << buff[1];
                    Q_EMIT appletResized(buff[0], buff[1]);
                }break;
                case CMD_WINDOW:{
                    int* buff = einterpret_cast<int*>(m_packet->data);
                    qInfo() << "Switched to window: " << buff[0];
                    Q_EMIT appletWindow(buff[0]);
                }break;
                case CMD_NEWWINDOW:{
                    int* buff = einterpret_cast<int*>(m_packet->data);
                    qInfo() << "Created a new window: " << buff[0];
                    Q_EMIT appletWindow(buff[0]);
                }break;
                case CMD_EVENT:{
                    QEvent* buff = (QEvent*)(m_packet->data);
                    qInfo() << "Received event: " << buff;
                    Q_EMIT appletEvent(buff);
                }break;
                case CMD_UPDATE:{
                    Q_EMIT appletUpdated();
                }break;
                case CMD_INVALID:{
                    qInfo() << "Invalid command.";
                }break;
                default:{
                    qInfo() << "Unknown command.";
                }break;
            }
        }
        memset(m_packet, 0, sizeof(QSPacket));
    }
}
void QAppletShmPrivate::serverWrite(QSPacket* packet) {
    QSPacketCommand cmd = static_cast<QSPacketCommand>(packet->cmd);

    switch (cmd) {
        case CMD_CREATE:
        case CMD_RESIZE:
        case CMD_EVENT:
            m_socket->write((char*)packet, sizeof(QSPacket));
            m_socket->flush();
        break;
        case CMD_INVALID:
            qInfo() << "Invalid command.";
        break;
        default:
            qInfo() << "Unknown command.";
        break;
    }
}
void QAppletShmPrivate::serverUpdate() {
    char buff = CMD_UPDATE;
    m_socket->write(&buff, 1);
    m_socket->flush();
}
//


//
// Texture provider:
//
QAppletShmTexturePrivate::QAppletShmTexturePrivate(QAppletShm* p_parent) {
    m_parent = p_parent;
    m_invalid = &p_parent->m_invalid;
    updateTexture();
}
void QAppletShmTexturePrivate::bind() {
    QOpenGLFunctions *f = QOpenGLContext::currentContext()->functions();
    if (!m_texture) {
        f->glGenTextures(1, &m_texture);
    }
    f->glBindTexture(GL_TEXTURE_2D, m_texture);
}
bool QAppletShmTexturePrivate::updateTexture() {
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

    if (!m_invalid->load()) {
        m_pixelBuffer = m_parent->m_pixelBuffer;
        m_height = m_parent->m_height;
        m_width = m_parent->m_width;
        f->glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, m_width, m_height, 0, GL_RGBA, GL_UNSIGNED_BYTE, m_pixelBuffer);
    }
    return true;
}
//


//
// QObject:
//
QAppletShm::QAppletShm(QQuickItem* parent): QQuickItem(parent) {
    m_texture = new QAppletShmTexturePrivate(this);
    m_private = new QAppletShmPrivate();
    QObject::connect(m_private, &QAppletShmPrivate::connected, this, &QAppletShm::connected, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::disconnected, this, &QAppletShm::disconnected, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletCreated, this, &QAppletShm::appletCreated, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletResized, this, &QAppletShm::appletResized, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletWindow, this, &QAppletShm::appletWindow, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletNewWindow, this, &QAppletShm::appletNewWindow, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletEvent, this, &QAppletShm::appletEvent, Qt::BlockingQueuedConnection);
    QObject::connect(m_private, &QAppletShmPrivate::appletUpdated, this, &QAppletShm::appletUpdated, Qt::BlockingQueuedConnection);
    m_valid = false;
    setFlag(QQuickItem::ItemHasContents);
    setAntialiasing(true);
    m_private->start();
}
QSGNode* QAppletShm::updatePaintNode(QSGNode* node, QQuickItem::UpdatePaintNodeData* tnode) {
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
void QAppletShm::event(QEvent* ev) {

    return true;
}

    Q_SIGNAL void connected();
    Q_SIGNAL void disconnected();
    Q_SIGNAL void appletCreated(QString shm);
    Q_SIGNAL void appletResized(int w, int h);
    Q_SIGNAL void appletWindow(int ix);
    Q_SIGNAL void appletNewWindow(int ix);
    Q_SIGNAL void appletEvent(QEvent* ev);
    Q_SIGNAL void appletUpdated();

void QAppletShm::connected() {}
void QAppletShm::disconnected() {}
void QAppletShm::appletCreated(QString p_shm) {
    m_valid = false;
    shm_close();
    m_shmFd = shm_open(p_shm, O_CREAT | O_RDONLY, S_IRUSR | S_IWUSR | S_IXUSR);
}
void QAppletShm::appletResized(int p_width, int p_height) {
    m_valid = false;
    if (m_pixelBuffer) {
        munmap((void*)m_pixelBuffer, m_pixelBufferSize);
    }
    m_width = p_width;
    m_height = p_height;
    m_pixelBufferSize = m_width*m_height*4;

    void* mmappedBuffer = mmap(nullptr, m_pixelBufferSize, PROT_READ | PROT_WRITE, MAP_SHARED, m_shmFd, 0);
    if (mmappedBuffer == (void*)(-1)) {
        qInfo() << "Unable to mmap buffer: " << strerror(errno);
        m_pixelBuffer = nullptr;
        m_pixelBufferSize = 0;
        m_width = 0;
        m_height = 0;
        return;
    }
    m_pixelBuffer = reinterpret_cast<const uchar*>(mmappedBuffer);
    appletWrite(m_pixelBufferSize);
    m_valid = true;

    setSize(QSize(m_width, m_height));
}
void QAppletShm::appletWindow(int ix) {
    m_window = ix;
}
void QAppletShm::appletNewWindow(int ix) {
    qInfo() << "UNIMPLEMENTED: New window: " << ix;
}
void QAppletShm::appletEvent(QEvent* ev) {
    qInfo() << "UNIMPLEMENTED: Event received: " << ev;
}
void QAppletShm::appletUpdated() {
    if (m_valid.load()) {
        update();
    }
}
