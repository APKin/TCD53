#pragma once
#include <QBytearray>
class LaserComand
{
public:

	// 计算激光器检验和
	uint32_t calculateCRC(const QByteArray& data);

	//可见光出光
	QByteArray lightOutLar();
	// 可见光关光：
	QByteArray lightCloseLar();
	//长波出光
	QByteArray longBauOutLar();
	//	长波关光
	QByteArray longBauCloseLar();

	// 功率档位设置(以3档为例)
	QByteArray changeDW(int index);
	// 发散角设置(以1档为例)
	QByteArray mradSet(int mradIndex);
	// 长波频率设置(以100Hz为例)
	// 长波频率设置(以100Hz为例)
		
	//长波占空比设置(以10 % 为例)
	QByteArray longBauPowerRate(short rate);
	// 参数查询

	// 蓝光干扰
	// 出光
	QByteArray blueOutLar();
	// 关光
	QByteArray blueCloseLar();
	// 电流
	QByteArray blueDW(short DW);



private:
	const QByteArray HEADER = QByteArray::fromHex("7E"); // 包头
	const QByteArray TAILER = QByteArray::fromHex("E7"); // 包头

};

