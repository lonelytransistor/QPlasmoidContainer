TARGET    = qAppletShmServer
TEMPLATE += app
CONFIG   += c++11
QT       += qml quick dbus Solid KConfigCore KConfigGui KXmlGui KDeclarative widgets KI18n quickwidgets

HEADERS += ../AppletPrivate/Globals.h
HEADERS += ../AppletPrivate/Macros.h

SOURCES += ../AppletPrivate/QAppletShm.cpp
HEADERS += ../AppletPrivate/QAppletShm.h

SOURCES += ../AppletPrivate/AppletContainer.cpp ../AppletPrivate/AppletConfigContainer.cpp ../AppletPrivate/ACC.cpp
HEADERS += ../AppletPrivate/AppletContainer.h ../AppletPrivate/AppletConfigContainer.h ../AppletPrivate/ACC.h

HEADERS += Applet
SOURCES += QAppletShmServer.cpp
HEADERS += QAppletShmServer.h
HEADERS += AppletStreamerServer.h main.h
SOURCES += AppletStreamerServer.cpp main.cpp

LIBS += -lKF5Plasma -lKF5PlasmaQuick -lKF5ConfigQml -lKF5Package
INCLUDEPATH += /usr/include/python3.10/ \
               /usr/include/KF5 \
               /usr/include/KF5/KCoreAddons \
               /usr/include/KF5/KService \
               /usr/include/KF5/KPackage \
               /usr/include/KF5/PlasmaQuick \
               /usr/include/KF5/KConfigQml
