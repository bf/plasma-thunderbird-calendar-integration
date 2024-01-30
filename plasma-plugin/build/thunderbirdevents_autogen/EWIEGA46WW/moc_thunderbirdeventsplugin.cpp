/****************************************************************************
** Meta object code from reading C++ file 'thunderbirdeventsplugin.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.12)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../thunderbirdeventsplugin/thunderbirdeventsplugin.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/qplugin.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'thunderbirdeventsplugin.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.12. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_ThunderbirdEventsPlugin_t {
    QByteArrayData data[1];
    char stringdata0[24];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_ThunderbirdEventsPlugin_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_ThunderbirdEventsPlugin_t qt_meta_stringdata_ThunderbirdEventsPlugin = {
    {
QT_MOC_LITERAL(0, 0, 23) // "ThunderbirdEventsPlugin"

    },
    "ThunderbirdEventsPlugin"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_ThunderbirdEventsPlugin[] = {

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

void ThunderbirdEventsPlugin::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject ThunderbirdEventsPlugin::staticMetaObject = { {
    QMetaObject::SuperData::link<CalendarEvents::CalendarEventsPlugin::staticMetaObject>(),
    qt_meta_stringdata_ThunderbirdEventsPlugin.data,
    qt_meta_data_ThunderbirdEventsPlugin,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *ThunderbirdEventsPlugin::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ThunderbirdEventsPlugin::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_ThunderbirdEventsPlugin.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "KCalendarCore::Calendar::CalendarObserver"))
        return static_cast< KCalendarCore::Calendar::CalendarObserver*>(this);
    if (!strcmp(_clname, "org.kde.CalendarEventsPlugin"))
        return static_cast< CalendarEvents::CalendarEventsPlugin*>(this);
    return CalendarEvents::CalendarEventsPlugin::qt_metacast(_clname);
}

int ThunderbirdEventsPlugin::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = CalendarEvents::CalendarEventsPlugin::qt_metacall(_c, _id, _a);
    return _id;
}

QT_PLUGIN_METADATA_SECTION
static constexpr unsigned char qt_pluginMetaData[] = {
    'Q', 'T', 'M', 'E', 'T', 'A', 'D', 'A', 'T', 'A', ' ', '!',
    // metadata version, Qt version, architectural requirements
    0, QT_VERSION_MAJOR, QT_VERSION_MINOR, qPluginArchRequirements(),
    0xbf, 
    // "IID"
    0x02,  0x78,  0x1c,  'o',  'r',  'g',  '.',  'k', 
    'd',  'e',  '.',  'C',  'a',  'l',  'e',  'n', 
    'd',  'a',  'r',  'E',  'v',  'e',  'n',  't', 
    's',  'P',  'l',  'u',  'g',  'i',  'n', 
    // "className"
    0x03,  0x77,  'T',  'h',  'u',  'n',  'd',  'e', 
    'r',  'b',  'i',  'r',  'd',  'E',  'v',  'e', 
    'n',  't',  's',  'P',  'l',  'u',  'g',  'i', 
    'n', 
    // "MetaData"
    0x04,  0xa2,  0x67,  'K',  'P',  'l',  'u',  'g', 
    'i',  'n',  0xa6,  0x67,  'A',  'u',  't',  'h', 
    'o',  'r',  's',  0x81,  0xa2,  0x65,  'E',  'm', 
    'a',  'i',  'l',  0x78,  0x19,  'b',  'e',  'n', 
    'j',  'a',  'm',  'i',  'n',  'f',  'l',  'e', 
    's',  'c',  'h',  '@',  'i',  'c',  'l',  'o', 
    'u',  'd',  '.',  'c',  'o',  'm',  0x64,  'N', 
    'a',  'm',  'e',  0x6f,  'B',  'e',  'n',  'j', 
    'a',  'm',  'i',  'n',  ' ',  'F',  'l',  'e', 
    's',  'c',  'h',  0x6b,  'D',  'e',  's',  'c', 
    'r',  'i',  'p',  't',  'i',  'o',  'n',  0x78, 
    0x36,  'C',  'a',  'l',  'e',  'n',  'd',  'a', 
    'r',  ' ',  'p',  'l',  'u',  'g',  'i',  'n', 
    ' ',  'f',  'o',  'r',  ' ',  'd',  'i',  's', 
    'p',  'l',  'a',  'y',  'i',  'n',  'g',  ' ', 
    'e',  'v',  'e',  'n',  't',  's',  ' ',  'f', 
    'r',  'o',  'm',  ' ',  't',  'h',  'u',  'n', 
    'd',  'e',  'r',  'b',  'i',  'r',  'd',  0x64, 
    'I',  'c',  'o',  'n',  0x6d,  'v',  'i',  'e', 
    'w',  '-',  'c',  'a',  'l',  'e',  'n',  'd', 
    'a',  'r',  0x64,  'N',  'a',  'm',  'e',  0x78, 
    0x19,  'T',  'h',  'u',  'n',  'd',  'e',  'r', 
    'b',  'i',  'r',  'd',  ' ',  'E',  'v',  'e', 
    'n',  't',  's',  ' ',  'P',  'l',  'u',  'g', 
    'i',  'n',  0x6c,  'S',  'e',  'r',  'v',  'i', 
    'c',  'e',  'T',  'y',  'p',  'e',  's',  0x81, 
    0x75,  'P',  'l',  'a',  's',  'm',  'a',  'C', 
    'a',  'l',  'e',  'n',  'd',  'a',  'r',  '/', 
    'P',  'l',  'u',  'g',  'i',  'n',  0x67,  'V', 
    'e',  'r',  's',  'i',  'o',  'n',  0x63,  '1', 
    '.',  '0',  0x78,  0x1d,  'X',  '-',  'K',  'D', 
    'E',  '-',  'P',  'l',  'a',  's',  'm',  'a', 
    'C',  'a',  'l',  'e',  'n',  'd',  'a',  'r', 
    '-',  'C',  'o',  'n',  'f',  'i',  'g',  'U', 
    'i',  0x78,  0x2d,  't',  'h',  'u',  'n',  'd', 
    'e',  'r',  'b',  'i',  'r',  'd',  'e',  'v', 
    'e',  'n',  't',  's',  '/',  'T',  'h',  'u', 
    'n',  'd',  'e',  'r',  'b',  'i',  'r',  'd', 
    'E',  'v',  'e',  'n',  't',  's',  'C',  'o', 
    'n',  'f',  'i',  'g',  '.',  'q',  'm',  'l', 
    0xff, 
};
QT_MOC_EXPORT_PLUGIN(ThunderbirdEventsPlugin, ThunderbirdEventsPlugin)

QT_WARNING_POP
QT_END_MOC_NAMESPACE
