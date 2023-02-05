#pragma once

#include <QLocalServer>
#include <QLocalSocket>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QMap>
#include "Globals.h"

struct Packet {
    char magicNumber[sizeof(STREAMER_MAGIC_NUMBER+1)];
    UUID uuid;
    long timeout;
    char applet[MAX(255, QEVENTSIZE)];
    qintptr socketFd;
    QTimer* timer;
};

class PacketReader {
    PacketReader() {
        memset(m_data, 0, sizeof(m_data));
    }
    ~PacketReader() {}
    bool append(char ch, Packet* p);

private:
    bool scanBuffer();

    int m_ix = 0;
    char m_data[sizeof(Packet)*2];
    bool m_magicNumberFound = false;
    char m_magicNumber[] = STREAMER_MAGIC_NUMBER;
};


class AppletStreamerServer: QObject {
    Q_OBJECT

public:
    enum ClientCommand {
        CLIENT_UPDATE = 1,
        CLIENT_RESIZE,
        CLIENT_INVALID
    }

    AppletStreamerServer(QString p_serverName, QObject* parent = nullptr);
    ~AppletStreamerServer();

    Q_SLOT void clientWrite(UUID uuid, const char* data, int size);
    Q_SIGNAL void createApplet(UUID uuid, QString applet);
    Q_SIGNAL void removeApplet(UUID uuid);

    void run() {
        m_server->listen(m_serverName);
    }
private:
    void clientOpen();

    void clientRead();
    void clientRemove(UUID uuid);
    void clientClose();

    PacketReader m_packetReader;
    QString m_serverName;
    QLocalServer* m_server = nullptr;
    QMap<qintptr, QMap<UUID, Packet>*> m_clientsCache;
    QMap<UUID, Packet> m_clients;
};
