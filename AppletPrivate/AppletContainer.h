#pragma once
#include <QQmlEngine>
#include <QQmlContext>
#include <QQuickItem>
#include <QObject>
#include <QString>
#include <QColor>

#include <KConfig>
#include <KConfigGroup>
#include <KSharedConfig>
#include <KLocalizedString>
#include <KDeclarative/ConfigPropertyMap>

#include <Plasma/Applet>
#include <Plasma/Containment>
#include <Plasma/Corona>
#include <Plasma/Package>

#include "ACC.h"

#define LT0_APPNAME "lonelytransistor"
#define LT0_CONFIGNAME LT0_APPNAME "-appletrc"

class Corona;
class AppletContainer: public QQuickItem {
    Q_OBJECT

    Q_PROPERTY(QString applet READ getApplet WRITE setApplet NOTIFY appletChanged)
    Q_PROPERTY(QColor background READ getBackground WRITE setBackground NOTIFY backgroundChanged RESET resetBackground)

public:
    AppletContainer(QQuickItem* parent = nullptr);
    ~AppletContainer();

    QColor getBackground();
    QString getApplet();
    void resetBackground();
    void setBackground(QColor color);
    void setApplet(QString plasmoid);

    Q_SIGNAL void appletChanged();
    Q_SIGNAL void backgroundChanged();

    Q_INVOKABLE void loadConfig();
    Q_INVOKABLE void saveConfig();

    ACCModel* getAppletConfigModel();
    KDeclarative::ConfigPropertyMap* getConfig();
    QQuickItem* getAppletQuick() { return m_appletQuick; }
    QColor getBackgroundColor() { return m_backgroundColor; }
private:
    void destroyApplet();
    bool setAppletInternal(QString plasmoid);
    void setContainmentBackground();
    void save();
    void restore();
    void setWallpaper();
    void geometryChanged(const QRectF &nGeo, const QRectF &oGeo) override;

    Corona* m_corona = nullptr;
    Plasma::Containment* m_containment = nullptr;
    Plasma::Applet* m_applet = nullptr;
    QString m_appletName = "";
    QQuickItem* m_containmentQuick = nullptr;
    QQuickItem* m_appletQuick = nullptr;
    QColor m_backgroundColor;
    QColor m_defaultBackgroundColor;

    KSharedConfigPtr m_sharedConfig;
    KConfigGroup m_sharedConfigGroup;
    KDeclarative::ConfigPropertyMap* m_appletConfig = nullptr;

    ACCModel* m_configModel = nullptr;
};

class Corona: public Plasma::Corona {
public:
    Corona(AppletContainer* view):Plasma::Corona() {
        m_view = view;
    }
    QRect screenGeometry(int id) const override {
        Q_UNUSED(id);
        return QRect(QPoint(0, 0), m_view->size().toSize());
    }

    int screenForContainment(const Plasma::Containment *containment) const override {
        Q_UNUSED(containment);
        return 0;
    }
private:
    AppletContainer* m_view = nullptr;
};
