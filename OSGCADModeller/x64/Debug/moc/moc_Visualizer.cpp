/****************************************************************************
** Meta object code from reading C++ file 'Visualizer.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "stdafx.h"
#include "../../../headers/Visualizer.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Visualizer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.2. It"
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

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSVisualizerENDCLASS_t {};
constexpr auto qt_meta_stringdata_CLASSVisualizerENDCLASS = QtMocHelpers::stringData(
    "Visualizer",
    "onSketchButtonClicked",
    "",
    "onViewButtonClicked",
    "onXYButtonClicked",
    "onYZButtonClicked",
    "onXZButtonClicked",
    "onPointButtonClicked",
    "onLineButtonClicked",
    "onCircleButtonClicked",
    "onEllipseButtonClicked",
    "onArcButtonClicked",
    "onSaveButtonClicked",
    "onClearButtonClicked"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSVisualizerENDCLASS_t {
    uint offsetsAndSizes[28];
    char stringdata0[11];
    char stringdata1[22];
    char stringdata2[1];
    char stringdata3[20];
    char stringdata4[18];
    char stringdata5[18];
    char stringdata6[18];
    char stringdata7[21];
    char stringdata8[20];
    char stringdata9[22];
    char stringdata10[23];
    char stringdata11[19];
    char stringdata12[20];
    char stringdata13[21];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSVisualizerENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSVisualizerENDCLASS_t qt_meta_stringdata_CLASSVisualizerENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "Visualizer"
        QT_MOC_LITERAL(11, 21),  // "onSketchButtonClicked"
        QT_MOC_LITERAL(33, 0),  // ""
        QT_MOC_LITERAL(34, 19),  // "onViewButtonClicked"
        QT_MOC_LITERAL(54, 17),  // "onXYButtonClicked"
        QT_MOC_LITERAL(72, 17),  // "onYZButtonClicked"
        QT_MOC_LITERAL(90, 17),  // "onXZButtonClicked"
        QT_MOC_LITERAL(108, 20),  // "onPointButtonClicked"
        QT_MOC_LITERAL(129, 19),  // "onLineButtonClicked"
        QT_MOC_LITERAL(149, 21),  // "onCircleButtonClicked"
        QT_MOC_LITERAL(171, 22),  // "onEllipseButtonClicked"
        QT_MOC_LITERAL(194, 18),  // "onArcButtonClicked"
        QT_MOC_LITERAL(213, 19),  // "onSaveButtonClicked"
        QT_MOC_LITERAL(233, 20)   // "onClearButtonClicked"
    },
    "Visualizer",
    "onSketchButtonClicked",
    "",
    "onViewButtonClicked",
    "onXYButtonClicked",
    "onYZButtonClicked",
    "onXZButtonClicked",
    "onPointButtonClicked",
    "onLineButtonClicked",
    "onCircleButtonClicked",
    "onEllipseButtonClicked",
    "onArcButtonClicked",
    "onSaveButtonClicked",
    "onClearButtonClicked"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSVisualizerENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   86,    2, 0x08,    1 /* Private */,
       3,    0,   87,    2, 0x08,    2 /* Private */,
       4,    0,   88,    2, 0x08,    3 /* Private */,
       5,    0,   89,    2, 0x08,    4 /* Private */,
       6,    0,   90,    2, 0x08,    5 /* Private */,
       7,    0,   91,    2, 0x08,    6 /* Private */,
       8,    0,   92,    2, 0x08,    7 /* Private */,
       9,    0,   93,    2, 0x08,    8 /* Private */,
      10,    0,   94,    2, 0x08,    9 /* Private */,
      11,    0,   95,    2, 0x08,   10 /* Private */,
      12,    0,   96,    2, 0x08,   11 /* Private */,
      13,    0,   97,    2, 0x08,   12 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject Visualizer::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSVisualizerENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSVisualizerENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSVisualizerENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<Visualizer, std::true_type>,
        // method 'onSketchButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onViewButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onXYButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onYZButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onXZButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onPointButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onLineButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onCircleButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onEllipseButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onArcButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onSaveButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'onClearButtonClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void Visualizer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Visualizer *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onSketchButtonClicked(); break;
        case 1: _t->onViewButtonClicked(); break;
        case 2: _t->onXYButtonClicked(); break;
        case 3: _t->onYZButtonClicked(); break;
        case 4: _t->onXZButtonClicked(); break;
        case 5: _t->onPointButtonClicked(); break;
        case 6: _t->onLineButtonClicked(); break;
        case 7: _t->onCircleButtonClicked(); break;
        case 8: _t->onEllipseButtonClicked(); break;
        case 9: _t->onArcButtonClicked(); break;
        case 10: _t->onSaveButtonClicked(); break;
        case 11: _t->onClearButtonClicked(); break;
        default: ;
        }
    }
    (void)_a;
}

const QMetaObject *Visualizer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Visualizer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSVisualizerENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int Visualizer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
