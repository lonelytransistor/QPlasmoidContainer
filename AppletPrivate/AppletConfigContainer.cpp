#include "AppletConfigContainer.h"

// Properties
AppletContainer* AppletConfigContainer::getApplet() {
    return m_appletContainer;
}
ACCCategory* AppletConfigContainer::getCategory() {
    return m_configCategory;
}
ACCModel* AppletConfigContainer::getConfigModel() {
    return m_configModel;
}
void AppletConfigContainer::setApplet(AppletContainer* p_applet) {
    m_appletContainer = p_applet;
    Q_EMIT appletChanged();
    if (!m_appletContainer)
        return;
    m_configModel = m_appletContainer->getAppletConfigModel();
    m_backgroundColor = m_appletContainer->getBackgroundColor();
    setFillColor(m_backgroundColor);
    Q_EMIT configModelChanged();
}
void AppletConfigContainer::setCategory(ACCCategory* p_category) {
    m_configCategory = p_category;
    destroyConfigUI();
    createConfigUI();
    Q_EMIT categoryChanged();
}
//

// Functions
Q_INVOKABLE void AppletConfigContainer::restore() {
    if (!m_appletContainer || !m_configUI)
        return;
    KDeclarative::ConfigPropertyMap* m_appletConfig = m_appletContainer->getConfig();
    for (QString key : m_appletConfig->keys()) {
        QQmlProperty::write(m_configUI, "cfg_" + key, m_appletConfig->value(key));
    }
}
Q_INVOKABLE void AppletConfigContainer::apply() {
    if (!m_appletContainer || !m_configUI)
        return;
    KDeclarative::ConfigPropertyMap* m_appletConfig = m_appletContainer->getConfig();
    for (QString key : m_appletConfig->keys()) {
        QVariant value = m_configUI->property(QString("cfg_" + key).toStdString().c_str());
        if (value.isValid()) {
            m_appletConfig->insert(key, value);
        }
    }
}
//

// Private
bool AppletConfigContainer::createConfigUI() {
    if (!m_configCategory || !m_configModel || !m_appletContainer)
        return false;
    QQmlContext* context = qmlContext(m_appletContainer->getAppletQuick()->property("rootItem").value<QObject*>());
    if (!context)
        return false;
    QQmlEngine* engine = context->engine();
    if (!engine)
        return false;
    QUrl uiPath = context->baseUrl().resolved(QString("../ui/")).resolved(m_configCategory->getSource());
    QQmlComponent configUIComponent(engine, uiPath, this);
    m_configUI = qobject_cast<QQuickItem*>(configUIComponent.beginCreate(context));
    if (!m_configUI) {
        qInfo() << configUIComponent.errors();
        return false;
    }
    restore();
    m_configUI->setFocus(true);
    m_configUI->setVisible(true);
    m_configUI->setParentItem(this);
    QQmlProperty::write(m_configUI, QStringLiteral("anchors.fill"), QVariant::fromValue<QObject*>(qobject_cast<QObject*>(this)));
    configUIComponent.completeCreate();
    return true;
}
void AppletConfigContainer::destroyConfigUI() {
    if (!m_configUI)
        return;
    m_configUI->setFocus(false);
    m_configUI->setVisible(false);
    m_configUI->setParentItem(nullptr);
    //m_configUI->destroy();
    m_configUI = nullptr;
}
//
