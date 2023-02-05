#pragma once
#include <QString>
#include <QObject>
#include <QVariant>
#include <QQmlPropertyMap>
#include <QQmlListProperty>
#include <QAbstractListModel>

class ACCCategory: public QObject {
    Q_OBJECT
    Q_PROPERTY(QString icon READ getIcon WRITE setIcon NOTIFY iconChanged)
    Q_PROPERTY(QString name READ getName WRITE setName NOTIFY nameChanged)
    Q_PROPERTY(QString source READ getSource WRITE setSource NOTIFY sourceChanged)
    Q_PROPERTY(QString pluginName READ getPluginName WRITE setPluginName NOTIFY pluginNameChanged)
    Q_PROPERTY(bool visible READ getVisible WRITE setVisible NOTIFY visibleChanged)

public:
    ACCCategory(QObject *parent = nullptr): QObject(parent) {
    }
    ACCCategory(const QString &p_icon, const QString &p_name, const QString &p_source, const QString &p_pluginName, bool p_visible, QObject *parent): QObject(parent) {
        m_icon = p_icon;
        m_name = p_name;
        m_pluginName = p_pluginName;
        m_visible = p_visible;
        m_source = p_source;
    }
    ~ACCCategory() {}

    QString getIcon() { return m_icon; }
    QString getName() { return m_name; }
    QString getSource() { return m_source; }
    QString getPluginName() { return m_pluginName; }
    bool getVisible() { return m_visible; }

    void setIcon(QString icon) {
        m_icon = icon;
        Q_EMIT iconChanged();
    }
    void setName(QString name) {
        m_name = name;
        Q_EMIT iconChanged();
    }
    void setSource(QString source) {
        m_source = source;
        Q_EMIT iconChanged();
    }
    void setPluginName(QString pluginName) {
        m_pluginName = pluginName;
        Q_EMIT pluginNameChanged();
    }
    void setVisible(bool visible) {
        m_visible = visible;
        Q_EMIT visibleChanged();
    }

Q_SIGNALS:
    void nameChanged();
    void iconChanged();
    void sourceChanged();
    void pluginNameChanged();
    void visibleChanged();

private:
    QString m_icon;
    QString m_name;
    QString m_source;
    QString m_pluginName;
    bool m_visible;
};

class ACCModel: public QAbstractListModel {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<ACCCategory> categories READ categories CONSTANT)
    Q_CLASSINFO("DefaultProperty", "categories")
    Q_PROPERTY(int count READ count NOTIFY countChanged)

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        IconRole,
        SourceRole,
        PluginNameRole,
        VisibleRole,
        KCMRole,
    };
    Q_ENUM(Roles)

    explicit ACCModel(QObject *parent = nullptr) {
        Q_UNUSED(parent);
    }
    ~ACCModel() {}

    Q_INVOKABLE void append(const QString &p_icon, const QString &p_name, const QString &p_path, const QString &p_pluginName, bool p_visible) {
        append(new ACCCategory(p_icon, p_name, p_path, p_pluginName, p_visible, this));
    }
    Q_INVOKABLE void append(ACCCategory* category) {
        m_categories.push_back(category);
        Q_EMIT countChanged();
    }
    Q_INVOKABLE void remove(ACCCategory* category) {
        m_categories.removeAll(category);
        Q_EMIT countChanged();
    }
    Q_INVOKABLE void removeAt(int index) {
        m_categories.removeAt(index);
        Q_EMIT countChanged();
    }
    Q_INVOKABLE void clear() {
        m_categories.clear();
        Q_EMIT countChanged();
    }
    Q_INVOKABLE QObject* at(int index) { return get(index); }
    Q_INVOKABLE QObject* get(int index) { return m_categories.at(index); }
    int count() { return m_categories.count(); }
    QQmlListProperty<ACCCategory> categories();

    int rowCount(const QModelIndex &index = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int, QByteArray> roleNames() const override;

    static int s_count(QQmlListProperty<ACCCategory>* prop);
    static ACCCategory* s_get(QQmlListProperty<ACCCategory>* prop, int index);
    static void s_append(QQmlListProperty<ACCCategory>* prop, ACCCategory* newObj);
    static void s_clear(QQmlListProperty<ACCCategory>* prop);

Q_SIGNALS:
    void countChanged();

private:
    QList<ACCCategory*> m_categories;
};
