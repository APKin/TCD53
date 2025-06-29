#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TowerController.h"
#include "FFmpegWidget.h"
#include <SystemSetting.h>
#include <RecordQuery.h>
#include "HelpWidget.h"
#include "StreamSetting.h"
#include "DeviceControl.h"

#include "SerialManager.h"

#include "EchoServer.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TowerControllerClass; };
QT_END_NAMESPACE

class TowerController : public QMainWindow
{
    Q_OBJECT

public:
    TowerController(QWidget *parent = nullptr);
    ~TowerController();
    // 初始化部分读取信息
    void initInfo();
private:
    Ui::TowerControllerClass *ui;
private slots:
    void on_btnRecordQuery_clicked();
    void on_btnSystenSettings_clicked();

    void on_btnStreamSetting_clicked();
    void on_btnDeviceControl_clicked();
    void on_btnHelp_clicked();
    // 启动，推流
    void on_btnStartAStop_clicked();

    void on_pushButton_7_clicked();

    // 界面告警树更新的槽函数，配合EchoSever使用
    void warnInfoUpdate(const QByteArray& data);
private:
    // 初始化
    void init();
    // 标志
    bool isStart;
    QString urls;

    // 左侧按钮界面区
    RecordQuery* rSecondWin;
    SystemSetting* sSecondWin;
    HelpWidget* helpWgt;

    DeviceControl* devWgt;
    StreamSetting* strWgt;

    // 串口使用
    SerialManager* serMan;
    // 使用串口
    QString portName;

    // echoserver端口号
    int serverPort;
    EchoServer* eServer;

};
