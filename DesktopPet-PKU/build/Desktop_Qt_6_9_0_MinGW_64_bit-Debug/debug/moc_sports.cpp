/****************************************************************************
** Meta object code from reading C++ file 'sports.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../frontend/sports.h"
#include <QtGui/qtextcursor.h>
#include <QtNetwork/QSslPreSharedKeyAuthenticator>
#include <QtNetwork/QSslError>
#include <QtGui/qscreen.h>
#include <QtCharts/qlineseries.h>
#include <QtCharts/qabstractbarseries.h>
#include <QtCharts/qvbarmodelmapper.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCharts/qcandlestickseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qboxplotseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qpieseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCharts/qxyseries.h>
#include <QtCore/qabstractitemmodel.h>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'sports.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN6SportsE_t {};
} // unnamed namespace

template <> constexpr inline auto Sports::qt_create_metaobjectdata<qt_meta_tag_ZN6SportsE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "Sports",
        "on_btnRecord_clicked",
        "",
        "on_btnStats_clicked",
        "on_btnReset_clicked",
        "refreshData"
    };

    QtMocHelpers::UintData qt_methods {
        // Slot 'on_btnRecord_clicked'
        QtMocHelpers::SlotData<void()>(1, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnStats_clicked'
        QtMocHelpers::SlotData<void()>(3, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'on_btnReset_clicked'
        QtMocHelpers::SlotData<void()>(4, 2, QMC::AccessPrivate, QMetaType::Void),
        // Slot 'refreshData'
        QtMocHelpers::SlotData<void()>(5, 2, QMC::AccessPublic, QMetaType::Void),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<Sports, qt_meta_tag_ZN6SportsE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject Sports::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6SportsE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6SportsE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN6SportsE_t>.metaTypes,
    nullptr
} };

void Sports::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<Sports *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->on_btnRecord_clicked(); break;
        case 1: _t->on_btnStats_clicked(); break;
        case 2: _t->on_btnReset_clicked(); break;
        case 3: _t->refreshData(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Sports::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Sports::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN6SportsE_t>.strings))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Sports::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
