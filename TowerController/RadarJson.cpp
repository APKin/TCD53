#include "RadarJson.h"


RadarJson::RadarJson()
{

}

QJsonObject RadarJson::setBWMode(int value)
{
   
    QJsonObject jsonObject;
    jsonObject.insert("needResponse", 1);
    jsonObject.insert("paramId", 17);
    QJsonObject params;
    params.insert("XcoreLACF1SetColPlt",value);
    jsonObject["params"] = params;
 
    
    return jsonObject;
}

QJsonObject RadarJson::setAGC(int value)
{
    QJsonObject jsonObject;
    jsonObject.insert("needResponse", 1);
    jsonObject.insert("paramId", 27);
    QJsonObject params;
    params.insert("XcoreLACF1SetAGCMode", value);
    jsonObject["params"] = params;

    return jsonObject;
}

QJsonObject RadarJson::setContrast(int value)
{
    QJsonObject jsonObject;
    jsonObject.insert("needResponse", 1);
    jsonObject.insert("paramId", 22);
    QJsonObject params;
    params.insert("XcoreLACF1SetContrast", value);
    jsonObject["params"] = params;

    return jsonObject;
}

QJsonObject RadarJson::setLight(int value)
{
    QJsonObject jsonObject;
    jsonObject.insert("needResponse", 1);
    jsonObject.insert("paramId", 23);
    QJsonObject params;
    params.insert("XcoreLACF1SetBrt", value);
    jsonObject["params"] = params;

    return jsonObject;
}

QJsonObject RadarJson::setSplicing(int value)
{
    QJsonObject jsonObject;
    jsonObject.insert("needResponse", 1);
    jsonObject.insert("paramId", 16842756);
    QJsonObject params;
    params.insert("circlefps", value);
    jsonObject["params"] = params;

    return jsonObject;
}

QJsonObject RadarJson::setLRPic(int lValue, int rValue)
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 16842759},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::setIP(QString ip)
{
    return QJsonObject();
}

QJsonObject RadarJson::QueryBWMode()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 17},
        {"query", 1},
    };

    return jsonObject;

}

QJsonObject RadarJson::QueryAGC()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 21},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::QueryContrast()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 22},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::QueryLight()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 23},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::QuerySplicing()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 16842756},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::QueryLRPic()
{
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 16842759},
        {"query", 1},
    };

    return jsonObject;
}

QJsonObject RadarJson::QueryIP()
{
    // 16777220
    QJsonObject jsonObject
    {
        {"needResponse", 1},
        {"paramId", 1684167772202759},
        {"query", 1},
    };
    return jsonObject;
}

QVector<int> RadarJson::replyFromRadar(const QJsonObject& reply)
{
    // 空代表失败
    // size 1 [0] = 0 代表设置
    // size N [0] = 1 代表查询 [1]
    QVector<int> vec;
    int errCode = reply.value("errcode").toInt();
    
    QString result = reply.value("result").toString();
    // 0 代表成功
    if (errCode == 0) {
        // 组装内容
        QJsonObject response = reply.value("response").toObject();
        if (response.isEmpty())
        {
            // 为空则是 2 设置命令
            vec.push_back(0);
            return vec;
        }
        else {
            // 1 查询命令
        }
        
        return vec;
    }
    else {
        return vec;
    }

    
}

