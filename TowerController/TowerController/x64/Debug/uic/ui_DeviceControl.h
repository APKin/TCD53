/********************************************************************************
** Form generated from reading UI file 'DeviceControl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONTROL_H
#define UI_DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>

QT_BEGIN_NAMESPACE

class Ui_DeviceControlClass
{
public:
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_5;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_9;
    QPushButton *pushButton_8;

    void setupUi(QDialog *DeviceControlClass)
    {
        if (DeviceControlClass->objectName().isEmpty())
            DeviceControlClass->setObjectName(QString::fromUtf8("DeviceControlClass"));
        DeviceControlClass->resize(450, 260);
        gridLayout_2 = new QGridLayout(DeviceControlClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(10);
        gridLayout->setVerticalSpacing(30);
        pushButton = new QPushButton(DeviceControlClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(DeviceControlClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_3 = new QPushButton(DeviceControlClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_4 = new QPushButton(DeviceControlClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 3, 1, 1);

        pushButton_6 = new QPushButton(DeviceControlClass);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(DeviceControlClass);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_5 = new QPushButton(DeviceControlClass);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 3, 1, 1);

        lineEdit = new QLineEdit(DeviceControlClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 0, 1, 4);

        lineEdit_2 = new QLineEdit(DeviceControlClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 3, 0, 1, 4);


        horizontalLayout_2->addLayout(gridLayout);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 6);
        horizontalLayout_2->setStretch(2, 1);

        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton_9 = new QPushButton(DeviceControlClass);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout->addWidget(pushButton_9);

        pushButton_8 = new QPushButton(DeviceControlClass);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout->addWidget(pushButton_8);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        gridLayout_2->setRowStretch(0, 5);
        gridLayout_2->setRowStretch(1, 1);
        gridLayout_2->setRowMinimumHeight(0, 1);

        retranslateUi(DeviceControlClass);

        QMetaObject::connectSlotsByName(DeviceControlClass);
    } // setupUi

    void retranslateUi(QDialog *DeviceControlClass)
    {
        DeviceControlClass->setWindowTitle(QCoreApplication::translate("DeviceControlClass", "DeviceControl", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceControlClass", "\347\233\270\346\234\272\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeviceControlClass", "\350\275\254\345\217\260\351\200\237\345\272\246", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\345\217\202\346\225\260\350\256\276\347\275\256", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DeviceControlClass", "\345\272\224\347\224\250\346\233\264\346\224\271", nullptr));
        pushButton_6->setText(QCoreApplication::translate("DeviceControlClass", "0\345\272\246\346\240\241\345\207\206", nullptr));
        pushButton_7->setText(QCoreApplication::translate("DeviceControlClass", "\344\275\215\345\247\277\346\233\264\346\226\260", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DeviceControlClass", "5Ga\346\216\245\345\205\245", nullptr));
        pushButton_9->setText(QCoreApplication::translate("DeviceControlClass", "\345\217\226\346\266\210", nullptr));
        pushButton_8->setText(QCoreApplication::translate("DeviceControlClass", "\347\241\256\345\256\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceControlClass: public Ui_DeviceControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONTROL_H
