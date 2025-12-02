#include "CarF.h"
#include "DBHelper.h"
//#include "sqlite3.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QDebug>
#include <QtEndian>
#include <QDataStream>

#include <QWindow>

const QByteArray CarF::SOF_BYTES = QByteArray::fromHex("AA55");
const QByteArray CarF::SOF_BYTES_GD = QByteArray::fromHex("55AA");
const QByteArray CarF::EOF_BYTES = QByteArray::fromHex("0D0A");

// 定义并初始化静态变量
QString CarF::imageSavePath = NULL;
DBHelper* db = new DBHelper();


void CALLBACK _CBDecodeFun(long               lPlayHandle,
    const unsigned char* pBuf,
    unsigned long       nBufSize,
    S_FRAMEINFO* pFrameInfo,
    void* pUserData)
{

    return;
}


// 实时预览回调实时码流
void CALLBACK RealData(long             lRealHandle,
    E_REALDATA_TYPE  eDataType,
    unsigned char* pBuffer,
    unsigned long    lBufSize,
    void* pUserData)
{
    CarF* pDlg = (CarF*)pUserData;
    // 参数eDataType表示回调上来的码流数据类型，pBuffer存放码流数据，lBufSize存放码流数据大小

    
    switch (eDataType)  // 根据码流数据类型不同，分别处理不同的数据
    {
    case REALDATA_HEAD:    /* 实时流的头数据 */

        pDlg->m_lPlayHandle = HDVPLAY_OpenStream(pBuffer, lBufSize);
        if (pDlg->m_lPlayHandle < 0)
        {
            qDebug() << QString("HDVPLAY_OpenStream\n");
            return;
        }
        // 播放窗口指定 

        if (!HDVPLAY_Play(pDlg->m_lPlayHandle, pDlg->lightWid, true))
        {
            qDebug() << QString("HDVPLAY_Play\n");
            return;
        }
        HDVPLAY_SetDecodeCallBack(pDlg->m_lPlayHandle, _CBDecodeFun, pUserData);
        break;
    case REALDATA_VIDEO:  /*实时视频流数据*/
        // 处理码流数据
        if (!HDVPLAY_InputData(pDlg->m_lPlayHandle, pBuffer, lBufSize))
        {
            qDebug() << QString("HDVPLAY_InputData\n");
            return;
        }
        break;
    case REALDATA_AUDIO:  /*实时音频流数据*/
        // 处理码流数据
 /*       if (pDlg->m_nAudioState == 1)
        {
            if (!HDVPLAY_InputData(pDlg->m_lPlayHandle, pBuffer, lBufSize))
            {
                qDebug() << QString(("HDVPLAY_InputData\n");
                return;
            }
        }
        break;*/
    default:
        break;
    }
    return;
}

// 网络库异常状态监测
void CALLBACK CBNetExceptionMsg(long lLoginID, long lRealHandle,
    E_NET_EXCEPTION_TYPE eNetMsgType,
    void* pUserData)
{
    return;
}


CarF::CarF(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 获取图片保存路径

    vec_id = 1;
    imageSavePath = getImagePath();
    qwc = new QtWidgetsClass();
    qwc->show();

    // 副界面
    OrderLog_.reset(new OrderLog(this));
    PictureSave_.reset(new PictureSave(this));
    SystemSetting_.reset(new SystemSetting(this));

    //init();

    //came_zb = new CameraZB(this);
    //// 设备启动失败则退出
    //// 因为没有设备所以一定会退出
    //if (!came_zb->initIPC_HDV()) {
    //    // 初始化失败则退出
    //    QMessageBox::warning(this, "设备tip", "中波相机初始化失败");
    //    qApp->quit();
    //}
    // 光斑自动
    ui.widget_gb->setVideoID(0);
    
    serMan = new SerialManager(this);
    connect(serMan, &SerialManager::dataReceived, this, &CarF::UVInfoUpdate);

    serManZT = new SerialManager(this);
   /* connect(serManZT, &SerialManager::dataReceived, this, &CarF::UVInfoUpdate);*/

    serManlar = new SerialManager(this);
    //connect(serManlar, &SerialManager::dataReceived, this, [&]() {
    //    ;
    //});

    serManGD = new SerialManager(this);
    connect(serManGD, &SerialManager::dataReceived_GD, this, &CarF::parseGD);

    serManKF = new SerialManager(this);

    serManKJG = new SerialManager(this);

    serManMC = new SerialManager(this);

    // 默认光设置
    ui.larLG->setText(u8"停光");
    ui.larKJG->setText(u8"停光");
    ui.larCB->setText(u8"停光");

    // 192.168.31.222:8602
    client_UVStatus = new QTcpSocket(this);
    // IP端口
    client_UVStatus->connectToHost("192.168.31.222", 8602);

    connect(client_UVStatus, &QTcpSocket::connected, [&]() {
        qDebug() << "Connected to server!";

        // 连接成功后发送数据
        //QString message = "Hello Server!";
        //client_UVStatus->write(message.toUtf8());
        //qDebug() << "Sent:" << message;
        });

    QObject::connect(client_UVStatus, &QTcpSocket::readyRead, [&]() {
        // 读取所有接收到的数据
        QByteArray data = client_UVStatus->readAll();
        qDebug() << "Received:" << data;

        // 收到数据后关闭连接（根据需求修改）
        // socket.disconnectFromHost();
        });

    QObject::connect(client_UVStatus, &QTcpSocket::disconnected, [&]() {
        qDebug() << "Disconnected from server";
        //QCoreApplication::quit();  // 退出应用
     });

    //QObject::connect(client_UVStatus, QOverload<QAbstractSocket::SocketError>::of(&QAbstractSocket::errorOccurred),
    //    [&](QAbstractSocket::SocketError error) {
    //        qDebug() << "Error:" << client_UVStatus->errorString();
    //    });
    larIsInit = false;
    QStringList mrad;
    mrad << "1.6mard" << "2.4mrad";
    ui.cbMrad->addItems(mrad);
    larIsInit = true;
    
    portName = "COM10";
    serMan->openPort(portName);

    portNameZT = "COM2";
    serManZT->openPort(portNameZT);

    portNameLarse = "COM1";
    serManlar->openPort_Lar(portNameLarse);

    portNameGD = "COM13";
    serManGD->openPort_GD(portNameGD);

    portNameKF = "COM5";
    serManKF->openPort(portNameKF);

    portNameKJG = "COM9";
    serManKJG->openPort_KJG(portNameKJG);

    portNameMC = "COM4";
    serManMC->openPort(portNameMC);

    //serverPort = 8602;
    //eServer = new EchoServer(this,serverPort);
    //eServer->startServer();
    /*connect(eServer, &EchoServer::sendJson, this, &CarF::UVInfoUpdate);*/
}

CarF::~CarF()
{
    //delete ui;
    //stopIPC_HDV();
    // 
    //delete came_zb;
    //came_zb = nullptr;
    delete serMan;
    serMan = nullptr;

    delete serManZT;
    serManZT = nullptr;

    delete serManlar;
    serManlar= nullptr;

    delete serManGD;
    serManGD = nullptr;

    delete eServer;
    eServer = nullptr;
    

}

void CarF::init()
{
    // 相机播放需要将窗口设置
    // ui.widget_light->setWindowFlags(Qt::Window);

    m_EncodeType = ENCODE_H264; // ENCODE_MPEG4 ENCODE_H264_Hi3510 ENCODE_H265
    m_lUserID = -1;
    m_iChanNum = 0;
    m_lRealDataID = -1;
    m_lPlayHandle = -1;
    // 初始化
    initIPC_HDV();
    bool isLogin = loginDev();
    if (!isLogin) {
        ;
    }
    // 可见光HWND
    lightWid = nullptr;
    

    QWindow* windowHandle = ui.widget_light->windowHandle();
    WId id = windowHandle->winId();
    lightWid = reinterpret_cast<HWND>(id);

    //if (WId id = qwc->effectiveWinId())
    //{
    //    lightWid = reinterpret_cast<HWND>(id);
    //}

}

bool CarF::initIPC_HDV()
{
    if (!IPCNET_Init())
    {
        QMessageBox::warning(nullptr, QString("tip"), QString(u8"中波相机初始化网络库失败！"));

        return false;
    }
    if (!HDVPLAY_Init())
    {
        QMessageBox::warning(nullptr, QString("tip"), QString(u8"中波相机初始化播放库失败！"));
        return false;
    }
    return true;
}

void CarF::stopIPC_HDV()
{
    IPCNET_Cleanup();
    HDVPLAY_Cleanup();
}

bool CarF::loginDev()
{
    QString devIP = cf.getCarmLightIP();// "192.168.1.18";
    m_lUserID = IPCNET_Login(devIP.toLocal8Bit().constData(), 90, "admin", "admin");
    if (m_lUserID < 0)
    {
        QMessageBox::warning(nullptr, QString("tip"), QString(u8"登录失败"));
        return false;
    }
    return true;
}

void CarF::camPlay()
{
    camStop();
    if (m_lUserID < 0)
    {
        QMessageBox::warning(nullptr, QString("tip"), QString(u8"请先登录设备"));
        return;
    }
    S_REALDATA_INFO sRealInfo;
    sRealInfo.eEncodeType = m_EncodeType;
    sRealInfo.lChannel = m_iChanNum;
    sRealInfo.lStreamMode = 1;	// 子码流

    m_lRealDataID = IPCNET_StartRealData(m_lUserID, &sRealInfo, RealData, this);
    if (m_lRealDataID < 0)
    {
        QMessageBox::warning(nullptr, QString("tip"), QString(u8"实时预览开启失败"));
        return;
    }
    IPCNET_SetNetExceptionCallBack(CBNetExceptionMsg, this);
}

void CarF::camStop()
{
    if (m_lRealDataID >= 0)
    {
        if (!IPCNET_StopRealData(m_lRealDataID))
        {

            QMessageBox::warning(nullptr, QString("tip"), QString(u8"实时预览停止失败"));
            return;
        }
    }
    if (m_lPlayHandle >= 0)
    {
        if (!HDVPLAY_Stop(m_lPlayHandle))
        {
            qDebug() << QString("HDVPLAY_Stop Faild!\n");
        }
        if (!HDVPLAY_CloseStream(m_lPlayHandle))
        {
            qDebug() << QString("HDVPLAY_CloseStream Faild!\n");
        }
        m_lPlayHandle = -1;
    }
    m_lRealDataID = -1;

}

void CarF::OnDecodeFun(long lPlayHandle, const unsigned char* pBuf, unsigned long nBufSize, S_FRAMEINFO* pFrameInfo)
{
    qDebug() << ("\nlPlayHandle = %d, nBufSize = %d", lPlayHandle, nBufSize);
}

void CarF::carPayLoad(quint8 msgType, QByteArray payload)
{
    if (msgType == 1)
    {
        // 无人车状态信息 (UV -> CCU) 21字节
        if (payload .size() !=21)
        {
            return;
        }
        else {
            QDataStream stream(payload);
            stream.setByteOrder(QDataStream::LittleEndian); // 根据实际情况设置字节序

            // 解析1字节数据
            // 
            
            quint32 timestamp;
            stream >> timestamp;

            quint8 vehicle_id;
            stream >> vehicle_id;

            quint32 utm_easting_cm;
            stream >> utm_easting_cm;
            utm_easting_cm /= 100;

            quint32 utm_northing_cm;
            stream >> utm_northing_cm;
            utm_northing_cm /= 100;
            ui.UVCoor->setText(QString::number(utm_easting_cm) + "," + QString::number(utm_northing_cm));


            quint16 heading_angle;
            stream >> heading_angle;
            heading_angle /= 10;
            ui.UVForw->setText(QString::number(heading_angle) + "°"); // 朝向

            quint16 speed;
            stream >> speed;

            quint8 battery_level;
            stream >> battery_level;
            ui.UVbatt->setText(QString::number(battery_level)+"%");

            quint16 horizontal_inclination;
            stream >> horizontal_inclination;
            horizontal_inclination /= 10;
            ui.UVup->setText(QString::number(horizontal_inclination) + "°"); // 俯仰

            quint8 vehicle_state;
            stream >> vehicle_state;
            //quint8 timestamp;
            //stream >> timestamp;

            //// 解析2字节数据
            //quint16 short2;
            //stream >> short2;

            //// 解析4字节数据
            //quint32 int4;
            //stream >> int4;
            //fun 指针
            /*const char* ptr = payload.constData();*/
            //quint8 byte1 = static_cast<quint8>(ptr[0]);

            //// 解析2字节数据（小端序）
            //quint16 short2 = qFromLittleEndian<quint16>(reinterpret_cast<const uchar*>(ptr + 1));

            //// 解析4字节数据（小端序）
            //quint32 int4 = qFromLittleEndian<quint32>(reinterpret_cast<const uchar*>(ptr + 3));
        }

    }
    else if (msgType == 2) {
        // 总控控制指令 (CCU -> UV) 16字节

        // 无人车控制界面，所以其实不会出现这个解析
    }
}

//打开指令记录窗口
void CarF::on_btnOrderLog_clicked()
{
    //OrderLog *secondWin = new OrderLog(this);
    //secondWin->exec(); // 模态显示对话框
    OrderLog_->exec();
}
void CarF::on_pbCameZBOpen_clicked()
{
    /*qDebug() << "123open";
    came_zb->camPlay();*/
    
}
void CarF::on_pbCameZBClose_clicked()
{
    /*qDebug() << "123close";
    came_zb->camStop();*/
}

void CarF::on_pbCarmGBOpen_clicked()
{
    ui.widget_gb->start();
}

void CarF::on_pbCarmGBClose_clicked()
{
    ui.widget_gb->stop();
}

void CarF::on_pbCameLightOpen_clicked()
{
    init();
    qDebug() << ui.widget_light->winId();

    //qDebug() << 
    //ui.widget_light->winId(); 
    camPlay();
}

void CarF::on_pbCameLightClose_clicked()
{
    qDebug() << "123close";
    camStop();
    stopIPC_HDV();
}

void CarF::on_cbMrad_currentIndexChanged(int index)
{
   if (!larIsInit) {
        return;
    }
    QByteArray command;
    command = larCommand.mradSet(index);
    serManlar->sendData(command);
}

// 蓝光
void CarF::on_pbLightRate_clicked()
{
    short value = ui.sbLightRate->value();

    QByteArray command;
    command = larCommand.blueDW(value);
    serManlar->sendData(command);
}

void CarF::on_pblightOutL_clicked()
{
    QByteArray command = larCommand.blueOutLar();// larCommand.lightOutLar();
    serManlar->sendData(command);
    ui.larLG->setText(u8"出光");
}

void CarF::on_pblightCL_clicked()
{
    QByteArray command = larCommand.blueCloseLar();//  lightCloseLar();
    serManlar->sendData(command);
    ui.larLG->setText(u8"停光");

}

// 可见光
void CarF::on_pbLightRate1_clicked()
{
    int value = ui.sbLightRate1->value();
    if (value > 10 || value <= 0)
    {
        QMessageBox::information(this, "tip", u8"该档位只能选择0或1");
            return;
    }

    QByteArray command = larCommand.changeDW(value);
    serManMC->sendData(command);
}

void CarF::on_pblightOutL1_clicked()
{
    QByteArray command = larCommand.lightOutLar();
    serManMC->sendData(command);
    ui.larKJG->setText(u8"出光");
}

void CarF::on_pblightCL1_clicked()
{
    QByteArray command = larCommand.lightCloseLar();
    serManMC->sendData(command);
    ui.larKJG->setText(u8"停光");
}

void CarF::on_pbLongBauRate_clicked()
{
    short rate = ui.sbLightRate->value();
    QByteArray command = larCommand.longBauPowerRate(rate);
    serManlar->sendData(command);
}

void CarF::on_pbLongBauoutL_clicked()
{
    QByteArray command = larCommand.longBauOutLar();
    serManlar->sendData(command);
    ui.larCB->setText(u8"出光");
}

void CarF::on_pbLongBauCL_clicked()
{
    QByteArray command = larCommand.longBauCloseLar();
    serManlar->sendData(command);
    ui.larCB->setText(u8"停光");
}

//uint32_t timestamp;        // Unix时间戳(秒)
//uint8_t vehicleId;        // 车辆ID
//uint32_t utmEastingCm;   // UTM东向坐标(cm)
//uint32_t utmNorthingCm;  // UTM北向坐标(cm)
//int16_t headingAngle;     // 航向角(0.1°)
//uint16_t speed;            // 速度(0.1 m/s)
//uint8_t batteryLevel;     // 电量百分比(0-100)
//int16_t horizontalInclination; // 水平倾角(0.1°)
//uint8_t vehicleState;     // 车辆状态

void CarF::UVInfoUpdate(QByteArray data)
{
    UnmannedVehicleStatus UVStatus;
    /*const uint8_t* buffer = reinterpret_cast<const uint8_t*>(data.constData());*/
    UnmannedVehicleStatus::fromFrame(data,UVStatus);
    QJsonObject json = UVStatus.toWrappedJsonObject();
    //QByteArray data_json = UVS_json.();
    QJsonDocument doc(json);
    QByteArray jsonData = doc.toJson();
    quint32 dataLength = jsonData.size();
    QByteArray finalData;

    finalData.reserve(sizeof(dataLength) + jsonData.size());

    finalData.append(reinterpret_cast<const char*>(&dataLength), sizeof(dataLength));
    finalData.append(jsonData);

    qDebug() << "client_UVStatus write";
    
    client_UVStatus->write(finalData);

}

void CarF::parseGD(QByteArray dataBuffer)
{
    while (dataBuffer.size() >= MIN_FRAME_SIZE) {
        // 步骤1：查找SOF
        //int startIdx = dataBuffer.indexOf(reinterpret_cast<const char*>(&SOF_), 2);
        int startIdx = dataBuffer.indexOf(SOF_BYTES_GD);
        if (startIdx == -1) {
            dataBuffer.clear(); // 无有效帧头，清空缓冲区
            return;
        }

        // 移除SOF前的无效数据
        if (startIdx > 0) {
            dataBuffer.remove(0, startIdx);
        }

        // 步骤2：检查长度是否足够
        if (dataBuffer.size() < MIN_FRAME_SIZE) break;

        // 提取Length字段（位置：SOF后第3字节）
        quint8 payloadLen = static_cast<quint8>(dataBuffer[3]);
        int totalFrameSize = 6 + payloadLen; // SOF(2)+Type(1)+Len(1)+Payload(n)+CRC(1)+EOF(2)

        // 检查完整帧是否已接收
        if (dataBuffer.size() < totalFrameSize) break;


        // --- 成功解析一帧 ---
        //emit frameReceived(msgType, payload); // 发送信号处理有效数据
        // 转为本地解析一帧
        {
            QDataStream stream(dataBuffer);
            stream.setByteOrder(QDataStream::BigEndian); // 根据实际情况设置字节序

            // 解析1字节数据

            quint16 head;
            stream >> head; // 55AA

            quint8 dataLenght;
            stream >> dataLenght;

            quint32 timetemp;
            stream >> timetemp;

            quint8 status;
            stream >> status; 
            // lon 经度
            qint32 lon;
            stream >> lon;
            lon /= pow(10, 7);
            // lat 纬度    
            quint32 lat;
            stream >> lat;
            lat /= pow(10, 7);

            qint32 high;
            stream >> high;
            high /= pow(10, 5);


        }

        // 步骤6：从缓冲区移除已处理帧
        dataBuffer.remove(0, totalFrameSize);

    }
}

//void CarF::UVInfoUpdate(const QByteArray& data)
//{
//    qDebug() << "UVInfo::" << data;
//    // 转
//    QByteArray dataBuffer = data;
//    parseData(dataBuffer);

//}
//quint8 CarF::calculateCRC(const QByteArray& data)
//{
//    quint8 crc = 0;
//    for (char byte : data) {
//        crc += static_cast<quint8>(byte);
//    }
//    return crc;
//}
quint8 CarF::calculateCRC(quint8 msg_type, quint8 length, const QByteArray& payload)
{
    uint8_t crc = 0;
    crc ^= msg_type;
    crc ^= length;
    for (int i = 0; i < length; i++) { // length指定payload长度
        crc ^= payload[i];
    }
    return crc;
    //return quint8();
}
void CarF::parseData(QByteArray& dataBuffer)
{
    while (dataBuffer.size() >= MIN_FRAME_SIZE) {
        // 步骤1：查找SOF
        //int startIdx = dataBuffer.indexOf(reinterpret_cast<const char*>(&SOF_), 2);
        int startIdx = dataBuffer.indexOf(SOF_BYTES);
        if (startIdx == -1) {
            dataBuffer.clear(); // 无有效帧头，清空缓冲区
            return;
        }

        // 移除SOF前的无效数据
        if (startIdx > 0) {
            dataBuffer.remove(0, startIdx);
        }

        // 步骤2：检查长度是否足够
        if (dataBuffer.size() < MIN_FRAME_SIZE) break;

        // 提取Length字段（位置：SOF后第3字节）
        quint8 payloadLen = static_cast<quint8>(dataBuffer[3]);
        int totalFrameSize = 6 + payloadLen; // SOF(2)+Type(1)+Len(1)+Payload(n)+CRC(1)+EOF(2)

        // 检查完整帧是否已接收
        if (dataBuffer.size() < totalFrameSize) break;

        // 步骤3：验证EOF

        QByteArray eofInData = dataBuffer.mid(5 + payloadLen, 2);
        if (eofInData != EOF_BYTES) {
            qWarning() << "Invalid EOF. Expected:" << EOF_BYTES.toHex()
                << "Received:" << eofInData.toHex();
            dataBuffer.remove(0, 2);  // 跳过当前SOF，继续搜索
            continue;
        }

        // 步骤4：提取关键字段
        quint8 msgType = static_cast<quint8>(dataBuffer[2]);
        QByteArray payload = dataBuffer.mid(4, payloadLen);
        quint8 receivedCRC = static_cast<quint8>(dataBuffer[4 + payloadLen]);

        // 步骤5：校验CRC（范围：MsgType+Length+Payload）
        QByteArray crcData = dataBuffer.mid(2, 2 + payloadLen); // 从MsgType开始
        quint8 calculatedCRC = calculateCRC(msgType,payloadLen,payload);

        if (receivedCRC != calculatedCRC) {
            dataBuffer.remove(0, totalFrameSize); // 移除错误帧
            continue;
        }

        // --- 成功解析一帧 ---
        //emit frameReceived(msgType, payload); // 发送信号处理有效数据
        // 转为本地解析一帧
        carPayLoad(msgType, payload);

        // 步骤6：从缓冲区移除已处理帧
        dataBuffer.remove(0, totalFrameSize);
    }
}
/*
* 查询img_path表最后一条数据，如果没有则创建一条默认数据并写入数据库，返回该数据
*/
QString CarF::getImagePath()
{
    QString lastImagePath= "D:/CarF/image/";
    QVariantMap maxIdData = db->getMaxIdData("img_path");
    if (maxIdData.isEmpty()) {
        QVariantMap map;
        map["url"]= lastImagePath;
        db->insertData("img_path", map);
    }
    else {
        QString lastImagePath = maxIdData["url"].toString();
    }
    return lastImagePath;
}
/*
* 保存图像存储路径
*/
void CarF::saveStringToFile(const QString& text, const QString& filename) {
    // 1. 提取文件路径的目录部分
    QFileInfo fileInfo(filename);
    QDir dir;

    // 2. 如果目录不存在，递归创建所有缺失的目录
    if (!dir.mkpath(fileInfo.absolutePath())) {
        qDebug() << "无法创建目录:" << fileInfo.absolutePath();
        return;
    }

    // 3. 打开文件并写入内容
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法创建或写入文件:" << file.errorString();
        return;
    }

    QTextStream stream(&file);
    //stream.setEncoding(QStringConverter::Utf8);  // 可选：设置编码为 UTF-8
    stream << text;  // 写入字符串

    // 文件会在 QFile 对象销毁时自动关闭

    // 3. 插入数据
    //db->insertData("img_path", "url", imageSavePath);

}

/*
* 读取文件存储路径配置
*/
QString CarF::readFileIfExists(const QString& filename) {
    // 1. 检查文件是否存在
    QFileInfo fileInfo(filename);
    if (!fileInfo.exists() || !fileInfo.isFile()) {
        qDebug() << "文件不存在或不是普通文件:" << filename;
        return QString();
    }

    // 2. 打开文件
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件:" << file.errorString();
        return QString();
    }

    // 3. 读取内容
    QTextStream stream(&file);
   // stream.setEncoding(QStringConverter::Utf8);  // 设置编码（需与写入时一致）
    QString content = stream.readAll();

    file.close();
    return content;
}
/*
* 无人车控制 自动前进
*/
void CarF::on_btnAutoDisplay_clicked() {
    //对接设备后，此处改为向第三方发送控制指令
    /*QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("控制无人车前进"));*/

    qint8 msgType = 2;
    qint8 len = 16;
    qint32 timestamp = QDateTime::currentSecsSinceEpoch(); // 时间戳
    qint32 east_cm = ui.east_cm->text().toFloat() * 100; 
    qint32 north_cm = ui.north_cm->text().toFloat() * 100;
    qint16 heading = ui.heading->text().toFloat() * 10;
    qint8 start = 0; // 0前进

    
    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    
    QByteArray payload;
    QDataStream stream_(&payload, QIODevice::WriteOnly);
    stream_.setByteOrder(QDataStream::LittleEndian);
    stream_ << timestamp << vec_id << east_cm << north_cm << heading << start;
    qint8 crc = calculateCRC(msgType, len, payload);

    stream << SOF_BYTES  << msgType << len  << timestamp << vec_id << east_cm << north_cm << heading << start << crc << EOF_BYTES;

    serMan->sendData(byteArray);

    
    
}
/*
* 无人车控制 停止
*/
void CarF::on_btnStop_clicked() {
    //对接设备后，此处改为向第三方发送控制指令
    /*QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("停止"));*/

    qint8 msgType = 2;
    qint8 len = 16;
    qint32 timestamp = QDateTime::currentSecsSinceEpoch(); // 时间戳
    qint32 east_cm = ui.east_cm->text().toFloat() * 100;
    qint32 north_cm = ui.north_cm->text().toFloat() * 100;
    qint16 heading = ui.heading->text().toFloat() * 10;
    qint8 stop = 1; // 0前进 1 停止


    QByteArray byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);

    QByteArray payload;
    QDataStream stream_(&payload, QIODevice::WriteOnly);
    stream_.setByteOrder(QDataStream::LittleEndian);
    stream_ << timestamp << vec_id << east_cm << north_cm << heading << stop;
    qint8 crc = calculateCRC(msgType, len, payload);

    stream << SOF_BYTES << msgType << len << timestamp << vec_id << east_cm << north_cm << heading << stop << crc << EOF_BYTES;

    serMan->sendData(byteArray);
}

void CarF::on_pbTurnFw_clicked()
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    // 0xA2 调转模式
    unsigned int fx = ui.spinBox_ZTfx->value();
    int fy = ui.spinBox_ZTfy->value();
    stream << 0xFF << 0xA2 << fx << fy;//  << 
    uint32_t crc = larCommand.calculateCRC(array);
    stream << crc << 0xFE;
    serManZT->sendData(array);
}

void CarF::on_pbTurnUD_clicked()
{
    // 删除
    on_pbTurnFw_clicked();
}

void CarF::on_pbKFJ_clicked()
{
    QByteArray array;
    QDataStream stream(&array, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    // 0x01 
    int fx = ui.spinBox_ZTfx->value();
    int fy = ui.spinBox_ZTfy->value();
    short len_ = 11;
    stream << 0xBB << 0xFB << len_ << 0xB2 << 0x01<< fx << fy;//  << 
    uint32_t crc = larCommand.calculateCRC(array);
    stream << crc;
    serManKF->sendData(array);
}

void CarF::on_pbKF_clicked()
{
}

void CarF::on_btnSystem_clicked()
{
    SystemSetting_->exec();
}

void CarF::on_btnImage_clicked()
{
    PictureSave_->exec();
}
