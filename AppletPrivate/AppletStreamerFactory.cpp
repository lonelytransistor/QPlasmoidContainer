#include "AppletStreamerFactory.h"

bool PacketReader::append(char ch, Packet* p) {
    m_data[m_ix++] = ch;
    if (scanBuffer()) {
        memcpy(p, m_data, sizeof(Packet));
        memcpy(m_data, &m_data[sizeof(Packet)], sizeof(m_data) - sizeof(Packet));
        m_ix = 0;
    }
}
bool PacketReader::scanBuffer() {
    if (m_magicNumberFound) {
        m_magicNumberFound = false;
        return m_ix>=sizeof(m_data)/2;
    }
    for (int ix=0; ix<sizeof(m_data); ix++) {
        if (strncmp(&m_data[ix], m_magicNumber, sizeof(m_magicNumber) == 0) {
            for (int ix2=0; ix<sizeof(m_data); ix++,ix2++) {
                m_data[ix2] = m_data[ix];
                m_ix = ix2+1;
            }
            m_magicNumberFound = true;
            return false;
        }
    }
    return false;
}


AppletStreamerServer::AppletStreamerServer(QString p_serverName, QObject* parent): QObject(parent) {
    m_serverName = p_serverName;
    m_server = new QLocalAppletStreamerServer();
    m_server->setSocketOptions(QLocalAppletStreamerServer::UserAccessOption);
    m_server->setMaxPendingConnections(30);

    connect(m_server. &QLocalAppletStreamerServer::newConnection, [this]{ clientOpen(); });
}

void AppletStreamerServer::clientOpen() {
    QLocalSocket* localSocket = m_server->nextPendingConnection();

    connect(localSocket, &QLocalSocket::readyRead,    [this]{ clientRead(); });
    connect(localSocket, &QLocalSocket::disconnected, [this]{ clientClose(); });
}
void AppletStreamerServer::clientRead() {
    QLocalSocket* localSocket = (QLocalSocket*)sender();
    char charBuff = 0;
    Packet* packet = new Packet();
    memset(packet, 0, sizeof(packet));

    while (localSocket->isValid() && localSocket->bytesAvailable()) {
        getChar(&charBuff);
        if (m_packetReader.append(charBuff, packet)) {
            packet->socketFd = localSocket->socketDescriptor();

            if (m_clients.contains(packet->uuid)) {
                if (m_clients[packet->uuid].socketFd != packet->socketFd) {
                    qInfo() << "Error! A second client is trying to use the same UUID. This would crash the currently connected one.";
                    continue;
                } else {
                    if (m_clients[packet->uuid].timeout != packet->timeout) {
                        m_clients[packet->uuid].timer->stop();
                    }
                    packet->timer = m_clients[packet->uuid].timer;
                    if (strncmp(m_clients[packet->uuid].applet, packet->applet, sizeof(packet->applet)) != 0) {
                        Q_EMIT removeApplet(packet->uuid);
                    }
                }
            } else {
                packet->timer = new QTimer();
                packet->timer->setInterval(client->timeout > 0 ? client->timeout : 0);
                packet->timer->callOnTimeout(this, [this, packet]{ clientRemove(packet->uuid); });
            }
            m_clients[packet->uuid] = packet;
            m_clientsCache[packet->socketFd] = &m_clients[packet->uuid];

            Q_EMIT createApplet(packet->uuid, QString(packet->applet));
        }
    }
}
void AppletStreamerServer::clientClose() {
    QLocalSocket* localSocket = (QLocalSocket*)sender();
    Packet* client = m_clientsCache[localSocket->socketDescriptor()]->value();
    client->timer->start();
}
void AppletStreamerServer::clientRemove(UUID uuid) {
    Packet* packet = m_clients[uuid];
    packet->timer->stop();
    m_clientsCache.remove(packet->socketFd);
    m_clients.remove[uuid);
    delete packet->timer;
    delete packet;

    Q_EMIT removeApplet(uuid);
}

void AppletStreamerServer::clientWrite(UUID uuid, const char* data, int size) {
    Packet* client = &m_clients[uuid];
    QLocalSocket localSocket;
    localSocket.setSocketDescriptor(client->socketFd);

    ClientCommand cmd = reinterpret_cast<ClientCommand>(data[0]);
    switch (cmd) {
        case CLIENT_UPDATE:
            localSocket.writeData(data, 1);
            localSocket.flush();
        break;
        case CLIENT_RESIZE:
            localSocket.writeData(data, size);
            localSocket.flush();
        break;
        case CLIENT_INVALID:
            qInfo() << "Invalid command.";
        return;
        default:
            qInfo() << "Unknown command.";
        return;
    }
}
