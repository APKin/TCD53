#ifndef JSONPARSE_H
#define JSONPARSE_H

#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonValue>
#include <QJsonParseError>
#include <QVector>
#include <QList>
// 基站感知数据
struct uniData{
    float detectedTime; // 探测到的时间
    QString targetId; // 探测到的目标id
    float latitude;	// 纬度	number(float)	-
    QString btsCode;//	基站编码	string	-
    int targetIdCount;	//探测到该目标的序号数	integer(int32)	-
    float speed;	// 速度单位米每秒	number(float)	-
    float longitude;//	经度	number(float)	-
    float height ;//	高度	number(float)
    uniData():detectedTime(0.0),targetId(""),latitude(0.0),btsCode(""),targetIdCount(0),speed(0.0),longitude(0.0),height(0.0){};
};
// 基站感知数据
struct mData{
    QString msg; // 业务返回提示
    int code; // 业务返回码
    QVector<uniData> vData;

    mData():msg(""),code(0){}
    void vDataClear(){
        vData.clear();
    };
    void clear(){
        msg = "";
        code =0;
        vDataClear();
    };

};

class JsonParse
{
public:
    JsonParse();
    mData getCurMData() const;
    void setCurMData(const mData &value);

    void MDataParse(const QByteArray & revData);

private:
    mData curMData;

};

#endif // JSONPARSE_H
