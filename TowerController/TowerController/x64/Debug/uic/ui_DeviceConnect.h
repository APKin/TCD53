/********************************************************************************
** Form generated from reading UI file 'DeviceConnect.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONNECT_H
#define UI_DEVICECONNECT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DeviceConnectClass
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLabel *label_4;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLabel *label_5;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;

    void setupUi(QDialog *DeviceConnectClass)
    {
        if (DeviceConnectClass->objectName().isEmpty())
            DeviceConnectClass->setObjectName(QString::fromUtf8("DeviceConnectClass"));
        DeviceConnectClass->resize(600, 400);
        gridLayout_2 = new QGridLayout(DeviceConnectClass);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(DeviceConnectClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        label_4 = new QLabel(DeviceConnectClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout->addWidget(label_4);

        pushButton = new QPushButton(DeviceConnectClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(DeviceConnectClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        label_5 = new QLabel(DeviceConnectClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_2->addWidget(label_5);

        pushButton_2 = new QPushButton(DeviceConnectClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DeviceConnectClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_6 = new QLabel(DeviceConnectClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        pushButton_3 = new QPushButton(DeviceConnectClass);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_3->addWidget(pushButton_3);


        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 1, 2, 1);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_3, 0, 2, 1, 1);

        gridLayout->setColumnStretch(0, 1);
        gridLayout->setColumnStretch(1, 6);
        gridLayout->setColumnStretch(2, 1);

        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton_4 = new QPushButton(DeviceConnectClass);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_4->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(DeviceConnectClass);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_4->addWidget(pushButton_5);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        retranslateUi(DeviceConnectClass);

        QMetaObject::connectSlotsByName(DeviceConnectClass);
    } // setupUi

    void retranslateUi(QDialog *DeviceConnectClass)
    {
        DeviceConnectClass->setWindowTitle(QCoreApplication::translate("DeviceConnectClass", "DeviceConnect", nullptr));
        label->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        pushButton->setText(QCoreApplication::translate("DeviceConnectClass", "PushButton", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        label_5->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        pushButton_2->setText(QCoreApplication::translate("DeviceConnectClass", "PushButton", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("DeviceConnectClass", "TextLabel", nullptr));
        pushButton_3->setText(QCoreApplication::translate("DeviceConnectClass", "PushButton", nullptr));
        pushButton_4->setText(QCoreApplication::translate("DeviceConnectClass", "PushButton", nullptr));
        pushButton_5->setText(QCoreApplication::translate("DeviceConnectClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceConnectClass: public Ui_DeviceConnectClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONNECT_H
