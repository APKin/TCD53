#include "CarF.h"
#include "DBHelper.h"
//#include "sqlite3.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

const QByteArray CarF::SOF_BYTES = QByteArray::fromHex("AA55");
const QByteArray CarF::EOF_BYTES = QByteArray::fromHex("0D0A");

// 定义并初始化静态变量
QString CarF::imageSavePath = NULL;
DBHelper* db = new DBHelper();


CarF::CarF(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 获取图片保存路径
    imageSavePath = getImagePath();

    came_zb = new CameraZB(this);
    // 暂时，设备启动失败则退出
    if (!came_zb->initIPC_HDV()) {
        // 初始化失败则退出
        QMessageBox::warning(this, "设备tip", "中波相机初始化失败");
        qApp->quit();
    }
    
    
    serMan = new SerialManager(this);
    connect(serMan, &SerialManager::dataReceived, this, &CarF::UVInfoUpdate);
    
    portName = "COM1";
    serMan->openPort(portName);

    serverPort = 8602;
    eServer = new EchoServer(this,serverPort);
    eServer->startServer();

}

CarF::~CarF()
{
    //stopIPC_HDV();
    // 
    delete came_zb;
    came_zb = nullptr;
    delete serMan;
    serMan = nullptr;

    delete eServer;
    eServer = nullptr;
    

}

// 在源文件（.cpp）中实现：
//打开系统设置窗口
void CarF::on_pushButton_clicked()
{
    SystemSetting *secondWin = new SystemSetting(this);
    if (secondWin->exec() == QDialog::Accepted) { // 模态显示对话框
        imageSavePath= secondWin->getResult(); // 获取输入的文本
        //更新入库
        QString maxId=db->getMaxId("img_path");
        db->updateData("img_path", "url", imageSavePath, maxId);
        //saveStringToFile(imageSavePath, "imageSavePath.bin");  // 自动创建 subdir 目录和 example.txt 文件
    }
    else {
        QMessageBox::information(nullptr, "取消操作", "您取消了输入。");
    }
}
//打开指令记录窗口
void CarF::on_btnOrderLog_clicked()
{
    OrderLog *secondWin = new OrderLog(this);
    secondWin->exec(); // 模态显示对话框
}
void CarF::on_pbCameZBOpen_clicked()
{
    qDebug() << "123open";
    came_zb->camPlay();
    
}
void CarF::on_pbCameZBClose_clicked()
{
    qDebug() << "123close";
    came_zb->camStop();
}
void CarF::UVInfoUpdate(const QByteArray& data)
{
    qDebug() << "UVInfo::" << data;
    // 转
    QByteArray dataBuffer = data;
    parseData(dataBuffer);

}
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
    QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("控制无人车前进"));
}
/*
* 无人车控制 停止
*/
void CarF::on_btnStop_clicked() {
    //对接设备后，此处改为向第三方发送控制指令
    QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("停止"));
}