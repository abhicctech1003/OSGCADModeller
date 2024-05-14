/********************************************************************************
** Form generated from reading UI file 'OSGCADModeller.ui'
**
** Created by: Qt User Interface Compiler version 6.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OSGCADMODELLER_H
#define UI_OSGCADMODELLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OSGCADModellerClass
{
public:

    void setupUi(QWidget *OSGCADModellerClass)
    {
        if (OSGCADModellerClass->objectName().isEmpty())
            OSGCADModellerClass->setObjectName("OSGCADModellerClass");
        OSGCADModellerClass->resize(600, 400);

        retranslateUi(OSGCADModellerClass);

        QMetaObject::connectSlotsByName(OSGCADModellerClass);
    } // setupUi

    void retranslateUi(QWidget *OSGCADModellerClass)
    {
        OSGCADModellerClass->setWindowTitle(QCoreApplication::translate("OSGCADModellerClass", "OSGCADModeller", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OSGCADModellerClass: public Ui_OSGCADModellerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OSGCADMODELLER_H
