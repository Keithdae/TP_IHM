/****************************************************************************
** Meta object code from reading C++ file 'drawarea.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.6)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../TP2/drawarea.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'drawarea.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.6. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_drawArea[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      19,   10,    9,    9, 0x0a,
      41,   36,    9,    9, 0x0a,
      70,   61,    9,    9, 0x0a,
     100,   91,    9,    9, 0x0a,
     129,  121,    9,    9, 0x0a,
     145,    9,    9,    9, 0x0a,
     162,    9,    9,    9, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_drawArea[] = {
    "drawArea\0\0newColor\0changeColor(int)\0"
    "nCol\0changeColor(QColor)\0newWidth\0"
    "changeLineWidth(int)\0newStyle\0"
    "changeLineStyle(int)\0newType\0"
    "selectType(int)\0deleteLastLine()\0"
    "clearAllLines()\0"
};

void drawArea::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        drawArea *_t = static_cast<drawArea *>(_o);
        switch (_id) {
        case 0: _t->changeColor((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->changeColor((*reinterpret_cast< QColor(*)>(_a[1]))); break;
        case 2: _t->changeLineWidth((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 3: _t->changeLineStyle((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->selectType((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->deleteLastLine(); break;
        case 6: _t->clearAllLines(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData drawArea::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject drawArea::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_drawArea,
      qt_meta_data_drawArea, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &drawArea::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *drawArea::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *drawArea::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_drawArea))
        return static_cast<void*>(const_cast< drawArea*>(this));
    return QWidget::qt_metacast(_clname);
}

int drawArea::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
