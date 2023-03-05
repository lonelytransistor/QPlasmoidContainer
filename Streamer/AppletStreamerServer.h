#pragma once

#include <QLocalServer>
#include <QLocalSocket>
#include <QObject>
#include <QString>
#include <QTimer>
#include <QMap>
#include "Applet"
#include "QAppletShmServer.h"

//
// Client data:
//
class QSClient: public QObject {
    Q_OBJECT

public:
    QSClient(QObject* parent = nullptr): QObject(parent) {};
    QSClient(UUID uuid, QString applet, QLocalSocket* socket, int timeout, bool valid = true);
    QSClient(const QSClient& r): QObject() {
        copy(r);
    }
    QSClient& operator=(QSClient r) {
        copy(r);
        return *this;
    }
    bool operator==(QSClient r);
    bool operator==(bool r) {
        return m_valid==r;
    }
    operator bool() const {
        return m_valid;
    }

    QString uuid() { return m_uuid; }
    QString name() { return m_applet; }
    QLocalSocket* socket() { return m_socket; }

    void startTimer();
    void stopTimer();

    Q_SIGNAL void timeout();
private:
    void remove();
    void copy(QSClient r) {
        m_uuid = r.m_uuid;
        m_applet = r.m_applet;
        m_socket = r.m_socket;
        m_timeout = r.m_timeout>=1 ? r.m_timeout : 1;
        if (r.m_timer != nullptr && !r.m_timer->isActive())
            r.stopTimer();
    }

    UUID m_uuid;
    bool m_valid = false;
    int m_timeout = 0;
    QString m_applet;
    QTimer* m_timer = nullptr;
    QLocalSocket* m_socket = nullptr;
};
class QSClientMap: public QMap<UUID,QSClient> {
public:
    QSClient& operator[](UUID uuid) {
        cleanup();
        if (!contains(uuid)) {
            insert(uuid, QSClient());
        }
        return QMap<UUID,QSClient>::operator[](uuid);
    }
    QSClient& operator[](QLocalSocket* localSocket) {
        cleanup();
        return QMap<UUID,QSClient>::operator[](findUuidBySocket(localSocket->socketDescriptor()));
    }

    void remove(UUID uuid) {
        QMap<UUID,QSClient>::remove(uuid);
        cleanup();
    }
    void remove(QLocalSocket* localSocket) {
        remove(findUuidBySocket(localSocket->socketDescriptor()));
        cleanup();
    }

private:
    UUID findUuidBySocket(qintptr socket);
    void cleanup();

    QMap<qintptr,UUID> m_altMap;
};

//
// Server:
//
class QSServer: public QThread {
    Q_OBJECT

public:

    QSServer(QString p_serverName, QObject* parent = nullptr);
    ~QSServer() {
        if (m_server) {
            m_server->close();
            delete m_server;
        }
    }

    void run();

    Q_SIGNAL void appletDestroy(UUID);
    Q_SIGNAL void appletCreate(UUID, QString);
    Q_SIGNAL void appletBuffer(UUID, int);
    Q_SIGNAL void appletWindow(UUID, int);
    Q_SIGNAL void appletEvent(UUID, QEvent*);

    void clientWrite(QSPacket* data);
    void clientUpdate(UUID uuid);
private:
    void clientOpen();
    void clientClose();
    void clientRemove(UUID uuid);
    void clientRead();

    QLocalServer* m_server = nullptr;
    QSPacket* m_packet = nullptr;
    QSPacketReader m_packetReader;
    QSClientMap m_clients;
    QString m_serverName;
};
//
