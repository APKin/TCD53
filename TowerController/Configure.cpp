#include "Configure.h"
#include <QFile>
#include <QDebug>

Configure* Configure::getInstance()
{
    static Configure cf;
    return &cf;
}

QString Configure::getGrName() const
{
    return grName;
}

QString Configure::getInfraredUrl() const
{
    return InfraredUrl;
}

QString Configure::getInfraredIp() const
{

    return InfraredIp;
}

QString Configure::getConSysIP() const
{
    return conSysIP;
}

int Configure::getConSysPort() const
{
    return conSysPort;
}

QString Configure::getRemoteIP() const
{
    return remoteIP;
}

int Configure::getRemotePort() const
{
    return remotePort;
}

QString Configure::getWebReport() const
{
    return webReport;
}

void Configure::readIni(const QByteArray& jsonData)
{
    QJsonParseError parseError;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &parseError);
    if (parseError.error != QJsonParseError::NoError) {
        qDebug() << "JSON格式错误：" << parseError.errorString();
        return;
    }

    // 3. 获取根对象
    if (!doc.isObject()) {
        qDebug() << "JSON根元素不是一个对象。";
        return;
    }
    QJsonObject rootObj = doc.object();

    // 4. 提取数据
    // 提取

    InfraredUrl = rootObj["InfraredUrl"].toString();

    InfraredIp = rootObj["InfraredIp"].toString();
    // 提取
    grName = rootObj["grName"].toString();

    conSysIP = rootObj["conSysIP"].toString();
    // 提取数字 
    conSysPort = rootObj["conSysPort"].toInt(); // toBool

    // 远端
    remoteIP = rootObj["remoteIP"].toString();

    remotePort = rootObj["remotePort"].toInt();

    webReport = rootObj["webReport"].toString();

    // 提取数组
    //QJsonArray tagsArray = rootObj["tags"].toArray();
    //QStringList tags;
    //for (const QJsonValue& value : tagsArray) {
    //    tags.append(value.toString());
    //}

}

Configure::Configure() {
    iniPath = "ini//config.ini";

    QFile file(iniPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件！";
        return;
    }
    else
    {
        QByteArray jsonData = file.readAll();
        file.close();
        readIni(jsonData);
    }

}