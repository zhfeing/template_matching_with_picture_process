/****************************************************************************
** Meta object code from reading C++ file 'templatematchui.h'
**
** Created by: The Qt Meta Object Compiler version 63 (Qt 4.8.7)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "templatematchui.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'templatematchui.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.7. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_TemplateMatchUi[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: signature, parameters, type, tag, flags
      52,   17,   16,   16, 0x05,
     118,   16,   16,   16, 0x05,
     140,   16,   16,   16, 0x05,

 // slots: signature, parameters, type, tag, flags
     167,  159,   16,   16, 0x08,
     205,  159,   16,   16, 0x08,
     239,   16,   16,   16, 0x08,
     271,  159,   16,   16, 0x08,
     310,  159,   16,   16, 0x08,
     337,  159,   16,   16, 0x08,
     364,   16,   16,   16, 0x08,
     376,   16,   16,   16, 0x08,
     392,   16,   16,   16, 0x08,
     413,   16,   16,   16, 0x08,
     441,  439,   16,   16, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_TemplateMatchUi[] = {
    "TemplateMatchUi\0\0mode,ifMulityAnswer,ifEdge,percent\0"
    "getChooseMode(TemplateMatchUi::TemplateMatchMode,bool,bool,float)\0"
    "openTemplatePicture()\0stopShowTemplPic()\0"
    "checked\0on_mulityResultCheckBox_clicked(bool)\0"
    "on_edgeModeCheckBox_clicked(bool)\0"
    "on_openTemplateButton_clicked()\0"
    "on_crossCorrlationButton_clicked(bool)\0"
    "on_absButton_clicked(bool)\0"
    "on_fftButton_clicked(bool)\0clickedOK()\0"
    "clickedCancel()\0openPictureSucceed()\0"
    "on_cancelButton_clicked()\0p\0"
    "changePercent(double)\0"
};

void TemplateMatchUi::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        TemplateMatchUi *_t = static_cast<TemplateMatchUi *>(_o);
        switch (_id) {
        case 0: _t->getChooseMode((*reinterpret_cast< TemplateMatchUi::TemplateMatchMode(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2])),(*reinterpret_cast< bool(*)>(_a[3])),(*reinterpret_cast< float(*)>(_a[4]))); break;
        case 1: _t->openTemplatePicture(); break;
        case 2: _t->stopShowTemplPic(); break;
        case 3: _t->on_mulityResultCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_edgeModeCheckBox_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_openTemplateButton_clicked(); break;
        case 6: _t->on_crossCorrlationButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_absButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 8: _t->on_fftButton_clicked((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->clickedOK(); break;
        case 10: _t->clickedCancel(); break;
        case 11: _t->openPictureSucceed(); break;
        case 12: _t->on_cancelButton_clicked(); break;
        case 13: _t->changePercent((*reinterpret_cast< double(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData TemplateMatchUi::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject TemplateMatchUi::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_TemplateMatchUi,
      qt_meta_data_TemplateMatchUi, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &TemplateMatchUi::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *TemplateMatchUi::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *TemplateMatchUi::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_TemplateMatchUi))
        return static_cast<void*>(const_cast< TemplateMatchUi*>(this));
    return QDialog::qt_metacast(_clname);
}

int TemplateMatchUi::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void TemplateMatchUi::getChooseMode(TemplateMatchUi::TemplateMatchMode _t1, bool _t2, bool _t3, float _t4)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)), const_cast<void*>(reinterpret_cast<const void*>(&_t4)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void TemplateMatchUi::openTemplatePicture()
{
    QMetaObject::activate(this, &staticMetaObject, 1, 0);
}

// SIGNAL 2
void TemplateMatchUi::stopShowTemplPic()
{
    QMetaObject::activate(this, &staticMetaObject, 2, 0);
}
QT_END_MOC_NAMESPACE
