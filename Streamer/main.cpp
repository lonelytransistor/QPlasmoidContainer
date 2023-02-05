#include "../Applet"
//#include "Server.h"

AppletStreamer* view;
int main(int p_argc, char *p_argv[]) {
    char** argv = new char*[p_argc];
    argv[0] = p_argv[0];
    argv[1] = (char*)"-platform";
    argv[2] = (char*)"offscreen";
    for (int ix=1; ix<p_argc; ix++) {
        argv[2+ix] = p_argv[ix];
    }
    int argc = p_argc + 2;

    QApplication::setStyle("breeze-dark");
    QApplication a(argc, argv);
    QApplet::registerTypes();

    view = new AppletStreamer();
    view->setSource(QUrl::fromLocalFile("application.qml"));
    view->show();

    // Why does it lose these on -platform offscreen? I have no idea.
    /*QStringList list;
    list.push_back(QDir::homePath() + QString("/.local/share/icons"));
    list.push_back(QString("/usr/share/icons"));
    for (QString path : QIcon::themeSearchPaths()) {
        list.push_back(path);
    }
    QIcon::setThemeSearchPaths(list);
    QIcon::setThemeName(QString("breeze-dark"));
    qInfo() << QIcon::themeSearchPaths();*/

    return a.exec();
}
