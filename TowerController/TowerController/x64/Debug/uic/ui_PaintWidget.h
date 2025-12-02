/********************************************************************************
** Form generated from reading UI file 'PaintWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAINTWIDGET_H
#define UI_PAINTWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaintWidgetClass
{
public:

    void setupUi(QWidget *PaintWidgetClass)
    {
        if (PaintWidgetClass->objectName().isEmpty())
            PaintWidgetClass->setObjectName(QString::fromUtf8("PaintWidgetClass"));
        PaintWidgetClass->resize(600, 400);

        retranslateUi(PaintWidgetClass);

        QMetaObject::connectSlotsByName(PaintWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *PaintWidgetClass)
    {
        PaintWidgetClass->setWindowTitle(QCoreApplication::translate("PaintWidgetClass", "PaintWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaintWidgetClass: public Ui_PaintWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAINTWIDGET_H
