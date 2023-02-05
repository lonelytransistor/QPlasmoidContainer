#pragma once

#include <QQuickView>
#include <QIcon>
#include <QDir>
#include <QWindow>
#include <QApplication>
#include <QOpenGLFunctions>
#include <QOpenGLFramebufferObjectFormat>
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

#include "Globals.h"

struct UUID {
    UUID& operator=(const UUID& r) {
        memcpy(uuid, r.uuid, sizeof(uuid));
        return *this;
    }
    bool operator==(const UUID& l, const UUID& r) {
        return memcmp(l, r, sizeof(uuid)) == 0;
    }
    char uuid[36];

    QString toString() {
        QString::fromLocal8Bit(uuid);
    }
};

class AppletStreamer: public QQuickView {
    Q_OBJECT
public:
    AppletStreamer(UUID uuid, QWindow* parent = nullptr);
    ~AppletStreamer();

    void reload();

    void beforeRendering();
    void afterRendering();
    void frameSwapped();

    Q_SIGNAL void resized(int width, int height);
    Q_SIGNAL void frameReady();
    Q_SLOT void resizeBuffer(int size);
    Q_SLOT void newEvent(QEvent* e);
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

    QString m_shmPath;
    GLubyte* m_pixelBuffer = nullptr;
    QOpenGLFramebufferObject* m_frameBuffer = nullptr;
};
