#include "main.h"

//
// Main application
//
void QSApplet::appletCreate(UUID uuid, QString appletName) {
    QAppletShmServer* applet = new QAppletShmServer(QString(STREAMER_SERVER_NAME) + ":" + appletName + ":" + uuid.toString(), appletName, uuid.toString());

    connect(applet, &QAppletShmServer::resized, this, [this,uuid](int w, int h){ appletResize(uuid, w, h); });
    connect(applet, &QAppletShmServer::updated, this, [this,uuid](){ appletUpdate(uuid); });

    applet->show();
    m_applets.insert(uuid, applet);
}
void QSApplet::appletDestroy(UUID uuid) {
    QAppletShmServer* applet = m_applets[uuid];
    m_applets.remove(uuid);

    applet->hide();
    applet->disconnect();
    applet->destroy();

    delete applet;
}
void QSApplet::appletBuffer(UUID uuid, int size) {
    QAppletShmServer* applet = m_applets[uuid];
    applet->resizeBuffer(size);
}
void QSApplet::appletWindow(UUID uuid, int ix) {
    Q_UNUSED(uuid);
    Q_UNUSED(ix);
    //m_applets[uuid]->setWindow(ix);
}
void QSApplet::appletWindows(UUID uuid) {
    Q_UNUSED(uuid);
    //return m_applets[uuid]->getWindows();
}
void QSApplet::appletEvent(UUID uuid, QEvent* event) {
    QCoreApplication::postEvent(m_applets[uuid]->getWindow(), event);
}

void QSApplet::appletUpdate(UUID uuid) {
    QMetaObject::invokeMethod(m_server, "clientUpdate", Qt::QueuedConnection, QGenericReturnArgument(), Q_ARG(UUID, uuid));
}
void QSApplet::appletResize(UUID uuid, int w, int h) {
    memcpy(&m_buffer.magicNumber, STREAMER_MAGIC_NUMBER, sizeof(STREAMER_MAGIC_NUMBER));
    uuid.toChar(m_buffer.uuid);
    m_buffer.cmd = CMD_RESIZE;
    int* buff = reinterpret_cast<int*>(m_buffer.data);
    buff[0] = w;
    buff[1] = h;
    QMetaObject::invokeMethod(m_server, "clientWrite", Qt::QueuedConnection, QGenericReturnArgument(), Q_ARG(QSPacket*, &m_buffer));
}
//

int main(int argc, char *argv[]) {
    QSApplet app(argc, argv);

    return app.exec();
}
