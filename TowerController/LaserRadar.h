#pragma once

#include "GetLidarData_MS06.h"
#include <string>

class LaserRadar
{
public:
	LaserRadar();
	~LaserRadar();
	//static LaserRadar* Instance();
	void laserRadarStart();
	void laserRadarStop();

	void laserRadarCapData();


	// 获取是否开启设备
	bool isRunning();

	//  修改雷达转速参数；
	bool  setLidarRotateSpeed(int SpeedValue, std::string& InfoString);

	// 修改雷达IP参数
	bool setLidarIP(std::string IPString, std::string& InfoString);

	//  修改目的 IP参数；
	bool setComputerIP(std::string IPString, std::string& InfoString);

	// 修改数据包端口；
	bool setDataPort(int PortNum, std::string& InfoString);

	// 修改设备包端口
	bool setDevPort(int PortNum, std::string& InfoString);

	// 修改 雷达工作状态
	bool setLidarWorkState(int StateValue, std::string& InfoString);

	// 修改雷达 帧率切换
	bool setFrameRateMode(int StateValue, std::string& InfoString);
private:
	GetLidarData* m_GetLidarData;

	// flag
	bool isRunning_lr;

	int cDataPort;
	int cDevPort;
	std::string cLidarIP ;
	std::string cDestIP ;
	std::string cGroupIp ;
	
};

