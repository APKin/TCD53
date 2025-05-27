#ifndef HTTPNETWORK_H
#define HTTPNETWORK_H

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include "jsonparse.h"


#include <time.h>

class HttpNetWork
{
public:
    HttpNetWork();
    // 基站感知数据
    int minData();

private:
    std::unique_ptr<QNetworkAccessManager> nMan;
    std::unique_ptr<QNetworkReply> nRep;
    std::unique_ptr<JsonParse> jParse;

    QUrl url_zy;

};

#endif // HTTPNETWORK_H
