import QtQml 2.15
import QtQuick 2.15

import AppletContainer 1.0
import AppletConfigContainer 1.0

Item {
    id: window
    width: 500
    height: 700

    AppletContainer {
        id: applet
        anchors.fill: parent
        applet: "com.github.prayag2.controlcentre"
    }
}
