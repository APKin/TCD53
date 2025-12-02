/****************************************************************************
** Meta object code from reading C++ file 'DeviceControl.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../DeviceControl.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'DeviceControl.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DeviceControl_t {
    QByteArrayData data[25];
    char stringdata0[460];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DeviceControl_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DeviceControl_t qt_meta_stringdata_DeviceControl = {
    {
QT_MOC_LITERAL(0, 0, 13), // "DeviceControl"
QT_MOC_LITERAL(1, 14, 17), // "laserRadarCommand"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 5), // "comId"
QT_MOC_LITERAL(4, 39, 7), // "command"
QT_MOC_LITERAL(5, 47, 15), // "portInfoChanged"
QT_MOC_LITERAL(6, 63, 9), // "portInfo_"
QT_MOC_LITERAL(7, 73, 4), // "info"
QT_MOC_LITERAL(8, 78, 16), // "on_pbImg_clicked"
QT_MOC_LITERAL(9, 95, 18), // "on_pbCutLR_clicked"
QT_MOC_LITERAL(10, 114, 18), // "on_bpSetIp_clicked"
QT_MOC_LITERAL(11, 133, 18), // "on_pbBWmod_clicked"
QT_MOC_LITERAL(12, 152, 16), // "on_pbAGC_clicked"
QT_MOC_LITERAL(13, 169, 29), // "on_leRDdataPort_returnPressed"
QT_MOC_LITERAL(14, 199, 28), // "on_leRDdevPort_returnPressed"
QT_MOC_LITERAL(15, 228, 24), // "on_leDstIP_returnPressed"
QT_MOC_LITERAL(16, 253, 23), // "on_leRDIP_returnPressed"
QT_MOC_LITERAL(17, 277, 23), // "on_leZBIP_returnPressed"
QT_MOC_LITERAL(18, 301, 32), // "on_cbRDSpeed_currentIndexChanged"
QT_MOC_LITERAL(19, 334, 4), // "arg1"
QT_MOC_LITERAL(20, 339, 31), // "on_cbRDWork_currentIndexChanged"
QT_MOC_LITERAL(21, 371, 5), // "index"
QT_MOC_LITERAL(22, 377, 29), // "on_cbRDZL_currentIndexChanged"
QT_MOC_LITERAL(23, 407, 26), // "on_pbChangePortnfo_clicked"
QT_MOC_LITERAL(24, 434, 25) // "on_pbScanSeriPort_clicked"

    },
    "DeviceControl\0laserRadarCommand\0\0comId\0"
    "command\0portInfoChanged\0portInfo_\0"
    "info\0on_pbImg_clicked\0on_pbCutLR_clicked\0"
    "on_bpSetIp_clicked\0on_pbBWmod_clicked\0"
    "on_pbAGC_clicked\0on_leRDdataPort_returnPressed\0"
    "on_leRDdevPort_returnPressed\0"
    "on_leDstIP_returnPressed\0"
    "on_leRDIP_returnPressed\0on_leZBIP_returnPressed\0"
    "on_cbRDSpeed_currentIndexChanged\0arg1\0"
    "on_cbRDWork_currentIndexChanged\0index\0"
    "on_cbRDZL_currentIndexChanged\0"
    "on_pbChangePortnfo_clicked\0"
    "on_pbScanSeriPort_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DeviceControl[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   99,    2, 0x06 /* Public */,
       5,    1,  104,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,  107,    2, 0x0a /* Public */,
       9,    0,  108,    2, 0x0a /* Public */,
      10,    0,  109,    2, 0x0a /* Public */,
      11,    0,  110,    2, 0x0a /* Public */,
      12,    0,  111,    2, 0x0a /* Public */,
      13,    0,  112,    2, 0x0a /* Public */,
      14,    0,  113,    2, 0x0a /* Public */,
      15,    0,  114,    2, 0x0a /* Public */,
      16,    0,  115,    2, 0x0a /* Public */,
      17,    0,  116,    2, 0x0a /* Public */,
      18,    1,  117,    2, 0x0a /* Public */,
      20,    1,  120,    2, 0x0a /* Public */,
      22,    1,  123,    2, 0x0a /* Public */,
      23,    0,  126,    2, 0x0a /* Public */,
      24,    0,  127,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::QString,    3,    4,
    QMetaType::Void, 0x80000000 | 6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void, QMetaType::Int,   21,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void DeviceControl::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<DeviceControl *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->laserRadarCommand((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->portInfoChanged((*reinterpret_cast< portInfo_(*)>(_a[1]))); break;
        case 2: _t->on_pbImg_clicked(); break;
        case 3: _t->on_pbCutLR_clicked(); break;
        case 4: _t->on_bpSetIp_clicked(); break;
        case 5: _t->on_pbBWmod_clicked(); break;
        case 6: _t->on_pbAGC_clicked(); break;
        case 7: _t->on_leRDdataPort_returnPressed(); break;
        case 8: _t->on_leRDdevPort_returnPressed(); break;
        case 9: _t->on_leDstIP_returnPressed(); break;
        case 10: _t->on_leRDIP_returnPressed(); break;
        case 11: _t->on_leZBIP_returnPressed(); break;
        case 12: _t->on_cbRDSpeed_currentIndexChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->on_cbRDWork_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_cbRDZL_currentIndexChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 15: _t->on_pbChangePortnfo_clicked(); break;
        case 16: _t->on_pbScanSeriPort_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (DeviceControl::*)(int , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceControl::laserRadarCommand)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (DeviceControl::*)(portInfo_ );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&DeviceControl::portInfoChanged)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject DeviceControl::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_DeviceControl.data,
    qt_meta_data_DeviceControl,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *DeviceControl::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeviceControl::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_DeviceControl.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int DeviceControl::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 17)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void DeviceControl::laserRadarCommand(int _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void DeviceControl::portInfoChanged(portInfo_ _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
