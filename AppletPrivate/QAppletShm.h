#pragma once

#include <QQuickView>
#include <QQuickWidget>
#include <QMainWindow>
#include <QWindow>
#include <QApplication>
#include <QOpenGLFramebufferObject>
#include <QOpenGLFunctions>
#include <QOpenGLWidget>
#include <QTimer>
#include <QFile>
#include <QThread>
#include <QDebug>
#include <QEvent>
#include <QObject>
#include <QQuickItem>
#include <QPainter>
#include <QQuickFramebufferObject>
#include <QSGRendererInterface>
#include <QQuickWindow>
#include <QSGDynamicTexture>
#include <QSGSimpleTextureNode>
#include <QSGSimpleRectNode>
#include <QImage>
#include <QMatrix4x4>
#include <QOpenGLFunctions_2_1>

#include <string>
#include <atomic>
#include <mutex>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <errno.h>
#include <string.h>

#include "Globals.h"

class QAppletShm;
static void _shm_close(int fd) {
    close(fd);
}

//
// Server:
//
class QAppletShmPrivate: public QThread {
    Q_OBJECT

public:
    QAppletShmPrivate(QString p_serverName, QObject* parent = nullptr);
    ~QAppletShmPrivate() {
        if (m_socket) {
            m_socket->close();
            delete m_socket;
        }
    }
    void run();

    Q_SIGNAL void connected();
    Q_SIGNAL void disconnected();
    Q_SIGNAL void appletCreated(QString shm);
    Q_SIGNAL void appletResized(int w, int h);
    Q_SIGNAL void appletWindow(int ix);
    Q_SIGNAL void appletNewWindow(int ix);
    Q_SIGNAL void appletEvent(QEvent* ev);
    Q_SIGNAL void appletUpdated();

    void serverWrite(QSPacket* data);
    void serverUpdate();
private:
    void serverOpen();
    void serverClose();
    void serverRead();

    UUID m_uuid;
    QString m_serverName;
    QLocalSocket* m_socket = nullptr;
    QSPacketReader m_packetReader;
    QSPacket* m_packet = nullptr;
};
//


class QAppletShmTexturePrivate: public QSGDynamicTexture {
    Q_OBJECT

public:
    QAppletShmTexturePrivate(QAppletShm* p_parent);
    void bind();
    bool updateTexture() override;
    bool hasAlphaChannel() const override {
        return true;
    }
    bool hasMipmaps() const override {
        return true;
    }
    int textureId() const override {
        return m_texture;
    }
    QSize textureSize() const override {
        return QSize(m_width, m_height);
    }

private:
    std::atomic<bool>* m_valid;

    int m_height = 0;
    int m_width = 0;
    int m_pixelBufferSize = 0;
    const uchar* m_pixelBuffer = nullptr;
    GLuint m_texture = 0;

    QAppletShm* m_parent = nullptr;
};

class QAppletShm: public QQuickItem {
    Q_OBJECT

    Q_PROPERTY(QString uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(int windowId READ getWindowId WRITE setWindowId NOTIFY windowIdChanged)
    Q_PROPERTY(bool valid READ getValid NOTIFY validChanged)

public:
    QAppletShm(QQuickItem* parent = nullptr);
    ~QAppletShm() {}

    QString getUuid() { return m_uuid.toString(); }
    int getWindowId() { return m_windowId; }
    bool getValid() { return m_uuid && m_windowId>0; }
    void setUuid(QString uuid) { m_uuid = uuid; }
    void setWindowId(int id) { m_windowId = id; }

    Q_SIGNAL void windowIdChanged();
    Q_SIGNAL void uuidChanged();
    Q_SIGNAL void validChanged();

public Q_SLOTS:
    void resizeReceived(int p_width, int p_height, const uchar* p_pixelBuffer);
    void updateReceived();

protected:
    virtual QSGNode* updatePaintNode(QSGNode* node, QQuickItem::UpdatePaintNodeData*) override;

private:
    void shm_close() {
        if (m_shmFd) {
            _shm_close(m_shmFd);
        }
    }
    std::atomic<bool> m_valid;

    UUID m_uuid;
    int m_windowId = 0;

    int m_height = 0;
    int m_width = 0;
    int m_pixelBufferSize = 0;

    const uchar* m_pixelBuffer = nullptr;
    QAppletShmTexturePrivate* m_texture = nullptr;
    QAppletShmPrivate* m_cmdReader = nullptr;

    friend class QAppletShmTexturePrivate;
};
