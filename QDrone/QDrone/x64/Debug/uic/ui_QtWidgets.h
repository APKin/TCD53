/********************************************************************************
** Form generated from reading UI file 'QtWidgets.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTWIDGETS_H
#define UI_QTWIDGETS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtWidgetsClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtWidgetsClass)
    {
        if (QtWidgetsClass->objectName().isEmpty())
            QtWidgetsClass->setObjectName(QString::fromUtf8("QtWidgetsClass"));
        QtWidgetsClass->resize(600, 400);
        menuBar = new QMenuBar(QtWidgetsClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        QtWidgetsClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtWidgetsClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        QtWidgetsClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtWidgetsClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        QtWidgetsClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtWidgetsClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        QtWidgetsClass->setStatusBar(statusBar);

        retranslateUi(QtWidgetsClass);

        QMetaObject::connectSlotsByName(QtWidgetsClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtWidgetsClass)
    {
        QtWidgetsClass->setWindowTitle(QCoreApplication::translate("QtWidgetsClass", "QtWidgets", nullptr));
    } // retranslateUi

};

namespace Ui {
    class QtWidgetsClass: public Ui_QtWidgetsClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTWIDGETS_H
