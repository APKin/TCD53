#pragma once

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>

class Configure
{
public:
	Configure();
	Configure* getInstance();
	
	QString getcarmZB() const;

	QString getCarmLightIP() const;

	QString getInfraredUrl() const;

	QString getInfraredIp() const;

	QString getConSysIP() const;
	
	int getConSysPort() const;

private:
	void readIni(const QByteArray& jsonData);

	// 配置文件路径
	QString iniPath;
	// 中波串口名称
	QString carmZB;
	// 可见光IP
	QString carmLightIP;
	// 激光器串口
	QString LaserCOM;
	// 红外全景URL
	QString InfraredUrl;

	// 红外全景IP
	QString InfraredIp;
	// 安防系统IP 、Port
	QString conSysIP;
	int conSysPort;
};

