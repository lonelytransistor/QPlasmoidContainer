/****************************************************************************
** Meta object code from reading C++ file 'AppletConfigContainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AppletPrivate/AppletConfigContainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppletConfigContainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppletConfigContainer_t {
    QByteArrayData data[15];
    char stringdata0[192];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppletConfigContainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppletConfigContainer_t qt_meta_stringdata_AppletConfigContainer = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AppletConfigContainer"
QT_MOC_LITERAL(1, 22, 13), // "hotkeyChanged"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 13), // "appletChanged"
QT_MOC_LITERAL(4, 51, 15), // "categoryChanged"
QT_MOC_LITERAL(5, 67, 18), // "configModelChanged"
QT_MOC_LITERAL(6, 86, 7), // "restore"
QT_MOC_LITERAL(7, 94, 5), // "apply"
QT_MOC_LITERAL(8, 100, 20), // "appletGlobalShortcut"
QT_MOC_LITERAL(9, 121, 5), // "model"
QT_MOC_LITERAL(10, 127, 9), // "ACCModel*"
QT_MOC_LITERAL(11, 137, 8), // "category"
QT_MOC_LITERAL(12, 146, 12), // "ACCCategory*"
QT_MOC_LITERAL(13, 159, 15), // "appletContainer"
QT_MOC_LITERAL(14, 175, 16) // "AppletContainer*"

    },
    "AppletConfigContainer\0hotkeyChanged\0"
    "\0appletChanged\0categoryChanged\0"
    "configModelChanged\0restore\0apply\0"
    "appletGlobalShortcut\0model\0ACCModel*\0"
    "category\0ACCCategory*\0appletContainer\0"
    "AppletContainer*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppletConfigContainer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       4,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x06 /* Public */,
       3,    0,   45,    2, 0x06 /* Public */,
       4,    0,   46,    2, 0x06 /* Public */,
       5,    0,   47,    2, 0x06 /* Public */,

 // methods: name, argc, parameters, tag, flags
       6,    0,   48,    2, 0x02 /* Public */,
       7,    0,   49,    2, 0x02 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // methods: parameters
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       8, QMetaType::QString, 0x00495003,
       9, 0x80000000 | 10, 0x00495009,
      11, 0x80000000 | 12, 0x0049510b,
      13, 0x80000000 | 14, 0x0049500b,

 // properties: notify_signal_id
       0,
       3,
       2,
       1,

       0        // eod
};

void AppletConfigContainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppletConfigContainer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->hotkeyChanged(); break;
        case 1: _t->appletChanged(); break;
        case 2: _t->categoryChanged(); break;
        case 3: _t->configModelChanged(); break;
        case 4: _t->restore(); break;
        case 5: _t->apply(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppletConfigContainer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletConfigContainer::hotkeyChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppletConfigContainer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletConfigContainer::appletChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppletConfigContainer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletConfigContainer::categoryChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (AppletConfigContainer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletConfigContainer::configModelChanged)) {
                *result = 3;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ACCCategory* >(); break;
        case 1:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< ACCModel* >(); break;
        case 3:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< AppletContainer* >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<AppletConfigContainer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getHotkey(); break;
        case 1: *reinterpret_cast< ACCModel**>(_v) = _t->getConfigModel(); break;
        case 2: *reinterpret_cast< ACCCategory**>(_v) = _t->getCategory(); break;
        case 3: *reinterpret_cast< AppletContainer**>(_v) = _t->getApplet(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<AppletConfigContainer *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setHotkey(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setCategory(*reinterpret_cast< ACCCategory**>(_v)); break;
        case 3: _t->setApplet(*reinterpret_cast< AppletContainer**>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject AppletConfigContainer::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickPaintedItem::staticMetaObject>(),
    qt_meta_stringdata_AppletConfigContainer.data,
    qt_meta_data_AppletConfigContainer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppletConfigContainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppletConfigContainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppletConfigContainer.stringdata0))
        return static_cast<void*>(this);
    return QQuickPaintedItem::qt_metacast(_clname);
}

int AppletConfigContainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickPaintedItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void AppletConfigContainer::hotkeyChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void AppletConfigContainer::appletChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppletConfigContainer::categoryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void AppletConfigContainer::configModelChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
