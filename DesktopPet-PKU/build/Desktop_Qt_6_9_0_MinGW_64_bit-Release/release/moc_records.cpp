/****************************************************************************
** Meta object code from reading C++ file 'records.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/records.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'records.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN7recordsE_t {};
} // unnamed namespace

template <> constexpr inline auto records::qt_create_metaobjectdata<qt_meta_tag_ZN7recordsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "records",
        "on_runButton_clicked",
        "",
        "on_badmintonBtn_clicked",
        "on_pingpongBtn_clicked",
        "on_tennisBtn_clicked",
        "on_basketballBtn_clicked",
        "on_volleyballBtn_clicked",
        "on_footballBtn_clicked",
        "on_ridingBtn_clicked",
        "on_climbingBtn_clicked",
        "on_swimmingBtn_clicked",
        "calculateRunningCalories",
        "calculateBadmintonCalories",
        "calculatePingpongCalories",
        "calculateTennisCalories",
        "calculateBasketballCalories",
        "calculateVolleyballCalories",
        "calculateFootballCalories",
        "calculateRidingCalories",
        "calculateClimbingCalories",
        "calculateSwimmingCalories"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_runButton_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_badmintonBtn_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_pingpongBtn_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_tennisBtn_clicked'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_basketballBtn_clicked'
        QtMocHelpers::SlotData<void()>(6, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_volleyballBtn_clicked'
        QtMocHelpers::SlotData<void()>(7, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_footballBtn_clicked'
        QtMocHelpers::SlotData<void()>(8, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_ridingBtn_clicked'
        QtMocHelpers::SlotData<void()>(9, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_climbingBtn_clicked'
        QtMocHelpers::SlotData<void()>(10, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_swimmingBtn_clicked'
        QtMocHelpers::SlotData<void()>(11, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateRunningCalories'
        QtMocHelpers::SlotData<void()>(12, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateBadmintonCalories'
        QtMocHelpers::SlotData<void()>(13, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculatePingpongCalories'
        QtMocHelpers::SlotData<void()>(14, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateTennisCalories'
        QtMocHelpers::SlotData<void()>(15, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateBasketballCalories'
        QtMocHelpers::SlotData<void()>(16, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateVolleyballCalories'
        QtMocHelpers::SlotData<void()>(17, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateFootballCalories'
        QtMocHelpers::SlotData<void()>(18, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateRidingCalories'
        QtMocHelpers::SlotData<void()>(19, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateClimbingCalories'
        QtMocHelpers::SlotData<void()>(20, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'calculateSwimmingCalories'
        QtMocHelpers::SlotData<void()>(21, 2, QMC::AccessPrivate, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<records, qt_meta_tag_ZN7recordsE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject records::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7recordsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7recordsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN7recordsE_t>.metaTypes,
    nullptr
} };

void records::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<records *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_runButton_clicked(); break;
        case 1: _t->on_badmintonBtn_clicked(); break;
        case 2: _t->on_pingpongBtn_clicked(); break;
        case 3: _t->on_tennisBtn_clicked(); break;
        case 4: _t->on_basketballBtn_clicked(); break;
        case 5: _t->on_volleyballBtn_clicked(); break;
        case 6: _t->on_footballBtn_clicked(); break;
        case 7: _t->on_ridingBtn_clicked(); break;
        case 8: _t->on_climbingBtn_clicked(); break;
        case 9: _t->on_swimmingBtn_clicked(); break;
        case 10: _t->calculateRunningCalories(); break;
        case 11: _t->calculateBadmintonCalories(); break;
        case 12: _t->calculatePingpongCalories(); break;
        case 13: _t->calculateTennisCalories(); break;
        case 14: _t->calculateBasketballCalories(); break;
        case 15: _t->calculateVolleyballCalories(); break;
        case 16: _t->calculateFootballCalories(); break;
        case 17: _t->calculateRidingCalories(); break;
        case 18: _t->calculateClimbingCalories(); break;
        case 19: _t->calculateSwimmingCalories(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *records::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *records::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN7recordsE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int records::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 20)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 20;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 20)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 20;
    }
    return _id;
}
QT_WARNING_POP
