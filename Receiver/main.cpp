#include "../Applet"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QQuickView* view = new QQuickView;

    QApplet::registerTypes();

    view->setSource(QUrl::fromLocalFile("receiver.qml"));
    view->show();

    return a.exec();
}
