#pragma once

#include <QQuickView>
#include <QIcon>
#include <QDir>
#include <QWindow>
#include <QApplication>
#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObjectFormat>
#include <QQmlIncubationController>
#include <QQmlEngine>
#include <QFile>
#include <QDebug>

#include <string>
#include <atomic>
#include <mutex>

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <signal.h>

#include "Applet"

static void _shm_close(int fd) {
    close(fd);
}
class QAppletShmIncubationController : public QObject, public QQmlIncubationController {
public:
    void setApplet(QString p_applet) { m_applet = p_applet; }
    QString getApplet() { return m_applet; }
private:
    QString m_applet;
};

class QAppletShmServer: public QQuickView {
    Q_OBJECT
public:
    QAppletShmServer(QString shmPath, QString appletName, QString sUuid, QWindow* parent = nullptr);
    ~QAppletShmServer();

    void reload();

    void beforeRendering();
    void afterRendering();
    void frameSwapped();

    Q_SIGNAL void resized(int width, int height);
    Q_SIGNAL void updated();
    void resizeBuffer(int size);
    QWindow* getWindow() {
        return qobject_cast<QWindow*>(this);
    }

    void shm_close(int fd) {
        _shm_close(fd);
    }
private:
    void releaseFrameBuffer();

    void resizeBuffer(int width, int height);
    void resizeEvent(QResizeEvent* e) override;
    void cleanupFb();

    std::mutex m_mutex;
    int m_height = 0;
    int m_width = 0;
    int m_shmFd = 0;
    int m_bufferSize = 0;

    QAppletShmIncubationController* m_incubator = nullptr;
    QQmlEngine* m_engine = nullptr;
    QString m_shmPath;
    GLubyte* m_pixelBuffer = nullptr;
    QOpenGLFramebufferObject* m_frameBuffer = nullptr;
    AppletContainer* m_applet = nullptr;
};
