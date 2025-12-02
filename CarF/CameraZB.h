//#pragma once
//
//#include "IPCSDK_Net.h";
//#include "IPCSDK_CGI.h"
//#include "HDVSDK_Play.h"
//#include <QObject>
//class CameraZB :public QObject
//{
//	Q_OBJECT
//public:
//	CameraZB(QWidget* parent = nullptr);
//
//	~CameraZB();
//
//	// 开启关闭播放设置
//	// 初始化网络和播放
//	bool initIPC_HDV();
//
//	void stopIPC_HDV();
//	// 登录
//	bool loginDev();
//
//	void camPlay();
//
//	void camPlay(HWND wid);
//
//	void camStop();
//
//
//	// 由于流程原因，部分暂时无法调用或测试函数放这里，以后删除
//	void back();
//
//public:
//	// 通道数，0-255 ;m_iChanNum < 0 || m_iChanNum > 255则失败
//	int m_iChanNum;
//	// encode类型
//	E_ENCODE_TYPE m_EncodeType;
//	// 用户ID值 -1为失败
//	long m_lUserID;
//
//	long m_lPlayHandle;
//	long m_lRealDataID;
//	long m_lRawDataID;
//
//
//
//};
//
