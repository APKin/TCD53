/********************************************************************************
** Form generated from reading UI file 'recordQuery.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECORDQUERY_H
#define UI_RECORDQUERY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordQueryClass
{
public:

    void setupUi(QWidget *recordQueryClass)
    {
        if (recordQueryClass->objectName().isEmpty())
            recordQueryClass->setObjectName(QString::fromUtf8("recordQueryClass"));
        recordQueryClass->resize(600, 400);

        retranslateUi(recordQueryClass);

        QMetaObject::connectSlotsByName(recordQueryClass);
    } // setupUi

    void retranslateUi(QWidget *recordQueryClass)
    {
        recordQueryClass->setWindowTitle(QCoreApplication::translate("recordQueryClass", "recordQuery", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recordQueryClass: public Ui_recordQueryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDQUERY_H
