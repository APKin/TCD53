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
    this->portName = portName;
    serial.setPortName(portName);
    
    serial.setBaudRate(QSerialPort::Baud115200);
    //if (!serial.setBaudRate(4600800)) {
    //    // 处理设置失败的情况
    //    qDebug() << "设置波特率失败";
    //}
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (serial.open(QIODevice::ReadWrite)) {
        return true;
    }
    qDebug() << "Open error:" << serial.errorString();
    return false;
}

bool SerialManager::openPort()
{
    serial.setPortName(portName);
    //
    serial.setBaudRate(QSerialPort::Baud115200);
    //if(!serial.setBaudRate(4600800)) {
    //    // 处理设置失败的情况
    //    qDebug() << "设置波特率失败";
    //}
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);
    
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

void SerialManager::processDataBuffer()
{
    // 循环处理直到没有完整数据包
    while (dataBuffer.size() >= PACKET_SIZE) {
        // 查找包头位置:cite[6]
        int headerIndex = dataBuffer.indexOf(HEADER);

        if (headerIndex == -1) {
            // 没有找到包头，清空无效数据
            dataBuffer.clear();
            return;
        }

        // 移除包头之前的所有数据
        if (headerIndex > 0) {
            dataBuffer.remove(0, headerIndex);
            continue; // 重新检查
        }

        // 此时dataBuffer以DA6A开头，检查长度是否足够
        if (dataBuffer.size() < PACKET_SIZE) {
            return; // 数据不够，等待更多数据
        }

        // 提取完整数据包
        QByteArray completePacket = dataBuffer.left(PACKET_SIZE);

        // 从缓冲区移除已处理的数据
        dataBuffer.remove(0, PACKET_SIZE);

        // 处理完整数据包
        emit dataReceived(completePacket);
    }
}

bool SerialManager::isResetPortInf0(portInfo_ info)
{
    if (serial.isOpen())
    {
        serial.close();
    }
    this->portName = info.portName;
    serial.setPortName(portName);

    if (!serial.setBaudRate(info.BaudRate)) {
        ;
    };
    // ?
    serial.setDataBits(QSerialPort::Data8);
    serial.setParity(QSerialPort::NoParity);
    serial.setStopBits(QSerialPort::OneStop);
    serial.setFlowControl(QSerialPort::NoFlowControl);

    if (serial.open(QIODevice::ReadWrite)) {
        return true;
    }
    qDebug() << "Open error:" << serial.errorString();
    return false;
}

void SerialManager::readData() {

    QByteArray newData = serial.readAll();
    dataBuffer.append(newData);
    // 
    processDataBuffer();

}