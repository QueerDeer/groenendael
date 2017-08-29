/****************************************************************************
** Meta object code from reading C++ file 'handlersignals.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "handlersignals.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'handlersignals.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_HandlerSignals_t {
    QByteArrayData data[12];
    char stringdata0[101];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_HandlerSignals_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_HandlerSignals_t qt_meta_stringdata_HandlerSignals = {
    {
QT_MOC_LITERAL(0, 0, 14), // "HandlerSignals"
QT_MOC_LITERAL(1, 15, 11), // "changeField"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 3), // "msg"
QT_MOC_LITERAL(4, 32, 3), // "pos"
QT_MOC_LITERAL(5, 36, 10), // "generation"
QT_MOC_LITERAL(6, 47, 6), // "engine"
QT_MOC_LITERAL(7, 54, 13), // "createSoldier"
QT_MOC_LITERAL(8, 68, 15), // "changeAnimation"
QT_MOC_LITERAL(9, 84, 4), // "name"
QT_MOC_LITERAL(10, 89, 4), // "anim"
QT_MOC_LITERAL(11, 94, 6) // "idshka"

    },
    "HandlerSignals\0changeField\0\0msg\0pos\0"
    "generation\0engine\0createSoldier\0"
    "changeAnimation\0name\0anim\0idshka"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_HandlerSignals[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x0a /* Public */,
       5,    0,   44,    2, 0x0a /* Public */,
       6,    0,   45,    2, 0x0a /* Public */,
       7,    1,   46,    2, 0x0a /* Public */,
       8,    4,   49,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    4,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,    9,   10,    4,   11,

       0        // eod
};

void HandlerSignals::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        HandlerSignals *_t = static_cast<HandlerSignals *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->changeField((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->generation(); break;
        case 2: _t->engine(); break;
        case 3: _t->createSoldier((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 4: _t->changeAnimation((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject HandlerSignals::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_HandlerSignals.data,
      qt_meta_data_HandlerSignals,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *HandlerSignals::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *HandlerSignals::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_HandlerSignals.stringdata0))
        return static_cast<void*>(const_cast< HandlerSignals*>(this));
    return QObject::qt_metacast(_clname);
}

int HandlerSignals::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
