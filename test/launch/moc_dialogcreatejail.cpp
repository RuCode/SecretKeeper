/****************************************************************************
** Meta object code from reading C++ file 'dialogcreatejail.h'
**
** Created: Sun Oct 19 20:28:21 2014
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "dialogcreatejail.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'dialogcreatejail.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_DialogCreateJail[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      18,   17,   17,   17, 0x08,
      46,   17,   17,   17, 0x08,
      75,   17,   17,   17, 0x08,
     106,   17,   17,   17, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_DialogCreateJail[] = {
    "DialogCreateJail\0\0on_pushButton_Gen_clicked()\0"
    "on_pushButton_hide_clicked()\0"
    "on_pushButton_Cancel_clicked()\0"
    "on_pushButton_Save_clicked()\0"
};

void DialogCreateJail::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        DialogCreateJail *_t = static_cast<DialogCreateJail *>(_o);
        switch (_id) {
        case 0: _t->on_pushButton_Gen_clicked(); break;
        case 1: _t->on_pushButton_hide_clicked(); break;
        case 2: _t->on_pushButton_Cancel_clicked(); break;
        case 3: _t->on_pushButton_Save_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData DialogCreateJail::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject DialogCreateJail::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DialogCreateJail,
      qt_meta_data_DialogCreateJail, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &DialogCreateJail::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *DialogCreateJail::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *DialogCreateJail::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_DialogCreateJail))
        return static_cast<void*>(const_cast< DialogCreateJail*>(this));
    return QDialog::qt_metacast(_clname);
}

int DialogCreateJail::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
