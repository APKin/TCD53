#pragma once

#include <QObject>

#include <QtSerialPort/QSerialPortInfo>
#include <QtSerialPort/QSerialPort>

#include "Global.h"

class SerialManager  : public QObject
{
	Q_OBJECT

public:
	SerialManager(QObject *parent);
	~SerialManager();

    bool openPort(const QString& portName);
    // 重载函数为了配合portName使用，大概率不会使用重载前的open
    bool openPort();
    
    

    void sendData(const QByteArray& data);

    void closePort();

    void setPortName(const QString& value);

    void processDataBuffer();

private slots:
    void readData(); 
public slots:
    bool isResetPortInf0(portInfo_ info);

signals:
    void dataReceived(const QByteArray& data);

private:
	QSerialPort serial;
    // 改为维护一个portName
	QString portName;
    // 充当缓冲
    QByteArray dataBuffer;
    const int PACKET_SIZE = 78;
    const QByteArray HEADER = QByteArray::fromHex("DA6A"); // 包头
};
