/****************************************************************************
** Meta object code from reading C++ file 'FFmpegThread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../FFmpegThread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FFmpegThread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_FFmpegThread_t {
    QByteArrayData data[12];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_FFmpegThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_FFmpegThread_t qt_meta_stringdata_FFmpegThread = {
    {
QT_MOC_LITERAL(0, 0, 12), // "FFmpegThread"
QT_MOC_LITERAL(1, 13, 12), // "receiveImage"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 5), // "image"
QT_MOC_LITERAL(4, 33, 6), // "setUrl"
QT_MOC_LITERAL(5, 40, 3), // "url"
QT_MOC_LITERAL(6, 44, 4), // "init"
QT_MOC_LITERAL(7, 49, 4), // "free"
QT_MOC_LITERAL(8, 54, 4), // "play"
QT_MOC_LITERAL(9, 59, 5), // "pause"
QT_MOC_LITERAL(10, 65, 4), // "next"
QT_MOC_LITERAL(11, 70, 4) // "stop"

    },
    "FFmpegThread\0receiveImage\0\0image\0"
    "setUrl\0url\0init\0free\0play\0pause\0next\0"
    "stop"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FFmpegThread[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       4,    1,   57,    2, 0x0a /* Public */,
       6,    0,   60,    2, 0x0a /* Public */,
       7,    0,   61,    2, 0x0a /* Public */,
       8,    0,   62,    2, 0x0a /* Public */,
       9,    0,   63,    2, 0x0a /* Public */,
      10,    0,   64,    2, 0x0a /* Public */,
      11,    0,   65,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage,    3,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Bool,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void FFmpegThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FFmpegThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->receiveImage((*reinterpret_cast< const QImage(*)>(_a[1]))); break;
        case 1: _t->setUrl((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: { bool _r = _t->init();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->free(); break;
        case 4: _t->play(); break;
        case 5: _t->pause(); break;
        case 6: _t->next(); break;
        case 7: _t->stop(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FFmpegThread::*)(const QImage & );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FFmpegThread::receiveImage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject FFmpegThread::staticMetaObject = { {
    QMetaObject::SuperData::link<QThread::staticMetaObject>(),
    qt_meta_stringdata_FFmpegThread.data,
    qt_meta_data_FFmpegThread,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *FFmpegThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FFmpegThread::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FFmpegThread.stringdata0))
        return static_cast<void*>(this);
    return QThread::qt_metacast(_clname);
}

int FFmpegThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
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

// SIGNAL 0
void FFmpegThread::receiveImage(const QImage & _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
