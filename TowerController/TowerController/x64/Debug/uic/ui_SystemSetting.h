/********************************************************************************
** Form generated from reading UI file 'SystemSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SYSTEMSETTING_H
#define UI_SYSTEMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_SystemSettingClass
{
public:

    void setupUi(QDialog *SystemSettingClass)
    {
        if (SystemSettingClass->objectName().isEmpty())
            SystemSettingClass->setObjectName(QString::fromUtf8("SystemSettingClass"));
        SystemSettingClass->resize(600, 400);

        retranslateUi(SystemSettingClass);

        QMetaObject::connectSlotsByName(SystemSettingClass);
    } // setupUi

    void retranslateUi(QDialog *SystemSettingClass)
    {
        SystemSettingClass->setWindowTitle(QCoreApplication::translate("SystemSettingClass", "SystemSetting", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemSettingClass: public Ui_SystemSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H
