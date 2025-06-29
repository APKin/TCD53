#include "TowerController.h"
#include <QMessageBox>

#include <ParkPoliceRecord.cpp>


TowerController::TowerController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TowerControllerClass())
{
    ui->setupUi(this);

    // 左侧按钮界面区
    sSecondWin = new SystemSetting(this);
    rSecondWin = new RecordQuery(this);
    helpWgt = new HelpWidget(this);

    devWgt = new DeviceControl(this);
    strWgt = new StreamSetting(this);

    serMan = new SerialManager(this);
    connect(serMan, &SerialManager::dataReceived, this, &TowerController::warnInfoUpdate);

    
    

    init();
    initInfo();

    eServer = new EchoServer(nullptr, serverPort);
    eServer->startServer();

}

TowerController::~TowerController()
{
    delete ui;

    delete rSecondWin;
    rSecondWin = nullptr;

    delete sSecondWin;
    sSecondWin = nullptr;

    delete helpWgt;
    helpWgt = nullptr;

    delete devWgt;
    devWgt = nullptr;

    delete strWgt;
    strWgt = nullptr;

    delete eServer;
    eServer = nullptr;

}
void TowerController::initInfo()
{
    // 配置信息？
    portName = "COM1";
    serMan->setPortName(portName);

    serMan->openPort();


    serverPort = 1234;
    // 忧伤角坐标显示
    ui->label_site->setText("40.446°, 116.391°12m");
    
}
// 初始化DAL
//ParkPoliceRecordDAL dal;
//记录查询按钮点击事件
void TowerController::on_btnRecordQuery_clicked()
{
    // 创建表（首次运行）
    //dal.createTable();
    
    rSecondWin->exec();
}
//系统设置按钮点击事件
void TowerController::on_btnSystenSettings_clicked() {

    sSecondWin->exec();
}

//推流设置按钮点击事件
void TowerController::on_btnStreamSetting_clicked()
{
    strWgt->exec();
}

//设备控制指令设置按钮点击事件
void TowerController::on_btnDeviceControl_clicked()
{
    devWgt->exec();
}


//帮助按钮点击事件
void TowerController::on_btnHelp_clicked()
{
    //helpWgt->exec();
    helpWgt->show(); // 非模态
}


void TowerController::on_btnStartAStop_clicked()
{
    if (isStart == true)
    {
        // 状态改为关闭
        isStart = false;    
        // 按钮图像修改
        ui->btnStartAStop->setText("关闭");
        ui->widget_6->close();
    }
    else {
        // 状态改为开启
        isStart = true;
        // 按钮图像修改
        ui->btnStartAStop->setText("开启");
        ui->widget_6->open();
    }
}

void TowerController::on_pushButton_7_clicked()
{
    //ui->widget_6->setCapPic();
    // 确认发送
    QByteArray data = "123";
    serMan->sendData(data);
}

void TowerController::warnInfoUpdate(const QByteArray& data)
{
    qDebug() << "123::" << data;
}

void TowerController::init()
{
    isStart = false;
    urls = "rtsp://127.0.0.1:8554/mystream";

    ui->widget_6->setUrl(urls);
}
