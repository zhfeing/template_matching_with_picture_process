/****************************************************************************
** Meta object code from reading C++ file 'processmainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "processmainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processmainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProcessMainWindow[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      19,   18,   18,   18, 0x05,

 // slots: signature, parameters, type, tag, flags
      51,   18,   18,   18, 0x08,
      86,   18,   18,   18, 0x08,
     117,   18,   18,   18, 0x08,
     144,   18,   18,   18, 0x08,
     176,   18,   18,   18, 0x08,
     203,   18,   18,   18, 0x08,
     227,   18,   18,   18, 0x08,
     251,   18,   18,   18, 0x08,
     281,  276,   18,   18, 0x08,
     365,  330,   18,   18, 0x08,
     431,   18,   18,   18, 0x08,
     461,   18,   18,   18, 0x08,
     488,   18,   18,   18, 0x08,
     521,   18,   18,   18, 0x08,
     543,   18,   18,   18, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProcessMainWindow[] = {
    "ProcessMainWindow\0\0toTemplate_OpenPictureSucceed()\0"
    "on_action_open_picture_triggered()\0"
    "on_openPictureButton_clicked()\0"
    "on_action_Quit_triggered()\0"
    "on_closePictureButton_clicked()\0"
    "on_denoiseButton_clicked()\0"
    "on_unDoButton_clicked()\0on_saveButton_clicked()\0"
    "on_sharpButton_clicked()\0mode\0"
    "getChooseMode(ChooseSharpOrder::ChooseSharpMode)\0"
    "mode,ifMulityAnswer,ifEdge,percent\0"
    "getChooseMode(TemplateMatchUi::TemplateMatchMode,bool,bool,float)\0"
    "on_action_save_as_triggered()\0"
    "on_actionAbout_triggered()\0"
    "on_templateMatchButton_clicked()\0"
    "openTemplatePicture()\0stopShowTemplPic()\0"
};

void ProcessMainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        ProcessMainWindow *_t = static_cast<ProcessMainWindow *>(_o);
        switch (_id) {
        case 0: _t->toTemplate_OpenPictureSucceed(); break;
        case 1: _t->on_action_open_picture_triggered(); break;
        case 2: _t->on_openPictureButton_clicked(); break;
        case 3: _t->on_action_Quit_triggered(); break;
        case 4: _t->on_closePictureButton_clicked(); break;
        case 5: _t->on_denoiseButton_clicked(); break;
        case 6: _t->on_unDoButton_clicked(); break;
        case 7: _t->on_saveButton_clicked(); break;
        case 8: _t->on_sharpButton_clicked(); break;
        case 9: _t->getChooseMode((*reinterpret_cast< ChooseSharpOrder::ChooseSharpMode(*)>(_a[1]))); break;
        case 10: _t->getChooseMode((*reinterpret_cast< TemplateMatchUi::TemplateMatchMode(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 11: _t->on_action_save_as_triggered(); break;
        case 12: _t->on_actionAbout_triggered(); break;
        case 13: _t->on_templateMatchButton_clicked(); break;
        case 14: _t->openTemplatePicture(); break;
        case 15: _t->stopShowTemplPic(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData ProcessMainWindow::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject ProcessMainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_ProcessMainWindow,
      qt_meta_data_ProcessMainWindow, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProcessMainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProcessMainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProcessMainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessMainWindow))
        return static_cast<void*>(const_cast< ProcessMainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int ProcessMainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 16)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 16;
    }
    return _id;
}

// SIGNAL 0
void ProcessMainWindow::toTemplate_OpenPictureSucceed()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}
QT_END_MOC_NAMESPACE
