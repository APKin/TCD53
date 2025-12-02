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
#include <QtWidgets/QFormLayout>
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
    QVBoxLayout *verticalLayout;
    QWidget *widget;
    QWidget *widget_2;
    QFormLayout *formLayout;
    QLabel *label_5;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_17;
    QSpinBox *spViewsite1;
    QLabel *label_18;
    QLineEdit *leViewwidth1;
    QPushButton *pbPlus;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_20;
    QSpinBox *spViewsite2;
    QLabel *label_19;
    QLineEdit *leViewwidth2;
    QPushButton *pbReduce;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_21;
    QSpinBox *spViewsite3;
    QLabel *label_22;
    QLineEdit *leViewwidth3;
    QHBoxLayout *horizontalLayout_9;
    QLabel *label_23;
    QSpinBox *spViewsite4;
    QLabel *label_24;
    QLineEdit *leViewwidth4;
    QHBoxLayout *horizontalLayout_10;
    QLabel *label_25;
    QSpinBox *spViewsite5;
    QLabel *label_26;
    QLineEdit *leViewwidth5;
    QVBoxLayout *verticalLayout_2;
    QWidget *widget_3;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_3;
    QSpinBox *spinBox;
    QLabel *label_4;
    QLineEdit *mainViewHeigh;

    void setupUi(QDialog *SystemSettingClass)
    {
        if (SystemSettingClass->objectName().isEmpty())
            SystemSettingClass->setObjectName(QString::fromUtf8("SystemSettingClass"));
        SystemSettingClass->resize(632, 636);
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


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

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

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        label_5 = new QLabel(SystemSettingClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QFont font;
        font.setPointSize(10);
        font.setBold(true);
        font.setWeight(75);
        label_5->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, label_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_17 = new QLabel(SystemSettingClass);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        horizontalLayout_3->addWidget(label_17);

        spViewsite1 = new QSpinBox(SystemSettingClass);
        spViewsite1->setObjectName(QString::fromUtf8("spViewsite1"));

        horizontalLayout_3->addWidget(spViewsite1);

        label_18 = new QLabel(SystemSettingClass);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        horizontalLayout_3->addWidget(label_18);

        leViewwidth1 = new QLineEdit(SystemSettingClass);
        leViewwidth1->setObjectName(QString::fromUtf8("leViewwidth1"));

        horizontalLayout_3->addWidget(leViewwidth1);

        pbPlus = new QPushButton(SystemSettingClass);
        pbPlus->setObjectName(QString::fromUtf8("pbPlus"));

        horizontalLayout_3->addWidget(pbPlus);


        formLayout->setLayout(1, QFormLayout::LabelRole, horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_20 = new QLabel(SystemSettingClass);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        horizontalLayout_4->addWidget(label_20);

        spViewsite2 = new QSpinBox(SystemSettingClass);
        spViewsite2->setObjectName(QString::fromUtf8("spViewsite2"));

        horizontalLayout_4->addWidget(spViewsite2);

        label_19 = new QLabel(SystemSettingClass);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        horizontalLayout_4->addWidget(label_19);

        leViewwidth2 = new QLineEdit(SystemSettingClass);
        leViewwidth2->setObjectName(QString::fromUtf8("leViewwidth2"));

        horizontalLayout_4->addWidget(leViewwidth2);

        pbReduce = new QPushButton(SystemSettingClass);
        pbReduce->setObjectName(QString::fromUtf8("pbReduce"));

        horizontalLayout_4->addWidget(pbReduce);


        formLayout->setLayout(2, QFormLayout::LabelRole, horizontalLayout_4);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_21 = new QLabel(SystemSettingClass);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        horizontalLayout_8->addWidget(label_21);

        spViewsite3 = new QSpinBox(SystemSettingClass);
        spViewsite3->setObjectName(QString::fromUtf8("spViewsite3"));

        horizontalLayout_8->addWidget(spViewsite3);

        label_22 = new QLabel(SystemSettingClass);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        horizontalLayout_8->addWidget(label_22);

        leViewwidth3 = new QLineEdit(SystemSettingClass);
        leViewwidth3->setObjectName(QString::fromUtf8("leViewwidth3"));

        horizontalLayout_8->addWidget(leViewwidth3);


        formLayout->setLayout(3, QFormLayout::LabelRole, horizontalLayout_8);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        label_23 = new QLabel(SystemSettingClass);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        horizontalLayout_9->addWidget(label_23);

        spViewsite4 = new QSpinBox(SystemSettingClass);
        spViewsite4->setObjectName(QString::fromUtf8("spViewsite4"));

        horizontalLayout_9->addWidget(spViewsite4);

        label_24 = new QLabel(SystemSettingClass);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        horizontalLayout_9->addWidget(label_24);

        leViewwidth4 = new QLineEdit(SystemSettingClass);
        leViewwidth4->setObjectName(QString::fromUtf8("leViewwidth4"));

        horizontalLayout_9->addWidget(leViewwidth4);


        formLayout->setLayout(4, QFormLayout::LabelRole, horizontalLayout_9);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        label_25 = new QLabel(SystemSettingClass);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        horizontalLayout_10->addWidget(label_25);

        spViewsite5 = new QSpinBox(SystemSettingClass);
        spViewsite5->setObjectName(QString::fromUtf8("spViewsite5"));

        horizontalLayout_10->addWidget(spViewsite5);

        label_26 = new QLabel(SystemSettingClass);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        horizontalLayout_10->addWidget(label_26);

        leViewwidth5 = new QLineEdit(SystemSettingClass);
        leViewwidth5->setObjectName(QString::fromUtf8("leViewwidth5"));

        horizontalLayout_10->addWidget(leViewwidth5);


        formLayout->setLayout(5, QFormLayout::LabelRole, horizontalLayout_10);


        gridLayout->addLayout(formLayout, 3, 0, 1, 1);

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

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_2 = new QLabel(SystemSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
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

        mainViewHeigh = new QLineEdit(SystemSettingClass);
        mainViewHeigh->setObjectName(QString::fromUtf8("mainViewHeigh"));

        horizontalLayout_2->addWidget(mainViewHeigh);


        verticalLayout_3->addLayout(horizontalLayout_2);


        gridLayout->addLayout(verticalLayout_3, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 1);
        gridLayout->setRowStretch(3, 4);
        gridLayout->setRowStretch(4, 1);

        retranslateUi(SystemSettingClass);

        QMetaObject::connectSlotsByName(SystemSettingClass);
    } // setupUi

    void retranslateUi(QDialog *SystemSettingClass)
    {
        SystemSettingClass->setWindowTitle(QCoreApplication::translate("SystemSettingClass", "SystemSetting", nullptr));
        label->setText(QCoreApplication::translate("SystemSettingClass", "\345\233\276\345\203\217\345\255\230\345\202\250\350\267\257\345\276\204", nullptr));
        btnFloderSetting->setText(QCoreApplication::translate("SystemSettingClass", "\346\265\217\350\247\210", nullptr));
        label_5->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\237", nullptr));
        label_17->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2371\344\275\215\347\275\256", nullptr));
        label_18->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2371\345\256\275\345\272\246", nullptr));
        pbPlus->setText(QCoreApplication::translate("SystemSettingClass", "+", nullptr));
        label_20->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2372\344\275\215\347\275\256", nullptr));
        label_19->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2372\345\256\275\345\272\246", nullptr));
        pbReduce->setText(QCoreApplication::translate("SystemSettingClass", "-", nullptr));
        label_21->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2373\344\275\215\347\275\256", nullptr));
        label_22->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2373\345\256\275\345\272\246", nullptr));
        label_23->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2374\344\275\215\347\275\256", nullptr));
        label_24->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2374\345\256\275\345\272\246", nullptr));
        label_25->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2375\344\275\215\347\275\256", nullptr));
        label_26->setText(QCoreApplication::translate("SystemSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\2375\345\256\275\345\272\246", nullptr));
        label_2->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217\344\275\215\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("SystemSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217\345\260\272\345\257\270", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SystemSettingClass: public Ui_SystemSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SYSTEMSETTING_H
