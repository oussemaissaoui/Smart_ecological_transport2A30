/****************************************************************************
** Meta object code from reading C++ file 'crud.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.9)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../crud.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'crud.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.9. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_CRUD_t {
    QByteArrayData data[10];
    char stringdata0[196];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_CRUD_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_CRUD_t qt_meta_stringdata_CRUD = {
    {
QT_MOC_LITERAL(0, 0, 4), // "CRUD"
QT_MOC_LITERAL(1, 5, 22), // "on_ajouter_emp_clicked"
QT_MOC_LITERAL(2, 28, 0), // ""
QT_MOC_LITERAL(3, 29, 26), // "on_pushButton_supp_clicked"
QT_MOC_LITERAL(4, 56, 30), // "on_pushButton_modifier_clicked"
QT_MOC_LITERAL(5, 87, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(6, 109, 23), // "on_pushButton_2_clicked"
QT_MOC_LITERAL(7, 133, 17), // "on_ask_ai_clicked"
QT_MOC_LITERAL(8, 151, 15), // "on_stat_clicked"
QT_MOC_LITERAL(9, 167, 28) // "on_pushButton_genpdf_clicked"

    },
    "CRUD\0on_ajouter_emp_clicked\0\0"
    "on_pushButton_supp_clicked\0"
    "on_pushButton_modifier_clicked\0"
    "on_pushButton_clicked\0on_pushButton_2_clicked\0"
    "on_ask_ai_clicked\0on_stat_clicked\0"
    "on_pushButton_genpdf_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_CRUD[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   54,    2, 0x08 /* Private */,
       3,    0,   55,    2, 0x08 /* Private */,
       4,    0,   56,    2, 0x08 /* Private */,
       5,    0,   57,    2, 0x08 /* Private */,
       6,    0,   58,    2, 0x08 /* Private */,
       7,    0,   59,    2, 0x08 /* Private */,
       8,    0,   60,    2, 0x08 /* Private */,
       9,    0,   61,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void CRUD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        CRUD *_t = static_cast<CRUD *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_ajouter_emp_clicked(); break;
        case 1: _t->on_pushButton_supp_clicked(); break;
        case 2: _t->on_pushButton_modifier_clicked(); break;
        case 3: _t->on_pushButton_clicked(); break;
        case 4: _t->on_pushButton_2_clicked(); break;
        case 5: _t->on_ask_ai_clicked(); break;
        case 6: _t->on_stat_clicked(); break;
        case 7: _t->on_pushButton_genpdf_clicked(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject CRUD::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_CRUD.data,
      qt_meta_data_CRUD,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *CRUD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *CRUD::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CRUD.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int CRUD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
