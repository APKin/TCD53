#pragma once

#include <QObject>

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>


class SerialManager  : public QObject
{
	Q_OBJECT

public:
	SerialManager(QObject *parent);
	~SerialManager();

    bool openPort(const QString& portName);

    // 惯导
    bool openPort_GD(const QString portName);
    // 重载函数为了配合portName使用，大概率不会使用重载前的open
    //bool openPort();

    bool openPort_Lar(const QString& portName);

    // 可见光 变背
    bool openPort_KJG(const QString& portName);
    
    void sendData(const QByteArray& data);

    void closePort();

    void setPortName(const QString& value);

    // 无人车状态
    void processDataBuffer();

    void processDataBuffer_ZT();

    void processDataBUffer_larse();

    void processDateBUffer_GD();

    void processDataBUfferr_MC();
private slots:
    void readData(); 

signals:
    void dataReceived(const QByteArray& data);

    void dataReceived_GD(const QByteArray& data);

private:
	QSerialPort serial;
    // 改为维护一个portName
	QString portName;
    // 充当缓冲
    QByteArray dataBuffer;
    const int PACKET_SIZE = 78;
    const QByteArray HEADER = QByteArray::fromHex("DA6A"); // 包头

    const int PACKET_SIZE_GD = 108;// 6C
    const QByteArray HEADER_GD = QByteArray::fromHex("55AA"); // 包头
};
