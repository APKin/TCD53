#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include "ui_CarF.h"
#include "OrderLog.h"
#include "PictureSave.h"
#include "SystemSetting.h"

#include "EchoServer.h"

// 定时获取的无人车状态
#include <QTimer>
#include "SerialManager.h"
#include "CameraZB.h"

#include <QTcpSocket>
// 解析
const int MIN_FRAME_SIZE = 7;     // 最小帧长度（不含Payload）

// 无人车状态信息，解析自Payload
struct UVStatus
{
    quint32 timestamp; // Unix时间戳 (秒)
    quint8 vehicle_id; // 车辆ID (预定义映射, 如 "UV001" -> 1) "UV001"
    quint32 utm_easting_cm; // UTM东向坐标 (JSON easting_m * 100), 单位: cm
    quint32 utm_northing_cm; // UTM北向坐标 (JSON northing_m * 100), 单位: cm
    qint16 heading_angle; // 航向角，实际值 * 10 (单位: 0.1°)
    quint16 speed; // 速度，实际值 * 10 (单位: 0.1 m/s)
    quint8 battery_level; // 电量百分比 (0-100)
    qint16 horizontal_inclination;  // 水平倾角，实际值 * 10 (单位: 0.1°)
    quint8 vehicle_state; // 车辆状态 (预定义映射, 如 "ok" -> 0x00)
        
};

// 总控指令信息，解析自Payload
struct CCUCommand
{
    quint32 timestamp; // Unix时间戳(秒)
    quint8 vehicle_id; // 车辆ID(预定义映射, 如 "UV001" -> 1)
    quint32 target_utm_easting_cm; // 目标UTM东向坐标(JSON easting_m * 100), 单位: cm
    quint32 target_utm_northing_cm; // 目标UTM北向坐标(JSON northing_m * 100), 单位 : cm
    qint16 target_heading_angle; // 目标航向角，实际值 * 10 (单位 : 0.1°)
    quint8 command_flags; // "命令标志位: Bit 0 : start_command(1 = start, 0 = no action)     Bit 1 : stop_command(1 = stop, 0 = no action)     Bits 2 - 7 : 保留(置0)"  

};

class CarF : public QMainWindow
{
    Q_OBJECT

public:
    CarF(QWidget *parent = nullptr);
    ~CarF();
    static QString imageSavePath; // 声明静态变量（不初始化）

    //bool initIPC_HDV();
    //void stopIPC_HDV();


//signals:
//    void updateUVStatus();

private:
    Ui::CarFClass ui;

    std::unique_ptr<OrderLog> OrderLog_;
    std::unique_ptr<PictureSave> PictureSave_;
    std::unique_ptr<SystemSetting> SystemSetting_;
private slots:
    //打开系统设置界面
    void on_pushButton_clicked();
    //void saveStringToFile(   QString& text, const QString& filename);
    QString getImagePath();
    //保存图像存储路径
    void saveStringToFile(const QString& text, const QString& filename);
    //读取文件存储路径配置
    QString readFileIfExists(const QString& filename);
    //无人车控制 自动前进
    void on_btnAutoDisplay_clicked();
    //无人车控制 停止
    void on_btnStop_clicked();
    //指令日志
    void on_btnOrderLog_clicked();
    // 中波相机开启
    void on_pbCameZBOpen_clicked();
    // 中波相机 关闭
    void on_pbCameZBClose_clicked();

    // 无人车串口信息
    //void UVInfoUpdate_json(QJsonObject data);

    void UVInfoUpdate(QByteArray data);


private:
    // 中波相机
    CameraZB* came_zb;
    // 串口使用
    SerialManager* serMan;
    // 使用串口
    QString portName;

    int serverPort;
    EchoServer* eServer;

    // 计算CRC的辅助函数（
    quint8 calculateCRC(quint8 msg_type, quint8 length,const QByteArray& payload);

    // 解析主函数（dataBuffer是累积数据的缓冲区）
    void parseData(QByteArray& dataBuffer); 

    static const QByteArray SOF_BYTES;   // 存储为 AA 55
    static const QByteArray EOF_BYTES;   // 存储为 0D 0A
    // 负责记录无人车传输信息
    UVStatus uvs;
    CCUCommand cc; 

    QTcpSocket* client_UVStatus;
};
