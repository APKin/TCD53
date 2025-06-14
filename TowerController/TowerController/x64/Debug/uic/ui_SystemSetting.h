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
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SystemSettingClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *txtSavePath;
    QPushButton *btnFloderSetting;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLineEdit *lineEdit_8;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QSpinBox *spinBox_2;
    QLabel *label_18;
    QLineEdit *lineEdit_9;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_20;
    QSpinBox *spinBox_3;
    QLabel *label_19;
    QLineEdit *lineEdit_10;
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *widget_2;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_8;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_9;
    QLineEdit *lineEdit;
    QLabel *label_10;
    QLineEdit *lineEdit_2;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_12;
    QLineEdit *lineEdit_4;
    QLabel *label_13;
    QLineEdit *lineEdit_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_15;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_16;
    QLineEdit *lineEdit_6;
    QLabel *label_14;
    QLineEdit *lineEdit_5;

    void setupUi(QDialog *SystemSettingClass)
    {
        if (SystemSettingClass->objectName().isEmpty())
            SystemSettingClass->setObjectName(QString::fromUtf8("SystemSettingClass"));
        SystemSettingClass->resize(600, 587);
        gridLayout = new QGridLayout(SystemSettingClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(SystemSettingClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        txtSavePath = new QLineEdit(SystemSettingClass);
        txtSavePath->setObjectName(QString::fromUtf8("txtSavePath"));

        horizontalLayout->addWidget(txtSavePath);

        btnFloderSetting = new QPushButton(SystemSettingClass);
        btnFloderSetting->setObjectName(QString::fromUtf8("btnFloderSetting"));

        horizontalLayout->addWidget(btnFloderSetting);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(SystemSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);

        verticalLayout_3->addWidget(label_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_3 = new QLabel(SystemSettingClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_2->addWidget(label_3);

        spinBox = new QSpinBox(SystemSettingClass);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        horizontalLayout_2->addWidget(spinBox);

        label_4 = new QLabel(SystemSettingClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_8 = new QLineEdit(SystemSettingClass);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_2->addWidget(lineEdit_8);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 2);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        widget_3 = new QWidget(SystemSettingClass);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        verticalLayout_2->addWidget(widget_3);

        widget_4 = new QWidget(SystemSettingClass);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        verticalLayout_2->addWidget(widget_4);


        gridLayout->addLayout(verticalLayout_2, 2, 0, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(SystemSettingClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setFont(font);

        verticalLayout_4->addWidget(label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_17 = new QLabel(SystemSettingClass);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_3->addWidget(label_17);

        spinBox_2 = new QSpinBox(SystemSettingClass);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        horizontalLayout_3->addWidget(spinBox_2);

        label_18 = new QLabel(SystemSettingClass);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_3->addWidget(label_18);

        lineEdit_9 = new QLineEdit(SystemSettingClass);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_3->addWidget(lineEdit_9);


        verticalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_20 = new QLabel(SystemSettingClass);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_4->addWidget(label_20);

        spinBox_3 = new QSpinBox(SystemSettingClass);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));

        horizontalLayout_4->addWidget(spinBox_3);

        label_19 = new QLabel(SystemSettingClass);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_4->addWidget(label_19);

        lineEdit_10 = new QLineEdit(SystemSettingClass);
        lineEdit_10->setObjectName(QString::fromUtf8("lineEdit_10"));

        horizontalLayout_4->addWidget(lineEdit_10);


        verticalLayout_4->addLayout(horizontalLayout_4);


        gridLayout->addLayout(verticalLayout_4, 3, 1, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget = new QWidget(SystemSettingClass);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(SystemSettingClass);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);


        gridLayout->addLayout(verticalLayout, 4, 0, 1, 1);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_8 = new QLabel(SystemSettingClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setFont(font);

        verticalLayout_5->addWidget(label_8);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_9 = new QLabel(SystemSettingClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_5->addWidget(label_9);

        lineEdit = new QLineEdit(SystemSettingClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_5->addWidget(lineEdit);

        label_10 = new QLabel(SystemSettingClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_5->addWidget(label_10);

        lineEdit_2 = new QLineEdit(SystemSettingClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_5->addWidget(lineEdit_2);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_8->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_11 = new QLabel(SystemSettingClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setFont(font);

        verticalLayout_6->addWidget(label_11);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_12 = new QLabel(SystemSettingClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_6->addWidget(label_12);

        lineEdit_4 = new QLineEdit(SystemSettingClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        horizontalLayout_6->addWidget(lineEdit_4);

        label_13 = new QLabel(SystemSettingClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_6->addWidget(label_13);

        lineEdit_3 = new QLineEdit(SystemSettingClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_6->addWidget(lineEdit_3);


        verticalLayout_6->addLayout(horizontalLayout_6);


        verticalLayout_8->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_15 = new QLabel(SystemSettingClass);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setFont(font);

        verticalLayout_7->addWidget(label_15);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_16 = new QLabel(SystemSettingClass);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        horizontalLayout_7->addWidget(label_16);

        lineEdit_6 = new QLineEdit(SystemSettingClass);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_7->addWidget(lineEdit_6);

        label_14 = new QLabel(SystemSettingClass);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_7->addWidget(label_14);

        lineEdit_5 = new QLineEdit(SystemSettingClass);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        horizontalLayout_7->addWidget(lineEdit_5);


        verticalLayout_7->addLayout(horizontalLayout_7);


        verticalLayout_8->addLayout(verticalLayout_7);


        gridLayout->addLayout(verticalLayout_8, 5, 0, 1, 2);


        retranslateUi(SystemSettingClass);

        QMetaObject::connectSlotsByName(SystemSettingClass);
    } // setupUi

    void retranslateUi(QDialog *SystemSettingClass)
    {
        SystemSettingClass->setWindowTitle(QCoreApplication::translate("SystemSettingClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("SystemSettingClass", "\345\233\276\345\203\217\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        btnFloderSetting->setText(QCoreApplication::translate("SystemSettingClass", "\346\265\217\350\247\210", nullptr));
        label_2->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217\344\275\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217\345\260\272\345\257\270", nullptr));
        label_5->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\237", nullptr));
        label_17->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2371\344\275\215\347\275\256", nullptr));
        label_18->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2371\345\256\275\345\272\246", nullptr));
        label_20->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2372\344\275\215\347\275\256", nullptr));
        label_19->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2372\345\256\275\345\272\246", nullptr));
        label_8->setText(QCoreApplication::translate("SystemSettingClass", "\345\221\250\350\247\206\351\233\267\350\276\276", nullptr));
        label_9->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("SystemSettingClass", "\346\277\200\345\205\211\351\233\267\350\276\276", nullptr));
        label_12->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
        label_15->setText(QCoreApplication::translate("SystemSettingClass", "\345\256\232\344\275\215\346\250\241\345\235\227", nullptr));
        label_16->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
        label_14->setText(QCoreApplication::translate("SystemSettingClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemSettingClass: public Ui_SystemSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H
