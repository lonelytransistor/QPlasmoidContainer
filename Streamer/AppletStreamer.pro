TARGET    = appletStreamer
TEMPLATE += app
CONFIG   += c++11
QT       += qml quick dbus Solid KConfigCore KConfigGui KXmlGui KDeclarative widgets KI18n quickwidgets


HEADERS += ../Applet

HEADERS += ../AppletPrivate/AppletContainer
SOURCES += ../AppletPrivate/AppletContainer.cpp ../AppletPrivate/AppletConfigContainer.cpp ../AppletPrivate/ACC.cpp
HEADERS += ../AppletPrivate/AppletContainer.h ../AppletPrivate/AppletConfigContainer.h ../AppletPrivate/ACC.h

HEADERS += ../AppletPrivate/AppletStreamer
SOURCES += ../AppletPrivate/AppletStreamer.cpp
HEADERS += ../AppletPrivate/AppletStreamer.h

HEADERS += ../AppletPrivate/AppletReceiver
SOURCES += ../AppletPrivate/AppletReceiver.cpp
HEADERS += ../AppletPrivate/AppletReceiver.h


SOURCES += main.cpp

LIBS += -lKF5Plasma -lKF5PlasmaQuick -lKF5ConfigQml -lKF5Package
INCLUDEPATH += /usr/include/python3.10/ \
               /usr/include/KF5 \
               /usr/include/KF5/KCoreAddons \
               /usr/include/KF5/KService \
               /usr/include/KF5/KPackage \
               /usr/include/KF5/PlasmaQuick \
               /usr/include/KF5/KConfigQml
