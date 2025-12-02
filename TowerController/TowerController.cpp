#include "TowerController.h"
#include <QMessageBox>
#include <thread>
//#include <ParkPoliceRecord.cpp>
#include <QtEndian>
#include <QBuffer>
#include <QStandardItemModel>

static uint32_t swapManual(uint32_t value) {
    return ((value & 0x000000FF) << 24) |
        ((value & 0x0000FF00) << 8) |
        ((value & 0x00FF0000) >> 8) |
        ((value & 0xFF000000) >> 24);
}

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

    iStore = new ImageStore(this);

    m_pDataRevInterFace = new Iray::DataReceiveInterface();
    connect(serMan, &SerialManager::dataReceived, this, &TowerController::warnInfoUpdate);

    connect(devWgt, &DeviceControl::portInfoChanged, serMan, &SerialManager::isResetPortInf0);


    init();
    initInfo();


    connect(sSecondWin, &SystemSetting::plusMoni, [=](int index) {
        if (index == 3)
        {
            ui->monitorView3->show();
            ui->pbMonitor3->setDisabled(false);
        }
        else if(index == 4)
        {
            ui->monitorView4->show();
            ui->pbMonitor4->setDisabled(false);
        }
        else if(index == 5)
        {
            ui->monitorView5->show();
            ui->pbMonitor5->setDisabled(false);
        }

    });

    connect(sSecondWin, &SystemSetting::reduceMoni, [=](int index) {
        if (index == 3)
        {
            ui->monitorView3->hide();
            ui->pbMonitor3->setDisabled(true);
        }
        else if (index == 4)
        {
            ui->monitorView4->hide();
            ui->pbMonitor4->setDisabled(true);
        }
        else if (index == 5)
        {
            ui->monitorView5->hide();
            ui->pbMonitor5->setDisabled(true);
        }
    });


    connect(this, &TowerController::updateWidget360, [&]() {
        this->update(); });

    /*connect(ui->widget360, &FFmpegWidget::receiveImage, this, [=](const QImage& image) {
        this->Image360 = image;
    });*/
    eServer = new EchoServer(nullptr, serverPort);
    eServer->startServer();
    eServer->connectRemote(cf.getRemoteIP(), cf.getRemotePort());



    // lRadar

    connect(devWgt, &DeviceControl::laserRadarCommand, this, [&](int id,QString command) {
        switch (id)
        {
        case 0: {
            std::string InfoString;
            lRadar.setDataPort(command.toInt(), InfoString);
        }break;

        case 1: {
            std::string InfoString;
            lRadar.setDevPort(command.toInt(), InfoString);
        }break;
        case 2: {
            std::string InfoString;
            lRadar.setComputerIP(command.toStdString(), InfoString);
        }break;
        case 3: {
            std::string InfoString;
            lRadar.setLidarIP(command.toStdString(), InfoString);
        }break;
        case 4: {
            std::string InfoString;
            //lRadar.setDataPort(command.toInt(), InfoString);
        }break;
        case 5: {
            std::string InfoString;
            lRadar.setLidarRotateSpeed(command.toInt(), InfoString);
        }break;
        case 6: {
            std::string InfoString;
            lRadar.setLidarWorkState(command.toInt(), InfoString);
        }break;
        case 7: {
            std::string InfoString;
            lRadar.setFrameRateMode(command.toInt(), InfoString);
        }break;
        default:
            break;
        }
        });
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
    
    // 断开
    if (isStart)
    {
        m_pDataRevInterFace->disconnectFromHost(dataRecvIP);
        delete m_pDataRevInterFace;
    }
    // 关闭串口
    serMan->closePort();

}
void TowerController::initInfo()
{
    // COM8 为周扫惯导设备 高字节在前，低字节在后-大端
    portName = cf.getGrName();
    serMan->setPortName(portName);

    serMan->openPort();

    serverPort = 1234;
    //// http 服务器管理
    //httpInfo.setUrl(cf.getInfraredUrl());
    devWgt->setUrl(cf.getInfraredUrl());
    // 右上角坐标显示
    ui->label_site->setText(u8"40.446°, 116.391°12m");

    // 默认为1
    curMoni = 1;
    // 初始化 6个视角宽度
    int height = ui->widget360->height();
    int width = ui->widget360->width();
    int gap_label = width / 6;

    ui->mainView->resize(height, height);
    ui->monitorView1->resize(height, height);
    ui->monitorView2->resize(height, height);
    ui->monitorView3->resize(height, height);
    ui->monitorView4->resize(height, height);
    ui->monitorView5->resize(height, height);

    ui->mainView->move(ui->widget360->pos());
    ui->monitorView1->move(ui->widget360->pos().x() + gap_label * 1, ui->widget360->pos().y());
    ui->monitorView2->move(ui->widget360->pos().x() + gap_label * 2, ui->widget360->pos().y());
    ui->monitorView3->move(ui->widget360->pos().x() + gap_label * 3, ui->widget360->pos().y());
    ui->monitorView4->move(ui->widget360->pos().x() + gap_label * 4, ui->widget360->pos().y());
    ui->monitorView5->move(ui->widget360->pos().x() + gap_label * 5, ui->widget360->pos().y());

    // 默认只开前两个重点监视,按钮同

    ui->monitorView3->hide();
    ui->monitorView4->hide();
    ui->monitorView5->hide();

    ui->pbMonitor3->setDisabled(true);
    ui->pbMonitor4->setDisabled(true);
    ui->pbMonitor5->setDisabled(true);

    //ui->widget360->setStyleSheet("background-color: black;");
    QStringList head;
    head << u8"目标" << u8"方向" << u8"俯仰" << u8"距离" << u8"时间";
    ui->tableWidget->setColumnCount(head.size());
    ui->tableWidget->setHorizontalHeaderLabels(head);
    
}
void TowerController::alarTreeUpDate(const AlarmData& alarmData)
{
    int countTarget = alarmData.vecTargetData.size();
    QString time = QString("%1_%2_%3 %4:%5:%6").arg(alarmData.alarmTime.year).arg(alarmData.alarmTime.month).arg(alarmData.alarmTime.day).arg(alarmData.alarmTime.hour).arg(alarmData.alarmTime.minute).arg(alarmData.alarmTime.second);;
    for (int i = 0; i < countTarget; i++)
    {
        int rowCount = ui->tableWidget->rowCount();

        TargetData cTarget = alarmData.vecTargetData.at(i);

        ui->tableWidget->insertRow(rowCount);
        int col = 0;
        {
            // 目标
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::number(cTarget.id));
            ui->tableWidget->setItem(rowCount, col++, item);
        }
        {
            // 方向
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::number(cTarget.fTagPosAngle));
            ui->tableWidget->setItem(rowCount, col++, item);
        }
        {
            // 俯仰
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::number(cTarget.fTagPitchAngle));
            ui->tableWidget->setItem(rowCount, col++, item);
        }
        {
            // 距离
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(QString::number(cTarget.iDistance));
            ui->tableWidget->setItem(rowCount, col++, item);
        }
        {
            // 时间
            QTableWidgetItem* item = new QTableWidgetItem;
            item->setText(time);
            ui->tableWidget->setItem(rowCount, col++, item);
        }
    }   
}

QJsonObject TowerController::alarJson(const AlarmData& alarmData)
{
    QJsonObject jsonObject;
    QString ip = alarmData.strIp;
    QString aTime = QString("%1%2%3_%4:%5:%6").arg(QString::number(alarmData.alarmTime.year)).arg(QString::number(alarmData.alarmTime.month)).arg(QString::number(alarmData.alarmTime.day)).arg(QString::number(alarmData.alarmTime.hour)).arg(QString::number(alarmData.alarmTime.minute)).arg(QString::number(alarmData.alarmTime.second));
    jsonObject.insert("strIp", ip);
    jsonObject.insert("alarmTime", aTime);

    QJsonArray jArray;
    for (TargetData mTarget: alarmData.vecTargetData)
    {
        QJsonObject targetInfo;
        jsonObject.insert("id", mTarget.id);
        jsonObject.insert("fTagPitchAngle",mTarget.fTagPitchAngle);
        jsonObject.insert("fTagPosAngle", mTarget.fTagPosAngle);
        jsonObject.insert("iDistance", mTarget.iDistance);
        jsonObject.insert("fLongitude", mTarget.fLongitude);
        jsonObject.insert("fLatitude", mTarget.fLongitude);
        jsonObject.insert("fhigh", mTarget.fSpeed);
        jArray.append(targetInfo);
    }

    jsonObject.insert("vecTargetData", jArray);

    return jsonObject;
    QJsonDocument jsonDoc(jsonObject);
    QByteArray jsonData = jsonDoc.toJson();

}

QJsonObject TowerController::towerStatusJson()
{
    QJsonObject jsonObject;

    QJsonObject targetInfo;

    jsonObject.insert("Longitude", curPos_gd.lon);
    jsonObject.insert("Latitude", curPos_gd.lat);
    jsonObject.insert("Hight",curPos_gd.high);
    jsonObject.insert("Status", m_pDataRevInterFace->isConnected());

    return jsonObject;
}

//void TowerController::paintEvent(QPaintEvent* e)
//{
//    // 依次绘画，不要打破顺序
//    // 360
//    // 三个图像,
//    std::unique_lock<std::mutex> lck(mtx_imag360);
//    
//    /*QPainter painter_(ui->widget360);
//    
//    painter_.fillRect(ui->widget360->rect(), Qt::black);*/
//
//    if (Image360.isNull()) {
//        qDebug() << "image360 null";
//        return;
//    }
//    
//    QPainter painter(ui->widget360);
//    painter.drawImage(ui->widget360->rect(), Image360);
//
//    // main
//    if (imageMain.isNull()) {
//        qDebug() << "imageMain null";
//        return;
//    }
//    QPainter painterMain(ui->widget_main);
//    painterMain.drawImage(ui->widget_main->rect(), imageMain);
//
//    // 重点
//    if (imageMoni.isNull()) {
//        qDebug() << "imageMoni null";
//        return;
//    }
//    QPainter painterMoni(ui->widget_moni);
//    painterMoni.drawImage(ui->widget_moni->rect(), imageMoni);
//  
//
//}
void TowerController::resizeEvent(QResizeEvent* event)
{
    int height = ui->widget360->height();
    int width = ui->widget360->width();
    int gap_label = width / 6;

    ui->mainView->resize(height, height);
    ui->monitorView1->resize(height, height);
    ui->monitorView2->resize(height, height);
    ui->monitorView3->resize(height, height);
    ui->monitorView4->resize(height, height);
    ui->monitorView5->resize(height, height);
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
    // 初始化时执行
    static bool isInit = false;
    if (!isInit)
    {
        devWgt->QueryAllInfo();
        isInit = true;
    }
    
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
    //if (isStart == true)
    //{
    //    // 状态改为关闭
    //    isStart = false;    
    //    // 按钮图像修改
    //    ui->btnStartAStop->setText("关闭");
    //    ui->widget360->close();
    //}
    //else {
    //    // 状态改为开启
    //    isStart = true;
    //    // 按钮图像修改
    //    ui->btnStartAStop->setText("开启");
    //    ui->widget360->open();
    //}
    
    // 1016 转为IPR SDK开启断开
    if (isLink != true)
    {
        QMessageBox::information(this, "tip", u8"请连接设备");
        return;
    }
    if (isStart == true)
    {
        
        isStart = false;
        if (isStart) {
            ui->btnStartAStop->setText(u8"关闭");
        }
    }
    else {

        isStart = true;
        if (isStart) {
            ui->btnStartAStop->setText(u8"开启");
            // 开始接收图像信息-分别新起线程
            getImageFromInfrared();
            // 告警信息
            getAlarmDataInfrared();

            reportTowerInfo();
        }
    }

    // lr Start Stop
    if (lRadar.isRunning())
    {
        lRadar.laserRadarStop();
    }
    else
    {
        lRadar.laserRadarStart();
        // 抓数据
        lRadar.laserRadarCapData();
    }
    
}

void TowerController::on_pbSaveImage_clicked()
{
    QString path_ = sSecondWin->getstorePath();
    QDir dir;
    bool exist = dir.exists(path_);
    if (!exist)
    {
        dir.mkdir(path_);
    }
    std::thread thread_([&] {
        for (int i = 0; i < 10; i++)
        {
            // 10
            QString mainPath = sSecondWin->getstorePath() + "/" + iStore->getMainName();
            QString moniPath = sSecondWin->getstorePath() + "/" + iStore->getCurMoni();
            QString mainPath_JPG = QString("image_%1_%2.jpg").arg(mainPath).arg(i);
            QString moniPath_JPG = QString("image_%1_%2.jpg").arg(moniPath).arg(i);
            bool isSave = false;
            if (!imageMain.isNull())
            {
                isSave = imageMain.save(mainPath_JPG, "JPG");
            }
            if (!imageMoni.isNull())
            {
                isSave = imageMoni.save(moniPath_JPG, "JPG");
            }
            
            

            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
        });
    thread_.detach();
    
    
}

void TowerController::on_pbLink_clicked()
{
     
    qDebug() << "link";

    if (isLink == false)
    {
        if (!m_pDataRevInterFace->isConnected())
        {
            isLink = m_pDataRevInterFace->connectToHost(dataRecvIP);
            // isLink = true;
        }
    }
    else
    {
        bool disConn = m_pDataRevInterFace->disconnectFromHost(dataRecvIP);
        isLink = !disConn; 
    }
    
    

    
}

void TowerController::on_pbRefresh_clicked()
{
    qDebug() << "refresh";
}

//void TowerController::on_pushButton_7_clicked()
//{
//    //ui->widget_6->setCapPic();
//    // 确认发送
//    QByteArray data = "123";
//    serMan->sendData(data);
//}



void TowerController::warnInfoUpdate(const QByteArray& data)
{
    // 经度lon纬度lat 
    std::lock_guard<std::mutex> lck(mtx_pos);
    QByteArray array = data;
    QByteArray head = data.mid(0,2);
    
    
    QByteArray lon_ = data.mid(44, 4);
    QByteArray lat_ = data.mid(48, 4);

    QByteArray high_ = data.mid(52, 3);

    uint32_t lon = qFromLittleEndian<uint32_t>(reinterpret_cast<const uchar*>(lon_.constData()));// qFromBigEndian<uint32_t>(reinterpret_cast<const uchar*>(lon_.constData()));
    double  lon_d = lon / pow(10, 7);
    qDebug() << "Unsigned Value:" << lon_d;
    uint32_t lat = qFromLittleEndian<uint32_t>(reinterpret_cast<const uchar*>(lat_.constData()));
    double  lat_d =  lat /pow(10, 7);
    qDebug() << "Unsigned Value:" << lat_d;

    uint32_t high = qFromLittleEndian<uint32_t>(reinterpret_cast<const uchar*>(high_.constData()));
    double high_d = high / pow(10, 2);

    ui->label_site->setText(QString::number(lon_d)+u8"°,"+QString::number(lat_d)+u8"°," +QString::number(high_d)+"m");
    
    // 记录当前位置
    curPos_gd.lon = lon_d;
    curPos_gd.lat = lat_d;
    curPos_gd.high = high_d;
    
}

void TowerController::on_pbMonitor1_clicked()
{
    curMoni = 1;
}

void TowerController::on_pbMonitor2_clicked()
{
    curMoni = 2;
}

void TowerController::on_pbMonitor3_clicked()
{
    curMoni = 3;
}

void TowerController::on_pbMonitor4_clicked()
{
    curMoni = 4;
}

void TowerController::on_pbMonitor5_clicked()
{
    curMoni = 5;
}

void TowerController::init()
{
    isLink = false;
    isStart = false;
    // 全景图像IP
    dataRecvIP = cf.getInfraredIp().toStdString();
    // 全景图像获取超时 毫秒
    iTimeout = 200;
    /*urls = "rtsp://127.0.0.1:8554/mystream";
    outUrl = "rtsp://127.0.0.1:8554/mystream1";

    ui->widget360->setUrl(urls);
    ui->widget360->setOutUrl(outUrl);*/
    // 临时代替url

    strWgt->setMainView(cf.getInfraredIp());
    strWgt->setMoiView(cf.getInfraredIp());
    strWgt->setWarnInfo(cf.getInfraredUrl());

    request.setUrl(QUrl(cf.getWebReport())); // 替换为你的服务器地址
    manager = new QNetworkAccessManager();

}

// 惯导计算经纬度 
void TowerController::calculateTargetPosition(MPos RPos, double elevation, double azimuth, double distance, double& targetLon, double& targetLat, double& targetAlt)
{
    // 将角度转换为弧度
    double el_rad = deg2rad(elevation);
    double az_rad = deg2rad(azimuth);
    double lat_rad = deg2rad(RPos.lat);
    double lon_rad = deg2rad(RPos.lon);

    // 计算目标相对于观测点的东北天坐标系中的坐标
    double east = distance * cos(el_rad) * sin(az_rad);
    double north = distance * cos(el_rad) * cos(az_rad);
    double up = distance * sin(el_rad);

    // 考虑地球曲率的更精确计算
    double R = EARTH_RADIUS + RPos.high;

    // 计算纬度变化量
    double deltaLat = north / R;

    // 计算经度变化量（考虑纬度对经度间隔的影响）
    double deltaLon = east / (R * cos(lat_rad));

    // 计算目标经纬度
    targetLat = rad2deg(lat_rad + deltaLat);
    targetLon = rad2deg(lon_rad + deltaLon);

    // 计算目标高度
    targetAlt = RPos.high + up;
}

int TowerController::getImageFromInfrared()
{
    std::thread getImage([&]() {
        while (m_pDataRevInterFace->isConnected() && isStart)
        {
            // 获取数据
            int ret = m_pDataRevInterFace->getPanorFrame(panorData, iTimeout);

            if (ret == 0)
            {
                // 转换成全景QImage;
                // 由于该图像是灰度图8bit
                mtx_imag360.lock();
                Image360 = QImage(panorData.data, panorData.width, panorData.height, panorData.width, QImage::Format_Indexed8);
                // 创建并设置灰度颜色表,必须步骤
                QVector<QRgb> colorTable;
                for (int i = 0; i < 256; ++i) {
                    colorTable.append(qRgb(i, i, i));
                }
                Image360.setColorTable(colorTable);

                // 同步更新主视角图和当前重点监视图像
                copyToShow_main();

                mtx_imag360.unlock();
                // 刷新Image 到 指定窗口

            }
            else
            {
                // 错误码
                std::cout << "getPanorFrame error: " << ret << std::endl;
                // 未收取则进行两个周期的暂停
                std::this_thread::sleep_for(std::chrono::milliseconds(iTimeout * 2));
            }           
        }
        });

    getImage.detach();
    return 0;
}

int TowerController::getAlarmDataInfrared()
{


    std::thread getAla([&]() {
        

        while (m_pDataRevInterFace->isConnected() && isStart)
        {
            // 获取数据 -
            int ret = m_pDataRevInterFace->getAlarmData(alarmData, 10);

            if (ret == 0)
            {
                ////处理报警数据
                mtx_ala.lock();
                // 计算坐标更新位置信息
                for (TargetData& target : alarmData.vecTargetData)
                {
                    double targetLon; double targetLat; double targetAlt;
                    calculateTargetPosition(curPos_gd, target.fTagPitchAngle, target.fTagPosAngle, target.iDistance, targetLon,targetLat,targetAlt);
                    target.fLongitude = targetLon;
                    target.fLatitude = targetLat;
                    // targetData 中并没有提供高度信息，替换为高度信息
                    target.fSpeed = targetAlt;
                
                }
                
                // 刷新告警树
                alarTreeUpDate(alarmData);

                // 1组装json
                //QJsonObject json_ = alarJson(alarmData);
                QString ip_ = cf.getRemoteIP();
                int port = cf.getRemotePort();

                QString prefix = "Alarm:";
                QByteArray prefixBa_ = prefix.toUtf8();

                QJsonObject json = alarJson(alarmData);
                QJsonDocument doc(json);
                QByteArray data = doc.toJson(QJsonDocument::Compact);

                QByteArray byteArray_preInfo = prefixBa_ + data;

                uint32_t sizeOfAla = byteArray_preInfo.size();

                QByteArray byteArray_int;
                byteArray_int.resize(4);
                std::memcpy(byteArray_int.data(), &sizeOfAla, 4);
                QByteArray byteInfo = byteArray_int + byteArray_preInfo;

                eServer->sendInfo(ip_, port, byteInfo);
                 
                // 2发送告警图像
                sendAlaPicInfo(alarmData);

                mtx_ala.unlock();
                // 发送信息
               
            }
            // 防止
            std::this_thread::sleep_for(std::chrono::milliseconds(500));

        }
        });

    getAla.detach();
    return 0;

    // 1115 test
    


}

int TowerController::reportTowerInfo()
{

    std::thread reportTower([&]() {
        
        while (m_pDataRevInterFace->isConnected() && isStart) {

            QString ip_ = cf.getRemoteIP();
            int port = cf.getRemotePort();

            // 铁塔信息
            QString prefix = "InfoTT:";
            QByteArray prefixBa_ = prefix.toUtf8();

            QJsonObject json = towerStatusJson();
            QJsonDocument doc(json);
            QByteArray data = doc.toJson(QJsonDocument::Compact);

            QByteArray byteArray_preInfo = prefixBa_ + data;

            uint32_t sizeOfAla = byteArray_preInfo.size();

            QByteArray byteArray_int;
            byteArray_int.resize(4);
            std::memcpy(byteArray_int.data(), &sizeOfAla, 4);
            QByteArray byteInfo = byteArray_int + byteArray_preInfo;

            eServer->sendInfo(ip_, port, byteInfo);

            // 图像
            mtx_imagMain.lock();
            QImage scaled = imageMain.scaled(imageMain.width() / 8, imageMain.height() / 8, Qt::KeepAspectRatio);
            mtx_imagMain.unlock();
            QByteArray byteArray;
            QBuffer buffer(&byteArray);
            buffer.open(QIODevice::WriteOnly);
            scaled.save(&buffer, "PNG"); // 或 "JPEG"
            QString base64Data = byteArray.toBase64();
            QByteArray message;
            QDataStream out(&message, QIODevice::WriteOnly);
            message.append(base64Data);

            QString prefixTT = "ImageTT:";
            QByteArray prefixBaTT = prefixTT.toUtf8();

            QByteArray info_ = prefixBaTT + message;

            sizeOfAla = info_.size();
            
            std::memcpy(byteArray_int.data(), &sizeOfAla, 4);

            info_ = byteArray_int + info_;

            eServer->sendInfo(ip_, port, info_);
        
            std::this_thread::sleep_for(std::chrono::milliseconds(1000));
        }
    });

    reportTower.detach();
    
        //    QImage image; // 你的QImage对象
        //    QFile file("SC.png");
        //    if (file.exists()) {
        //        qDebug() << "file exist";
        //    }
        //    else {
        //        qDebug() << "file exist!";
        //    }
        //    image.load("SC.png");
        //    QImage scaled = image.scaled(image.width() / 8, image.height() / 8, Qt::KeepAspectRatio);
        //    QByteArray byteArray;
        //    QBuffer buffer(&byteArray);
        //    buffer.open(QIODevice::WriteOnly);
        //    scaled.save(&buffer, "PNG"); // 或 "JPEG"
        //    QString base64Data = byteArray.toBase64();
        //    QByteArray message;
        //    QDataStream out(&message, QIODevice::WriteOnly);
        //    message.append(base64Data);

        //    QString prefixTT = "ImageTT:";
        //    QByteArray prefixBaTT = prefixTT.toUtf8();

        //    QByteArray info_ = prefixBaTT + message;

        //    sizeOfAla = info_.size();

        //    std::memcpy(byteArray_int.data(), &sizeOfAla, 4);

        //    info_ = byteArray_int + info_;

        //    eServer->sendInfo(ip_, port, info_);
        
        //    std::this_thread::sleep_for(std::chrono::milliseconds(50));

        //}
    return 0;
}

void TowerController::copyToShow_main()
{
    // 四个坐标系转换计算
    // main
    int iW = Image360.width();
    int iH = Image360.height();
    int wid360W = ui->widget360->width();
    int wid360H = ui->widget360->height();
    // 计算比例
    int scaW = iW / wid360W;
    int scaH = iH / wid360H;
    // 计算主视角位置和大小
    int mainWidth = ui->mainView->width() * scaW;
    int mainHeight = ui->mainView->height() * scaH;
    int imgX = ui->mainView->x() * scaW;
    int imgY = ui->mainView->y()* scaH;

    //copy -- x, y, width, height
    imageMain = Image360.copy(imgX, imgY, mainWidth, mainHeight);
    // 计算当前重点区域位置和大小
    int moniWidth = 0;
    int moniHeight = 0;
    int cImgX =10;
    int cImgY = 10;
    if (curMoni == 1)
    {
        moniWidth = ui->monitorView1->width()*scaW;
        moniHeight = ui->monitorView1->height() * scaH;
        cImgX = ui->monitorView1->x() * scaW;
        cImgY = ui->monitorView1->y() * scaH;
    }
    else if (curMoni == 2)
    {
        moniWidth = ui->monitorView2->width() * scaW;
        moniHeight = ui->monitorView2->height() * scaH;
        cImgX = ui->monitorView2->x() * scaW;
        cImgY = ui->monitorView2->y() * scaH;
    }
    else if (curMoni == 3 )
    {
        moniWidth = ui->monitorView3->width() * scaW;
        moniHeight = ui->monitorView3->height() * scaH;
        cImgX = ui->monitorView3->x() * scaW;
        cImgY = ui->monitorView3->y() * scaH;
    }
    else if (curMoni == 4) {
        moniWidth = ui->monitorView4->width() * scaW;
        moniHeight = ui->monitorView4->height() * scaH;
        cImgX = ui->monitorView4->x() * scaW;
        cImgY = ui->monitorView4->y() * scaH;
    }
    else if (curMoni == 5) {
        moniWidth = ui->monitorView5->width() * scaW;
        moniHeight = ui->monitorView5->height() * scaH;
        cImgX = ui->monitorView5->x() * scaW;
        cImgY = ui->monitorView5->y() * scaH;
    }
    
    
    imageMoni = Image360.copy(cImgX,cImgY, moniWidth, moniHeight);

    ui->widget360->setImage(Image360);
    ui->widget_main->setImage(imageMain);
    ui->widget_moni->setImage(imageMoni);
    this->update();
}

void TowerController::sendAlaPicInfo(AlarmData alaData)
{
    // 无监视数据则不执行
    if (imageMoni.isNull())
    {
        return;
    }
    for (TargetData& target : alarmData.vecTargetData)
    {
        QHttpMultiPart* multiPart = new QHttpMultiPart(QHttpMultiPart::FormDataType);
        // 创建并设置文本部分
        QHttpPart textPart;
        textPart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"id\""));
        
        textPart.setBody(QString::number(target.id).toUtf8());

        // 创建并设置TIME部分
        QString time = QString("%1_%2_%3 %4:%5:%6").arg(alarmData.alarmTime.year).arg(alarmData.alarmTime.month).arg(alarmData.alarmTime.day).arg(alarmData.alarmTime.hour).arg(alarmData.alarmTime.minute).arg(alarmData.alarmTime.second);
        QHttpPart timePart;
        timePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"date\""));
        timePart.setBody(time.toUtf8());

        // 创建并设置图像部分
        QHttpPart imagePart;

        // 将QImage转换为QByteArray
        QByteArray imageData;
        QBuffer buffer(&imageData);
        buffer.open(QIODevice::WriteOnly);
        
        imageMoni.save(&buffer, "JPG"); // 将图像以JPG格式保存到缓冲区，可根据需要选择"PNG"等格式
        buffer.close();

        // 设置图像部分的头部信息
        imagePart.setHeader(QNetworkRequest::ContentTypeHeader, QVariant("image/jpeg")); // 根据实际图像格式设置
        imagePart.setHeader(QNetworkRequest::ContentDispositionHeader, QVariant("form-data; name=\"file\"; filename=\"image.jpg\"")); // 设置文件名

        // 将图像数据设置为图像部分的主体
        imagePart.setBody(imageData);
        multiPart->append(textPart);
        multiPart->append(timePart);
        multiPart->append(imagePart);
        //        *multiPart = *(this->multiPart);
        QNetworkRequest request(QUrl(cf.getWebReport()));
        QNetworkReply* reply = manager->post(request, multiPart);
        multiPart->setParent(reply); // 正确设置parent

        QObject::connect(reply, &QNetworkReply::finished, [reply]() {

            if (reply->error() == QNetworkReply::NoError) {
                // 处理成功响应
                QByteArray response_data = reply->readAll();
                qDebug() << "Upload successful:" << response_data;
            }
            else {
                // 处理错误
                qDebug() << "Upload error:" << reply->errorString();
            }
            reply->deleteLater();

            });

    }
}

double deg2rad(double deg)
{
    return deg * PI_ / 180.0;
}

double rad2deg(double rad)
{
    return rad * 180.0 / PI_;
}