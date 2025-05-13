/********************************************************************************
** Form generated from reading UI file 'OrderLog.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ORDERLOG_H
#define UI_ORDERLOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_OrderLogClass
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QTableView *tableView;
    QLineEdit *lineEdit;

    void setupUi(QWidget *OrderLogClass)
    {
        if (OrderLogClass->objectName().isEmpty())
            OrderLogClass->setObjectName(QString::fromUtf8("OrderLogClass"));
        OrderLogClass->resize(600, 400);
        label = new QLabel(OrderLogClass);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(50, 30, 54, 12));
        label_2 = new QLabel(OrderLogClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(240, 30, 54, 12));
        pushButton = new QPushButton(OrderLogClass);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(430, 30, 75, 23));
        pushButton_2 = new QPushButton(OrderLogClass);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(520, 30, 75, 23));
        tableView = new QTableView(OrderLogClass);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(60, 100, 501, 251));
        lineEdit = new QLineEdit(OrderLogClass);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 30, 113, 20));

        retranslateUi(OrderLogClass);

        QMetaObject::connectSlotsByName(OrderLogClass);
    } // setupUi

    void retranslateUi(QWidget *OrderLogClass)
    {
        OrderLogClass->setWindowTitle(QCoreApplication::translate("OrderLogClass", "OrderLog", nullptr));
        label->setText(QCoreApplication::translate("OrderLogClass", "\345\205\263\351\224\256\350\257\215", nullptr));
        label_2->setText(QCoreApplication::translate("OrderLogClass", "\346\227\266\351\227\264", nullptr));
        pushButton->setText(QCoreApplication::translate("OrderLogClass", "\346\220\234\347\264\242", nullptr));
        pushButton_2->setText(QCoreApplication::translate("OrderLogClass", "\351\207\215\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OrderLogClass: public Ui_OrderLogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ORDERLOG_H
