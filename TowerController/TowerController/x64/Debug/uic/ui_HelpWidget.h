/********************************************************************************
** Form generated from reading UI file 'HelpWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HELPWIDGET_H
#define UI_HELPWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_HelpWidgetClass
{
public:

    void setupUi(QDialog *HelpWidgetClass)
    {
        if (HelpWidgetClass->objectName().isEmpty())
            HelpWidgetClass->setObjectName(QString::fromUtf8("HelpWidgetClass"));
        HelpWidgetClass->resize(600, 400);

        retranslateUi(HelpWidgetClass);

        QMetaObject::connectSlotsByName(HelpWidgetClass);
    } // setupUi

    void retranslateUi(QDialog *HelpWidgetClass)
    {
        HelpWidgetClass->setWindowTitle(QCoreApplication::translate("HelpWidgetClass", "HelpWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class HelpWidgetClass: public Ui_HelpWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HELPWIDGET_H
