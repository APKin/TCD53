/********************************************************************************
** Form generated from reading UI file 'RecordQuery.ui'
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

class Ui_RecordQueryClass
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_4;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *txtKeyWord;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QDateEdit *detBegin;
    QLabel *label_3;
    QDateEdit *detEnd;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRecordQuery;
    QPushButton *pushButton_2;
    QTreeView *treeView;

    void setupUi(QWidget *RecordQueryClass)
    {
        if (RecordQueryClass->objectName().isEmpty())
            RecordQueryClass->setObjectName(QString::fromUtf8("RecordQueryClass"));
        RecordQueryClass->resize(600, 400);
        gridLayout = new QGridLayout(RecordQueryClass);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(RecordQueryClass);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        txtKeyWord = new QLineEdit(RecordQueryClass);
        txtKeyWord->setObjectName(QString::fromUtf8("txtKeyWord"));

        horizontalLayout_2->addWidget(txtKeyWord);


        horizontalLayout_4->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(RecordQueryClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        detBegin = new QDateEdit(RecordQueryClass);
        detBegin->setObjectName(QString::fromUtf8("detBegin"));

        horizontalLayout_3->addWidget(detBegin);

        label_3 = new QLabel(RecordQueryClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        detEnd = new QDateEdit(RecordQueryClass);
        detEnd->setObjectName(QString::fromUtf8("detEnd"));

        horizontalLayout_3->addWidget(detEnd);


        horizontalLayout_4->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnRecordQuery = new QPushButton(RecordQueryClass);
        btnRecordQuery->setObjectName(QString::fromUtf8("btnRecordQuery"));

        horizontalLayout->addWidget(btnRecordQuery);

        pushButton_2 = new QPushButton(RecordQueryClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout->addWidget(pushButton_2);


        horizontalLayout_4->addLayout(horizontalLayout);


        gridLayout->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        treeView = new QTreeView(RecordQueryClass);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        gridLayout->addWidget(treeView, 1, 0, 1, 1);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 3);

        retranslateUi(RecordQueryClass);

        QMetaObject::connectSlotsByName(RecordQueryClass);
    } // setupUi

    void retranslateUi(QWidget *RecordQueryClass)
    {
        RecordQueryClass->setWindowTitle(QCoreApplication::translate("RecordQueryClass", "\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        label->setText(QCoreApplication::translate("RecordQueryClass", "\345\205\263\351\224\256\350\257\215", nullptr));
        label_2->setText(QCoreApplication::translate("RecordQueryClass", "\346\227\266\351\227\264", nullptr));
        label_3->setText(QCoreApplication::translate("RecordQueryClass", "\350\207\263", nullptr));
        btnRecordQuery->setText(QCoreApplication::translate("RecordQueryClass", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("RecordQueryClass", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RecordQueryClass: public Ui_RecordQueryClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECORDQUERY_H
