/********************************************************************************
** Form generated from reading UI file 'TowerController.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TOWERCONTROLLER_H
#define UI_TOWERCONTROLLER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <ffmpegwidget.h>
#include "anglescalebar.h"

QT_BEGIN_NAMESPACE

class Ui_TowerControllerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnRecordQuery;
    QPushButton *btnSystenSettings;
    QPushButton *btnStreamSetting;
    QPushButton *btnDeviceControl;
    QPushButton *btnHelp;
    QLabel *label;
    QLabel *label_site;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *btnStartAStop;
    QLabel *label_9;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_14;
    QLabel *label_13;
    QLabel *label_12;
    QLabel *label_11;
    QLabel *label_10;
    QVBoxLayout *verticalLayout;
    QLabel *label_6;
    QWidget *widget_3;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_3;
    AngleScaleBar *widget;
    FFmpegWidget *widget_6;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_8;
    QTreeView *treeView;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_7;
    QWidget *widget_4;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QWidget *widget_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TowerControllerClass)
    {
        if (TowerControllerClass->objectName().isEmpty())
            TowerControllerClass->setObjectName(QString::fromUtf8("TowerControllerClass"));
        TowerControllerClass->resize(1189, 798);
        centralWidget = new QWidget(TowerControllerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnRecordQuery = new QPushButton(centralWidget);
        btnRecordQuery->setObjectName(QString::fromUtf8("btnRecordQuery"));

        horizontalLayout->addWidget(btnRecordQuery);

        btnSystenSettings = new QPushButton(centralWidget);
        btnSystenSettings->setObjectName(QString::fromUtf8("btnSystenSettings"));

        horizontalLayout->addWidget(btnSystenSettings);

        btnStreamSetting = new QPushButton(centralWidget);
        btnStreamSetting->setObjectName(QString::fromUtf8("btnStreamSetting"));

        horizontalLayout->addWidget(btnStreamSetting);

        btnDeviceControl = new QPushButton(centralWidget);
        btnDeviceControl->setObjectName(QString::fromUtf8("btnDeviceControl"));

        horizontalLayout->addWidget(btnDeviceControl);

        btnHelp = new QPushButton(centralWidget);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));

        horizontalLayout->addWidget(btnHelp);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 3);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        label_site = new QLabel(centralWidget);
        label_site->setObjectName(QString::fromUtf8("label_site"));

        gridLayout->addWidget(label_site, 0, 4, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_2->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_2->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_2->addWidget(pushButton_8);

        btnStartAStop = new QPushButton(centralWidget);
        btnStartAStop->setObjectName(QString::fromUtf8("btnStartAStop"));

        horizontalLayout_2->addWidget(btnStartAStop);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_3->addWidget(label_4);

        label_14 = new QLabel(centralWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_3->addWidget(label_14);

        label_13 = new QLabel(centralWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_3->addWidget(label_13);

        label_12 = new QLabel(centralWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_3->addWidget(label_12);

        label_11 = new QLabel(centralWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_3->addWidget(label_11);

        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_3->addWidget(label_10);


        gridLayout->addLayout(horizontalLayout_3, 1, 2, 1, 3);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 3);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout->addWidget(label_6);

        widget_3 = new QWidget(centralWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));

        verticalLayout->addWidget(widget_3);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 5);

        gridLayout_2->addLayout(verticalLayout, 3, 0, 1, 1);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_5->addWidget(label_3);

        widget = new AngleScaleBar(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        verticalLayout_5->addWidget(widget);

        widget_6 = new FFmpegWidget(centralWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));

        verticalLayout_5->addWidget(widget_6);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 1);
        verticalLayout_5->setStretch(2, 4);

        gridLayout_2->addLayout(verticalLayout_5, 1, 0, 1, 3);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_3->addWidget(label_8);

        treeView = new QTreeView(centralWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        verticalLayout_3->addWidget(treeView);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 5);

        gridLayout_2->addLayout(verticalLayout_3, 3, 2, 1, 1);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_2->addWidget(label_7);

        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));

        verticalLayout_2->addWidget(widget_4);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 5);

        gridLayout_2->addLayout(verticalLayout_2, 3, 1, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        widget_2 = new QWidget(centralWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout_4->addWidget(widget_2);

        verticalLayout_4->setStretch(0, 1);
        verticalLayout_4->setStretch(1, 6);

        gridLayout_2->addLayout(verticalLayout_4, 2, 0, 1, 3);

        gridLayout_2->setColumnStretch(0, 1);
        gridLayout_2->setColumnStretch(1, 1);
        gridLayout_2->setColumnStretch(2, 1);
        TowerControllerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TowerControllerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1189, 22));
        TowerControllerClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(TowerControllerClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        TowerControllerClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(TowerControllerClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TowerControllerClass->setStatusBar(statusBar);

        retranslateUi(TowerControllerClass);

        QMetaObject::connectSlotsByName(TowerControllerClass);
    } // setupUi

    void retranslateUi(QMainWindow *TowerControllerClass)
    {
        TowerControllerClass->setWindowTitle(QCoreApplication::translate("TowerControllerClass", "TowerController", nullptr));
        btnRecordQuery->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        btnSystenSettings->setText(QCoreApplication::translate("TowerControllerClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnStreamSetting->setText(QCoreApplication::translate("TowerControllerClass", "\346\216\250\346\265\201\350\256\276\347\275\256", nullptr));
        btnDeviceControl->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\276\345\244\207\346\216\247\345\210\266\346\214\207\344\273\244\350\256\276\347\275\256", nullptr));
        btnHelp->setText(QCoreApplication::translate("TowerControllerClass", "\345\270\256\345\212\251", nullptr));
        label->setText(QCoreApplication::translate("TowerControllerClass", "\345\221\250\346\211\253\350\256\276\345\244\207\346\216\247\345\210\266\347\225\214\351\235\242", nullptr));
        label_site->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        pushButton_6->setText(QCoreApplication::translate("TowerControllerClass", "\344\277\235\345\255\230", nullptr));
        pushButton_7->setText(QCoreApplication::translate("TowerControllerClass", "PushButton", nullptr));
        pushButton_8->setText(QCoreApplication::translate("TowerControllerClass", "\345\210\267\346\226\260", nullptr));
        btnStartAStop->setText(QCoreApplication::translate("TowerControllerClass", "\345\274\200\345\205\263", nullptr));
        label_9->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_4->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\276\345\244\207\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        label_14->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_13->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_12->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_11->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_10->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
        label_6->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\345\214\272\345\237\237", nullptr));
        label_3->setText(QCoreApplication::translate("TowerControllerClass", "\347\272\242\345\244\226\345\221\250\350\247\206\351\233\267\350\276\276360\302\260\347\216\257\350\247\206\345\233\276\345\203\217", nullptr));
        label_8->setText(QCoreApplication::translate("TowerControllerClass", "\345\221\212\350\255\246\344\277\241\346\201\257", nullptr));
        label_7->setText(QCoreApplication::translate("TowerControllerClass", "\351\233\267\350\276\276\344\277\241\346\201\257", nullptr));
        label_5->setText(QCoreApplication::translate("TowerControllerClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TowerControllerClass: public Ui_TowerControllerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOWERCONTROLLER_H
