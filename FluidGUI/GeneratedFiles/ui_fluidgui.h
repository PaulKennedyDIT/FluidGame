/********************************************************************************
** Form generated from reading UI file 'fluidgui.ui'
**
** Created by: Qt User Interface Compiler version 5.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FLUIDGUI_H
#define UI_FLUIDGUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FluidGUIClass
{
public:

    void setupUi(QWidget *FluidGUIClass)
    {
        if (FluidGUIClass->objectName().isEmpty())
            FluidGUIClass->setObjectName(QStringLiteral("FluidGUIClass"));
        FluidGUIClass->resize(600, 400);

        retranslateUi(FluidGUIClass);

        QMetaObject::connectSlotsByName(FluidGUIClass);
    } // setupUi

    void retranslateUi(QWidget *FluidGUIClass)
    {
        FluidGUIClass->setWindowTitle(QApplication::translate("FluidGUIClass", "FluidGUI", 0));
    } // retranslateUi

};

namespace Ui {
    class FluidGUIClass: public Ui_FluidGUIClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FLUIDGUI_H
