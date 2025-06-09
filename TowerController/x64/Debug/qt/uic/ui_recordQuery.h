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
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recordQueryClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDateEdit *dateEdit;
    QLabel *label_3;
    QDateEdit *dateEdit_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTreeView *treeView;

    void setupUi(QWidget *recordQueryClass)
    {
        if (recordQueryClass->objectName().isEmpty())
            recordQueryClass->setObjectName(QString::fromUtf8("recordQueryClass"));
        recordQueryClass->resize(600, 400);
        gridLayout = new QGridLayout(recordQueryClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(recordQueryClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        lineEdit = new QLineEdit(recordQueryClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(recordQueryClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        dateEdit = new QDateEdit(recordQueryClass);
        dateEdit->setObjectName(QString::fromUtf8("dateEdit"));

        horizontalLayout_3->addWidget(dateEdit);

        label_3 = new QLabel(recordQueryClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        dateEdit_2 = new QDateEdit(recordQueryClass);
        dateEdit_2->setObjectName(QString::fromUtf8("dateEdit_2"));

        horizontalLayout_3->addWidget(dateEdit_2);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        pushButton = new QPushButton(recordQueryClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout->addWidget(pushButton);

        pushButton_2 = new QPushButton(recordQueryClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        treeView = new QTreeView(recordQueryClass);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 3);

        retranslateUi(recordQueryClass);

        QMetaObject::connectSlotsByName(recordQueryClass);
    } // setupUi

    void retranslateUi(QWidget *recordQueryClass)
    {
        recordQueryClass->setWindowTitle(QCoreApplication::translate("recordQueryClass", "recordQuery", nullptr));
        label->setText(QCoreApplication::translate("recordQueryClass", "\345\205\263\351\224\256\350\257\215", nullptr));
        label_2->setText(QCoreApplication::translate("recordQueryClass", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("recordQueryClass", "\350\207\263", nullptr));
        pushButton->setText(QCoreApplication::translate("recordQueryClass", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("recordQueryClass", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class recordQueryClass: public Ui_recordQueryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDQUERY_H
