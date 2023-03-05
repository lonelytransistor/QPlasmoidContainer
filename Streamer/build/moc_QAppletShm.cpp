/****************************************************************************
** Meta object code from reading C++ file 'QAppletShm.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../AppletPrivate/QAppletShm.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'QAppletShm.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QAppletShmPrivate_t {
    QByteArrayData data[9];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAppletShmPrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAppletShmPrivate_t qt_meta_stringdata_QAppletShmPrivate = {
    {
QT_MOC_LITERAL(0, 0, 17), // "QAppletShmPrivate"
QT_MOC_LITERAL(1, 18, 14), // "resizeReceived"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 5), // "width"
QT_MOC_LITERAL(4, 40, 6), // "height"
QT_MOC_LITERAL(5, 47, 12), // "const uchar*"
QT_MOC_LITERAL(6, 60, 11), // "pixelBuffer"
QT_MOC_LITERAL(7, 72, 14), // "updateReceived"
QT_MOC_LITERAL(8, 87, 13) // "clearReceived"

    },
    "QAppletShmPrivate\0resizeReceived\0\0"
    "width\0height\0const uchar*\0pixelBuffer\0"
    "updateReceived\0clearReceived"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAppletShmPrivate[] = {

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

void QAppletShmPrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QAppletShmPrivate *>(_o);
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
            using _t = void (QAppletShmPrivate::*)(int , int , const uchar * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShmPrivate::resizeReceived)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QAppletShmPrivate::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShmPrivate::updateReceived)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QAppletShmPrivate::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShmPrivate::clearReceived)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QAppletShmPrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_QAppletShmPrivate.data,
    qt_meta_data_QAppletShmPrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QAppletShmPrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAppletShmPrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QAppletShmPrivate.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int QAppletShmPrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void QAppletShmPrivate::resizeReceived(int _t1, int _t2, const uchar * _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QAppletShmPrivate::updateReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QAppletShmPrivate::clearReceived()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
struct qt_meta_stringdata_QAppletShmTexturePrivate_t {
    QByteArrayData data[1];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAppletShmTexturePrivate_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAppletShmTexturePrivate_t qt_meta_stringdata_QAppletShmTexturePrivate = {
    {
QT_MOC_LITERAL(0, 0, 24) // "QAppletShmTexturePrivate"

    },
    "QAppletShmTexturePrivate"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAppletShmTexturePrivate[] = {

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

void QAppletShmTexturePrivate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject QAppletShmTexturePrivate::staticMetaObject = { {
    QMetaObject::SuperData::link<QSGDynamicTexture::staticMetaObject>(),
    qt_meta_stringdata_QAppletShmTexturePrivate.data,
    qt_meta_data_QAppletShmTexturePrivate,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QAppletShmTexturePrivate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAppletShmTexturePrivate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QAppletShmTexturePrivate.stringdata0))
        return static_cast<void*>(this);
    return QSGDynamicTexture::qt_metacast(_clname);
}

int QAppletShmTexturePrivate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QSGDynamicTexture::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_QAppletShm_t {
    QByteArrayData data[14];
    char stringdata0[147];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QAppletShm_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QAppletShm_t qt_meta_stringdata_QAppletShm = {
    {
QT_MOC_LITERAL(0, 0, 10), // "QAppletShm"
QT_MOC_LITERAL(1, 11, 15), // "windowIdChanged"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 11), // "uuidChanged"
QT_MOC_LITERAL(4, 40, 12), // "validChanged"
QT_MOC_LITERAL(5, 53, 14), // "resizeReceived"
QT_MOC_LITERAL(6, 68, 7), // "p_width"
QT_MOC_LITERAL(7, 76, 8), // "p_height"
QT_MOC_LITERAL(8, 85, 12), // "const uchar*"
QT_MOC_LITERAL(9, 98, 13), // "p_pixelBuffer"
QT_MOC_LITERAL(10, 112, 14), // "updateReceived"
QT_MOC_LITERAL(11, 127, 4), // "uuid"
QT_MOC_LITERAL(12, 132, 8), // "windowId"
QT_MOC_LITERAL(13, 141, 5) // "valid"

    },
    "QAppletShm\0windowIdChanged\0\0uuidChanged\0"
    "validChanged\0resizeReceived\0p_width\0"
    "p_height\0const uchar*\0p_pixelBuffer\0"
    "updateReceived\0uuid\0windowId\0valid"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QAppletShm[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       3,   50, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x06 /* Public */,
       3,    0,   40,    2, 0x06 /* Public */,
       4,    0,   41,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   42,    2, 0x0a /* Public */,
      10,    0,   49,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int, 0x80000000 | 8,    6,    7,    9,
    QMetaType::Void,

 // properties: name, type, flags
      11, QMetaType::QString, 0x00495103,
      12, QMetaType::Int, 0x00495103,
      13, QMetaType::Bool, 0x00495001,

 // properties: notify_signal_id
       1,
       0,
       2,

       0        // eod
};

void QAppletShm::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QAppletShm *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->windowIdChanged(); break;
        case 1: _t->uuidChanged(); break;
        case 2: _t->validChanged(); break;
        case 3: _t->resizeReceived((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const uchar*(*)>(_a[3]))); break;
        case 4: _t->updateReceived(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (QAppletShm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShm::windowIdChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (QAppletShm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShm::uuidChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (QAppletShm::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&QAppletShm::validChanged)) {
                *result = 2;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<QAppletShm *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->getUuid(); break;
        case 1: *reinterpret_cast< int*>(_v) = _t->getWindowId(); break;
        case 2: *reinterpret_cast< bool*>(_v) = _t->getValid(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<QAppletShm *>(_o);
        (void)_t;
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setUuid(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setWindowId(*reinterpret_cast< int*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject QAppletShm::staticMetaObject = { {
    QMetaObject::SuperData::link<QQuickItem::staticMetaObject>(),
    qt_meta_stringdata_QAppletShm.data,
    qt_meta_data_QAppletShm,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QAppletShm::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QAppletShm::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QAppletShm.stringdata0))
        return static_cast<void*>(this);
    return QQuickItem::qt_metacast(_clname);
}

int QAppletShm::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QQuickItem::qt_metacall(_c, _id, _a);
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
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 3;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 3;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void QAppletShm::windowIdChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void QAppletShm::uuidChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void QAppletShm::validChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
