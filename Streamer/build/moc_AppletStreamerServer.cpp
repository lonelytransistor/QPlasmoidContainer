/****************************************************************************
** Meta object code from reading C++ file 'AppletStreamerServer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../AppletStreamerServer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppletStreamerServer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSClient_t {
    QByteArrayData data[3];
    char stringdata0[18];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSClient_t qt_meta_stringdata_QSClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QSClient"
QT_MOC_LITERAL(1, 9, 7), // "timeout"
QT_MOC_LITERAL(2, 17, 0) // ""

    },
    "QSClient\0timeout\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void QSClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->timeout(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSClient::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSClient::timeout)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QSClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_QSClient.data,
    qt_meta_data_QSClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int QSClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void QSClient::timeout()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_QSServer_t {
    QByteArrayData data[9];
    char stringdata0[88];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSServer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSServer_t qt_meta_stringdata_QSServer = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QSServer"
QT_MOC_LITERAL(1, 9, 13), // "appletDestroy"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 4), // "UUID"
QT_MOC_LITERAL(4, 29, 12), // "appletCreate"
QT_MOC_LITERAL(5, 42, 12), // "appletBuffer"
QT_MOC_LITERAL(6, 55, 12), // "appletWindow"
QT_MOC_LITERAL(7, 68, 11), // "appletEvent"
QT_MOC_LITERAL(8, 80, 7) // "QEvent*"

    },
    "QSServer\0appletDestroy\0\0UUID\0appletCreate\0"
    "appletBuffer\0appletWindow\0appletEvent\0"
    "QEvent*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSServer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,
       4,    2,   42,    2, 0x06 /* Public */,
       5,    2,   47,    2, 0x06 /* Public */,
       6,    2,   52,    2, 0x06 /* Public */,
       7,    2,   57,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    2,    2,

       0        // eod
};

void QSServer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSServer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appletDestroy((*reinterpret_cast< UUID(*)>(_a[1]))); break;
        case 1: _t->appletCreate((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->appletBuffer((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->appletWindow((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->appletEvent((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QSServer::*)(UUID );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSServer::appletDestroy)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QSServer::*)(UUID , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSServer::appletCreate)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QSServer::*)(UUID , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSServer::appletBuffer)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (QSServer::*)(UUID , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSServer::appletWindow)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (QSServer::*)(UUID , QEvent * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QSServer::appletEvent)) {
                *result = 4;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSServer::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_QSServer.data,
    qt_meta_data_QSServer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSServer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSServer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSServer.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QSServer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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
    return _id;
}

// SIGNAL 0
void QSServer::appletDestroy(UUID _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QSServer::appletCreate(UUID _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void QSServer::appletBuffer(UUID _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void QSServer::appletWindow(UUID _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void QSServer::appletEvent(UUID _t1, QEvent * _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
