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
    // 重载函数为了配合portName使用，大概率不会使用重载前的open
    bool openPort();

    void sendData(const QByteArray& data);

    void closePort();

    void setPortName(const QString& value);

private slots:
    void readData() {
        QByteArray data = serial.readAll();
        emit dataReceived(data);
    }

signals:
    void dataReceived(const QByteArray& data);

private:
	QSerialPort serial;
    // 改为维护一个portName
	QString portName;
};
