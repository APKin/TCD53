/********************************************************************************
** Form generated from reading UI file 'DeviceControl.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEVICECONTROL_H
#define UI_DEVICECONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_DeviceControlClass
{
public:
    QGridLayout *gridLayout_5;
    QGridLayout *gridLayout_4;
    QLineEdit *leDataUpdata;
    QLabel *label_32;
    QLabel *label_25;
    QComboBox *comboBoxSeriPort;
    QLineEdit *leBT;
    QLabel *label_30;
    QPushButton *pbScanSeriPort;
    QLabel *label_31;
    QHBoxLayout *horizontalLayout;
    QLabel *label_29;
    QRadioButton *rbHight;
    QRadioButton *rbLow;
    QSpacerItem *horizontalSpacer;
    QLabel *label_27;
    QSpinBox *sbDataSite;
    QLabel *label_26;
    QSpinBox *sbStopSite;
    QLabel *label_28;
    QPushButton *pbChangePortnfo;
    QGridLayout *gridLayout;
    QLabel *label_19;
    QLabel *label_17;
    QLineEdit *leZBIP;
    QLineEdit *leRDdevPort;
    QLabel *label_20;
    QLabel *label_21;
    QComboBox *cbRDSpeed;
    QComboBox *cbRDZL;
    QLineEdit *leDstIP;
    QLabel *label_18;
    QLabel *label_16;
    QLineEdit *leRDdataPort;
    QLineEdit *leRDIP;
    QLabel *label_22;
    QComboBox *cbRDWork;
    QLabel *label_23;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_8;
    QRadioButton *cbBlack;
    QRadioButton *cbWhite;
    QPushButton *pbBWmod;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_9;
    QRadioButton *cbManual;
    QRadioButton *cbAuto0;
    QRadioButton *cbAuto1;
    QPushButton *pbAGC;
    QHBoxLayout *horizontalLayout_7;
    QLabel *label_10;
    QLineEdit *leContrast;
    QHBoxLayout *horizontalLayout_8;
    QLabel *label_11;
    QLineEdit *leLight;
    QLabel *label_24;
    QGridLayout *gridLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QLineEdit *leImg;
    QPushButton *pbImg;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *leCutL;
    QLabel *label_6;
    QLineEdit *leCutR;
    QPushButton *pbCutLR;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_4;
    QLineEdit *lineEdit_6;
    QLabel *label_12;
    QLineEdit *lineEdit_7;
    QLabel *label_13;
    QLineEdit *lineEdit_9;
    QLabel *label_14;
    QLineEdit *lineEdit_8;
    QPushButton *pbSetIp;
    QLabel *label_7;
    QLabel *label_15;
    QLabel *label;

    void setupUi(QDialog *DeviceControlClass)
    {
        if (DeviceControlClass->objectName().isEmpty())
            DeviceControlClass->setObjectName(QString::fromUtf8("DeviceControlClass"));
        DeviceControlClass->resize(672, 832);
        gridLayout_5 = new QGridLayout(DeviceControlClass);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QString::fromUtf8("gridLayout_5"));
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setSpacing(6);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        leDataUpdata = new QLineEdit(DeviceControlClass);
        leDataUpdata->setObjectName(QString::fromUtf8("leDataUpdata"));

        gridLayout_4->addWidget(leDataUpdata, 2, 6, 1, 1);

        label_32 = new QLabel(DeviceControlClass);
        label_32->setObjectName(QString::fromUtf8("label_32"));

        gridLayout_4->addWidget(label_32, 2, 7, 1, 1);

        label_25 = new QLabel(DeviceControlClass);
        label_25->setObjectName(QString::fromUtf8("label_25"));

        gridLayout_4->addWidget(label_25, 0, 0, 1, 1);

        comboBoxSeriPort = new QComboBox(DeviceControlClass);
        comboBoxSeriPort->setObjectName(QString::fromUtf8("comboBoxSeriPort"));

        gridLayout_4->addWidget(comboBoxSeriPort, 3, 2, 1, 2);

        leBT = new QLineEdit(DeviceControlClass);
        leBT->setObjectName(QString::fromUtf8("leBT"));

        gridLayout_4->addWidget(leBT, 2, 1, 1, 2);

        label_30 = new QLabel(DeviceControlClass);
        label_30->setObjectName(QString::fromUtf8("label_30"));

        gridLayout_4->addWidget(label_30, 3, 0, 1, 1);

        pbScanSeriPort = new QPushButton(DeviceControlClass);
        pbScanSeriPort->setObjectName(QString::fromUtf8("pbScanSeriPort"));

        gridLayout_4->addWidget(pbScanSeriPort, 3, 1, 1, 1);

        label_31 = new QLabel(DeviceControlClass);
        label_31->setObjectName(QString::fromUtf8("label_31"));

        gridLayout_4->addWidget(label_31, 2, 3, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label_29 = new QLabel(DeviceControlClass);
        label_29->setObjectName(QString::fromUtf8("label_29"));

        horizontalLayout->addWidget(label_29);

        rbHight = new QRadioButton(DeviceControlClass);
        rbHight->setObjectName(QString::fromUtf8("rbHight"));

        horizontalLayout->addWidget(rbHight);

        rbLow = new QRadioButton(DeviceControlClass);
        rbLow->setObjectName(QString::fromUtf8("rbLow"));

        horizontalLayout->addWidget(rbLow);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 5);

        label_27 = new QLabel(DeviceControlClass);
        label_27->setObjectName(QString::fromUtf8("label_27"));

        gridLayout_4->addWidget(label_27, 2, 0, 1, 1);

        sbDataSite = new QSpinBox(DeviceControlClass);
        sbDataSite->setObjectName(QString::fromUtf8("sbDataSite"));

        gridLayout_4->addWidget(sbDataSite, 0, 1, 1, 2);

        label_26 = new QLabel(DeviceControlClass);
        label_26->setObjectName(QString::fromUtf8("label_26"));

        gridLayout_4->addWidget(label_26, 0, 3, 1, 2);

        sbStopSite = new QSpinBox(DeviceControlClass);
        sbStopSite->setObjectName(QString::fromUtf8("sbStopSite"));

        gridLayout_4->addWidget(sbStopSite, 0, 5, 1, 1);

        label_28 = new QLabel(DeviceControlClass);
        label_28->setObjectName(QString::fromUtf8("label_28"));

        gridLayout_4->addWidget(label_28, 2, 5, 1, 1);

        pbChangePortnfo = new QPushButton(DeviceControlClass);
        pbChangePortnfo->setObjectName(QString::fromUtf8("pbChangePortnfo"));

        gridLayout_4->addWidget(pbChangePortnfo, 3, 5, 1, 1);


        gridLayout_5->addLayout(gridLayout_4, 7, 0, 1, 1);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        label_19 = new QLabel(DeviceControlClass);
        label_19->setObjectName(QString::fromUtf8("label_19"));

        gridLayout->addWidget(label_19, 2, 0, 1, 2);

        label_17 = new QLabel(DeviceControlClass);
        label_17->setObjectName(QString::fromUtf8("label_17"));

        gridLayout->addWidget(label_17, 0, 4, 1, 2);

        leZBIP = new QLineEdit(DeviceControlClass);
        leZBIP->setObjectName(QString::fromUtf8("leZBIP"));

        gridLayout->addWidget(leZBIP, 2, 2, 1, 2);

        leRDdevPort = new QLineEdit(DeviceControlClass);
        leRDdevPort->setObjectName(QString::fromUtf8("leRDdevPort"));

        gridLayout->addWidget(leRDdevPort, 0, 6, 1, 1);

        label_20 = new QLabel(DeviceControlClass);
        label_20->setObjectName(QString::fromUtf8("label_20"));

        gridLayout->addWidget(label_20, 3, 0, 1, 2);

        label_21 = new QLabel(DeviceControlClass);
        label_21->setObjectName(QString::fromUtf8("label_21"));

        gridLayout->addWidget(label_21, 4, 0, 1, 2);

        cbRDSpeed = new QComboBox(DeviceControlClass);
        cbRDSpeed->setObjectName(QString::fromUtf8("cbRDSpeed"));

        gridLayout->addWidget(cbRDSpeed, 3, 2, 1, 2);

        cbRDZL = new QComboBox(DeviceControlClass);
        cbRDZL->setObjectName(QString::fromUtf8("cbRDZL"));

        gridLayout->addWidget(cbRDZL, 4, 2, 1, 2);

        leDstIP = new QLineEdit(DeviceControlClass);
        leDstIP->setObjectName(QString::fromUtf8("leDstIP"));

        gridLayout->addWidget(leDstIP, 1, 2, 1, 2);

        label_18 = new QLabel(DeviceControlClass);
        label_18->setObjectName(QString::fromUtf8("label_18"));

        gridLayout->addWidget(label_18, 1, 0, 1, 2);

        label_16 = new QLabel(DeviceControlClass);
        label_16->setObjectName(QString::fromUtf8("label_16"));

        gridLayout->addWidget(label_16, 0, 0, 1, 2);

        leRDdataPort = new QLineEdit(DeviceControlClass);
        leRDdataPort->setObjectName(QString::fromUtf8("leRDdataPort"));

        gridLayout->addWidget(leRDdataPort, 0, 2, 1, 2);

        leRDIP = new QLineEdit(DeviceControlClass);
        leRDIP->setObjectName(QString::fromUtf8("leRDIP"));

        gridLayout->addWidget(leRDIP, 1, 6, 1, 1);

        label_22 = new QLabel(DeviceControlClass);
        label_22->setObjectName(QString::fromUtf8("label_22"));

        gridLayout->addWidget(label_22, 1, 4, 1, 2);

        cbRDWork = new QComboBox(DeviceControlClass);
        cbRDWork->setObjectName(QString::fromUtf8("cbRDWork"));

        gridLayout->addWidget(cbRDWork, 3, 6, 1, 1);

        label_23 = new QLabel(DeviceControlClass);
        label_23->setObjectName(QString::fromUtf8("label_23"));

        gridLayout->addWidget(label_23, 3, 4, 1, 2);


        gridLayout_5->addLayout(gridLayout, 5, 0, 1, 1);

        gridLayout_3 = new QGridLayout();
        gridLayout_3->setSpacing(6);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        label_8 = new QLabel(DeviceControlClass);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        horizontalLayout_5->addWidget(label_8);

        cbBlack = new QRadioButton(DeviceControlClass);
        cbBlack->setObjectName(QString::fromUtf8("cbBlack"));

        horizontalLayout_5->addWidget(cbBlack);

        cbWhite = new QRadioButton(DeviceControlClass);
        cbWhite->setObjectName(QString::fromUtf8("cbWhite"));

        horizontalLayout_5->addWidget(cbWhite);

        pbBWmod = new QPushButton(DeviceControlClass);
        pbBWmod->setObjectName(QString::fromUtf8("pbBWmod"));

        horizontalLayout_5->addWidget(pbBWmod);


        gridLayout_3->addLayout(horizontalLayout_5, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        label_9 = new QLabel(DeviceControlClass);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        horizontalLayout_6->addWidget(label_9);

        cbManual = new QRadioButton(DeviceControlClass);
        cbManual->setObjectName(QString::fromUtf8("cbManual"));

        horizontalLayout_6->addWidget(cbManual);

        cbAuto0 = new QRadioButton(DeviceControlClass);
        cbAuto0->setObjectName(QString::fromUtf8("cbAuto0"));

        horizontalLayout_6->addWidget(cbAuto0);

        cbAuto1 = new QRadioButton(DeviceControlClass);
        cbAuto1->setObjectName(QString::fromUtf8("cbAuto1"));

        horizontalLayout_6->addWidget(cbAuto1);

        pbAGC = new QPushButton(DeviceControlClass);
        pbAGC->setObjectName(QString::fromUtf8("pbAGC"));

        horizontalLayout_6->addWidget(pbAGC);


        gridLayout_3->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        label_10 = new QLabel(DeviceControlClass);
        label_10->setObjectName(QString::fromUtf8("label_10"));

        horizontalLayout_7->addWidget(label_10);

        leContrast = new QLineEdit(DeviceControlClass);
        leContrast->setObjectName(QString::fromUtf8("leContrast"));

        horizontalLayout_7->addWidget(leContrast);


        gridLayout_3->addLayout(horizontalLayout_7, 2, 0, 1, 1);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        label_11 = new QLabel(DeviceControlClass);
        label_11->setObjectName(QString::fromUtf8("label_11"));

        horizontalLayout_8->addWidget(label_11);

        leLight = new QLineEdit(DeviceControlClass);
        leLight->setObjectName(QString::fromUtf8("leLight"));

        horizontalLayout_8->addWidget(leLight);


        gridLayout_3->addLayout(horizontalLayout_8, 3, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_3, 3, 0, 1, 1);

        label_24 = new QLabel(DeviceControlClass);
        label_24->setObjectName(QString::fromUtf8("label_24"));

        gridLayout_5->addWidget(label_24, 6, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setSpacing(6);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(DeviceControlClass);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        leImg = new QLineEdit(DeviceControlClass);
        leImg->setObjectName(QString::fromUtf8("leImg"));

        horizontalLayout_4->addWidget(leImg);

        pbImg = new QPushButton(DeviceControlClass);
        pbImg->setObjectName(QString::fromUtf8("pbImg"));

        horizontalLayout_4->addWidget(pbImg);


        gridLayout_2->addLayout(horizontalLayout_4, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(DeviceControlClass);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        label_5 = new QLabel(DeviceControlClass);
        label_5->setObjectName(QString::fromUtf8("label_5"));

        horizontalLayout_3->addWidget(label_5);

        leCutL = new QLineEdit(DeviceControlClass);
        leCutL->setObjectName(QString::fromUtf8("leCutL"));

        horizontalLayout_3->addWidget(leCutL);

        label_6 = new QLabel(DeviceControlClass);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        horizontalLayout_3->addWidget(label_6);

        leCutR = new QLineEdit(DeviceControlClass);
        leCutR->setObjectName(QString::fromUtf8("leCutR"));

        horizontalLayout_3->addWidget(leCutR);

        pbCutLR = new QPushButton(DeviceControlClass);
        pbCutLR->setObjectName(QString::fromUtf8("pbCutLR"));

        horizontalLayout_3->addWidget(pbCutLR);


        gridLayout_2->addLayout(horizontalLayout_3, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_4 = new QLabel(DeviceControlClass);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_6 = new QLineEdit(DeviceControlClass);
        lineEdit_6->setObjectName(QString::fromUtf8("lineEdit_6"));

        horizontalLayout_2->addWidget(lineEdit_6);

        label_12 = new QLabel(DeviceControlClass);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        horizontalLayout_2->addWidget(label_12);

        lineEdit_7 = new QLineEdit(DeviceControlClass);
        lineEdit_7->setObjectName(QString::fromUtf8("lineEdit_7"));

        horizontalLayout_2->addWidget(lineEdit_7);

        label_13 = new QLabel(DeviceControlClass);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        horizontalLayout_2->addWidget(label_13);

        lineEdit_9 = new QLineEdit(DeviceControlClass);
        lineEdit_9->setObjectName(QString::fromUtf8("lineEdit_9"));

        horizontalLayout_2->addWidget(lineEdit_9);

        label_14 = new QLabel(DeviceControlClass);
        label_14->setObjectName(QString::fromUtf8("label_14"));

        horizontalLayout_2->addWidget(label_14);

        lineEdit_8 = new QLineEdit(DeviceControlClass);
        lineEdit_8->setObjectName(QString::fromUtf8("lineEdit_8"));

        horizontalLayout_2->addWidget(lineEdit_8);

        pbSetIp = new QPushButton(DeviceControlClass);
        pbSetIp->setObjectName(QString::fromUtf8("pbSetIp"));

        horizontalLayout_2->addWidget(pbSetIp);


        gridLayout_2->addLayout(horizontalLayout_2, 2, 0, 1, 1);


        gridLayout_5->addLayout(gridLayout_2, 1, 0, 1, 1);

        label_7 = new QLabel(DeviceControlClass);
        label_7->setObjectName(QString::fromUtf8("label_7"));

        gridLayout_5->addWidget(label_7, 2, 0, 1, 1);

        label_15 = new QLabel(DeviceControlClass);
        label_15->setObjectName(QString::fromUtf8("label_15"));

        gridLayout_5->addWidget(label_15, 4, 0, 1, 1);

        label = new QLabel(DeviceControlClass);
        label->setObjectName(QString::fromUtf8("label"));

        gridLayout_5->addWidget(label, 0, 0, 1, 1);


        retranslateUi(DeviceControlClass);

        QMetaObject::connectSlotsByName(DeviceControlClass);
    } // setupUi

    void retranslateUi(QDialog *DeviceControlClass)
    {
        DeviceControlClass->setWindowTitle(QCoreApplication::translate("DeviceControlClass", "DeviceControl", nullptr));
        label_32->setText(QCoreApplication::translate("DeviceControlClass", "Hz", nullptr));
        label_25->setText(QCoreApplication::translate("DeviceControlClass", "\346\225\260\346\215\256\344\275\215", nullptr));
        label_30->setText(QCoreApplication::translate("DeviceControlClass", "\344\270\262\345\217\243\351\200\211\346\213\251", nullptr));
        pbScanSeriPort->setText(QCoreApplication::translate("DeviceControlClass", "\346\211\253\346\217\217", nullptr));
        label_31->setText(QCoreApplication::translate("DeviceControlClass", "bps", nullptr));
        label_29->setText(QCoreApplication::translate("DeviceControlClass", "\345\255\227\350\212\202\345\211\215\345\220\216\350\256\276\347\275\256", nullptr));
        rbHight->setText(QCoreApplication::translate("DeviceControlClass", "\351\253\230\345\255\227\350\212\202\345\234\250\345\211\215", nullptr));
        rbLow->setText(QCoreApplication::translate("DeviceControlClass", "\344\275\216\345\255\227\350\212\202\345\234\250\345\220\216", nullptr));
        label_27->setText(QCoreApplication::translate("DeviceControlClass", "\346\263\242\347\211\271\347\216\207", nullptr));
        label_26->setText(QCoreApplication::translate("DeviceControlClass", "\345\201\234\346\255\242\344\275\215", nullptr));
        label_28->setText(QCoreApplication::translate("DeviceControlClass", "\346\225\260\346\215\256\346\233\264\346\226\260\351\242\221\347\216\207", nullptr));
        pbChangePortnfo->setText(QCoreApplication::translate("DeviceControlClass", "\346\233\264\346\224\271\344\270\262\345\217\243\344\277\241\346\201\257", nullptr));
        label_19->setText(QCoreApplication::translate("DeviceControlClass", "\347\273\204\346\222\255IP", nullptr));
        label_17->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\350\256\276\345\244\207\345\214\205\347\253\257\345\217\243\345\217\267", nullptr));
        label_20->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\350\275\254\351\200\237\345\200\274", nullptr));
        label_21->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\345\270\247\347\216\207\345\210\207\346\215\242", nullptr));
        label_18->setText(QCoreApplication::translate("DeviceControlClass", "\347\233\256\347\232\204IP", nullptr));
        label_16->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\346\225\260\346\215\256\345\214\205\347\253\257\345\217\243\345\217\267", nullptr));
        label_22->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276IP", nullptr));
        label_23->setText(QCoreApplication::translate("DeviceControlClass", "\351\233\267\350\276\276\345\267\245\344\275\234\347\212\266\346\200\201", nullptr));
        label_8->setText(QCoreApplication::translate("DeviceControlClass", "\351\273\221\347\231\275\347\203\255\346\250\241\345\274\217\357\274\232", nullptr));
        cbBlack->setText(QCoreApplication::translate("DeviceControlClass", "\351\273\221\347\203\255", nullptr));
        cbWhite->setText(QCoreApplication::translate("DeviceControlClass", "\347\231\275\347\203\255", nullptr));
        pbBWmod->setText(QCoreApplication::translate("DeviceControlClass", "\350\256\276\347\275\256", nullptr));
        label_9->setText(QCoreApplication::translate("DeviceControlClass", "AGC\346\250\241\345\274\217\357\274\232", nullptr));
        cbManual->setText(QCoreApplication::translate("DeviceControlClass", "\346\211\213\345\212\250", nullptr));
        cbAuto0->setText(QCoreApplication::translate("DeviceControlClass", "\350\207\252\345\212\250\350\260\203\346\225\2640", nullptr));
        cbAuto1->setText(QCoreApplication::translate("DeviceControlClass", "\350\207\252\345\212\250\350\260\203\346\225\2641", nullptr));
        pbAGC->setText(QCoreApplication::translate("DeviceControlClass", "\350\256\276\347\275\256", nullptr));
        label_10->setText(QCoreApplication::translate("DeviceControlClass", "\345\257\271\346\257\224\345\272\246\357\274\232", nullptr));
        label_11->setText(QCoreApplication::translate("DeviceControlClass", "\346\230\216\346\232\227\345\272\246\357\274\232", nullptr));
        label_24->setText(QCoreApplication::translate("DeviceControlClass", "\345\256\232\344\275\215\346\250\241\345\235\227", nullptr));
        label_2->setText(QCoreApplication::translate("DeviceControlClass", "\345\205\250\346\231\257\345\233\276\346\213\274\346\216\245\346\225\260\357\274\232", nullptr));
        pbImg->setText(QCoreApplication::translate("DeviceControlClass", "\350\256\276\347\275\256", nullptr));
        label_3->setText(QCoreApplication::translate("DeviceControlClass", "\346\213\274\346\216\245\345\267\246\345\217\263\345\211\252\345\210\207\345\210\227\346\225\260\357\274\232", nullptr));
        label_5->setText(QCoreApplication::translate("DeviceControlClass", "L:", nullptr));
        label_6->setText(QCoreApplication::translate("DeviceControlClass", "R:", nullptr));
        pbCutLR->setText(QCoreApplication::translate("DeviceControlClass", "\350\256\276\347\275\256", nullptr));
        label_4->setText(QCoreApplication::translate("DeviceControlClass", "\347\275\221\344\274\240IP\357\274\232", nullptr));
        label_12->setText(QCoreApplication::translate("DeviceControlClass", ":", nullptr));
        label_13->setText(QCoreApplication::translate("DeviceControlClass", ":", nullptr));
        label_14->setText(QCoreApplication::translate("DeviceControlClass", ":", nullptr));
        pbSetIp->setText(QCoreApplication::translate("DeviceControlClass", "\350\256\276\347\275\256", nullptr));
        label_7->setText(QCoreApplication::translate("DeviceControlClass", "\347\263\273\347\273\237\350\256\276\347\275\256", nullptr));
        label_15->setText(QCoreApplication::translate("DeviceControlClass", "\346\277\200\345\205\211\351\233\267\350\276\276", nullptr));
        label->setText(QCoreApplication::translate("DeviceControlClass", "\344\270\273\351\241\265\350\256\276\347\275\256", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DeviceControlClass: public Ui_DeviceControlClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEVICECONTROL_H
