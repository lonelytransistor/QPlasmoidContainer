#include "AppletContainer.h"

AppletContainer::AppletContainer(QQuickItem* parent): QQuickItem(parent) {
    KLocalizedString::setApplicationDomain(LT0_APPNAME);
    m_corona = new Corona(this);

    m_containment = m_corona->createContainment(QStringLiteral("org.kde.desktopcontainment"), QVariantList()<<QStringLiteral("org.kde.plasma:force-create"));
    m_containment->setContainmentType(Plasma::Types::CustomContainment);
    m_containment->setFormFactor(Plasma::Types::Planar);
    m_containment->setLocation(Plasma::Types::Floating);

    m_containmentQuick = qobject_cast<QQuickItem*>(m_containment->property("_plasma_graphicObject").value<QObject*>());
    m_containmentQuick->setFocus(true);
    m_containmentQuick->setParentItem(this);
    m_containmentQuick->setVisible(true);

    KSharedConfig::Ptr kdeConfig  = KSharedConfig::openConfig("kdeglobals", KConfig::SimpleConfig | KConfig::CascadeConfig);
    KConfigGroup kdeConfigGroup = kdeConfig.data()->group("Colors:Window");
    m_defaultBackgroundColor = kdeConfigGroup.readEntry("BackgroundNormal", QColor(0,0,0));

    m_sharedConfig = KSharedConfig::openConfig(LT0_CONFIGNAME, KConfig::SimpleConfig | KConfig::CascadeConfig);
    m_sharedConfigGroup = m_sharedConfig->group("SwipeEffect").group("Plasmoids");

    setWallpaper();
}
AppletContainer::~AppletContainer() {
    destroyApplet();
    if (m_containment) {
        delete m_containment;
    }
}
////
////
KDeclarative::ConfigPropertyMap* AppletContainer::getConfig() {
    if (!m_appletConfig) {
        m_appletConfig = qobject_cast<KDeclarative::ConfigPropertyMap*>(m_appletQuick->property("configuration").value<QObject*>());
    }
    return m_appletConfig;
}
void AppletContainer::loadConfig() {
    m_appletConfig = getConfig();
    if (!m_appletConfig)
        return;

    KConfigGroup config = m_sharedConfigGroup.group(m_appletName);
    for (QString key : config.keyList()) {
        QVariant value = config.readEntry(key, QString());
        QVariant::Type type = m_appletConfig->value(key).type();
        if (value.canConvert(type)) {
            switch (type) {
                case QVariant::Color:
                    value = QVariant(config.readEntry(key, QColor()));
                break;
                default:
                    value.convert(type);
                break;
            }
        }
        m_appletConfig->insert(key, value);
    }
}
void AppletContainer::saveConfig() {
    m_appletConfig = getConfig();
    if (!m_appletConfig)
        return;

    KConfigGroup config = m_sharedConfigGroup.group(m_appletName);
    for (QString key : m_appletConfig->keys()) {
        config.writeEntry(key, m_appletConfig->value(key));
    }
    m_sharedConfig->sync();
}
////
////
void AppletContainer::setApplet(QString plasmoid) {
    if (m_appletName == plasmoid)
        return;

    m_appletName = plasmoid;
    setAppletInternal(plasmoid);
    Q_EMIT appletChanged();
}
QString AppletContainer::getApplet() {
    return m_appletName;
}
void AppletContainer::resetBackground() {
    m_backgroundColor = m_defaultBackgroundColor;
    Q_EMIT backgroundChanged();
}
void AppletContainer::setBackground(QColor color) {
    m_backgroundColor = color;
    setWallpaper();
    Q_EMIT appletChanged();
}
QColor AppletContainer::getBackground() {
    return m_backgroundColor;
}
////
////
void AppletContainer::geometryChanged(const QRectF &nGeo, const QRectF &oGeo) {
    Q_UNUSED(nGeo); Q_UNUSED(oGeo);
    int i_w = m_appletQuick->size().width();
    int i_h = m_appletQuick->size().height();
    int o_w = m_containmentQuick->size().width();
    int o_h = m_containmentQuick->size().height();
    int w = std::max(i_w, o_w);
    int h = std::max(i_h, o_h);
    m_containmentQuick->setSize(QSize(w, h));

    m_corona->screenGeometryChanged(0);
    m_corona->availableScreenRectChanged();
    m_corona->availableScreenRegionChanged();
}
////
void AppletContainer::destroyApplet() {
    if (!m_applet) {
        return;
    }
    disconnect(m_appletQuick, SIGNAL(busyChanged()), this, SLOT(loadConfig()));
    disconnect(m_appletQuick, SIGNAL(configNeedsSaving()), this, SLOT(saveConfig()));
    //m_configModel->destroy();
    //m_applet->destroy();
    m_applet = nullptr;
    m_appletQuick = nullptr;
    m_appletConfig = nullptr;
    m_configModel = nullptr;
}
void AppletContainer::setWallpaper() {
    KConfigGroup group = m_containment->config();
    group = group.group("Wallpaper");
    group = group.group("org.kde.color");
    group = group.group("General");
    group.writeEntry("Color", m_backgroundColor);
    m_containment->setWallpaper("org.kde.color");
}
ACCModel* AppletContainer::getAppletConfigModel() {
    if (m_configModel)
        return m_configModel;
    if (!m_applet || !m_appletQuick)
        return nullptr;
    QString configPath = m_applet->kPackage().filePath("configmodel");
    QQmlContext* context = qmlContext(m_appletQuick);
    if (!context)
        return nullptr;
    QQmlEngine* engine = context->engine();
    if (!engine)
        return nullptr;
    QQmlComponent configComponent(engine, QUrl::fromLocalFile(configPath), m_appletQuick);
    m_configModel = qobject_cast<ACCModel*>(configComponent.create(context));
    if (!m_configModel)
        return nullptr;
    configComponent.completeCreate();

    return qobject_cast<ACCModel*>(m_configModel);
}
QQmlContext* AppletContainer::getRootContext() {
    QQmlContext* context = qmlContext(m_appletQuick);
    if (!context)
        return nullptr;
    QQmlEngine* engine = context->engine();
    if (!engine)
        return nullptr;
    return engine->rootContext();
}
bool AppletContainer::setAppletInternal(QString plasmoid) {
    destroyApplet();

    m_applet = m_containment->createApplet(plasmoid, QVariantList()<<QStringLiteral("org.kde.plasma:force-create"));
    if (!m_applet->pluginMetaData().isValid()) {
        destroyApplet();
        return false;
    }

    const QString localePath = m_applet->kPackage().filePath("translations");
    if (!localePath.isEmpty()) {
        const QString localeDomain = QByteArray("plasma_applet_") + m_applet->pluginMetaData().pluginId();
        KLocalizedString::addDomainLocaleDir(localeDomain.toLatin1(), localePath);
    }

    m_applet->setBackgroundHints(Plasma::Types::NoBackground);
    m_appletQuick = qobject_cast<QQuickItem*>(m_applet->property("_plasma_graphicObject").value<QObject*>());
    connect(m_appletQuick, SIGNAL(busyChanged()), this, SLOT(loadConfig()));
    connect(m_appletQuick, SIGNAL(configNeedsSaving()), this, SLOT(saveConfig()));

    return true;
}
