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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_SystemSettingClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *SystemSettingClass)
    {
        if (SystemSettingClass->objectName().isEmpty())
            SystemSettingClass->setObjectName(QString::fromUtf8("SystemSettingClass"));
        SystemSettingClass->resize(406, 278);
        gridLayout = new QGridLayout(SystemSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        label = new QLabel(SystemSettingClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(SystemSettingClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);

        pushButton_3 = new QPushButton(SystemSettingClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        pushButton = new QPushButton(SystemSettingClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(SystemSettingClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 6);
        gridLayout->setRowStretch(1, 4);

        retranslateUi(SystemSettingClass);

        QMetaObject::connectSlotsByName(SystemSettingClass);
    } // setupUi

    void retranslateUi(QDialog *SystemSettingClass)
    {
        SystemSettingClass->setWindowTitle(QCoreApplication::translate("SystemSettingClass", "SystemSetting", nullptr));
        label->setText(QCoreApplication::translate("SystemSettingClass", "\345\233\276\345\203\217\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        pushButton_3->setText(QCoreApplication::translate("SystemSettingClass", "\346\265\217\350\247\210", nullptr));
        pushButton->setText(QCoreApplication::translate("SystemSettingClass", "\345\217\226\346\266\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("SystemSettingClass", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemSettingClass: public Ui_SystemSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H
