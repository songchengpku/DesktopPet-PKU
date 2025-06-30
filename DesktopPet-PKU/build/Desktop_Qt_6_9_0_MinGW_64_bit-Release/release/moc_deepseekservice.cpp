/****************************************************************************
** Meta object code from reading C++ file 'deepseekservice.h'
**
** Created by: The Qt Meta Object Compiler version 69 (Qt 6.9.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../backend/deepseekservice.h"
#include <QtNetwork/QSslError>
#include <QtCore/qmetatype.h>

#include <QtCore/qtmochelpers.h>

#include <memory>


#include <QtCore/qxptype_traits.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'deepseekservice.h' doesn't include <QObject>."
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
struct qt_meta_tag_ZN15DeepSeekServiceE_t {};
} // unnamed namespace

template <> constexpr inline auto DeepSeekService::qt_create_metaobjectdata<qt_meta_tag_ZN15DeepSeekServiceE_t>()
{
    namespace QMC = QtMocConstants;
    QtMocHelpers::StringRefStorage qt_stringData {
        "DeepSeekService",
        "responseReceived",
        "",
        "reply",
        "errorOccurred",
        "error",
        "onApiResponse",
        "QNetworkReply*"
    };

    QtMocHelpers::UintData qt_methods {
        // Signal 'responseReceived'
        QtMocHelpers::SignalData<void(const QString &)>(1, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 3 },
        }}),
        // Signal 'errorOccurred'
        QtMocHelpers::SignalData<void(const QString &)>(4, 2, QMC::AccessPublic, QMetaType::Void, {{
            { QMetaType::QString, 5 },
        }}),
        // Slot 'onApiResponse'
        QtMocHelpers::SlotData<void(QNetworkReply *)>(6, 2, QMC::AccessPrivate, QMetaType::Void, {{
            { 0x80000000 | 7, 3 },
        }}),
    };
    QtMocHelpers::UintData qt_properties {
    };
    QtMocHelpers::UintData qt_enums {
    };
    return QtMocHelpers::metaObjectData<DeepSeekService, qt_meta_tag_ZN15DeepSeekServiceE_t>(QMC::MetaObjectFlag{}, qt_stringData,
            qt_methods, qt_properties, qt_enums);
}
Q_CONSTINIT const QMetaObject DeepSeekService::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DeepSeekServiceE_t>.stringdata,
    qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DeepSeekServiceE_t>.data,
    qt_static_metacall,
    nullptr,
    qt_staticMetaObjectRelocatingContent<qt_meta_tag_ZN15DeepSeekServiceE_t>.metaTypes,
    nullptr
} };

void DeepSeekService::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    auto *_t = static_cast<DeepSeekService *>(_o);
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: _t->responseReceived((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 1: _t->errorOccurred((*reinterpret_cast< std::add_pointer_t<QString>>(_a[1]))); break;
        case 2: _t->onApiResponse((*reinterpret_cast< std::add_pointer_t<QNetworkReply*>>(_a[1]))); break;
        default: ;
        }
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< QNetworkReply* >(); break;
            }
            break;
        }
    }
    if (_c == QMetaObject::IndexOfMethod) {
        if (QtMocHelpers::indexOfMethod<void (DeepSeekService::*)(const QString & )>(_a, &DeepSeekService::responseReceived, 0))
            return;
        if (QtMocHelpers::indexOfMethod<void (DeepSeekService::*)(const QString & )>(_a, &DeepSeekService::errorOccurred, 1))
            return;
    }
}

const QMetaObject *DeepSeekService::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DeepSeekService::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_staticMetaObjectStaticContent<qt_meta_tag_ZN15DeepSeekServiceE_t>.strings))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int DeepSeekService::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DeepSeekService::responseReceived(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 0, nullptr, _t1);
}

// SIGNAL 1
void DeepSeekService::errorOccurred(const QString & _t1)
{
    QMetaObject::activate<void>(this, &staticMetaObject, 1, nullptr, _t1);
}
QT_WARNING_POP
