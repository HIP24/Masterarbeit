/****************************************************************************
** Meta object code from reading C++ file 'KsGLWidget.hpp'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../src/KsGLWidget.hpp"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'KsGLWidget.hpp' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_KsGLWidget_t {
    QByteArrayData data[19];
    char stringdata0[135];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KsGLWidget_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KsGLWidget_t qt_meta_stringdata_KsGLWidget = {
    {
QT_MOC_LITERAL(0, 0, 10), // "KsGLWidget"
QT_MOC_LITERAL(1, 11, 5), // "found"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 6), // "size_t"
QT_MOC_LITERAL(4, 25, 3), // "pos"
QT_MOC_LITERAL(5, 29, 8), // "notFound"
QT_MOC_LITERAL(6, 38, 8), // "uint64_t"
QT_MOC_LITERAL(7, 47, 2), // "ts"
QT_MOC_LITERAL(8, 50, 2), // "sd"
QT_MOC_LITERAL(9, 53, 3), // "cpu"
QT_MOC_LITERAL(10, 57, 3), // "pid"
QT_MOC_LITERAL(11, 61, 6), // "zoomIn"
QT_MOC_LITERAL(12, 68, 7), // "zoomOut"
QT_MOC_LITERAL(13, 76, 10), // "scrollLeft"
QT_MOC_LITERAL(14, 87, 11), // "scrollRight"
QT_MOC_LITERAL(15, 99, 12), // "stopUpdating"
QT_MOC_LITERAL(16, 112, 6), // "select"
QT_MOC_LITERAL(17, 119, 10), // "updateView"
QT_MOC_LITERAL(18, 130, 4) // "mark"

    },
    "KsGLWidget\0found\0\0size_t\0pos\0notFound\0"
    "uint64_t\0ts\0sd\0cpu\0pid\0zoomIn\0zoomOut\0"
    "scrollLeft\0scrollRight\0stopUpdating\0"
    "select\0updateView\0mark"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KsGLWidget[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       9,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       5,    4,   62,    2, 0x06 /* Public */,
      11,    0,   71,    2, 0x06 /* Public */,
      12,    0,   72,    2, 0x06 /* Public */,
      13,    0,   73,    2, 0x06 /* Public */,
      14,    0,   74,    2, 0x06 /* Public */,
      15,    0,   75,    2, 0x06 /* Public */,
      16,    1,   76,    2, 0x06 /* Public */,
      17,    2,   79,    2, 0x06 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 6, QMetaType::Int, QMetaType::Int, QMetaType::Int,    7,    8,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, QMetaType::Bool,    4,   18,

       0        // eod
};

void KsGLWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<KsGLWidget *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->found((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 1: _t->notFound((*reinterpret_cast< uint64_t(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 2: _t->zoomIn(); break;
        case 3: _t->zoomOut(); break;
        case 4: _t->scrollLeft(); break;
        case 5: _t->scrollRight(); break;
        case 6: _t->stopUpdating(); break;
        case 7: _t->select((*reinterpret_cast< size_t(*)>(_a[1]))); break;
        case 8: _t->updateView((*reinterpret_cast< size_t(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (KsGLWidget::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::found)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)(uint64_t , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::notFound)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::zoomIn)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::zoomOut)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::scrollLeft)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::scrollRight)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::stopUpdating)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)(size_t );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::select)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (KsGLWidget::*)(size_t , bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&KsGLWidget::updateView)) {
                *result = 8;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject KsGLWidget::staticMetaObject = { {
    QMetaObject::SuperData::link<QOpenGLWidget::staticMetaObject>(),
    qt_meta_stringdata_KsGLWidget.data,
    qt_meta_data_KsGLWidget,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *KsGLWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KsGLWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_KsGLWidget.stringdata0))
        return static_cast<void*>(this);
    return QOpenGLWidget::qt_metacast(_clname);
}

int KsGLWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QOpenGLWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void KsGLWidget::found(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void KsGLWidget::notFound(uint64_t _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void KsGLWidget::zoomIn()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void KsGLWidget::zoomOut()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void KsGLWidget::scrollLeft()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void KsGLWidget::scrollRight()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void KsGLWidget::stopUpdating()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void KsGLWidget::select(size_t _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 7, _a);
}

// SIGNAL 8
void KsGLWidget::updateView(size_t _t1, bool _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 8, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
