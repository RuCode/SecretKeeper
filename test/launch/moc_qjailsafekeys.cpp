/****************************************************************************
** Meta object code from reading C++ file 'qjailsafekeys.h'
**
** Created: Sun Oct 12 20:32:02 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "qjailsafekeys.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'qjailsafekeys.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_QJailSafeKeys[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      37,   15,   14,   14, 0x05,
     105,   63,   14,   14, 0x05,

 // slots: signature, parameters, type, tag, flags
     144,   15,   14,   14, 0x0a,
     171,   63,   14,   14, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_QJailSafeKeys[] = {
    "QJailSafeKeys\0\0RootIndex,Description\0"
    "ReadRootItem(int,QString)\0"
    "RootIndex,ChildIndex,Password,Description\0"
    "ReadChildItem(int,int,QString,QString)\0"
    "WriteRootItem(int,QString)\0"
    "WriteChildItem(int,int,QString,QString)\0"
};

void QJailSafeKeys::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        QJailSafeKeys *_t = static_cast<QJailSafeKeys *>(_o);
        switch (_id) {
        case 0: _t->ReadRootItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->ReadChildItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        case 2: _t->WriteRootItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->WriteChildItem((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3])),(*reinterpret_cast< QString(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData QJailSafeKeys::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject QJailSafeKeys::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_QJailSafeKeys,
      qt_meta_data_QJailSafeKeys, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &QJailSafeKeys::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *QJailSafeKeys::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *QJailSafeKeys::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_QJailSafeKeys))
        return static_cast<void*>(const_cast< QJailSafeKeys*>(this));
    return QObject::qt_metacast(_clname);
}

int QJailSafeKeys::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void QJailSafeKeys::ReadRootItem(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void QJailSafeKeys::ReadChildItem(int _t1, int _t2, QString _t3, QString _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE