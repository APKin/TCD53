#include "httpnetwork.h"

HttpNetWork::HttpNetWork()
{
    url_zy = "https://www.demo.uavcmlc.com/open/api/developer/oapi/execute";
    nMan.reset(new QNetworkAccessManager());
//    nRep
    jParse.reset(new JsonParse);
}

int HttpNetWork::minData()
{

}
