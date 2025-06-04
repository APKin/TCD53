#include "jsonparse.h"

JsonParse::JsonParse()
{

}

mData JsonParse::getCurMData() const
{
    return curMData;
}

void JsonParse::setCurMData(const mData &value)
{
    curMData = value;
}

void JsonParse::MDataParse(const QByteArray &revData)
{
    curMData.clear();
    QJsonDocument jd = QJsonDocument::fromJson(revData);
    if(jd.isEmpty()){
        return ;
    }
    QJsonObject rootObj = jd.object();
    curMData.msg = rootObj.value("msg").toString();
    curMData.code = rootObj.value("code").toInt();
    QJsonArray dataArray = rootObj.value("data").toArray();
    for(QJsonValue arrVal :dataArray){
        QJsonObject obj = arrVal.toObject();
        uniData tempData;
        tempData.detectedTime = obj.value("detectedTime").toString().toFloat();
        tempData.targetId = obj.value("targetId").toString();
        tempData.latitude = obj.value("latitude").toString().toFloat();

        tempData.btsCode = obj.value("btsCode").toString();
        tempData.targetIdCount = obj.value("targetIdCount").toInt();

        tempData.speed = obj.value("speed").toString().toFloat();
        tempData.longitude = obj.value("longitude").toString().toFloat();
        tempData.height = obj.value("height").toString().toFloat();

        curMData.vData.push_back(tempData);
    }
}
