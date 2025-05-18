/********************************************************************************
** Form generated from reading UI file 'StreamSetting.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STREAMSETTING_H
#define UI_STREAMSETTING_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_StreamSettingClass
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QLabel *label_3;
    QLineEdit *lineEdit_2;
    QLabel *label;
    QGridLayout *gridLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLabel *label_5;
    QLineEdit *lineEdit_4;
    QGridLayout *gridLayout_3;
    QLabel *label_8;
    QLineEdit *lineEdit_5;
    QLabel *label_9;
    QLineEdit *lineEdit_6;
    QLabel *label_7;
    QGridLayout *gridLayout_4;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton;
    QPushButton *pushButton_2;

    void setupUi(QDialog *StreamSettingClass)
    {
        if (StreamSettingClass->objectName().isEmpty())
            StreamSettingClass->setObjectName(QString::fromUtf8("StreamSettingClass"));
        StreamSettingClass->resize(600, 400);
        gridLayout_7 = new QGridLayout(StreamSettingClass);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_2, 0, 0, 1, 1);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(StreamSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        lineEdit = new QLineEdit(StreamSettingClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 1, 1, 1, 1);

        label_3 = new QLabel(StreamSettingClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        gridLayout->addWidget(label_3, 1, 2, 1, 1);

        lineEdit_2 = new QLineEdit(StreamSettingClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 3, 1, 1);

        label = new QLabel(StreamSettingClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        label_4 = new QLabel(StreamSettingClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 2);

        lineEdit_3 = new QLineEdit(StreamSettingClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        gridLayout_2->addWidget(lineEdit_3, 1, 1, 1, 1);

        label_6 = new QLabel(StreamSettingClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout_2->addWidget(label_6, 1, 2, 1, 1);

        label_5 = new QLabel(StreamSettingClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEdit_4 = new QLineEdit(StreamSettingClass);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));

        gridLayout_2->addWidget(lineEdit_4, 1, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_8 = new QLabel(StreamSettingClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        lineEdit_5 = new QLineEdit(StreamSettingClass);
        lineEdit_5->setObjectName(QString::fromUtf8("lineEdit_5"));

        gridLayout_3->addWidget(lineEdit_5, 1, 1, 1, 1);

        label_9 = new QLabel(StreamSettingClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout_3->addWidget(label_9, 1, 2, 1, 1);

        lineEdit_6 = new QLineEdit(StreamSettingClass);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        gridLayout_3->addWidget(lineEdit_6, 1, 3, 1, 1);

        label_7 = new QLabel(StreamSettingClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        spinBox_2 = new QSpinBox(StreamSettingClass);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));

        gridLayout_4->addWidget(spinBox_2, 1, 4, 1, 1);

        spinBox = new QSpinBox(StreamSettingClass);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));

        gridLayout_4->addWidget(spinBox, 1, 1, 1, 1);

        label_10 = new QLabel(StreamSettingClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 0, 1, 2);

        label_11 = new QLabel(StreamSettingClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        gridLayout_4->addWidget(label_11, 1, 0, 1, 1);

        label_12 = new QLabel(StreamSettingClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout_4->addWidget(label_12, 1, 3, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 3, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pushButton = new QPushButton(StreamSettingClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(StreamSettingClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        gridLayout_6->addLayout(horizontalLayout, 1, 0, 1, 3);

        gridLayout_6->setRowStretch(0, 8);
        gridLayout_6->setRowStretch(1, 1);
        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 6);
        gridLayout_6->setColumnStretch(2, 1);

        gridLayout_7->addLayout(gridLayout_6, 0, 0, 1, 1);


        retranslateUi(StreamSettingClass);

        QMetaObject::connectSlotsByName(StreamSettingClass);
    } // setupUi

    void retranslateUi(QDialog *StreamSettingClass)
    {
        StreamSettingClass->setWindowTitle(QCoreApplication::translate("StreamSettingClass", "StreamSetting", nullptr));
        label_2->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label_3->setText(QCoreApplication::translate("StreamSettingClass", "\344\270\262\346\265\201\345\257\206\351\222\245", nullptr));
        label->setText(QCoreApplication::translate("StreamSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("StreamSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\237", nullptr));
        label_6->setText(QCoreApplication::translate("StreamSettingClass", "\344\270\262\346\265\201\345\257\206\351\222\245", nullptr));
        label_5->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label_8->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label_9->setText(QCoreApplication::translate("StreamSettingClass", "\344\270\262\346\265\201\345\257\206\351\222\245", nullptr));
        label_7->setText(QCoreApplication::translate("StreamSettingClass", "\345\221\212\350\255\246\344\277\241\346\201\257", nullptr));
        label_10->setText(QCoreApplication::translate("StreamSettingClass", "\345\205\266\344\273\226\350\256\276\347\275\256", nullptr));
        label_11->setText(QCoreApplication::translate("StreamSettingClass", "\350\247\206\351\242\221\346\257\224\347\211\271\347\216\207", nullptr));
        label_12->setText(QCoreApplication::translate("StreamSettingClass", "\345\270\270\347\224\250FPS\345\200\274\357\274\210\345\270\247\347\216\207\357\274\211", nullptr));
        pushButton->setText(QCoreApplication::translate("StreamSettingClass", "PushButton", nullptr));
        pushButton_2->setText(QCoreApplication::translate("StreamSettingClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StreamSettingClass: public Ui_StreamSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMSETTING_H
