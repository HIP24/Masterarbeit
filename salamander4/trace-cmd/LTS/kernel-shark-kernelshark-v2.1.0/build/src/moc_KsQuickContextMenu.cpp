/****************************************************************************
** Meta object code from reading C++ file 'KsQuickContextMenu.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/KsQuickContextMenu.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KsQuickContextMenu.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KsQuickMarkerMenu_t {
    QByteArrayData data[3];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsQuickMarkerMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsQuickMarkerMenu_t qt_meta_stringdata_KsQuickMarkerMenu = {
    {
QT_MOC_LITERAL(0, 0, 17), // "KsQuickMarkerMenu"
QT_MOC_LITERAL(1, 18, 8), // "deselect"
QT_MOC_LITERAL(2, 27, 0) // ""

    },
    "KsQuickMarkerMenu\0deselect\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsQuickMarkerMenu[] = {

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

void KsQuickMarkerMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsQuickMarkerMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->deselect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsQuickMarkerMenu::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsQuickMarkerMenu::deselect)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsQuickMarkerMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<QMenu::staticMetaObject>(),
    qt_meta_stringdata_KsQuickMarkerMenu.data,
    qt_meta_data_KsQuickMarkerMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsQuickMarkerMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsQuickMarkerMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsQuickMarkerMenu.stringdata0))
        return static_cast<void*>(this);
    return QMenu::qt_metacast(_clname);
}

int KsQuickMarkerMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMenu::qt_metacall(_c, _id, _a);
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
void KsQuickMarkerMenu::deselect()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_KsQuickContextMenu_t {
    QByteArrayData data[9];
    char stringdata0[83];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsQuickContextMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsQuickContextMenu_t qt_meta_stringdata_KsQuickContextMenu = {
    {
QT_MOC_LITERAL(0, 0, 18), // "KsQuickContextMenu"
QT_MOC_LITERAL(1, 19, 11), // "addTaskPlot"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 2), // "sd"
QT_MOC_LITERAL(4, 35, 3), // "pid"
QT_MOC_LITERAL(5, 39, 10), // "addCPUPlot"
QT_MOC_LITERAL(6, 50, 3), // "cpu"
QT_MOC_LITERAL(7, 54, 14), // "removeTaskPlot"
QT_MOC_LITERAL(8, 69, 13) // "removeCPUPlot"

    },
    "KsQuickContextMenu\0addTaskPlot\0\0sd\0"
    "pid\0addCPUPlot\0cpu\0removeTaskPlot\0"
    "removeCPUPlot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsQuickContextMenu[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x06 /* Public */,
       5,    2,   39,    2, 0x06 /* Public */,
       7,    2,   44,    2, 0x06 /* Public */,
       8,    2,   49,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    6,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    6,

       0        // eod
};

void KsQuickContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsQuickContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->addTaskPlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->addCPUPlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->removeTaskPlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 3: _t->removeCPUPlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsQuickContextMenu::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsQuickContextMenu::addTaskPlot)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KsQuickContextMenu::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsQuickContextMenu::addCPUPlot)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KsQuickContextMenu::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsQuickContextMenu::removeTaskPlot)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KsQuickContextMenu::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsQuickContextMenu::removeCPUPlot)) {
                *result = 3;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsQuickContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<KsQuickMarkerMenu::staticMetaObject>(),
    qt_meta_stringdata_KsQuickContextMenu.data,
    qt_meta_data_KsQuickContextMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsQuickContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsQuickContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsQuickContextMenu.stringdata0))
        return static_cast<void*>(this);
    return KsQuickMarkerMenu::qt_metacast(_clname);
}

int KsQuickContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KsQuickMarkerMenu::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void KsQuickContextMenu::addTaskPlot(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KsQuickContextMenu::addCPUPlot(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KsQuickContextMenu::removeTaskPlot(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void KsQuickContextMenu::removeCPUPlot(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
struct qt_meta_stringdata_KsRmPlotContextMenu_t {
    QByteArrayData data[3];
    char stringdata0[32];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsRmPlotContextMenu_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsRmPlotContextMenu_t qt_meta_stringdata_KsRmPlotContextMenu = {
    {
QT_MOC_LITERAL(0, 0, 19), // "KsRmPlotContextMenu"
QT_MOC_LITERAL(1, 20, 10), // "removePlot"
QT_MOC_LITERAL(2, 31, 0) // ""

    },
    "KsRmPlotContextMenu\0removePlot\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsRmPlotContextMenu[] = {

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
       1,    1,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void KsRmPlotContextMenu::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsRmPlotContextMenu *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->removePlot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsRmPlotContextMenu::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsRmPlotContextMenu::removePlot)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsRmPlotContextMenu::staticMetaObject = { {
    QMetaObject::SuperData::link<KsQuickMarkerMenu::staticMetaObject>(),
    qt_meta_stringdata_KsRmPlotContextMenu.data,
    qt_meta_data_KsRmPlotContextMenu,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsRmPlotContextMenu::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsRmPlotContextMenu::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsRmPlotContextMenu.stringdata0))
        return static_cast<void*>(this);
    return KsQuickMarkerMenu::qt_metacast(_clname);
}

int KsRmPlotContextMenu::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KsQuickMarkerMenu::qt_metacall(_c, _id, _a);
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
void KsRmPlotContextMenu::removePlot(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
