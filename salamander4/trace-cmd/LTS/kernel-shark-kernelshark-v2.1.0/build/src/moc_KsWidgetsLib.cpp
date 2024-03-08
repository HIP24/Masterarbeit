/****************************************************************************
** Meta object code from reading C++ file 'KsWidgetsLib.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/KsWidgetsLib.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QVector>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KsWidgetsLib.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KsWidgetsLib__KsProgressBar_t {
    QByteArrayData data[1];
    char stringdata0[28];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsProgressBar_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsProgressBar_t qt_meta_stringdata_KsWidgetsLib__KsProgressBar = {
    {
QT_MOC_LITERAL(0, 0, 27) // "KsWidgetsLib::KsProgressBar"

    },
    "KsWidgetsLib::KsProgressBar"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsProgressBar[] = {

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

void KsWidgetsLib::KsProgressBar::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsProgressBar::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsProgressBar.data,
    qt_meta_data_KsWidgetsLib__KsProgressBar,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsProgressBar::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsProgressBar::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsProgressBar.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsProgressBar::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog_t {
    QByteArrayData data[7];
    char stringdata0[65];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog_t qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog = {
    {
QT_MOC_LITERAL(0, 0, 32), // "KsWidgetsLib::KsTimeOffsetDialog"
QT_MOC_LITERAL(1, 33, 5), // "apply"
QT_MOC_LITERAL(2, 39, 0), // ""
QT_MOC_LITERAL(3, 40, 2), // "sd"
QT_MOC_LITERAL(4, 43, 3), // "val"
QT_MOC_LITERAL(5, 47, 11), // "_setDefault"
QT_MOC_LITERAL(6, 59, 5) // "index"

    },
    "KsWidgetsLib::KsTimeOffsetDialog\0apply\0"
    "\0sd\0val\0_setDefault\0index"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsTimeOffsetDialog[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   24,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   29,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Double,    3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    6,

       0        // eod
};

void KsWidgetsLib::KsTimeOffsetDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsTimeOffsetDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->apply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< double(*)>(_a[2]))); break;
        case 1: _t->_setDefault((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsTimeOffsetDialog::*)(int , double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsTimeOffsetDialog::apply)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsTimeOffsetDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog.data,
    qt_meta_data_KsWidgetsLib__KsTimeOffsetDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsTimeOffsetDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsTimeOffsetDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsTimeOffsetDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KsWidgetsLib::KsTimeOffsetDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void KsWidgetsLib::KsTimeOffsetDialog::apply(int _t1, double _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget_t {
    QByteArrayData data[1];
    char stringdata0[31];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget = {
    {
QT_MOC_LITERAL(0, 0, 30) // "KsWidgetsLib::KsCheckBoxWidget"

    },
    "KsWidgetsLib::KsCheckBoxWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxWidget[] = {

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

void KsWidgetsLib::KsCheckBoxWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog_t {
    QByteArrayData data[5];
    char stringdata0[54];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog = {
    {
QT_MOC_LITERAL(0, 0, 30), // "KsWidgetsLib::KsCheckBoxDialog"
QT_MOC_LITERAL(1, 31, 5), // "apply"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 2), // "sd"
QT_MOC_LITERAL(4, 41, 12) // "QVector<int>"

    },
    "KsWidgetsLib::KsCheckBoxDialog\0apply\0"
    "\0sd\0QVector<int>"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxDialog[] = {

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
       1,    2,   19,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    2,

       0        // eod
};

void KsWidgetsLib::KsCheckBoxDialog::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsCheckBoxDialog *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->apply((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QVector<int>(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 1:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QVector<int> >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsCheckBoxDialog::*)(int , QVector<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsCheckBoxDialog::apply)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxDialog::staticMetaObject = { {
    QMetaObject::SuperData::link<QDialog::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxDialog,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxDialog::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxDialog::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxDialog.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxDialog::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    }
    return _id;
}

// SIGNAL 0
void KsWidgetsLib::KsCheckBoxDialog::apply(int _t1, QVector<int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable_t {
    QByteArrayData data[4];
    char stringdata0[47];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable = {
    {
QT_MOC_LITERAL(0, 0, 29), // "KsWidgetsLib::KsCheckBoxTable"
QT_MOC_LITERAL(1, 30, 11), // "changeState"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 3) // "row"

    },
    "KsWidgetsLib::KsCheckBoxTable\0changeState\0"
    "\0row"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxTable[] = {

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
    QMetaType::Void, QMetaType::Int,    3,

       0        // eod
};

void KsWidgetsLib::KsCheckBoxTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsCheckBoxTable *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->changeState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsCheckBoxTable::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsCheckBoxTable::changeState)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxTable::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxTable,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTable.stringdata0))
        return static_cast<void*>(this);
    return QTableWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableWidget::qt_metacall(_c, _id, _a);
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
void KsWidgetsLib::KsCheckBoxTable::changeState(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget_t {
    QByteArrayData data[1];
    char stringdata0[36];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget = {
    {
QT_MOC_LITERAL(0, 0, 35) // "KsWidgetsLib::KsCheckBoxTable..."

    },
    "KsWidgetsLib::KsCheckBoxTableWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxTableWidget[] = {

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

void KsWidgetsLib::KsCheckBoxTableWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxTableWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<KsCheckBoxWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxTableWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxTableWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxTableWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTableWidget.stringdata0))
        return static_cast<void*>(this);
    return KsCheckBoxWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxTableWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KsCheckBoxWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree_t {
    QByteArrayData data[3];
    char stringdata0[37];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree = {
    {
QT_MOC_LITERAL(0, 0, 28), // "KsWidgetsLib::KsCheckBoxTree"
QT_MOC_LITERAL(1, 29, 6), // "verify"
QT_MOC_LITERAL(2, 36, 0) // ""

    },
    "KsWidgetsLib::KsCheckBoxTree\0verify\0"
    ""
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxTree[] = {

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

void KsWidgetsLib::KsCheckBoxTree::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsCheckBoxTree *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->verify(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsCheckBoxTree::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsCheckBoxTree::verify)) {
                *result = 0;
                return;
            }
        }
    }
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxTree::staticMetaObject = { {
    QMetaObject::SuperData::link<QTreeWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxTree,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxTree::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxTree::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTree.stringdata0))
        return static_cast<void*>(this);
    return QTreeWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxTree::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTreeWidget::qt_metacall(_c, _id, _a);
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
void KsWidgetsLib::KsCheckBoxTree::verify()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
struct qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget_t {
    QByteArrayData data[1];
    char stringdata0[35];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget_t qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget = {
    {
QT_MOC_LITERAL(0, 0, 34) // "KsWidgetsLib::KsCheckBoxTreeW..."

    },
    "KsWidgetsLib::KsCheckBoxTreeWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsCheckBoxTreeWidget[] = {

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

void KsWidgetsLib::KsCheckBoxTreeWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    (void)_o;
    (void)_id;
    (void)_c;
    (void)_a;
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsCheckBoxTreeWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<KsCheckBoxWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget.data,
    qt_meta_data_KsWidgetsLib__KsCheckBoxTreeWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsCheckBoxTreeWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsCheckBoxTreeWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsCheckBoxTreeWidget.stringdata0))
        return static_cast<void*>(this);
    return KsCheckBoxWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsCheckBoxTreeWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = KsCheckBoxWidget::qt_metacall(_c, _id, _a);
    return _id;
}
struct qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget_t {
    QByteArrayData data[6];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget_t qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget = {
    {
QT_MOC_LITERAL(0, 0, 38), // "KsWidgetsLib::KsEventFieldSel..."
QT_MOC_LITERAL(1, 39, 14), // "_streamChanged"
QT_MOC_LITERAL(2, 54, 0), // ""
QT_MOC_LITERAL(3, 55, 6), // "stream"
QT_MOC_LITERAL(4, 62, 13), // "_eventChanged"
QT_MOC_LITERAL(5, 76, 5) // "event"

    },
    "KsWidgetsLib::KsEventFieldSelectWidget\0"
    "_streamChanged\0\0stream\0_eventChanged\0"
    "event"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsWidgetsLib__KsEventFieldSelectWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   24,    2, 0x08 /* Private */,
       4,    1,   27,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,

       0        // eod
};

void KsWidgetsLib::KsEventFieldSelectWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsEventFieldSelectWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->_streamChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 1: _t->_eventChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsWidgetsLib::KsEventFieldSelectWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget.data,
    qt_meta_data_KsWidgetsLib__KsEventFieldSelectWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsWidgetsLib::KsEventFieldSelectWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsWidgetsLib::KsEventFieldSelectWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsWidgetsLib__KsEventFieldSelectWidget.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int KsWidgetsLib::KsEventFieldSelectWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 2;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
