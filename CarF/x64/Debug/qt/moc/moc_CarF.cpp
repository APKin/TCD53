/****************************************************************************
** Meta object code from reading C++ file 'CarF.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../CarF.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'CarF.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CarF_t {
    QByteArrayData data[10];
    char stringdata0[134];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CarF_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CarF_t qt_meta_stringdata_CarF = {
    {
QT_MOC_LITERAL(0, 0, 4), // "CarF"
QT_MOC_LITERAL(1, 5, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 12), // "getImagePath"
QT_MOC_LITERAL(4, 41, 16), // "saveStringToFile"
QT_MOC_LITERAL(5, 58, 4), // "text"
QT_MOC_LITERAL(6, 63, 8), // "filename"
QT_MOC_LITERAL(7, 72, 16), // "readFileIfExists"
QT_MOC_LITERAL(8, 89, 25), // "on_btnAutoDisplay_clicked"
QT_MOC_LITERAL(9, 115, 18) // "on_btnStop_clicked"

    },
    "CarF\0on_pushButton_clicked\0\0getImagePath\0"
    "saveStringToFile\0text\0filename\0"
    "readFileIfExists\0on_btnAutoDisplay_clicked\0"
    "on_btnStop_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CarF[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   44,    2, 0x08 /* Private */,
       3,    0,   45,    2, 0x08 /* Private */,
       4,    2,   46,    2, 0x08 /* Private */,
       7,    1,   51,    2, 0x08 /* Private */,
       8,    0,   54,    2, 0x08 /* Private */,
       9,    0,   55,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    5,    6,
    QMetaType::QString, QMetaType::QString,    6,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CarF::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<CarF *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_pushButton_clicked(); break;
        case 1: { QString _r = _t->getImagePath();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 2: _t->saveStringToFile((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 3: { QString _r = _t->readFileIfExists((*reinterpret_cast< const QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 4: _t->on_btnAutoDisplay_clicked(); break;
        case 5: _t->on_btnStop_clicked(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject CarF::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CarF.data,
    qt_meta_data_CarF,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *CarF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CarF::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CarF.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int CarF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
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
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
