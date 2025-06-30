/****************************************************************************
** Meta object code from reading C++ file 'clotheschanging.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/clotheschanging.h"
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'clotheschanging.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15ClothesChangingE_t {};
} // unnamed namespace

template <> constexpr inline auto ClothesChanging::qt_create_metaobjectdata<qt_meta_tag_ZN15ClothesChangingE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "ClothesChanging",
        "skinChanged",
        "",
        "choice",
        "on_complete_clicked",
        "on_suit1_clicked",
        "on_suit2_clicked",
        "on_suit3_clicked",
        "on_suit4_clicked"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'skinChanged'
        QtMocHelpers::SignalData<void(int)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::Int, 3 },
        }}),
        // Slot 'on_complete_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_suit1_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_suit2_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_suit3_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_suit4_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<ClothesChanging, qt_meta_tag_ZN15ClothesChangingE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject ClothesChanging::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ClothesChangingE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ClothesChangingE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15ClothesChangingE_t>.metaTypes,
    nullptr
} };

void ClothesChanging::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<ClothesChanging *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->skinChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->on_complete_clicked(); break;
        case 2: _t->on_suit1_clicked(); break;
        case 3: _t->on_suit2_clicked(); break;
        case 4: _t->on_suit3_clicked(); break;
        case 5: _t->on_suit4_clicked(); break;
        default: ;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (ClothesChanging::*)(int )>(_a, &ClothesChanging::skinChanged, 0))
            return;
    }
}

const QMetaObject *ClothesChanging::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *ClothesChanging::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15ClothesChangingE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int ClothesChanging::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void ClothesChanging::skinChanged(int _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}
QT_WARNING_POP
