/****************************************************************************
** Meta object code from reading C++ file 'KsTraceViewer.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/KsTraceViewer.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KsTraceViewer.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KsTableView_t {
    QByteArrayData data[1];
    char stringdata0[12];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsTableView_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsTableView_t qt_meta_stringdata_KsTableView = {
    {
QT_MOC_LITERAL(0, 0, 11) // "KsTableView"

    },
    "KsTableView"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsTableView[] = {

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

void KsTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableView::staticMetaObject>(),
    qt_meta_stringdata_KsTableView.data,
    qt_meta_data_KsTableView,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsTableView.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int KsTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsTraceViewer_t {
    QByteArrayData data[9];
    char stringdata0[69];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsTraceViewer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsTraceViewer_t qt_meta_stringdata_KsTraceViewer = {
    {
QT_MOC_LITERAL(0, 0, 13), // "KsTraceViewer"
QT_MOC_LITERAL(1, 14, 6), // "select"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 6), // "size_t"
QT_MOC_LITERAL(4, 29, 11), // "addTaskPlot"
QT_MOC_LITERAL(5, 41, 2), // "sd"
QT_MOC_LITERAL(6, 44, 3), // "pid"
QT_MOC_LITERAL(7, 48, 8), // "deselect"
QT_MOC_LITERAL(8, 57, 11) // "_searchEdit"

    },
    "KsTraceViewer\0select\0\0size_t\0addTaskPlot\0"
    "sd\0pid\0deselect\0_searchEdit"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsTraceViewer[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x06 /* Public */,
       4,    2,   37,    2, 0x06 /* Public */,
       7,    0,   42,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   43,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    5,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void KsTraceViewer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsTraceViewer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->select((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 1: _t->addTaskPlot((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->deselect(); break;
        case 3: _t->_searchEdit((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsTraceViewer::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsTraceViewer::select)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KsTraceViewer::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsTraceViewer::addTaskPlot)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KsTraceViewer::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsTraceViewer::deselect)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsTraceViewer::staticMetaObject = { {
    QMetaObject::SuperData::link<KsWidgetsLib::KsDataWidget::staticMetaObject>(),
    qt_meta_stringdata_KsTraceViewer.data,
    qt_meta_data_KsTraceViewer,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsTraceViewer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsTraceViewer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsTraceViewer.stringdata0))
        return static_cast<void*>(this);
    return KsWidgetsLib::KsDataWidget::qt_metacast(_clname);
}

int KsTraceViewer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KsWidgetsLib::KsDataWidget::qt_metacall(_c, _id, _a);
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
void KsTraceViewer::select(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KsTraceViewer::addTaskPlot(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KsTraceViewer::deselect()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
