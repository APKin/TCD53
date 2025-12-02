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
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include <draggablelabel.h>
#include <paintwidget.h>
#include "anglescalebar.h"

QT_BEGIN_NAMESPACE

class Ui_TowerControllerClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QGridLayout *gridLayout_6;
    QLabel *labelRadarInfo;
    QSpacerItem *horizontalSpacer_9;
    QWidget *widget3D;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pbSaveImage;
    QPushButton *pbLink;
    QPushButton *pbRefresh;
    QPushButton *btnStartAStop;
    QSpacerItem *horizontalSpacer_12;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_devstatus;
    QLabel *labelRadar;
    QLabel *labelLight1;
    QLabel *labelLocal;
    QLabel *labelNet;
    QGridLayout *gridLayout_8;
    QLabel *labelMoni;
    QSpacerItem *horizontalSpacer_11;
    PaintWidget *widget_moni;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QSpacerItem *horizontalSpacer;
    QPushButton *pbMonitor1;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *pbMonitor2;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pbMonitor3;
    QSpacerItem *horizontalSpacer_4;
    QPushButton *pbMonitor4;
    QSpacerItem *horizontalSpacer_5;
    QPushButton *pbMonitor5;
    QSpacerItem *horizontalSpacer_6;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QGridLayout *gridLayout_4;
    QLabel *label360Pic;
    QSpacerItem *horizontalSpacer_7;
    AngleScaleBar *widget;
    PaintWidget *widget360;
    DraggableLabel *mainView;
    DraggableLabel *monitorView1;
    DraggableLabel *monitorView2;
    DraggableLabel *monitorView3;
    DraggableLabel *monitorView4;
    DraggableLabel *monitorView5;
    QGridLayout *gridLayout_5;
    QLabel *labelMain;
    QSpacerItem *horizontalSpacer_8;
    PaintWidget *widget_main;
    QGridLayout *gridLayout_7;
    QLabel *labelWarn;
    QSpacerItem *horizontalSpacer_10;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout_6;
    QWidget *widgetTitle;
    QHBoxLayout *horizontalLayout_7;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnRecordQuery;
    QPushButton *btnSystenSettings;
    QPushButton *btnStreamSetting;
    QPushButton *btnDeviceControl;
    QPushButton *btnHelp;
    QLabel *label_title;
    QLabel *label_site;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TowerControllerClass)
    {
        if (TowerControllerClass->objectName().isEmpty())
            TowerControllerClass->setObjectName(QString::fromUtf8("TowerControllerClass"));
        TowerControllerClass->resize(1251, 798);
        centralWidget = new QWidget(TowerControllerClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setSpacing(6);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        labelRadarInfo = new QLabel(centralWidget);
        labelRadarInfo->setObjectName(QString::fromUtf8("labelRadarInfo"));

        gridLayout_6->addWidget(labelRadarInfo, 0, 0, 1, 1);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_6->addItem(horizontalSpacer_9, 0, 1, 1, 1);

        widget3D = new QWidget(centralWidget);
        widget3D->setObjectName(QString::fromUtf8("widget3D"));

        gridLayout_6->addWidget(widget3D, 1, 0, 1, 2);

        gridLayout_6->setRowStretch(0, 1);
        gridLayout_6->setRowStretch(1, 4);
        gridLayout_6->setColumnStretch(0, 1);
        gridLayout_6->setColumnStretch(1, 1);

        gridLayout->addLayout(gridLayout_6, 4, 1, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pbSaveImage = new QPushButton(centralWidget);
        pbSaveImage->setObjectName(QString::fromUtf8("pbSaveImage"));

        horizontalLayout_2->addWidget(pbSaveImage);

        pbLink = new QPushButton(centralWidget);
        pbLink->setObjectName(QString::fromUtf8("pbLink"));

        horizontalLayout_2->addWidget(pbLink);

        pbRefresh = new QPushButton(centralWidget);
        pbRefresh->setObjectName(QString::fromUtf8("pbRefresh"));

        horizontalLayout_2->addWidget(pbRefresh);

        btnStartAStop = new QPushButton(centralWidget);
        btnStartAStop->setObjectName(QString::fromUtf8("btnStartAStop"));

        horizontalLayout_2->addWidget(btnStartAStop);


        horizontalLayout->addLayout(horizontalLayout_2);

        horizontalSpacer_12 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_12);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_devstatus = new QLabel(centralWidget);
        label_devstatus->setObjectName(QString::fromUtf8("label_devstatus"));

        horizontalLayout_3->addWidget(label_devstatus);

        labelRadar = new QLabel(centralWidget);
        labelRadar->setObjectName(QString::fromUtf8("labelRadar"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelRadar->sizePolicy().hasHeightForWidth());
        labelRadar->setSizePolicy(sizePolicy);
        labelRadar->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(labelRadar, 0, Qt::AlignVCenter);

        labelLight1 = new QLabel(centralWidget);
        labelLight1->setObjectName(QString::fromUtf8("labelLight1"));
        sizePolicy.setHeightForWidth(labelLight1->sizePolicy().hasHeightForWidth());
        labelLight1->setSizePolicy(sizePolicy);
        labelLight1->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(labelLight1, 0, Qt::AlignVCenter);

        labelLocal = new QLabel(centralWidget);
        labelLocal->setObjectName(QString::fromUtf8("labelLocal"));
        sizePolicy.setHeightForWidth(labelLocal->sizePolicy().hasHeightForWidth());
        labelLocal->setSizePolicy(sizePolicy);
        labelLocal->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(labelLocal, 0, Qt::AlignVCenter);

        labelNet = new QLabel(centralWidget);
        labelNet->setObjectName(QString::fromUtf8("labelNet"));
        sizePolicy.setHeightForWidth(labelNet->sizePolicy().hasHeightForWidth());
        labelNet->setSizePolicy(sizePolicy);
        labelNet->setMinimumSize(QSize(16, 16));

        horizontalLayout_3->addWidget(labelNet, 0, Qt::AlignVCenter);

        horizontalLayout_3->setStretch(0, 3);
        horizontalLayout_3->setStretch(1, 1);
        horizontalLayout_3->setStretch(2, 1);
        horizontalLayout_3->setStretch(3, 1);
        horizontalLayout_3->setStretch(4, 1);

        horizontalLayout->addLayout(horizontalLayout_3);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 5);
        horizontalLayout->setStretch(2, 1);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 3);

        gridLayout_8 = new QGridLayout();
        gridLayout_8->setSpacing(6);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        labelMoni = new QLabel(centralWidget);
        labelMoni->setObjectName(QString::fromUtf8("labelMoni"));

        gridLayout_8->addWidget(labelMoni, 0, 0, 1, 1);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_8->addItem(horizontalSpacer_11, 0, 1, 1, 1);

        widget_moni = new PaintWidget(centralWidget);
        widget_moni->setObjectName(QString::fromUtf8("widget_moni"));
        gridLayout_3 = new QGridLayout(widget_moni);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        pbMonitor1 = new QPushButton(widget_moni);
        pbMonitor1->setObjectName(QString::fromUtf8("pbMonitor1"));

        horizontalLayout_4->addWidget(pbMonitor1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);

        pbMonitor2 = new QPushButton(widget_moni);
        pbMonitor2->setObjectName(QString::fromUtf8("pbMonitor2"));

        horizontalLayout_4->addWidget(pbMonitor2);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_3);

        pbMonitor3 = new QPushButton(widget_moni);
        pbMonitor3->setObjectName(QString::fromUtf8("pbMonitor3"));

        horizontalLayout_4->addWidget(pbMonitor3);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_4);

        pbMonitor4 = new QPushButton(widget_moni);
        pbMonitor4->setObjectName(QString::fromUtf8("pbMonitor4"));

        horizontalLayout_4->addWidget(pbMonitor4);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);

        pbMonitor5 = new QPushButton(widget_moni);
        pbMonitor5->setObjectName(QString::fromUtf8("pbMonitor5"));

        horizontalLayout_4->addWidget(pbMonitor5);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_6);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 2);
        horizontalLayout_4->setStretch(2, 1);
        horizontalLayout_4->setStretch(3, 2);
        horizontalLayout_4->setStretch(4, 1);
        horizontalLayout_4->setStretch(5, 2);
        horizontalLayout_4->setStretch(6, 1);
        horizontalLayout_4->setStretch(7, 2);
        horizontalLayout_4->setStretch(8, 1);
        horizontalLayout_4->setStretch(9, 2);
        horizontalLayout_4->setStretch(10, 5);

        gridLayout_3->addLayout(horizontalLayout_4, 1, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 57, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer, 0, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 56, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_3->addItem(verticalSpacer_2, 2, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 5);
        gridLayout_3->setRowStretch(1, 2);
        gridLayout_3->setRowStretch(2, 1);

        gridLayout_8->addWidget(widget_moni, 1, 0, 1, 2);

        gridLayout_8->setRowStretch(0, 1);
        gridLayout_8->setRowStretch(1, 4);
        gridLayout_8->setColumnStretch(0, 1);
        gridLayout_8->setColumnStretch(1, 1);

        gridLayout->addLayout(gridLayout_8, 4, 0, 1, 1);

        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label360Pic = new QLabel(centralWidget);
        label360Pic->setObjectName(QString::fromUtf8("label360Pic"));

        gridLayout_4->addWidget(label360Pic, 0, 0, 1, 1);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_4->addItem(horizontalSpacer_7, 0, 1, 1, 1);

        widget = new AngleScaleBar(centralWidget);
        widget->setObjectName(QString::fromUtf8("widget"));

        gridLayout_4->addWidget(widget, 1, 0, 1, 2);

        widget360 = new PaintWidget(centralWidget);
        widget360->setObjectName(QString::fromUtf8("widget360"));
        mainView = new DraggableLabel(widget360);
        mainView->setObjectName(QString::fromUtf8("mainView"));
        mainView->setGeometry(QRect(33, 20, 101, 71));
        monitorView1 = new DraggableLabel(widget360);
        monitorView1->setObjectName(QString::fromUtf8("monitorView1"));
        monitorView1->setGeometry(QRect(150, 20, 101, 71));
        monitorView2 = new DraggableLabel(widget360);
        monitorView2->setObjectName(QString::fromUtf8("monitorView2"));
        monitorView2->setGeometry(QRect(300, 30, 101, 71));
        monitorView3 = new DraggableLabel(widget360);
        monitorView3->setObjectName(QString::fromUtf8("monitorView3"));
        monitorView3->setGeometry(QRect(430, 30, 101, 71));
        monitorView4 = new DraggableLabel(widget360);
        monitorView4->setObjectName(QString::fromUtf8("monitorView4"));
        monitorView4->setGeometry(QRect(540, 30, 101, 71));
        monitorView5 = new DraggableLabel(widget360);
        monitorView5->setObjectName(QString::fromUtf8("monitorView5"));
        monitorView5->setGeometry(QRect(670, 30, 101, 71));

        gridLayout_4->addWidget(widget360, 2, 0, 1, 2);

        gridLayout_4->setRowStretch(0, 2);
        gridLayout_4->setRowStretch(1, 1);
        gridLayout_4->setRowStretch(2, 8);
        gridLayout_4->setColumnStretch(0, 1);
        gridLayout_4->setColumnStretch(1, 4);

        gridLayout->addLayout(gridLayout_4, 2, 0, 1, 3);

        gridLayout_5 = new QGridLayout();
        gridLayout_5->setSpacing(6);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        labelMain = new QLabel(centralWidget);
        labelMain->setObjectName(QString::fromUtf8("labelMain"));

        gridLayout_5->addWidget(labelMain, 0, 0, 1, 1);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_5->addItem(horizontalSpacer_8, 0, 1, 1, 1);

        widget_main = new PaintWidget(centralWidget);
        widget_main->setObjectName(QString::fromUtf8("widget_main"));

        gridLayout_5->addWidget(widget_main, 1, 0, 1, 2);

        gridLayout_5->setRowStretch(0, 1);
        gridLayout_5->setRowStretch(1, 4);
        gridLayout_5->setColumnStretch(0, 1);
        gridLayout_5->setColumnStretch(1, 4);

        gridLayout->addLayout(gridLayout_5, 3, 0, 1, 3);

        gridLayout_7 = new QGridLayout();
        gridLayout_7->setSpacing(6);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        labelWarn = new QLabel(centralWidget);
        labelWarn->setObjectName(QString::fromUtf8("labelWarn"));

        gridLayout_7->addWidget(labelWarn, 0, 0, 1, 1);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_7->addItem(horizontalSpacer_10, 0, 1, 1, 1);

        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        gridLayout_7->addWidget(tableWidget, 1, 0, 1, 2);

        gridLayout_7->setRowStretch(0, 1);
        gridLayout_7->setRowStretch(1, 4);
        gridLayout_7->setColumnStretch(0, 1);
        gridLayout_7->setColumnStretch(1, 1);

        gridLayout->addLayout(gridLayout_7, 4, 2, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        widgetTitle = new QWidget(centralWidget);
        widgetTitle->setObjectName(QString::fromUtf8("widgetTitle"));
        horizontalLayout_7 = new QHBoxLayout(widgetTitle);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        btnRecordQuery = new QPushButton(widgetTitle);
        btnRecordQuery->setObjectName(QString::fromUtf8("btnRecordQuery"));

        horizontalLayout_5->addWidget(btnRecordQuery);

        btnSystenSettings = new QPushButton(widgetTitle);
        btnSystenSettings->setObjectName(QString::fromUtf8("btnSystenSettings"));

        horizontalLayout_5->addWidget(btnSystenSettings);

        btnStreamSetting = new QPushButton(widgetTitle);
        btnStreamSetting->setObjectName(QString::fromUtf8("btnStreamSetting"));

        horizontalLayout_5->addWidget(btnStreamSetting);

        btnDeviceControl = new QPushButton(widgetTitle);
        btnDeviceControl->setObjectName(QString::fromUtf8("btnDeviceControl"));

        horizontalLayout_5->addWidget(btnDeviceControl);

        btnHelp = new QPushButton(widgetTitle);
        btnHelp->setObjectName(QString::fromUtf8("btnHelp"));

        horizontalLayout_5->addWidget(btnHelp);


        horizontalLayout_7->addLayout(horizontalLayout_5);

        label_title = new QLabel(widgetTitle);
        label_title->setObjectName(QString::fromUtf8("label_title"));

        horizontalLayout_7->addWidget(label_title, 0, Qt::AlignHCenter|Qt::AlignVCenter);

        label_site = new QLabel(widgetTitle);
        label_site->setObjectName(QString::fromUtf8("label_site"));

        horizontalLayout_7->addWidget(label_site, 0, Qt::AlignRight);

        horizontalLayout_7->setStretch(0, 1);
        horizontalLayout_7->setStretch(1, 1);
        horizontalLayout_7->setStretch(2, 1);

        horizontalLayout_6->addWidget(widgetTitle);


        gridLayout->addLayout(horizontalLayout_6, 0, 0, 1, 3);

        gridLayout->setRowStretch(0, 1);
        gridLayout->setRowStretch(1, 1);
        gridLayout->setRowStretch(2, 4);
        gridLayout->setRowStretch(3, 4);
        gridLayout->setRowStretch(4, 4);
        TowerControllerClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(TowerControllerClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1251, 22));
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
        labelRadarInfo->setText(QString());
        pbSaveImage->setText(QCoreApplication::translate("TowerControllerClass", "\344\277\235\345\255\230\345\233\276\345\203\217", nullptr));
        pbLink->setText(QCoreApplication::translate("TowerControllerClass", "\350\277\236\346\216\245", nullptr));
        pbRefresh->setText(QCoreApplication::translate("TowerControllerClass", "\345\210\267\346\226\260", nullptr));
        btnStartAStop->setText(QCoreApplication::translate("TowerControllerClass", "\345\274\200\345\205\263", nullptr));
        label_devstatus->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\276\345\244\207\350\277\236\346\216\245\347\212\266\346\200\201\357\274\232", nullptr));
        labelRadar->setText(QString());
        labelLight1->setText(QString());
        labelLocal->setText(QString());
        labelNet->setText(QString());
        labelMoni->setText(QString());
        pbMonitor1->setText(QCoreApplication::translate("TowerControllerClass", "1", nullptr));
        pbMonitor2->setText(QCoreApplication::translate("TowerControllerClass", "2", nullptr));
        pbMonitor3->setText(QCoreApplication::translate("TowerControllerClass", "3", nullptr));
        pbMonitor4->setText(QCoreApplication::translate("TowerControllerClass", "4", nullptr));
        pbMonitor5->setText(QCoreApplication::translate("TowerControllerClass", "5", nullptr));
        label360Pic->setText(QString());
        mainView->setText(QCoreApplication::translate("TowerControllerClass", "\344\270\273\350\247\206\350\247\222\345\233\276\345\203\217", nullptr));
        monitorView1->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\350\247\206\350\247\2221", nullptr));
        monitorView2->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\350\247\206\350\247\2222", nullptr));
        monitorView3->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\350\247\206\350\247\2223", nullptr));
        monitorView4->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\350\247\206\350\247\2224", nullptr));
        monitorView5->setText(QCoreApplication::translate("TowerControllerClass", "\351\207\215\347\202\271\347\233\221\350\247\206\350\247\206\350\247\2225", nullptr));
        labelMain->setText(QString());
        labelWarn->setText(QString());
        btnRecordQuery->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\260\345\275\225\346\237\245\350\257\242", nullptr));
        btnSystenSettings->setText(QCoreApplication::translate("TowerControllerClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnStreamSetting->setText(QCoreApplication::translate("TowerControllerClass", "\346\216\250\346\265\201\350\256\276\347\275\256", nullptr));
        btnDeviceControl->setText(QCoreApplication::translate("TowerControllerClass", "\350\256\276\345\244\207\346\216\247\345\210\266\346\214\207\344\273\244\350\256\276\347\275\256", nullptr));
        btnHelp->setText(QCoreApplication::translate("TowerControllerClass", "\345\270\256\345\212\251", nullptr));
        label_title->setText(QCoreApplication::translate("TowerControllerClass", "\345\221\250\346\211\253\350\256\276\345\244\207\346\216\247\345\210\266\347\225\214\351\235\242", nullptr));
        label_site->setText(QCoreApplication::translate("TowerControllerClass", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TowerControllerClass: public Ui_TowerControllerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TOWERCONTROLLER_H
