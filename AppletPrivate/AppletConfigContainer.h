#pragma once

#include <QQuickPaintedItem>
#include <QQmlProperty>
#include <QQuickItem>
#include <QObject>
#include <QString>
#include <QColor>

#include <KConfig>
#include <KConfigGroup>
#include <KSharedConfig>
#include <KDeclarative/ConfigPropertyMap>

#include <Plasma/Applet>
#include <Plasma/Containment>
#include <Plasma/Corona>
#include <Plasma/Package>

#include "ACC.h"
#include "AppletContainer.h"

class AppletConfigContainer: public QQuickPaintedItem {
    Q_OBJECT
    Q_PROPERTY(QString appletGlobalShortcut READ getHotkey WRITE setHotkey NOTIFY hotkeyChanged)
    Q_PROPERTY(ACCModel* model READ getConfigModel NOTIFY configModelChanged)
    Q_PROPERTY(ACCCategory* category READ getCategory WRITE setCategory NOTIFY categoryChanged)
    Q_PROPERTY(AppletContainer* appletContainer READ getApplet WRITE setApplet NOTIFY appletChanged)

public:
    AppletConfigContainer(QQuickItem* parent = nullptr): QQuickPaintedItem(parent) {
        Q_UNUSED(parent);
    }
    ~AppletConfigContainer() {
    }
    void paint(QPainter *painter) override {
        Q_UNUSED(painter);
    }
    QString getHotkey() {
        return QString();
    }
    void setHotkey(QString) {
    }

    AppletContainer* getApplet();
    ACCCategory* getCategory();
    ACCModel* getConfigModel();
    void setApplet(AppletContainer* p_applet);
    void setCategory(ACCCategory* p_category);

    Q_INVOKABLE void restore();
    Q_INVOKABLE void apply();

Q_SIGNALS:
    void hotkeyChanged();
    void appletChanged();
    void categoryChanged();
    void configModelChanged();

private:
    bool createConfigUI();
    void destroyConfigUI();

    ACCModel* m_configModel = nullptr;
    ACCCategory* m_configCategory = nullptr;
    AppletContainer* m_appletContainer = nullptr;
    QQuickItem* m_configUI = nullptr;
    QColor m_backgroundColor;
};
