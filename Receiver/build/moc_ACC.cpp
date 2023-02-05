/****************************************************************************
** Meta object code from reading C++ file 'ACC.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AppletPrivate/ACC.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ACC.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ACCCategory_t {
    QByteArrayData data[12];
    char stringdata0[120];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ACCCategory_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ACCCategory_t qt_meta_stringdata_ACCCategory = {
    {
QT_MOC_LITERAL(0, 0, 11), // "ACCCategory"
QT_MOC_LITERAL(1, 12, 11), // "nameChanged"
QT_MOC_LITERAL(2, 24, 0), // ""
QT_MOC_LITERAL(3, 25, 11), // "iconChanged"
QT_MOC_LITERAL(4, 37, 13), // "sourceChanged"
QT_MOC_LITERAL(5, 51, 17), // "pluginNameChanged"
QT_MOC_LITERAL(6, 69, 14), // "visibleChanged"
QT_MOC_LITERAL(7, 84, 4), // "icon"
QT_MOC_LITERAL(8, 89, 4), // "name"
QT_MOC_LITERAL(9, 94, 6), // "source"
QT_MOC_LITERAL(10, 101, 10), // "pluginName"
QT_MOC_LITERAL(11, 112, 7) // "visible"

    },
    "ACCCategory\0nameChanged\0\0iconChanged\0"
    "sourceChanged\0pluginNameChanged\0"
    "visibleChanged\0icon\0name\0source\0"
    "pluginName\0visible"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ACCCategory[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       5,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,
       5,    0,   42,    2, 0x06 /* Public */,
       6,    0,   43,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QString, 0x00495103,
       8, QMetaType::QString, 0x00495103,
       9, QMetaType::QString, 0x00495103,
      10, QMetaType::QString, 0x00495103,
      11, QMetaType::Bool, 0x00495103,

 // properties: notify_signal_id
       1,
       0,
       2,
       3,
       4,

       0        // eod
};

void ACCCategory::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ACCCategory *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nameChanged(); break;
        case 1: _t->iconChanged(); break;
        case 2: _t->sourceChanged(); break;
        case 3: _t->pluginNameChanged(); break;
        case 4: _t->visibleChanged(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ACCCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCCategory::nameChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (ACCCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCCategory::iconChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (ACCCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCCategory::sourceChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (ACCCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCCategory::pluginNameChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (ACCCategory::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCCategory::visibleChanged)) {
                *result = 4;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ACCCategory *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getIcon(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->getName(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->getSource(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->getPluginName(); break;
        case 4: *reinterpret_cast< bool*>(_v) = _t->getVisible(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<ACCCategory *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setIcon(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setSource(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setPluginName(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setVisible(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ACCCategory::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_ACCCategory.data,
    qt_meta_data_ACCCategory,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ACCCategory::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ACCCategory::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ACCCategory.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int ACCCategory::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 5;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 5;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ACCCategory::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void ACCCategory::iconChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void ACCCategory::sourceChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void ACCCategory::pluginNameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void ACCCategory::visibleChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}
struct qt_meta_stringdata_ACCModel_t {
    QByteArrayData data[28];
    char stringdata0[264];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ACCModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ACCModel_t qt_meta_stringdata_ACCModel = {
    {
QT_MOC_LITERAL(0, 0, 8), // "ACCModel"
QT_MOC_LITERAL(1, 9, 15), // "DefaultProperty"
QT_MOC_LITERAL(2, 25, 10), // "categories"
QT_MOC_LITERAL(3, 36, 12), // "countChanged"
QT_MOC_LITERAL(4, 49, 0), // ""
QT_MOC_LITERAL(5, 50, 6), // "append"
QT_MOC_LITERAL(6, 57, 6), // "p_icon"
QT_MOC_LITERAL(7, 64, 6), // "p_name"
QT_MOC_LITERAL(8, 71, 6), // "p_path"
QT_MOC_LITERAL(9, 78, 12), // "p_pluginName"
QT_MOC_LITERAL(10, 91, 9), // "p_visible"
QT_MOC_LITERAL(11, 101, 12), // "ACCCategory*"
QT_MOC_LITERAL(12, 114, 8), // "category"
QT_MOC_LITERAL(13, 123, 6), // "remove"
QT_MOC_LITERAL(14, 130, 8), // "removeAt"
QT_MOC_LITERAL(15, 139, 5), // "index"
QT_MOC_LITERAL(16, 145, 5), // "clear"
QT_MOC_LITERAL(17, 151, 2), // "at"
QT_MOC_LITERAL(18, 154, 3), // "get"
QT_MOC_LITERAL(19, 158, 29), // "QQmlListProperty<ACCCategory>"
QT_MOC_LITERAL(20, 188, 5), // "count"
QT_MOC_LITERAL(21, 194, 5), // "Roles"
QT_MOC_LITERAL(22, 200, 8), // "NameRole"
QT_MOC_LITERAL(23, 209, 8), // "IconRole"
QT_MOC_LITERAL(24, 218, 10), // "SourceRole"
QT_MOC_LITERAL(25, 229, 14), // "PluginNameRole"
QT_MOC_LITERAL(26, 244, 11), // "VisibleRole"
QT_MOC_LITERAL(27, 256, 7) // "KCMRole"

    },
    "ACCModel\0DefaultProperty\0categories\0"
    "countChanged\0\0append\0p_icon\0p_name\0"
    "p_path\0p_pluginName\0p_visible\0"
    "ACCCategory*\0category\0remove\0removeAt\0"
    "index\0clear\0at\0get\0QQmlListProperty<ACCCategory>\0"
    "count\0Roles\0NameRole\0IconRole\0SourceRole\0"
    "PluginNameRole\0VisibleRole\0KCMRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ACCModel[] = {

 // content:
       8,       // revision
       0,       // classname
       1,   14, // classinfo
       8,   16, // methods
       2,   84, // properties
       1,   92, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // classinfo: key, value
       1,    2,

 // signals: name, argc, parameters, tag, flags
       3,    0,   56,    4, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       5,    5,   57,    4, 0x02 /* Public */,
       5,    1,   68,    4, 0x02 /* Public */,
      13,    1,   71,    4, 0x02 /* Public */,
      14,    1,   74,    4, 0x02 /* Public */,
      16,    0,   77,    4, 0x02 /* Public */,
      17,    1,   78,    4, 0x02 /* Public */,
      18,    1,   81,    4, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::Bool,    6,    7,    8,    9,   10,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::Int,   15,
    QMetaType::Void,
    QMetaType::QObjectStar, QMetaType::Int,   15,
    QMetaType::QObjectStar, QMetaType::Int,   15,

 // properties: name, type, flags
       2, 0x80000000 | 19, 0x00095409,
      20, QMetaType::Int, 0x00495001,

 // properties: notify_signal_id
       0,
       0,

 // enums: name, alias, flags, count, data
      21,   21, 0x0,    6,   97,

 // enum data: key, value
      22, uint(ACCModel::NameRole),
      23, uint(ACCModel::IconRole),
      24, uint(ACCModel::SourceRole),
      25, uint(ACCModel::PluginNameRole),
      26, uint(ACCModel::VisibleRole),
      27, uint(ACCModel::KCMRole),

       0        // eod
};

void ACCModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<ACCModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->countChanged(); break;
        case 1: _t->append((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< bool(*)>(_a[5]))); break;
        case 2: _t->append((*reinterpret_cast< ACCCategory*(*)>(_a[1]))); break;
        case 3: _t->remove((*reinterpret_cast< ACCCategory*(*)>(_a[1]))); break;
        case 4: _t->removeAt((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->clear(); break;
        case 6: { QObject* _r = _t->at((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        case 7: { QObject* _r = _t->get((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QObject**>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ACCCategory* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ACCCategory* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (ACCModel::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&ACCModel::countChanged)) {
                *result = 0;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<ACCModel *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QQmlListProperty<ACCCategory>*>(_v) = _t->categories(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->count(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject ACCModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractListModel::staticMetaObject>(),
    qt_meta_stringdata_ACCModel.data,
    qt_meta_data_ACCModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ACCModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ACCModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ACCModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractListModel::qt_metacast(_clname);
}

int ACCModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractListModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 2;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 2;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void ACCModel::countChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
