/****************************************************************************
** Meta object code from reading C++ file 'suggestionswindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../../../src/plugins/editor/suggestionswindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'suggestionswindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Editor__SuggestionsWindow_t {
    QByteArrayData data[11];
    char stringdata0[136];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Editor__SuggestionsWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Editor__SuggestionsWindow_t qt_meta_stringdata_Editor__SuggestionsWindow = {
    {
QT_MOC_LITERAL(0, 0, 25), // "Editor::SuggestionsWindow"
QT_MOC_LITERAL(1, 26, 23), // "requestHelpForAlgorithm"
QT_MOC_LITERAL(2, 50, 0), // ""
QT_MOC_LITERAL(3, 51, 7), // "package"
QT_MOC_LITERAL(4, 59, 8), // "function"
QT_MOC_LITERAL(5, 68, 18), // "acceptedSuggestion"
QT_MOC_LITERAL(6, 87, 4), // "text"
QT_MOC_LITERAL(7, 92, 6), // "hidden"
QT_MOC_LITERAL(8, 99, 19), // "handleItemActivated"
QT_MOC_LITERAL(9, 119, 5), // "index"
QT_MOC_LITERAL(10, 125, 10) // "acceptItem"

    },
    "Editor::SuggestionsWindow\0"
    "requestHelpForAlgorithm\0\0package\0"
    "function\0acceptedSuggestion\0text\0"
    "hidden\0handleItemActivated\0index\0"
    "acceptItem"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Editor__SuggestionsWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   39,    2, 0x06 /* Public */,
       5,    1,   44,    2, 0x06 /* Public */,
       7,    0,   47,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,   48,    2, 0x09 /* Protected */,
      10,    0,   51,    2, 0x09 /* Protected */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QModelIndex,    9,
    QMetaType::Void,

       0        // eod
};

void Editor::SuggestionsWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SuggestionsWindow *_t = static_cast<SuggestionsWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->requestHelpForAlgorithm((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2]))); break;
        case 1: _t->acceptedSuggestion((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 2: _t->hidden(); break;
        case 3: _t->handleItemActivated((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 4: _t->acceptItem(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (SuggestionsWindow::*_t)(const QString & , const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SuggestionsWindow::requestHelpForAlgorithm)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SuggestionsWindow::*_t)(const QString & );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SuggestionsWindow::acceptedSuggestion)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SuggestionsWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&SuggestionsWindow::hidden)) {
                *result = 2;
                return;
            }
        }
    }
}

const QMetaObject Editor::SuggestionsWindow::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Editor__SuggestionsWindow.data,
      qt_meta_data_Editor__SuggestionsWindow,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Editor::SuggestionsWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Editor::SuggestionsWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Editor__SuggestionsWindow.stringdata0))
        return static_cast<void*>(const_cast< SuggestionsWindow*>(this));
    return QWidget::qt_metacast(_clname);
}

int Editor::SuggestionsWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Editor::SuggestionsWindow::requestHelpForAlgorithm(const QString & _t1, const QString & _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Editor::SuggestionsWindow::acceptedSuggestion(const QString & _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Editor::SuggestionsWindow::hidden()
{
    QMetaObject::activate(this, &staticMetaObject, 2, Q_NULLPTR);
}
QT_END_MOC_NAMESPACE
