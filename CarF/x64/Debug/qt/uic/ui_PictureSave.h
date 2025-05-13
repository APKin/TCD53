/********************************************************************************
** Form generated from reading UI file 'PictureSave.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PICTURESAVE_H
#define UI_PICTURESAVE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_PictureSaveClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_5;
    QLabel *label;
    QLineEdit *lineEdit;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_6;
    QLabel *label_2;
    QLineEdit *lineEdit_2;
    QSpacerItem *horizontalSpacer_3;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_7;
    QLabel *label_3;
    QLineEdit *lineEdit_3;
    QSpacerItem *horizontalSpacer_4;

    void setupUi(QDialog *PictureSaveClass)
    {
        if (PictureSaveClass->objectName().isEmpty())
            PictureSaveClass->setObjectName(QString::fromUtf8("PictureSaveClass"));
        PictureSaveClass->resize(600, 345);
        gridLayout = new QGridLayout(PictureSaveClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pushButton = new QPushButton(PictureSaveClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_4->addWidget(pushButton);

        pushButton_2 = new QPushButton(PictureSaveClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_4->addWidget(pushButton_2);


        gridLayout->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_5);

        label = new QLabel(PictureSaveClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEdit = new QLineEdit(PictureSaveClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout->addWidget(lineEdit);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 1);
        horizontalLayout->setStretch(2, 5);
        horizontalLayout->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_6);

        label_2 = new QLabel(PictureSaveClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        lineEdit_2 = new QLineEdit(PictureSaveClass);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        horizontalLayout_2->setStretch(0, 1);
        horizontalLayout_2->setStretch(1, 1);
        horizontalLayout_2->setStretch(2, 5);
        horizontalLayout_2->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_7);

        label_3 = new QLabel(PictureSaveClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        lineEdit_3 = new QLineEdit(PictureSaveClass);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));

        horizontalLayout_3->addWidget(lineEdit_3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        horizontalLayout_3->setStretch(0, 1);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 5);
        horizontalLayout_3->setStretch(3, 1);

        verticalLayout->addLayout(horizontalLayout_3);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        gridLayout->setRowStretch(0, 5);

        retranslateUi(PictureSaveClass);

        QMetaObject::connectSlotsByName(PictureSaveClass);
    } // setupUi

    void retranslateUi(QDialog *PictureSaveClass)
    {
        PictureSaveClass->setWindowTitle(QCoreApplication::translate("PictureSaveClass", "PictureSave", nullptr));
        pushButton->setText(QCoreApplication::translate("PictureSaveClass", "\345\217\226\346\266\210", nullptr));
        pushButton_2->setText(QCoreApplication::translate("PictureSaveClass", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("PictureSaveClass", "\344\270\255\346\263\242\347\272\242\345\244\226\345\233\276\345\203\217", nullptr));
        label_2->setText(QCoreApplication::translate("PictureSaveClass", "\345\217\257\350\247\201\345\205\211\345\233\276\345\203\217  ", nullptr));
        label_3->setText(QCoreApplication::translate("PictureSaveClass", "\345\205\211\346\226\221\346\243\200\346\265\213\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PictureSaveClass: public Ui_PictureSaveClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PICTURESAVE_H
