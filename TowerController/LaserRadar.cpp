#include "LaserRadar.h"
#include <thread>

LaserRadar::LaserRadar()
{
	isRunning_lr = false; 

	cDataPort = 2368;
	cDevPort = 2369;
	cLidarIP = "192.168.1.200";
	cDestIP = "192.168.1.102";
	cGroupIp = "226.1.1.102";

	m_GetLidarData = new GetLidarData_MS06;
	m_GetLidarData->setPortAndIP(cDataPort, cDevPort, cDestIP, cLidarIP, cGroupIp);
}

LaserRadar::~LaserRadar()
{
	delete m_GetLidarData;
}

//LaserRadar* LaserRadar::Instance()
//{
//	static LaserRadar laRadar;
//	return &laRadar;
//}

void LaserRadar::laserRadarStart()
{
	m_GetLidarData->LidarStart();
	// 通过是否能够获取数据判断是否成功开启
	LidarStateParam mLidarStateParam;
	std::string mInfo1;
	if (!m_GetLidarData->getLidarParamState(mLidarStateParam, mInfo1)) {

		std::cout << mInfo1 << std::endl;
		isRunning_lr = false;

	}
	else {
		isRunning_lr = true;
	}
	//
	 
}

void LaserRadar::laserRadarStop()
{
	m_GetLidarData->LidarStop();
	isRunning_lr = false;

}

void LaserRadar::laserRadarCapData()
{
	std::thread capData([&]() {
		while (isRunning_lr)
		{
			if (m_GetLidarData->isFrameOK)
			{
				//			启动程序获取雷达数据，解析
				std::shared_ptr<std::vector<MuchLidarData>> m_LidarData_temp;
				std::string mInfo;
				if (!m_GetLidarData->getLidarPerFrameDate(m_LidarData_temp, mInfo))
				{
					std::cout << mInfo << std::endl;
					std::this_thread::sleep_for(std::chrono::milliseconds(1));
					continue;

				}
				std::cout << m_LidarData_temp->size() << std::endl;
			}
			else
			{
				std::this_thread::sleep_for(std::chrono::milliseconds(1));
			}
		}
		});
	

		//output the number of point cloud

	capData.detach();
}

bool LaserRadar::isRunning()
{
	return isRunning_lr;
}

bool LaserRadar::setLidarRotateSpeed(int SpeedValue, std::string& InfoString)
{
	return m_GetLidarData->setDataPort(SpeedValue,InfoString);
}

bool LaserRadar::setLidarIP(std::string IPString, std::string& InfoString)
{
	return m_GetLidarData->setLidarIP( IPString, InfoString);
}

bool LaserRadar::setComputerIP(std::string IPString, std::string& InfoString)
{
	return m_GetLidarData->setComputerIP(IPString,InfoString);
}

bool LaserRadar::setDataPort(int PortNum, std::string& InfoString)
{
	return  m_GetLidarData->setDataPort(PortNum, InfoString);
}

bool LaserRadar::setDevPort(int PortNum, std::string& InfoString)
{
	return  m_GetLidarData->setDevPort(PortNum, InfoString);
}

bool LaserRadar::setLidarWorkState(int StateValue, std::string& InfoString)
{
	return  m_GetLidarData->setLidarWorkState(StateValue, InfoString);
}

bool LaserRadar::setFrameRateMode(int StateValue, std::string& InfoString)
{
	return  m_GetLidarData->setFrameRateMode(StateValue, InfoString);
}
