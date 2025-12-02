#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TowerController.h"

#include <iostream>
#include "SystemSetting.h"
#include <RecordQuery.h>

#include "HelpWidget.h"
#include "StreamSetting.h"
#include "DeviceControl.h"
#include "ImageStore.h"
#include "SerialManager.h"
#include "Configure.h"

#include "LaserRadar.h"
#include "DataReceiveInterface.h"
#include "EchoServer.h"

#include <QHttpMultiPart>
#include <QHttpPart>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

using namespace Iray;
#include <mutex>
#include <atomic>

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>
#include <QDir>

QT_BEGIN_NAMESPACE
namespace Ui { class TowerControllerClass; };
QT_END_NAMESPACE

const double EARTH_RADIUS = 6371000.0;
const double PI_ = 3.14159265358979323846;

// 角度转弧度
double deg2rad(double deg);

// 弧度转角度
double rad2deg(double rad); 

class TowerController : public QMainWindow
{
    Q_OBJECT

public:
    TowerController(QWidget *parent = nullptr);
    ~TowerController();
    // 初始化部分读取信息
    void initInfo();
    void alarTreeUpDate(const AlarmData& alarmData);
    QJsonObject alarJson(const AlarmData& alarmData);
    QJsonObject towerStatusJson();
    //void paintEvent(QPaintEvent* e);

    void resizeEvent(QResizeEvent* event);
signals:
    void updateWidget360();

    
private:
    Ui::TowerControllerClass *ui;
private slots:
    void on_btnRecordQuery_clicked();
    void on_btnSystenSettings_clicked();

    void on_btnStreamSetting_clicked();
    void on_btnDeviceControl_clicked();
    void on_btnHelp_clicked();
    // 启动周视，关闭
    void on_btnStartAStop_clicked();

    void on_pbSaveImage_clicked();

    /*void on_pushButton_7_clicked();*/
    void on_pbLink_clicked();

    void on_pbRefresh_clicked();

    // 界面告警树更新的槽函数，配合EchoSever使用
    void warnInfoUpdate(const QByteArray& data);

    // 选择当前重点
    void on_pbMonitor1_clicked();

    void on_pbMonitor2_clicked();
    void on_pbMonitor3_clicked();
    void on_pbMonitor4_clicked();
    void on_pbMonitor5_clicked();

    //void resizeEvent(QResizeEvent* event);
private:
    std::mutex mtx_imag360;
    std::mutex mtx_Moni;
    std::mutex mtx_ala;
    std::mutex mtx_imagMain;
    std::mutex mtx_pos;
    // 初始化 红外相关
    void init();
    Configure cf;
    LaserRadar lRadar;
    
    //
    panoramaData panorData;
    AlarmData alarmData;
    unsigned int iTimeout;

    struct MPos {
        double lat;
        double lon;
        double high;
    };
    // 惯导位置
    MPos curPos_gd;
    // 计算位置
    MPos curPos_cal;

    void calculateTargetPosition(MPos RPos, double elevation, double azimuth, double distance,double& targetLon, double& targetLat, double& targetAlt);
    // 获取全景图像
    int getImageFromInfrared();
    int getAlarmDataInfrared();

    int reportTowerInfo();


    // 标志
    // 连接显示
    std::atomic_bool isLink;
    // 周扫开始
    bool isStart;
    QString urls;
    QString outUrl;

    // IPR SDK
    Iray::DataReceiveInterface* m_pDataRevInterFace;
    //DataReceiveInterface dataRecv;
    std::string dataRecvIP;

    // 左侧按钮界面区
    RecordQuery* rSecondWin;
    SystemSetting* sSecondWin;
    HelpWidget* helpWgt;

    DeviceControl* devWgt;
    StreamSetting* strWgt;

    ImageStore* iStore;
    // 串口使用
    SerialManager* serMan;
    // 使用串口
    QString portName;

    // echoserver端口号
    int serverPort;
    EchoServer* eServer;
    /*httpNetInfo httpInfo;*/

    // 图像
    QImage Image360;
    // 临时360图像
    QImage Image360_temp;
    QImage imageMain;

    QImage imageMoni;
    // 当前重点
    std::atomic_int curMoni;
    void copyToShow_main();

    // url 传输告警信息
    QNetworkRequest request;
    QNetworkAccessManager* manager;
    void sendAlaPicInfo(AlarmData alaData);

    QTimer* timer;
};
