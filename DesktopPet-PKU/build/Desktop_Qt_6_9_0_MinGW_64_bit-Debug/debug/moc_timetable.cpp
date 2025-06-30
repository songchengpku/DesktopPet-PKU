/****************************************************************************
** Meta object code from reading C++ file 'timetable.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/timetable.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'timetable.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN16TextEditDelegateE_t {};
} // unnamed namespace

template <> constexpr inline auto TextEditDelegate::qt_create_metaobjectdata<qt_meta_tag_ZN16TextEditDelegateE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "TextEditDelegate"
    };

    QtMocHelpers::UintData qt_methods {
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<TextEditDelegate, qt_meta_tag_ZN16TextEditDelegateE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject TextEditDelegate::staticMetaObject = { {
    QMetaObject::SuperData::link<QStyledItemDelegate::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TextEditDelegateE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TextEditDelegateE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN16TextEditDelegateE_t>.metaTypes,
    nullptr
} };

void TextEditDelegate::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<TextEditDelegate *>(_o);
    (void)_t;
    (void)_c;
    (void)_id;
    (void)_a;
}

const QMetaObject *TextEditDelegate::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TextEditDelegate::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN16TextEditDelegateE_t>.strings))
        return static_cast<void*>(this);
    return QStyledItemDelegate::qt_metacast(_clname);
}

int TextEditDelegate::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QStyledItemDelegate::qt_metacall(_c, _id, _a);
    return _id;
}
namespace {
struct qt_meta_tag_ZN9TimetableE_t {};
} // unnamed namespace

template <> constexpr inline auto Timetable::qt_create_metaobjectdata<qt_meta_tag_ZN9TimetableE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Timetable",
        "on_add_clicked",
        "",
        "on_dlt_clicked",
        "on_save_clicked",
        "on_tableWidget_cellChanged",
        "row",
        "column",
        "on_close_clicked",
        "on_clear_clicked",
        "resizeTableToViewport"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_add_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_dlt_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_save_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tableWidget_cellChanged'
        QtMocHelpers::SlotData<void(int, int)>(5, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { QMetaType::Int, 6 }, { QMetaType::Int, 7 },
        }}),
        // Slot 'on_close_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_clear_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'resizeTableToViewport'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Timetable, qt_meta_tag_ZN9TimetableE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Timetable::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TimetableE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TimetableE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN9TimetableE_t>.metaTypes,
    nullptr
} };

void Timetable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Timetable *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_add_clicked(); break;
        case 1: _t->on_dlt_clicked(); break;
        case 2: _t->on_save_clicked(); break;
        case 3: _t->on_tableWidget_cellChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        case 4: _t->on_close_clicked(); break;
        case 5: _t->on_clear_clicked(); break;
        case 6: _t->resizeTableToViewport(); break;
        default: ;
        }
    }
}

const QMetaObject *Timetable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Timetable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN9TimetableE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Timetable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 7;
    }
    return _id;
}
QT_WARNING_POP
