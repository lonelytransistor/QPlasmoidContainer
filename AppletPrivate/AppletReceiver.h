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

class AppletReceiverPrivate: public QThread {
    Q_OBJECT
public:
    AppletReceiverPrivate(QObject* parent = nullptr): QThread(parent) {
    }
    ~AppletReceiverPrivate() {
    }
    void run() override;

Q_SIGNALS:
    void resizeReceived(int width, int height, const uchar* pixelBuffer);
    void updateReceived();
    void clearReceived();

private:
    void readLoop();

    const uchar* m_pixelBuffer;
    long m_pixelBufferSize = 0;
    int m_height = 0;
    int m_width = 0;

    FILE* m_pipeFd = nullptr;
    int m_shmFd = 0;
};

class AppletReceiver;
class AppletReceiverTexturePrivate: public QSGDynamicTexture {
    Q_OBJECT

public:
    AppletReceiverTexturePrivate(AppletReceiver* p_parent);
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
    std::atomic<bool>* m_resizing;

    int m_height = 0;
    int m_width = 0;
    int m_pixelBufferSize = 0;

    const uchar* m_pixelBuffer = nullptr;
    GLuint m_texture = 0;

    AppletReceiver* m_parent = nullptr;
    QString m_test;
};

class AppletReceiver: public QQuickItem {
    Q_OBJECT

    Q_PROPERTY(QString uuid READ getUuid WRITE setUuid NOTIFY uuidChanged)
    Q_PROPERTY(int windowId READ getWindowId WRITE setWindowId NOTIFY windowIdChanged)
    Q_PROPERTY(bool valid READ getValid NOTIFY validChanged)

public:
    AppletReceiver(QQuickItem* parent = nullptr);
    ~AppletReceiver() {}

    QString getUuid();
    int getWindowId();
    bool getValid();
    void setUuid(QString uuid);
    void setWindowId(int id);

    Q_SIGNAL void windowIdChanged();
    Q_SIGNAL void uuidChanged();
    Q_SIGNAL void validChanged();

public Q_SLOTS:
    void resizeReceived(int p_width, int p_height, const uchar* p_pixelBuffer);
    void updateReceived();

protected:
    virtual QSGNode* updatePaintNode(QSGNode* node, QQuickItem::UpdatePaintNodeData*) override;

private:
    std::atomic<bool> m_resizing;

    UUID m_uuid = "";
    int m_windowId = 0;

    int m_height = 0;
    int m_width = 0;
    int m_pixelBufferSize = 0;

    const uchar* m_pixelBuffer = nullptr;
    AppletReceiverTexturePrivate* m_texture = nullptr;
    AppletReceiverPrivate* m_cmdReader = nullptr;

    friend class AppletReceiverTexturePrivate;
};
