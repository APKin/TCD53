#pragma once

#include <windows.h>
#include <vector>
namespace Iray
{
#define MaxiAlarmImgLen (100 * 100 * 4 + 20)
#pragma pack(1)

	// 时间戳
	struct TimeData
	{
		int year;		// 年
		int month;		// 月
		int day;		// 日
		int hour;		// 时
		int minute;		// 分
		int second;		// 秒

		bool operator==(const TimeData& tData) const
		{
			return this->year == tData.year && this->month == tData.month
				&& this->day == tData.day && this->hour == tData.hour
				&& this->minute == tData.minute && this->second == tData.second;
		}

		TimeData& operator=(const TimeData& tData)
		{
			if (this != &tData)
			{
				this->year = tData.year;
				this->month = tData.month;
				this->day = tData.day;
				this->hour = tData.hour;
				this->minute = tData.minute;
				this->second = tData.second;
			}
			return *this;
		}
	};

	// 目标坐标
	struct TargetPos
	{
		int iPosX;		// 目标中心点x
		int iPosY;		// 目标中心点y
		int iRectX;		// 目标检测框x
		int iRectY;		// 目标检测框y
		int iRectWidth;	// 目标检测框宽
		int iRectHeight;// 目标检测框高
	};

	struct PosData
	{
		int iPosX;
		int iPosY;
	};

	// 单个目标信息
	struct TargetData
	{
		int id;				// 目标ID
		int type;			// 目标类型
		TargetPos curPos;	// 目标坐标
		float fTagPitchAngle; //目标俯仰角度
		float fTagPosAngle;  //目标方位角度
		int iDistance;		// 目标距离
		float fLongitude;	// 目标精度
		float fLatitude;	// 目标纬度
		float fSpeed;		// 目标速度
		int iTrackPosNum;	// 轨迹个数
		std::vector<PosData> vecTrackPos;	// 轨迹数据
		int iImgWidth;		// 切片
		int iImgHeight;		// 切片高
		int imgDataLen;		// 切片数据长度
		unsigned char data[MaxiAlarmImgLen]; // 切片数据,为RGB 32位数据
		std::string alarmZone;	// 报警区域
	};

	// 报警数据
	struct AlarmData
	{
		char strIp[30];	// 设备IP
		TimeData alarmTime;	// 报警时间
		short iPitchAngle;	// 设备俯仰角度,放大10倍
		int iImgWidth;		// 全景图宽
		int iImgHeight;		// 全景图高
		int iTargetNum;		// 目标个数
		std::vector<TargetData> vecTargetData;	// 目标数据

		bool operator==(const AlarmData &data) const
		{
			return this->strIp == data.strIp && this->alarmTime == data.alarmTime;
		}
	};

	// @brief 全景数据类(8位灰度数据)
	class panoramaData
	{
	public:
		panoramaData() {
			width = 0;
			height = 0;
			dataLength = 0;
			data = NULL;
		}

		panoramaData(int iWidth, int iHeight) {
			width = iWidth;
			height = iHeight;
			dataLength = iWidth * iHeight;
			data = new unsigned char[dataLength];
		}

		panoramaData(const panoramaData & panorData)
		{
			width = panorData.width;
			height = panorData.height;
			dataLength = panorData.dataLength;
			dataTime = panorData.dataTime;
			data = new unsigned char[panorData.dataLength];
			memmove(this->data, panorData.data, panorData.dataLength);
		}

		panoramaData& operator=(const panoramaData & panorData)
		{
			if (this != &panorData) {
				if (this->dataLength != panorData.dataLength) {
					if (this->data) {
						delete[] data;
						data = NULL;
					}
					data = new unsigned char[panorData.dataLength];
				}

				width = panorData.width;
				height = panorData.height;
				dataLength = panorData.dataLength;
				dataTime = panorData.dataTime;
				memmove(this->data, panorData.data, panorData.dataLength);
			}
			return *this;
		}

		~panoramaData() {
			delete[]data;
			data = NULL;
		}

		TimeData dataTime; // 数据时间
		unsigned width; //全景图宽度
		unsigned height;//全景图高度
		unsigned char *data;//全景帧数据
		unsigned dataLength; //全景帧数据长度
	};

	// @brief 全景数据类(8位灰度数据)
	class panorama4x90Data
	{
	public:
		panorama4x90Data() {
			width = 0;
			height = 0;
			dataLength = 0;
			data = NULL;
			strDevIp = "";
		}

		panorama4x90Data(int iWidth, int iHeight) {
			width = iWidth;
			height = iHeight;
			dataLength = iWidth * iHeight;
			data = new unsigned char[dataLength];
			strDevIp = "";
		}

		panorama4x90Data(const panorama4x90Data & panorData)
		{
			width = panorData.width;
			height = panorData.height;
			dataLength = panorData.dataLength;
			data = new unsigned char[panorData.dataLength];
			strDevIp = panorData.strDevIp;
			timeData = panorData.timeData;
			memmove(this->data, panorData.data, panorData.dataLength);
		}

		panorama4x90Data& operator=(const panorama4x90Data & panorData)
		{
			if (this != &panorData) {
				if (this->dataLength != panorData.dataLength) {
					if (this->data) {
						delete[] data;
						data = NULL;
					}
					data = new unsigned char[panorData.dataLength];
				}

				width = panorData.width;
				height = panorData.height;
				dataLength = panorData.dataLength;
				strDevIp = panorData.strDevIp;
				timeData = panorData.timeData;
				memmove(this->data, panorData.data, panorData.dataLength);
			}
			return *this;
		}

		~panorama4x90Data() {
			delete[]data;
			data = NULL;
		}

		unsigned width; //全景图宽度
		unsigned height;//全景图高度
		unsigned char *data;//全景帧数据
		unsigned dataLength; //全景帧数据长度
		std::string strDevIp; //设备IP
		TimeData timeData;   //时间
	};

	struct InfraredImgData
	{
		//std::string strIp;
		//TimeData imgTime;
		//int iImgWidth;		// 全景图宽
		//int iImgHeight;		// 全景图高 
		//int imgDataLen;
		//unsigned char *data;

		std::string strIp;
		TimeData imgTime;
		int iSeq;			// 图像序号
		int iSumSeq;		// 图像总序号
		int iLeftCutNum;	// 左裁剪
		int iRightCutNum;	// 右裁剪
		int iMoveNum;		// 偏移
		int iImgWidth;		// 全景图宽
		int iImgHeight;		// 全景图高 
		int imgDataLen;
		unsigned char *data;
	};

	enum RectType
	{
		PurpleRect = 1, //紫色大框
		GreenRect,      //绿色框
		BlueRect,       //蓝色框
		YellowRect      //黄色框
	};

	enum CtrlCmdType
	{
		RectLeftSlowMove = (PurpleRect << 24) | (GreenRect << 16) | (BlueRect << 8) | YellowRect, //矩形框向左慢移
		RectLeftFastMove, //矩形框向左快移

		RectRightSlowMove,//矩形框向右慢移
		RectRightFastMove,//矩形框向右快移

		RectUpMove,       //矩形框向上移动
		RectDownMove,     //矩形框向下移动

		RectZoom,         //矩形框缩放
		GPSDataQuery      //GPS数据查询
	};

	struct RectCmdParam
	{
		RectType rectType; //矩形框类型
		unsigned char startStopFlag; //0 :stop, 1: start，开始或停止移动标志，发送缩放命令时不需要设置
		unsigned char zoomValue; // 缩放倍数值(1~6)，发送移动命令时不需要设置
	};

	struct GPSData
	{
		int iLat; //纬度，除1000000得到真实值
		char latHemisphere; //纬度半球；1表示北半球（N）,2表示南半球（S）
		int iLng; //经度，除1000000得到真实值
		char lngHemisphere; //经度半球  1表示西半球（W）,2表示东半球（E）
	};

#pragma pack()
};