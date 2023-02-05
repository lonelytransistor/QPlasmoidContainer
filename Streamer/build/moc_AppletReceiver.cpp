/****************************************************************************
** Meta object code from reading C++ file 'AppletReceiver.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AppletPrivate/AppletReceiver.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'AppletReceiver.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AppletReceiverPrivate_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppletReceiverPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppletReceiverPrivate_t qt_meta_stringdata_AppletReceiverPrivate = {
    {
QT_MOC_LITERAL(0, 0, 21), // "AppletReceiverPrivate"
QT_MOC_LITERAL(1, 22, 14), // "resizeReceived"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 5), // "width"
QT_MOC_LITERAL(4, 44, 6), // "height"
QT_MOC_LITERAL(5, 51, 12), // "const uchar*"
QT_MOC_LITERAL(6, 64, 11), // "pixelBuffer"
QT_MOC_LITERAL(7, 76, 14), // "updateReceived"
QT_MOC_LITERAL(8, 91, 13) // "clearReceived"

    },
    "AppletReceiverPrivate\0resizeReceived\0"
    "\0width\0height\0const uchar*\0pixelBuffer\0"
    "updateReceived\0clearReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppletReceiverPrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    3,   29,    2, 0x06 /* Public */,
       7,    0,   36,    2, 0x06 /* Public */,
       8,    0,   37,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void AppletReceiverPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppletReceiverPrivate *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uchar*(*)>(_a[3]))); break;
        case 1: _t->updateReceived(); break;
        case 2: _t->clearReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (AppletReceiverPrivate::*)(int , int , const uchar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletReceiverPrivate::resizeReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (AppletReceiverPrivate::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletReceiverPrivate::updateReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (AppletReceiverPrivate::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AppletReceiverPrivate::clearReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppletReceiverPrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_AppletReceiverPrivate.data,
    qt_meta_data_AppletReceiverPrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppletReceiverPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppletReceiverPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppletReceiverPrivate.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int AppletReceiverPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void AppletReceiverPrivate::resizeReceived(int _t1, int _t2, const uchar * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AppletReceiverPrivate::updateReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void AppletReceiverPrivate::clearReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_AppletReceiverTexturePrivate_t {
    QByteArrayData data[1];
    char stringdata0[29];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppletReceiverTexturePrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppletReceiverTexturePrivate_t qt_meta_stringdata_AppletReceiverTexturePrivate = {
    {
QT_MOC_LITERAL(0, 0, 28) // "AppletReceiverTexturePrivate"

    },
    "AppletReceiverTexturePrivate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppletReceiverTexturePrivate[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       0,    0, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

       0        // eod
};

void AppletReceiverTexturePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject AppletReceiverTexturePrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QSGDynamicTexture::staticMetaObject>(),
    qt_meta_stringdata_AppletReceiverTexturePrivate.data,
    qt_meta_data_AppletReceiverTexturePrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppletReceiverTexturePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppletReceiverTexturePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppletReceiverTexturePrivate.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "QOpenGLFunctions_2_1"))
        return static_cast< QOpenGLFunctions_2_1*>(this);
    return QSGDynamicTexture::qt_metacast(_clname);
}

int AppletReceiverTexturePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSGDynamicTexture::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_AppletReceiver_t {
    QByteArrayData data[8];
    char stringdata0[90];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AppletReceiver_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AppletReceiver_t qt_meta_stringdata_AppletReceiver = {
    {
QT_MOC_LITERAL(0, 0, 14), // "AppletReceiver"
QT_MOC_LITERAL(1, 15, 14), // "resizeReceived"
QT_MOC_LITERAL(2, 30, 0), // ""
QT_MOC_LITERAL(3, 31, 7), // "p_width"
QT_MOC_LITERAL(4, 39, 8), // "p_height"
QT_MOC_LITERAL(5, 48, 12), // "const uchar*"
QT_MOC_LITERAL(6, 61, 13), // "p_pixelBuffer"
QT_MOC_LITERAL(7, 75, 14) // "updateReceived"

    },
    "AppletReceiver\0resizeReceived\0\0p_width\0"
    "p_height\0const uchar*\0p_pixelBuffer\0"
    "updateReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AppletReceiver[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   24,    2, 0x0a /* Public */,
       7,    0,   31,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 5,    3,    4,    6,
    QMetaType::Void,

       0        // eod
};

void AppletReceiver::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<AppletReceiver *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->resizeReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uchar*(*)>(_a[3]))); break;
        case 1: _t->updateReceived(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject AppletReceiver::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_AppletReceiver.data,
    qt_meta_data_AppletReceiver,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *AppletReceiver::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AppletReceiver::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AppletReceiver.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int AppletReceiver::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
