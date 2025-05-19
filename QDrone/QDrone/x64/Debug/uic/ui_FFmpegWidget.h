/********************************************************************************
** Form generated from reading UI file 'FFmpegWidget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FFMPEGWIDGET_H
#define UI_FFMPEGWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FFmpegWidgetClass
{
public:

    void setupUi(QWidget *FFmpegWidgetClass)
    {
        if (FFmpegWidgetClass->objectName().isEmpty())
            FFmpegWidgetClass->setObjectName(QString::fromUtf8("FFmpegWidgetClass"));
        FFmpegWidgetClass->resize(600, 400);

        retranslateUi(FFmpegWidgetClass);

        QMetaObject::connectSlotsByName(FFmpegWidgetClass);
    } // setupUi

    void retranslateUi(QWidget *FFmpegWidgetClass)
    {
        FFmpegWidgetClass->setWindowTitle(QCoreApplication::translate("FFmpegWidgetClass", "FFmpegWidget", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FFmpegWidgetClass: public Ui_FFmpegWidgetClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FFMPEGWIDGET_H
