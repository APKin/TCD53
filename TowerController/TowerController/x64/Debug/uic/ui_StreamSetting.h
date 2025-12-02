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

QT_BEGIN_NAMESPACE

class Ui_StreamSettingClass
{
public:
    QGridLayout *gridLayout_7;
    QGridLayout *gridLayout_6;
    QSpacerItem *horizontalSpacer_2;
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_2;
    QLineEdit *leMoiView;
    QLabel *label_4;
    QLabel *label_5;
    QGridLayout *gridLayout_3;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *leWarnInfo;
    QGridLayout *gridLayout;
    QLabel *label_2;
    QLineEdit *leMainView;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbSure;
    QPushButton *pbCan;

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
        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        leMoiView = new QLineEdit(StreamSettingClass);
        leMoiView->setObjectName(QString::fromUtf8("leMoiView"));

        gridLayout_2->addWidget(leMoiView, 1, 1, 1, 1);

        label_4 = new QLabel(StreamSettingClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        gridLayout_2->addWidget(label_4, 0, 0, 1, 2);

        label_5 = new QLabel(StreamSettingClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_7 = new QLabel(StreamSettingClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_3->addWidget(label_7, 0, 0, 1, 2);

        label_8 = new QLabel(StreamSettingClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout_3->addWidget(label_8, 1, 0, 1, 1);

        leWarnInfo = new QLineEdit(StreamSettingClass);
        leWarnInfo->setObjectName(QString::fromUtf8("leWarnInfo"));

        gridLayout_3->addWidget(leWarnInfo, 1, 1, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 2, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_2 = new QLabel(StreamSettingClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        leMainView = new QLineEdit(StreamSettingClass);
        leMainView->setObjectName(QString::fromUtf8("leMainView"));

        gridLayout->addWidget(leMainView, 1, 1, 1, 1);

        label = new QLabel(StreamSettingClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 0, 1, 2);


        gridLayout_5->addLayout(gridLayout, 0, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_5, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer, 0, 2, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        pbSure = new QPushButton(StreamSettingClass);
        pbSure->setObjectName(QString::fromUtf8("pbSure"));

        horizontalLayout->addWidget(pbSure);

        pbCan = new QPushButton(StreamSettingClass);
        pbCan->setObjectName(QString::fromUtf8("pbCan"));

        horizontalLayout->addWidget(pbCan);


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
        label_4->setText(QCoreApplication::translate("StreamSettingClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\237", nullptr));
        label_5->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label_7->setText(QCoreApplication::translate("StreamSettingClass", "\345\221\212\350\255\246\344\277\241\346\201\257", nullptr));
        label_8->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label_2->setText(QCoreApplication::translate("StreamSettingClass", "\346\234\215\345\212\241\345\231\250", nullptr));
        label->setText(QCoreApplication::translate("StreamSettingClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
        pbSure->setText(QCoreApplication::translate("StreamSettingClass", "\347\241\256\345\256\232", nullptr));
        pbCan->setText(QCoreApplication::translate("StreamSettingClass", "\345\217\226\346\266\210", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StreamSettingClass: public Ui_StreamSettingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STREAMSETTING_H
