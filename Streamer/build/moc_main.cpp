/****************************************************************************
** Meta object code from reading C++ file 'main.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.8)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../main.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'main.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.8. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_QSApplet_t {
    QByteArrayData data[18];
    char stringdata0[151];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_QSApplet_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_QSApplet_t qt_meta_stringdata_QSApplet = {
    {
QT_MOC_LITERAL(0, 0, 8), // "QSApplet"
QT_MOC_LITERAL(1, 9, 12), // "appletCreate"
QT_MOC_LITERAL(2, 22, 0), // ""
QT_MOC_LITERAL(3, 23, 4), // "UUID"
QT_MOC_LITERAL(4, 28, 13), // "appletDestroy"
QT_MOC_LITERAL(5, 42, 4), // "uuid"
QT_MOC_LITERAL(6, 47, 12), // "appletBuffer"
QT_MOC_LITERAL(7, 60, 4), // "size"
QT_MOC_LITERAL(8, 65, 12), // "appletWindow"
QT_MOC_LITERAL(9, 78, 2), // "ix"
QT_MOC_LITERAL(10, 81, 13), // "appletWindows"
QT_MOC_LITERAL(11, 95, 11), // "appletEvent"
QT_MOC_LITERAL(12, 107, 7), // "QEvent*"
QT_MOC_LITERAL(13, 115, 5), // "event"
QT_MOC_LITERAL(14, 121, 12), // "appletUpdate"
QT_MOC_LITERAL(15, 134, 12), // "appletResize"
QT_MOC_LITERAL(16, 147, 1), // "w"
QT_MOC_LITERAL(17, 149, 1) // "h"

    },
    "QSApplet\0appletCreate\0\0UUID\0appletDestroy\0"
    "uuid\0appletBuffer\0size\0appletWindow\0"
    "ix\0appletWindows\0appletEvent\0QEvent*\0"
    "event\0appletUpdate\0appletResize\0w\0h"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_QSApplet[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   54,    2, 0x0a /* Public */,
       4,    1,   59,    2, 0x0a /* Public */,
       6,    2,   62,    2, 0x0a /* Public */,
       8,    2,   67,    2, 0x0a /* Public */,
      10,    1,   72,    2, 0x0a /* Public */,
      11,    2,   75,    2, 0x0a /* Public */,
      14,    1,   80,    2, 0x0a /* Public */,
      15,    3,   83,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::QString,    2,    2,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    5,    7,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int,    5,    9,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 12,    5,   13,
    QMetaType::Void, 0x80000000 | 3,    5,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int,    5,   16,   17,

       0        // eod
};

void QSApplet::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<QSApplet *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->appletCreate((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->appletDestroy((*reinterpret_cast< UUID(*)>(_a[1]))); break;
        case 2: _t->appletBuffer((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->appletWindow((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->appletWindows((*reinterpret_cast< UUID(*)>(_a[1]))); break;
        case 5: _t->appletEvent((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< QEvent*(*)>(_a[2]))); break;
        case 6: _t->appletUpdate((*reinterpret_cast< UUID(*)>(_a[1]))); break;
        case 7: _t->appletResize((*reinterpret_cast< UUID(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject QSApplet::staticMetaObject = { {
    QMetaObject::SuperData::link<QGuiApplication::staticMetaObject>(),
    qt_meta_stringdata_QSApplet.data,
    qt_meta_data_QSApplet,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *QSApplet::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *QSApplet::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_QSApplet.stringdata0))
        return static_cast<void*>(this);
    return QGuiApplication::qt_metacast(_clname);
}

int QSApplet::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGuiApplication::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
