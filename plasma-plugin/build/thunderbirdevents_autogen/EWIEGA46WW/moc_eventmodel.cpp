/****************************************************************************
** Meta object code from reading C++ file 'eventmodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../thunderbirdeventsplugin/eventmodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'eventmodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_EventModel_t {
    QByteArrayData data[9];
    char stringdata0[105];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_EventModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_EventModel_t qt_meta_stringdata_EventModel = {
    {
QT_MOC_LITERAL(0, 0, 10), // "EventModel"
QT_MOC_LITERAL(1, 11, 11), // "addCalendar"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 19), // "Akonadi::Collection"
QT_MOC_LITERAL(4, 44, 3), // "col"
QT_MOC_LITERAL(5, 48, 14), // "removeCalendar"
QT_MOC_LITERAL(6, 63, 15), // "onItemsReceived"
QT_MOC_LITERAL(7, 79, 19), // "Akonadi::Item::List"
QT_MOC_LITERAL(8, 99, 5) // "items"

    },
    "EventModel\0addCalendar\0\0Akonadi::Collection\0"
    "col\0removeCalendar\0onItemsReceived\0"
    "Akonadi::Item::List\0items"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_EventModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x0a /* Public */,
       5,    1,   32,    2, 0x0a /* Public */,
       6,    1,   35,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    8,

       0        // eod
};

void EventModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<EventModel *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addCalendar((*reinterpret_cast< const Akonadi::Collection(*)>(_a[1]))); break;
        case 1: _t->removeCalendar((*reinterpret_cast< const Akonadi::Collection(*)>(_a[1]))); break;
        case 2: _t->onItemsReceived((*reinterpret_cast< const Akonadi::Item::List(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Akonadi::Collection >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Akonadi::Collection >(); break;
            }
            break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Akonadi::Item::List >(); break;
            }
            break;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject EventModel::staticMetaObject = { {
    QMetaObject::SuperData::link<Akonadi::CalendarBase::staticMetaObject>(),
    qt_meta_stringdata_EventModel.data,
    qt_meta_data_EventModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *EventModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *EventModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_EventModel.stringdata0))
        return static_cast<void*>(this);
    return Akonadi::CalendarBase::qt_metacast(_clname);
}

int EventModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = Akonadi::CalendarBase::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
