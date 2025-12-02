#pragma once

#include "GetLidarData.h"

class GetLidarData_MS06 : public GetLidarData
{
public:
	GetLidarData_MS06();
	~GetLidarData_MS06();

	void LidarRun() override;
	
	bool setLidarRotateState(int StateValue, std::string& InfoString) override;							//Lidar rotate/stationary 
	bool setLidarSoureSelection(int StateValue, std::string& InfoString) override;						//time source selection
	bool setLidarWorkState(int StateValue, std::string& InfoString) override;							//Lidar state, low power mode or not

	virtual bool  setFrameRateMode(int StateValue, std::string& InfoString);							//set Lidar frame rate mode
	virtual bool  setPhaseLockedSwitch(int StateValue, std::string& InfoString);						//set Lidar phase locked switch

	virtual bool setGatewayIP(std::string IPString, std::string& InfoString) override;					//set Gateway IP
	virtual bool setSubnetMaskIP(std::string IPString, std::string& InfoString) override;				//set Subnet Mask IP
	int m_StackFrame = 1;

	virtual bool getLidarParamState(LidarStateParam& mLidarStateParam, std::string& InfoString) override;
private:
	int count = 0;
	float m_fDistanceAcc = 0.004f;										//Distance accuracy: 4mm(0.004m)
	float m_fH_AngleAcc = 0.01f;										//horizontal angle accuracy: 0.01°
	float m_fV_AngleAcc = 0.01f;										//vertical  angle accuracy为: 0.01°
													
	float m_fPutTheMirrorOffAngle[4];									//The offset angle varies according to different channels
	float m_DeadZoneOffset = 10.82f;									//vertical  angle Offset rotation
	
	std::vector<MuchLidarData> PointCloudLastData;
	std::vector<MuchLidarData> tempPointCloud;
	void handleSingleEcho(unsigned char* data);									//single echo handling
	void handleDoubleEcho(unsigned char* data);									//double echo handling
	m_PointXYZ XYZ_calculate(int, float&, float&, float, float tDistance2);	//Coordinate conversion formula()  tDistance2： <=0, then he data of the second echo is not calculated
};

