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
	
	QString getGrName() const;

	QString getInfraredUrl() const;

	QString getInfraredIp() const;

	QString getConSysIP() const;
	
	int getConSysPort() const;

	QString getRemoteIP() const;

	int getRemotePort() const;

	QString getWebReport() const;

private:
	void readIni(const QByteArray& jsonData);

	// 配置文件路径
	QString iniPath;
	// 惯导串口名称
	QString grName;
	// 红外全景URL
	QString InfraredUrl;

	// 红外全景IP
	QString InfraredIp;
	// 安防系统IP 、Port
	QString conSysIP;
	int conSysPort;

	// 云端JAVA IP,Port
	QString remoteIP;
	int remotePort;

	QString webReport;
};

