/****************************************************************************
** Meta object code from reading C++ file 'timetable_add.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/timetable_add.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timetable_add.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 69
#error "This file was generated using the moc from 6.9.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {
struct qt_meta_tag_ZN13Timetable_addE_t {};
} // unnamed namespace

template <> constexpr inline auto Timetable_add::qt_create_metaobjectdata<qt_meta_tag_ZN13Timetable_addE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Timetable_add",
        "on_complete_clicked",
        "",
        "on_name_textChanged",
        "arg1",
        "on_message_textChanged",
        "on_weekday1_currentIndexChanged",
        "index",
        "on_weekday2_currentIndexChanged",
        "on_weekday3_currentIndexChanged",
        "on_weekday4_currentIndexChanged",
        "on_time11_currentIndexChanged",
        "on_time12_currentIndexChanged",
        "on_time21_currentIndexChanged",
        "on_time22_currentIndexChanged",
        "on_time31_currentIndexChanged",
        "on_time32_currentIndexChanged",
        "on_time41_currentIndexChanged",
        "on_time42_currentIndexChanged"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_complete_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_name_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(3, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'on_message_textChanged'
        QtMocHelpers::SlotData<void(const QString &)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::QString, 4 },
        }}),
        // Slot 'on_weekday1_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_weekday2_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(8, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_weekday3_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(9, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_weekday4_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(10, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time11_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(11, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time12_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(12, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time21_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(13, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time22_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(14, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time31_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(15, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time32_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(16, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time41_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(17, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
        // Slot 'on_time42_currentIndexChanged'
        QtMocHelpers::SlotData<void(int)>(18, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 7 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Timetable_add, qt_meta_tag_ZN13Timetable_addE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Timetable_add::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13Timetable_addE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13Timetable_addE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN13Timetable_addE_t>.metaTypes,
    nullptr
} };

void Timetable_add::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Timetable_add *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_complete_clicked(); break;
        case 1: _t->on_name_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->on_message_textChanged((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 3: _t->on_weekday1_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->on_weekday2_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->on_weekday3_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->on_weekday4_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->on_time11_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->on_time12_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->on_time21_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->on_time22_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->on_time31_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->on_time32_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->on_time41_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->on_time42_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *Timetable_add::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Timetable_add::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN13Timetable_addE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Timetable_add::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
