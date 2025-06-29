#pragma once
#include "IPCSDK_CGI.h"
#include <QTimer>
#include <QXmlStreamReader>

struct GETValue
{

};

struct SETValue
{

};

class CarStatus
{
public:
	CarStatus();
	~CarStatus();



private:
	GETValue parseXmlWithStream_GET(QByteArray& getInfo);
	SETValue parseXmlWithStream_SET(QByteArray& setInfo);

};

