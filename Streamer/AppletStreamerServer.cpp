#include "AppletStreamerServer.h"

//
// Client data:
//
QSClient::QSClient(UUID uuid, QString applet, QLocalSocket* socket, int timeout, bool valid) {
    m_uuid = uuid;
    m_applet = applet;
    m_socket = socket;
    m_timeout = timeout;
    m_valid = valid;
}
void QSClient::startTimer() {
    stopTimer();
    m_timer = new QTimer();
    m_timer->setInterval(m_timeout);
    m_timer->callOnTimeout(this, [this]{ remove(); });
}
void QSClient::stopTimer() {
    if (!m_timer) {
        return;
    }
    m_timer->stop();
    delete m_timer;
    m_timer = nullptr;
}
void QSClient::remove() {
    stopTimer();
    Q_EMIT timeout();
}

UUID QSClientMap::findUuidBySocket(qintptr socket) {
    UUID uuid;
    if (!m_altMap.contains(socket)) {
        for (UUID u : keys()) {
            if (QMap<UUID,QSClient>::operator[](u).socket()->socketDescriptor() == socket) {
                uuid = u;
                break;
            }
        }
        if (contains(uuid)) {
            m_altMap.insert(socket, uuid);
        } else {
            m_altMap.insert(socket, UUID());
        }
    }
    return uuid;
}
void QSClientMap::cleanup() {
    for (qintptr s : m_altMap.keys()) {
        bool removeDesc = true;
        for (QSClient c : values()) {
            if (c.socket()->socketDescriptor() == s) {
                removeDesc = false;
                break;
            }
        }
        if (removeDesc) {
            m_altMap.remove(s);
        }
    }
}


//
// Server:
//
QSServer::QSServer(QString p_serverName, QObject* parent): QThread(parent) {
    m_serverName = p_serverName;
}
void QSServer::run() {
    m_server = new QLocalServer();
    m_server->setSocketOptions(QLocalServer::UserAccessOption);
    m_server->setMaxPendingConnections(30);
    connect(m_server, &QLocalServer::newConnection, [this]{ clientOpen(); });
    m_server->listen(m_serverName);
}
void QSServer::clientOpen() {
    QLocalSocket* localSocket = m_server->nextPendingConnection();

    connect(localSocket, &QLocalSocket::readyRead,    [this]{ clientRead(); });
    connect(localSocket, &QLocalSocket::disconnected, [this]{ clientClose(); });
}
void QSServer::clientClose() {
    m_clients[qobject_cast<QLocalSocket*>(sender())].startTimer();
}
void QSServer::clientRemove(UUID uuid) {
    m_clients.remove(uuid);

    Q_EMIT appletDestroy(uuid);
}

void QSServer::clientRead() {
    QLocalSocket* socket = (QLocalSocket*)sender();
    QSPacket* m_packet = new QSPacket();
    char charBuff = 0;

    while (socket->isValid() && socket->bytesAvailable()) {
        socket->getChar(&charBuff);

        if (m_packetReader.append(charBuff, m_packet)) {
            UUID uuid(m_packet->uuid);

            if (!m_clients[uuid] && m_packet->cmd!=CMD_CREATE) {
                qInfo() << "No such client.";
            } else {
                switch (m_packet->cmd) {
                    case CMD_CREATE:{
                        if (m_clients[uuid]) {
                            if (m_clients[uuid].socket()->socketDescriptor() != socket->socketDescriptor()) {
                                qInfo() << "Error! A second client is trying to use the same UUID. This would crash the currently connected one.";
                                break;
                            }
                            if (m_clients[uuid].name() == m_packet->data) {
                                break;
                            }
                            m_clients[uuid].stopTimer();
                            m_clients.remove(uuid);
                            Q_EMIT appletDestroy(uuid);
                        }
                        unsigned long int timeout = static_cast<unsigned long int>(m_packet->data[0]);
                        QSClient client = QSClient(
                            uuid,
                            QString(m_packet->data),
                            socket,
                            timeout>=1 ? timeout : 1
                        );
                        connect(&client, &QSClient::timeout, [this, uuid](){ clientRemove(uuid); });
                        m_clients[uuid] = client;

                        qInfo() << "Creating a new applet: " << QString::fromLocal8Bit(&(m_packet->data[sizeof(unsigned long int)]), sizeof(QSPacket::data)) << " with a UUID=" << uuid.toString();
                        Q_EMIT appletCreate(uuid, QString::fromLocal8Bit(&(m_packet->data[sizeof(unsigned long int)]), sizeof(QSPacket::data)));
                    }break;
                    case CMD_RESIZE:{
                        qInfo() << "Resizing framebuffer to: " << reinterpret_cast<int*>(m_packet->data)[0] << " for UUID=" << uuid.toString();
                        Q_EMIT appletBuffer(uuid, reinterpret_cast<int*>(m_packet->data)[0]);
                    }break;
                    case CMD_WINDOW:{
                        qInfo() << "Switching to window: " << reinterpret_cast<int*>(m_packet->data)[0] << " for UUID=" << uuid.toString();
                        Q_EMIT appletWindow(uuid, reinterpret_cast<int*>(m_packet->data)[0]);
                    }break;
                    case CMD_EVENT:{
                        qInfo() << "Forwarding event: " << (QEvent*)(m_packet->data) << " for UUID=" << uuid.toString();
                        Q_EMIT appletEvent(uuid, (QEvent*)(m_packet->data));
                    }break;
                    case CMD_UPDATE:{ // Ping
                        clientUpdate(uuid); // Pong
                    }break;
                    case CMD_INVALID:{
                        qInfo() << "Invalid command.";
                    }break;
                    default:{
                        qInfo() << "Unknown command.";
                    }break;
                }
            }
        }
        memset(m_packet, 0, sizeof(QSPacket));
    }
}
void QSServer::clientWrite(QSPacket* packet) {
    UUID uuid(packet->uuid);
    QSPacketCommand cmd = static_cast<QSPacketCommand>(packet->cmd);
    if (!m_clients[uuid]) {
        return;
    }
    QLocalSocket* socket = m_clients[uuid].socket();

    switch (cmd) {
        case CMD_CREATE:
        case CMD_RESIZE:
        case CMD_EVENT:
            socket->write((char*)packet, sizeof(QSPacket));
            socket->flush();
        break;
        case CMD_INVALID:
            qInfo() << "Invalid command.";
        break;
        default:
            qInfo() << "Unknown command.";
        break;
    }
}
void QSServer::clientUpdate(UUID uuid) {
    if (!m_clients[uuid]) {
        qInfo() << "No such client.";
        return;
    }
    QLocalSocket* socket = m_clients[uuid].socket();
    char charBuff = (char)CMD_UPDATE;
    socket->write(&charBuff, 1);
    socket->flush();
}
//
