/****************************************************************************
** Meta object code from reading C++ file 'KsDualMarker.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/KsDualMarker.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KsDualMarker.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KsMarkerButton_t {
    QByteArrayData data[3];
    char stringdata0[25];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsMarkerButton_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsMarkerButton_t qt_meta_stringdata_KsMarkerButton = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KsMarkerButton"
QT_MOC_LITERAL(1, 15, 8), // "deselect"
QT_MOC_LITERAL(2, 24, 0) // ""

    },
    "KsMarkerButton\0deselect\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsMarkerButton[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,

       0        // eod
};

void KsMarkerButton::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsMarkerButton *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deselect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsMarkerButton::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsMarkerButton::deselect)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsMarkerButton::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_KsMarkerButton.data,
    qt_meta_data_KsMarkerButton,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsMarkerButton::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsMarkerButton::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsMarkerButton.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int KsMarkerButton::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KsMarkerButton::deselect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_KsGraphMark_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsGraphMark_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsGraphMark_t qt_meta_stringdata_KsGraphMark = {
    {
QT_MOC_LITERAL(0, 0, 11) // "KsGraphMark"

    },
    "KsGraphMark"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsGraphMark[] = {

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

void KsGraphMark::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsGraphMark::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_KsGraphMark.data,
    qt_meta_data_KsGraphMark,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsGraphMark::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsGraphMark::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsGraphMark.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int KsGraphMark::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsDualMarkerSM_t {
    QByteArrayData data[12];
    char stringdata0[115];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsDualMarkerSM_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsDualMarkerSM_t qt_meta_stringdata_KsDualMarkerSM = {
    {
QT_MOC_LITERAL(0, 0, 14), // "KsDualMarkerSM"
QT_MOC_LITERAL(1, 15, 17), // "markSwitchForView"
QT_MOC_LITERAL(2, 33, 0), // ""
QT_MOC_LITERAL(3, 34, 10), // "updateView"
QT_MOC_LITERAL(4, 45, 6), // "size_t"
QT_MOC_LITERAL(5, 52, 3), // "pos"
QT_MOC_LITERAL(6, 56, 4), // "mark"
QT_MOC_LITERAL(7, 61, 11), // "updateGraph"
QT_MOC_LITERAL(8, 73, 10), // "machineToA"
QT_MOC_LITERAL(9, 84, 10), // "machineToB"
QT_MOC_LITERAL(10, 95, 9), // "deselectA"
QT_MOC_LITERAL(11, 105, 9) // "deselectB"

    },
    "KsDualMarkerSM\0markSwitchForView\0\0"
    "updateView\0size_t\0pos\0mark\0updateGraph\0"
    "machineToA\0machineToB\0deselectA\0"
    "deselectB"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsDualMarkerSM[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   49,    2, 0x06 /* Public */,
       3,    2,   50,    2, 0x06 /* Public */,
       7,    1,   55,    2, 0x06 /* Public */,
       8,    0,   58,    2, 0x06 /* Public */,
       9,    0,   59,    2, 0x06 /* Public */,
      10,    0,   60,    2, 0x06 /* Public */,
      11,    0,   61,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 4, QMetaType::Bool,    5,    6,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KsDualMarkerSM::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsDualMarkerSM *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->markSwitchForView(); break;
        case 1: _t->updateView((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 2: _t->updateGraph((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 3: _t->machineToA(); break;
        case 4: _t->machineToB(); break;
        case 5: _t->deselectA(); break;
        case 6: _t->deselectB(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsDualMarkerSM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::markSwitchForView)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)(size_t , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::updateView)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::updateGraph)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::machineToA)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::machineToB)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::deselectA)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KsDualMarkerSM::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsDualMarkerSM::deselectB)) {
                *result = 6;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsDualMarkerSM::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_KsDualMarkerSM.data,
    qt_meta_data_KsDualMarkerSM,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsDualMarkerSM::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsDualMarkerSM::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsDualMarkerSM.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KsDualMarkerSM::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void KsDualMarkerSM::markSwitchForView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void KsDualMarkerSM::updateView(size_t _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KsDualMarkerSM::updateGraph(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KsDualMarkerSM::machineToA()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void KsDualMarkerSM::machineToB()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void KsDualMarkerSM::deselectA()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void KsDualMarkerSM::deselectB()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
