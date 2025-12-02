#pragma once

#include <QString>
struct portInfo_ {
	QString portName;
	int BaudRate;
	int DataBits;
	int Parity;
	int StopBits;
	bool isHigh;

};
