/********************************************************************************
** Form generated from reading UI file 'CarF.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CARF_H
#define UI_CARF_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "videowindow.h"

QT_BEGIN_NAMESPACE

class Ui_CarFClass
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnImage;
    QLabel *label;
    QPushButton *btnSystem;
    QPushButton *btnOrderLog;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QWidget *widget_hb;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QWidget *widget_light;
    QVBoxLayout *verticalLayout_3;
    QLabel *label_4;
    VideoWindow *widget_gb;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_4;
    QLabel *label_5;
    QWidget *widget_4;
    QGridLayout *gridLayout_4;
    QLabel *label_10;
    QLabel *UVCoor;
    QLabel *label_13;
    QLabel *UVForw;
    QLabel *UVup;
    QLabel *UVbatt;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QLabel *label_24;
    QLabel *larLG;
    QLabel *label_23;
    QLabel *larKJG;
    QLabel *label_22;
    QLabel *larCB;
    QLabel *label_18;
    QLabel *label_21;
    QVBoxLayout *verticalLayout_5;
    QLabel *label_6;
    QWidget *widget_5;
    QGridLayout *gridLayout_5;
    QLabel *label_28;
    QLineEdit *north_cm;
    QLabel *label_29;
    QSpinBox *heading;
    QLabel *label_33;
    QLineEdit *east_cm;
    QPushButton *btnStop;
    QPushButton *btnAutoDisplay;
    QLabel *label_7;
    QWidget *widget_6;
    QGridLayout *gridLayout_6;
    QSpinBox *spinBox_ZTfx;
    QLabel *label_36;
    QSpinBox *spinBox_ZTfy;
    QPushButton *pbTurnFw;
    QSpinBox *spinBox_KF;
    QPushButton *pbKFJ;
    QLabel *label_32;
    QLabel *label_30;
    QLabel *label_31;
    QLabel *label_34;
    QLabel *label_35;
    QPushButton *pbTurnUD;
    QVBoxLayout *verticalLayout_6;
    QLabel *label_8;
    QWidget *widget_7;
    QGridLayout *gridLayout_7;
    QLabel *label_38;
    QPushButton *pbCameLightClose;
    QPushButton *pbCameLightOpen;
    QLabel *label_39;
    QLabel *label_40;
    QPushButton *pbCarmGBOpen;
    QPushButton *pushButton_13;
    QPushButton *pbKF;
    QPushButton *pbCameZBOpen;
    QPushButton *pbCameZBClose;
    QLabel *label_37;
    QPushButton *pbCarmGBClose;
    QPushButton *pushButton_10;
    QPushButton *pushButton_12;
    QSpinBox *spLight;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_9;
    QWidget *widget_8;
    QGridLayout *gridLayout_8;
    QLabel *label_43;
    QLabel *label_50;
    QSpinBox *sbLightRate1;
    QPushButton *pbLongBauoutL;
    QPushButton *pbLongBauCL;
    QPushButton *pbLightRate;
    QPushButton *pbLongBauRate;
    QLabel *label_48;
    QComboBox *cbMrad;
    QPushButton *pblightOutL1;
    QLabel *label_41;
    QSpinBox *sbLongBauRate;
    QLabel *label_49;
    QLabel *label_44;
    QPushButton *pblightCL1;
    QLabel *label_47;
    QSpinBox *sbLightRate;
    QLabel *label_42;
    QLabel *label_46;
    QPushButton *pbLightRate1;
    QPushButton *pblightCL;
    QLabel *label_45;
    QPushButton *pblightOutL;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *CarFClass)
    {
        if (CarFClass->objectName().isEmpty())
            CarFClass->setObjectName(QString::fromUtf8("CarFClass"));
        CarFClass->resize(1192, 693);
        centralWidget = new QWidget(CarFClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_2 = new QGridLayout(centralWidget);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 0, 4, 1, 1);

        btnImage = new QPushButton(centralWidget);
        btnImage->setObjectName(QString::fromUtf8("btnImage"));

        gridLayout->addWidget(btnImage, 1, 0, 1, 1);

        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout->addWidget(label, 0, 3, 1, 1);

        btnSystem = new QPushButton(centralWidget);
        btnSystem->setObjectName(QString::fromUtf8("btnSystem"));

        gridLayout->addWidget(btnSystem, 0, 0, 1, 1);

        btnOrderLog = new QPushButton(centralWidget);
        btnOrderLog->setObjectName(QString::fromUtf8("btnOrderLog"));

        gridLayout->addWidget(btnOrderLog, 0, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 0, 2, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        widget_hb = new QWidget(centralWidget);
        widget_hb->setObjectName(QString::fromUtf8("widget_hb"));

        verticalLayout->addWidget(widget_hb);

        verticalLayout->setStretch(0, 1);
        verticalLayout->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        verticalLayout_2->addWidget(label_3);

        widget_light = new QWidget(centralWidget);
        widget_light->setObjectName(QString::fromUtf8("widget_light"));

        verticalLayout_2->addWidget(widget_light);

        verticalLayout_2->setStretch(0, 1);
        verticalLayout_2->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout_2);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        verticalLayout_3->addWidget(label_4);

        widget_gb = new VideoWindow(centralWidget);
        widget_gb->setObjectName(QString::fromUtf8("widget_gb"));

        verticalLayout_3->addWidget(widget_gb);

        verticalLayout_3->setStretch(0, 1);
        verticalLayout_3->setStretch(1, 10);

        horizontalLayout->addLayout(verticalLayout_3);


        gridLayout_2->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        verticalLayout_4->addWidget(label_5);

        widget_4 = new QWidget(centralWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        gridLayout_4 = new QGridLayout(widget_4);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        label_10 = new QLabel(widget_4);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        gridLayout_4->addWidget(label_10, 0, 1, 1, 1);

        UVCoor = new QLabel(widget_4);
        UVCoor->setObjectName(QString::fromUtf8("UVCoor"));

        gridLayout_4->addWidget(UVCoor, 0, 2, 1, 1);

        label_13 = new QLabel(widget_4);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout_4->addWidget(label_13, 1, 1, 1, 1);

        UVForw = new QLabel(widget_4);
        UVForw->setObjectName(QString::fromUtf8("UVForw"));

        gridLayout_4->addWidget(UVForw, 1, 2, 1, 1);

        UVup = new QLabel(widget_4);
        UVup->setObjectName(QString::fromUtf8("UVup"));

        gridLayout_4->addWidget(UVup, 2, 2, 1, 1);

        UVbatt = new QLabel(widget_4);
        UVbatt->setObjectName(QString::fromUtf8("UVbatt"));

        gridLayout_4->addWidget(UVbatt, 3, 2, 1, 1);

        groupBox = new QGroupBox(widget_4);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        label_24 = new QLabel(groupBox);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_3->addWidget(label_24, 0, 0, 1, 1);

        larLG = new QLabel(groupBox);
        larLG->setObjectName(QString::fromUtf8("larLG"));

        gridLayout_3->addWidget(larLG, 0, 1, 1, 1);

        label_23 = new QLabel(groupBox);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout_3->addWidget(label_23, 1, 0, 1, 1);

        larKJG = new QLabel(groupBox);
        larKJG->setObjectName(QString::fromUtf8("larKJG"));

        gridLayout_3->addWidget(larKJG, 1, 1, 1, 1);

        label_22 = new QLabel(groupBox);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout_3->addWidget(label_22, 2, 0, 1, 1);

        larCB = new QLabel(groupBox);
        larCB->setObjectName(QString::fromUtf8("larCB"));

        gridLayout_3->addWidget(larCB, 2, 1, 1, 1);


        gridLayout_4->addWidget(groupBox, 4, 1, 1, 2);

        label_18 = new QLabel(widget_4);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout_4->addWidget(label_18, 2, 1, 1, 1);

        label_21 = new QLabel(widget_4);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout_4->addWidget(label_21, 3, 1, 1, 1);


        verticalLayout_4->addWidget(widget_4);

        verticalLayout_4->setStretch(1, 10);

        horizontalLayout_2->addLayout(verticalLayout_4);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        verticalLayout_5->addWidget(label_6);

        widget_5 = new QWidget(centralWidget);
        widget_5->setObjectName(QString::fromUtf8("widget_5"));
        gridLayout_5 = new QGridLayout(widget_5);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        label_28 = new QLabel(widget_5);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_5->addWidget(label_28, 0, 0, 1, 1);

        north_cm = new QLineEdit(widget_5);
        north_cm->setObjectName(QString::fromUtf8("north_cm"));

        gridLayout_5->addWidget(north_cm, 0, 3, 1, 1);

        label_29 = new QLabel(widget_5);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        gridLayout_5->addWidget(label_29, 1, 0, 1, 1);

        heading = new QSpinBox(widget_5);
        heading->setObjectName(QString::fromUtf8("heading"));

        gridLayout_5->addWidget(heading, 1, 1, 1, 2);

        label_33 = new QLabel(widget_5);
        label_33->setObjectName(QString::fromUtf8("label_33"));

        gridLayout_5->addWidget(label_33, 1, 3, 1, 1);

        east_cm = new QLineEdit(widget_5);
        east_cm->setObjectName(QString::fromUtf8("east_cm"));

        gridLayout_5->addWidget(east_cm, 0, 1, 1, 2);

        btnStop = new QPushButton(widget_5);
        btnStop->setObjectName(QString::fromUtf8("btnStop"));

        gridLayout_5->addWidget(btnStop, 2, 3, 1, 1);

        btnAutoDisplay = new QPushButton(widget_5);
        btnAutoDisplay->setObjectName(QString::fromUtf8("btnAutoDisplay"));

        gridLayout_5->addWidget(btnAutoDisplay, 2, 0, 1, 3);


        verticalLayout_5->addWidget(widget_5);

        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        verticalLayout_5->addWidget(label_7);

        widget_6 = new QWidget(centralWidget);
        widget_6->setObjectName(QString::fromUtf8("widget_6"));
        gridLayout_6 = new QGridLayout(widget_6);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QString::fromUtf8("gridLayout_6"));
        spinBox_ZTfx = new QSpinBox(widget_6);
        spinBox_ZTfx->setObjectName(QString::fromUtf8("spinBox_ZTfx"));

        gridLayout_6->addWidget(spinBox_ZTfx, 0, 1, 1, 1);

        label_36 = new QLabel(widget_6);
        label_36->setObjectName(QString::fromUtf8("label_36"));

        gridLayout_6->addWidget(label_36, 2, 2, 2, 1);

        spinBox_ZTfy = new QSpinBox(widget_6);
        spinBox_ZTfy->setObjectName(QString::fromUtf8("spinBox_ZTfy"));

        gridLayout_6->addWidget(spinBox_ZTfy, 1, 1, 1, 1);

        pbTurnFw = new QPushButton(widget_6);
        pbTurnFw->setObjectName(QString::fromUtf8("pbTurnFw"));

        gridLayout_6->addWidget(pbTurnFw, 0, 3, 1, 1);

        spinBox_KF = new QSpinBox(widget_6);
        spinBox_KF->setObjectName(QString::fromUtf8("spinBox_KF"));

        gridLayout_6->addWidget(spinBox_KF, 2, 1, 2, 1);

        pbKFJ = new QPushButton(widget_6);
        pbKFJ->setObjectName(QString::fromUtf8("pbKFJ"));

        gridLayout_6->addWidget(pbKFJ, 3, 3, 1, 1);

        label_32 = new QLabel(widget_6);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_6->addWidget(label_32, 2, 0, 2, 1);

        label_30 = new QLabel(widget_6);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_6->addWidget(label_30, 0, 0, 1, 1);

        label_31 = new QLabel(widget_6);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_6->addWidget(label_31, 1, 0, 1, 1);

        label_34 = new QLabel(widget_6);
        label_34->setObjectName(QString::fromUtf8("label_34"));

        gridLayout_6->addWidget(label_34, 0, 2, 1, 1);

        label_35 = new QLabel(widget_6);
        label_35->setObjectName(QString::fromUtf8("label_35"));

        gridLayout_6->addWidget(label_35, 1, 2, 1, 1);

        pbTurnUD = new QPushButton(widget_6);
        pbTurnUD->setObjectName(QString::fromUtf8("pbTurnUD"));

        gridLayout_6->addWidget(pbTurnUD, 1, 3, 2, 1);


        verticalLayout_5->addWidget(widget_6);

        verticalLayout_5->setStretch(0, 1);
        verticalLayout_5->setStretch(1, 4);
        verticalLayout_5->setStretch(2, 1);
        verticalLayout_5->setStretch(3, 4);

        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        verticalLayout_6->addWidget(label_8);

        widget_7 = new QWidget(centralWidget);
        widget_7->setObjectName(QString::fromUtf8("widget_7"));
        gridLayout_7 = new QGridLayout(widget_7);
        gridLayout_7->setSpacing(6);
        gridLayout_7->setContentsMargins(11, 11, 11, 11);
        gridLayout_7->setObjectName(QString::fromUtf8("gridLayout_7"));
        label_38 = new QLabel(widget_7);
        label_38->setObjectName(QString::fromUtf8("label_38"));

        gridLayout_7->addWidget(label_38, 3, 0, 1, 1);

        pbCameLightClose = new QPushButton(widget_7);
        pbCameLightClose->setObjectName(QString::fromUtf8("pbCameLightClose"));

        gridLayout_7->addWidget(pbCameLightClose, 4, 2, 1, 5);

        pbCameLightOpen = new QPushButton(widget_7);
        pbCameLightOpen->setObjectName(QString::fromUtf8("pbCameLightOpen"));

        gridLayout_7->addWidget(pbCameLightOpen, 4, 0, 1, 2);

        label_39 = new QLabel(widget_7);
        label_39->setObjectName(QString::fromUtf8("label_39"));

        gridLayout_7->addWidget(label_39, 6, 0, 1, 1);

        label_40 = new QLabel(widget_7);
        label_40->setObjectName(QString::fromUtf8("label_40"));

        gridLayout_7->addWidget(label_40, 5, 0, 1, 1);

        pbCarmGBOpen = new QPushButton(widget_7);
        pbCarmGBOpen->setObjectName(QString::fromUtf8("pbCarmGBOpen"));

        gridLayout_7->addWidget(pbCarmGBOpen, 7, 0, 1, 2);

        pushButton_13 = new QPushButton(widget_7);
        pushButton_13->setObjectName(QString::fromUtf8("pushButton_13"));

        gridLayout_7->addWidget(pushButton_13, 2, 3, 1, 4);

        pbKF = new QPushButton(widget_7);
        pbKF->setObjectName(QString::fromUtf8("pbKF"));

        gridLayout_7->addWidget(pbKF, 5, 6, 1, 1);

        pbCameZBOpen = new QPushButton(widget_7);
        pbCameZBOpen->setObjectName(QString::fromUtf8("pbCameZBOpen"));

        gridLayout_7->addWidget(pbCameZBOpen, 1, 0, 1, 1);

        pbCameZBClose = new QPushButton(widget_7);
        pbCameZBClose->setObjectName(QString::fromUtf8("pbCameZBClose"));

        gridLayout_7->addWidget(pbCameZBClose, 1, 6, 1, 1);

        label_37 = new QLabel(widget_7);
        label_37->setObjectName(QString::fromUtf8("label_37"));

        gridLayout_7->addWidget(label_37, 0, 0, 1, 1);

        pbCarmGBClose = new QPushButton(widget_7);
        pbCarmGBClose->setObjectName(QString::fromUtf8("pbCarmGBClose"));

        gridLayout_7->addWidget(pbCarmGBClose, 7, 2, 1, 5);

        pushButton_10 = new QPushButton(widget_7);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        gridLayout_7->addWidget(pushButton_10, 1, 1, 1, 4);

        pushButton_12 = new QPushButton(widget_7);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        gridLayout_7->addWidget(pushButton_12, 2, 0, 1, 3);

        spLight = new QSpinBox(widget_7);
        spLight->setObjectName(QString::fromUtf8("spLight"));

        gridLayout_7->addWidget(spLight, 5, 1, 1, 4);


        verticalLayout_6->addWidget(widget_7);

        verticalLayout_6->setStretch(0, 1);
        verticalLayout_6->setStretch(1, 10);

        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        verticalLayout_7->addWidget(label_9);

        widget_8 = new QWidget(centralWidget);
        widget_8->setObjectName(QString::fromUtf8("widget_8"));
        gridLayout_8 = new QGridLayout(widget_8);
        gridLayout_8->setSpacing(6);
        gridLayout_8->setContentsMargins(11, 11, 11, 11);
        gridLayout_8->setObjectName(QString::fromUtf8("gridLayout_8"));
        label_43 = new QLabel(widget_8);
        label_43->setObjectName(QString::fromUtf8("label_43"));

        gridLayout_8->addWidget(label_43, 1, 0, 1, 1);

        label_50 = new QLabel(widget_8);
        label_50->setObjectName(QString::fromUtf8("label_50"));

        gridLayout_8->addWidget(label_50, 6, 2, 1, 2);

        sbLightRate1 = new QSpinBox(widget_8);
        sbLightRate1->setObjectName(QString::fromUtf8("sbLightRate1"));

        gridLayout_8->addWidget(sbLightRate1, 3, 1, 1, 1);

        pbLongBauoutL = new QPushButton(widget_8);
        pbLongBauoutL->setObjectName(QString::fromUtf8("pbLongBauoutL"));

        gridLayout_8->addWidget(pbLongBauoutL, 7, 1, 1, 6);

        pbLongBauCL = new QPushButton(widget_8);
        pbLongBauCL->setObjectName(QString::fromUtf8("pbLongBauCL"));

        gridLayout_8->addWidget(pbLongBauCL, 7, 7, 1, 1);

        pbLightRate = new QPushButton(widget_8);
        pbLightRate->setObjectName(QString::fromUtf8("pbLightRate"));

        gridLayout_8->addWidget(pbLightRate, 1, 6, 1, 2);

        pbLongBauRate = new QPushButton(widget_8);
        pbLongBauRate->setObjectName(QString::fromUtf8("pbLongBauRate"));

        gridLayout_8->addWidget(pbLongBauRate, 6, 5, 1, 3);

        label_48 = new QLabel(widget_8);
        label_48->setObjectName(QString::fromUtf8("label_48"));

        gridLayout_8->addWidget(label_48, 7, 0, 1, 1);

        cbMrad = new QComboBox(widget_8);
        cbMrad->setObjectName(QString::fromUtf8("cbMrad"));

        gridLayout_8->addWidget(cbMrad, 0, 1, 1, 7);

        pblightOutL1 = new QPushButton(widget_8);
        pblightOutL1->setObjectName(QString::fromUtf8("pblightOutL1"));

        gridLayout_8->addWidget(pblightOutL1, 5, 1, 1, 6);

        label_41 = new QLabel(widget_8);
        label_41->setObjectName(QString::fromUtf8("label_41"));

        gridLayout_8->addWidget(label_41, 1, 3, 1, 3);

        sbLongBauRate = new QSpinBox(widget_8);
        sbLongBauRate->setObjectName(QString::fromUtf8("sbLongBauRate"));

        gridLayout_8->addWidget(sbLongBauRate, 6, 1, 1, 1);

        label_49 = new QLabel(widget_8);
        label_49->setObjectName(QString::fromUtf8("label_49"));

        gridLayout_8->addWidget(label_49, 3, 2, 1, 2);

        label_44 = new QLabel(widget_8);
        label_44->setObjectName(QString::fromUtf8("label_44"));

        gridLayout_8->addWidget(label_44, 2, 0, 1, 1);

        pblightCL1 = new QPushButton(widget_8);
        pblightCL1->setObjectName(QString::fromUtf8("pblightCL1"));

        gridLayout_8->addWidget(pblightCL1, 5, 7, 1, 1);

        label_47 = new QLabel(widget_8);
        label_47->setObjectName(QString::fromUtf8("label_47"));

        gridLayout_8->addWidget(label_47, 6, 0, 1, 1);

        sbLightRate = new QSpinBox(widget_8);
        sbLightRate->setObjectName(QString::fromUtf8("sbLightRate"));

        gridLayout_8->addWidget(sbLightRate, 1, 1, 1, 2);

        label_42 = new QLabel(widget_8);
        label_42->setObjectName(QString::fromUtf8("label_42"));

        gridLayout_8->addWidget(label_42, 0, 0, 1, 1);

        label_46 = new QLabel(widget_8);
        label_46->setObjectName(QString::fromUtf8("label_46"));

        gridLayout_8->addWidget(label_46, 5, 0, 1, 1);

        pbLightRate1 = new QPushButton(widget_8);
        pbLightRate1->setObjectName(QString::fromUtf8("pbLightRate1"));

        gridLayout_8->addWidget(pbLightRate1, 3, 7, 1, 1);

        pblightCL = new QPushButton(widget_8);
        pblightCL->setObjectName(QString::fromUtf8("pblightCL"));

        gridLayout_8->addWidget(pblightCL, 2, 6, 1, 2);

        label_45 = new QLabel(widget_8);
        label_45->setObjectName(QString::fromUtf8("label_45"));

        gridLayout_8->addWidget(label_45, 3, 0, 1, 1);

        pblightOutL = new QPushButton(widget_8);
        pblightOutL->setObjectName(QString::fromUtf8("pblightOutL"));

        gridLayout_8->addWidget(pblightOutL, 2, 1, 1, 1);


        verticalLayout_7->addWidget(widget_8);

        verticalLayout_7->setStretch(0, 1);
        verticalLayout_7->setStretch(1, 10);

        horizontalLayout_2->addLayout(verticalLayout_7);

        horizontalLayout_2->setStretch(0, 2);
        horizontalLayout_2->setStretch(1, 2);
        horizontalLayout_2->setStretch(2, 2);
        horizontalLayout_2->setStretch(3, 3);

        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);

        CarFClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(CarFClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1192, 22));
        CarFClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(CarFClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        CarFClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(CarFClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        CarFClass->setStatusBar(statusBar);

        retranslateUi(CarFClass);

        QMetaObject::connectSlotsByName(CarFClass);
    } // setupUi

    void retranslateUi(QMainWindow *CarFClass)
    {
        CarFClass->setWindowTitle(QCoreApplication::translate("CarFClass", "CarF", nullptr));
        btnImage->setText(QCoreApplication::translate("CarFClass", "\345\233\276\345\203\217\344\277\235\345\255\230", nullptr));
        label->setText(QCoreApplication::translate("CarFClass", "\346\227\240\344\272\272\350\275\246\346\216\247\345\210\266\347\225\214\351\235\242", nullptr));
        btnSystem->setText(QCoreApplication::translate("CarFClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        btnOrderLog->setText(QCoreApplication::translate("CarFClass", "\346\214\207\344\273\244\346\227\245\345\277\227", nullptr));
        label_2->setText(QCoreApplication::translate("CarFClass", "\344\270\255\345\244\226\347\272\242\346\263\242\345\233\276\345\203\217", nullptr));
        label_3->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\233\276\345\203\217", nullptr));
        label_4->setText(QCoreApplication::translate("CarFClass", "\345\205\211\346\226\221\346\243\200\346\265\213\345\233\276\345\203\217", nullptr));
        label_5->setText(QCoreApplication::translate("CarFClass", "\347\212\266\346\200\201\346\230\276\347\244\272\345\214\272", nullptr));
        label_10->setText(QCoreApplication::translate("CarFClass", "\346\227\240\344\272\272\350\275\246\345\235\220\346\240\207\344\275\215\347\275\256\357\274\232", nullptr));
        UVCoor->setText(QCoreApplication::translate("CarFClass", "0", nullptr));
        label_13->setText(QCoreApplication::translate("CarFClass", "\346\234\235\345\220\221\350\247\222\345\272\246\357\274\232", nullptr));
        UVForw->setText(QCoreApplication::translate("CarFClass", "0", nullptr));
        UVup->setText(QCoreApplication::translate("CarFClass", "0", nullptr));
        UVbatt->setText(QCoreApplication::translate("CarFClass", "0", nullptr));
        groupBox->setTitle(QCoreApplication::translate("CarFClass", "\346\277\200\345\205\211\345\231\250\347\212\266\346\200\201\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\350\207\264\347\233\262\357\274\232", nullptr));
        larLG->setText(QCoreApplication::translate("CarFClass", "TextLabel", nullptr));
        label_23->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\357\274\232", nullptr));
        larKJG->setText(QCoreApplication::translate("CarFClass", "TextLabel", nullptr));
        label_22->setText(QCoreApplication::translate("CarFClass", "\351\225\277\346\263\242\347\272\242\345\244\226\345\271\262\346\211\260\357\274\232", nullptr));
        larCB->setText(QCoreApplication::translate("CarFClass", "TextLabel", nullptr));
        label_18->setText(QCoreApplication::translate("CarFClass", "\350\275\254\345\217\260\346\226\271\344\275\215\344\277\257\344\273\260\357\274\232", nullptr));
        label_21->setText(QCoreApplication::translate("CarFClass", "\346\227\240\344\272\272\350\275\246\347\224\265\351\207\217\357\274\232", nullptr));
        label_6->setText(QCoreApplication::translate("CarFClass", "\346\227\240\344\272\272\350\275\246\346\216\247\345\210\266", nullptr));
        label_28->setText(QCoreApplication::translate("CarFClass", "\350\256\276\345\256\232\345\235\220\346\240\207", nullptr));
        label_29->setText(QCoreApplication::translate("CarFClass", "\350\256\276\345\256\232\346\234\235\345\220\221", nullptr));
        label_33->setText(QCoreApplication::translate("CarFClass", "\302\260", nullptr));
        btnStop->setText(QCoreApplication::translate("CarFClass", "\345\201\234\346\255\242", nullptr));
        btnAutoDisplay->setText(QCoreApplication::translate("CarFClass", "\350\207\252\345\212\250\345\211\215\350\277\233", nullptr));
        label_7->setText(QCoreApplication::translate("CarFClass", "\350\275\254\345\217\260\346\216\247\345\210\266", nullptr));
        label_36->setText(QCoreApplication::translate("CarFClass", "\302\260", nullptr));
        pbTurnFw->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        pbKFJ->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        label_32->setText(QCoreApplication::translate("CarFClass", "\345\277\253\345\217\215\351\225\234", nullptr));
        label_30->setText(QCoreApplication::translate("CarFClass", "\350\275\254\345\217\260\346\226\271\345\220\221", nullptr));
        label_31->setText(QCoreApplication::translate("CarFClass", "\350\275\254\345\217\260\344\277\257\344\273\260", nullptr));
        label_34->setText(QCoreApplication::translate("CarFClass", "\302\260", nullptr));
        label_35->setText(QCoreApplication::translate("CarFClass", "\302\260", nullptr));
        pbTurnUD->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        label_8->setText(QCoreApplication::translate("CarFClass", "\347\233\270\346\234\272\346\216\247\345\210\266", nullptr));
        label_38->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\347\233\270\346\234\272", nullptr));
        pbCameLightClose->setText(QCoreApplication::translate("CarFClass", "\345\205\263\351\227\255", nullptr));
        pbCameLightOpen->setText(QCoreApplication::translate("CarFClass", "\346\211\223\345\274\200", nullptr));
        label_39->setText(QCoreApplication::translate("CarFClass", "\345\205\211\346\226\221\346\243\200\346\265\213\347\233\270\346\234\272", nullptr));
        label_40->setText(QCoreApplication::translate("CarFClass", "\346\233\235\345\205\211", nullptr));
        pbCarmGBOpen->setText(QCoreApplication::translate("CarFClass", "\346\211\223\345\274\200", nullptr));
        pushButton_13->setText(QCoreApplication::translate("CarFClass", "\350\267\237\347\236\204\345\201\234\346\255\242", nullptr));
        pbKF->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        pbCameZBOpen->setText(QCoreApplication::translate("CarFClass", "\346\211\223\345\274\200", nullptr));
        pbCameZBClose->setText(QCoreApplication::translate("CarFClass", "\345\205\263\351\227\255", nullptr));
        label_37->setText(QCoreApplication::translate("CarFClass", "\344\270\255\346\263\242\345\244\226\347\233\270\346\234\272", nullptr));
        pbCarmGBClose->setText(QCoreApplication::translate("CarFClass", "\345\205\263\351\227\255", nullptr));
        pushButton_10->setText(QCoreApplication::translate("CarFClass", "\346\240\241\346\255\243", nullptr));
        pushButton_12->setText(QCoreApplication::translate("CarFClass", "\350\267\237\347\236\204\345\220\257\345\212\250", nullptr));
        label_9->setText(QCoreApplication::translate("CarFClass", "\346\277\200\345\205\211\345\231\250\346\216\247\345\210\266", nullptr));
        label_43->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\350\203\275\351\207\217\350\260\203\350\212\202\357\274\232", nullptr));
        label_50->setText(QCoreApplication::translate("CarFClass", "%", nullptr));
        pbLongBauoutL->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\207\272\345\205\211", nullptr));
        pbLongBauCL->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\276\205\346\234\272", nullptr));
        pbLightRate->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        pbLongBauRate->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        label_48->setText(QCoreApplication::translate("CarFClass", "\351\225\277\346\263\242\347\272\242\345\244\226\345\271\262\346\211\260\346\216\247\345\210\266\357\274\232", nullptr));
        pblightOutL1->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\207\272\345\205\211", nullptr));
        label_41->setText(QCoreApplication::translate("CarFClass", "%", nullptr));
        label_49->setText(QCoreApplication::translate("CarFClass", "%", nullptr));
        label_44->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\346\216\247\345\210\266\357\274\232", nullptr));
        pblightCL1->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\276\205\346\234\272", nullptr));
        label_47->setText(QCoreApplication::translate("CarFClass", "\351\225\277\346\263\242\347\272\242\345\244\226\345\271\262\346\211\260\350\203\275\351\207\217\350\260\203\350\212\202\357\274\232", nullptr));
        label_42->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\217\221\346\225\243\350\247\222\345\210\207\346\215\242\357\274\232", nullptr));
        label_46->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\350\207\264\347\233\262\346\216\247\345\210\266\357\274\232", nullptr));
        pbLightRate1->setText(QCoreApplication::translate("CarFClass", "\347\241\256\345\256\232", nullptr));
        pblightCL->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\276\205\346\234\272", nullptr));
        label_45->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\350\207\264\347\233\262\350\203\275\351\207\217\350\260\203\350\212\202\357\274\232", nullptr));
        pblightOutL->setText(QCoreApplication::translate("CarFClass", "\345\217\257\350\247\201\345\205\211\345\271\262\346\211\260\345\207\272\345\205\211", nullptr));
    } // retranslateUi

};

namespace Ui {
    class CarFClass: public Ui_CarFClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CARF_H
