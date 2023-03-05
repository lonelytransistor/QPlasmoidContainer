#pragma once
#include <QGuiApplication>
#include <QString>
#include <QEvent>
#include <QMap>
#include "AppletStreamerServer.h"
#include "QAppletShmServer.h"

//
// Main application:
//
class QSAppletPrivate {
public:
    QSAppletPrivate(int &p_argc, char **p_argv) {
        argv = new char*[p_argc+2];
        argv[0] = p_argv[0];
        argv[1] = (char*)"-platform";
        argv[2] = (char*)"offscreen";
        for (int ix=1; ix<p_argc; ix++) {
            argv[2+ix] = p_argv[ix];
        }
        argc = p_argc + 2;
    }
    char** argv;
    int argc;
};

class QSApplet: public QGuiApplication {
    Q_OBJECT
public:
    QSApplet(int &argc, char *argv[]): QSApplet(QSAppletPrivate(argc, argv)) {}
    QSApplet(QSAppletPrivate priv): QGuiApplication(priv.argc, priv.argv) {
        QApplication::setStyle("breeze-dark");
        m_server = new QSServer(STREAMER_SERVER_NAME);
        m_server->start();
        QApplet::registerTypes();
    }
    ~QSApplet() {
        delete m_server;
    }

    // From server:
    Q_SLOT void appletCreate(UUID, QString);
    Q_SLOT void appletDestroy(UUID uuid);
    Q_SLOT void appletBuffer(UUID uuid, int size);
    Q_SLOT void appletWindow(UUID uuid, int ix);
    Q_SLOT void appletWindows(UUID uuid);
    Q_SLOT void appletEvent(UUID uuid, QEvent* event);
    // From applet:
    Q_SLOT void appletUpdate(UUID uuid);
    Q_SLOT void appletResize(UUID uuid, int w, int h);

    bool event(QEvent* ev) override {
        if (ev->type() == QEvent::Show) {
            for (QWindow* window : allWindows()) {
                qInfo() << window;
                //qInfo() << window->incubationController()->getApplet();
            }
        }
        return QGuiApplication::event(ev);
    }
private:
    QMap<UUID,QAppletShmServer*> m_applets;
    QSServer* m_server;
    QSPacket m_buffer;
};
//
