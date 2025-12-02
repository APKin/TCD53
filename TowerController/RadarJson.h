#pragma once
#include <QJsonDocument>

#include <QJsonObject>
#include <QJsonArray>
#include <QVector>

class RadarJson
{
public:
    RadarJson();

    // 设置命令
    QJsonObject setBWMode(int value);

    QJsonObject setAGC(int value);
    // 对比度
    QJsonObject setContrast(int value);
    // 亮度
    QJsonObject setLight(int value);
    // 全景拼接张数
    QJsonObject setSplicing(int value);
    // 拼接左右
    QJsonObject setLRPic(int lValue, int rValue);

    // ip
    QJsonObject setIP(QString ip);
    // 查询命令
    // 黑白
    QJsonObject QueryBWMode();

    QJsonObject QueryAGC();
    // 对比度
    QJsonObject QueryContrast();
    // 亮度
    QJsonObject QueryLight();
    // 全景拼接张数
    QJsonObject QuerySplicing();
    // 拼接左右
    QJsonObject QueryLRPic();
    // IP
    QJsonObject QueryIP();


    // 雷达应答解析
    QVector<int> replyFromRadar(const QJsonObject &reply);




};
