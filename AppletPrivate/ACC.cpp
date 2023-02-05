#include "ACC.h"

int ACCModel::s_count(QQmlListProperty<ACCCategory>* prop) {
    ACCModel* model = qobject_cast<ACCModel*>(prop->object);
    if (model)
        return model->count();
    return 0;
}
ACCCategory* ACCModel::s_get(QQmlListProperty<ACCCategory>* prop, int index) {
    ACCModel* model = qobject_cast<ACCModel*>(prop->object);
    if (model)
        return qobject_cast<ACCCategory*>(model->get(index));
    return nullptr;
}
void ACCModel::s_append(QQmlListProperty<ACCCategory>* prop, ACCCategory* newObj) {
    ACCModel* model = qobject_cast<ACCModel*>(prop->object);
    if (model && newObj)
        model->append(newObj);
}
void ACCModel::s_clear(QQmlListProperty<ACCCategory>* prop) {
    ACCModel* model = qobject_cast<ACCModel*>(prop->object);
    if (model)
        model->clear();
}
QQmlListProperty<ACCCategory> ACCModel::categories() {
    return QQmlListProperty<ACCCategory>(this, nullptr, ACCModel::s_append, ACCModel::s_count, ACCModel::s_get, ACCModel::s_clear);
}
QHash<int, QByteArray> ACCModel::roleNames() const {
    return {
        {NameRole, "name"},
        {IconRole, "icon"},
        {SourceRole, "source"},
        {PluginNameRole, "pluginName"},
        {VisibleRole, "visible"},
        {KCMRole, "kcm"},
    };
}
int ACCModel::rowCount(const QModelIndex& index) const {
    if (index.column() > 0)
        return 0;
    return m_categories.count();
}
QVariant ACCModel::data(const QModelIndex& index, int role) const {
    if (index.row() < 0 || index.row() >= m_categories.count())
        return QVariant();
    ACCCategory* cat = m_categories.at(index.row());
    switch (role) {
        case NameRole:
            return cat->getName();
        case IconRole:
            return cat->getIcon();
        case SourceRole:
            return cat->getSource();
        case PluginNameRole:
            return cat->getPluginName();
        case VisibleRole:
            return cat->getVisible();
        case KCMRole:
            return QVariant();
        default:
            return QVariant();
    }
}
