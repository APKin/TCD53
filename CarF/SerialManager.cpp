#include "SerialManager.h"
#include <QDebug>
SerialManager::SerialManager(QObject *parent)
	: QObject(parent)
{
	connect(&serial, &QSerialPort::readyRead, this, &SerialManager::readData);
}

SerialManager::~SerialManager()
{
    ;
}

bool SerialManager::openPort(const QString & portName)
{
    serial.setPortName(portName);
    // 以下是默认数据，理应从配置文件读取 APK 618
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);

    if (serial.open(QIODevice::ReadWrite)) {
        return true;
    }
    qDebug() << "Open error:" << serial.errorString();
    return false;
}

bool SerialManager::openPort()
{
    serial.setPortName(portName);
    // 以下是默认数据，理应从配置文件读取 APK
    serial.setBaudRate(QSerialPort::Baud115200);
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);

    if (serial.open(QIODevice::ReadWrite)) {
        return true;
    }
    qDebug() << "Open error:" << serial.errorString();
    return false;
}

void SerialManager::sendData(const QByteArray & data)
{
    if (serial.isOpen()) {
        serial.write(data);
        serial.waitForBytesWritten(1000);
    }
}

void SerialManager::closePort()
{
    serial.close();
}

void SerialManager::setPortName(const QString& value)
{
    portName = value;
}
