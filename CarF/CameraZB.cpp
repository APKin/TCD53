//#include "CameraZB.h"
//#include <QMessageBox>
//#include <QDebug>
//// 解码后数据回调
//void CALLBACK _CBDecodeFun(long               lPlayHandle,
//	const unsigned char* pBuf,
//	unsigned long       nBufSize,
//	S_FRAMEINFO* pFrameInfo,
//	void* pUserData)
//{
//	
//	return;
//}
//
//// 实时预览回调实时码流
//void CALLBACK RealData(long             lRealHandle,
//	E_REALDATA_TYPE  eDataType,
//	unsigned char* pBuffer,
//	unsigned long    lBufSize,
//	void* pUserData)
//{
//    CameraZB* pDlg = (CameraZB*)pUserData;
//    // 参数eDataType表示回调上来的码流数据类型，pBuffer存放码流数据，lBufSize存放码流数据大小
//    long m_lPlayHandle = 0;
//    HWND lightWid = nullptr;
//    switch (eDataType)  // 根据码流数据类型不同，分别处理不同的数据
//    {
//    case REALDATA_HEAD:    /* 实时流的头数据 */
//        
//        m_lPlayHandle = HDVPLAY_OpenStream(pBuffer, lBufSize);
//        if (m_lPlayHandle < 0)
//        {
//            qDebug() << QString("HDVPLAY_OpenStream\n");
//            return;
//        }
//        // 播放窗口指定 
//        
// /*       if (WId id = pDlg->effectiveWinId()) {
//            lightWid = reinterpret_cast<HWND>(id);
//        }*/
//
//        if (!HDVPLAY_Play(m_lPlayHandle, lightWid, true))
//        {
//            qDebug() << QString("HDVPLAY_Play\n");
//            return;
//        }
//        HDVPLAY_SetDecodeCallBack(m_lPlayHandle, _CBDecodeFun, pUserData);
//        break;
//    case REALDATA_VIDEO:  /*实时视频流数据*/
//        // 处理码流数据
//        if (!HDVPLAY_InputData(m_lPlayHandle, pBuffer, lBufSize))
//        {
//            qDebug() << QString("HDVPLAY_InputData\n");
//            return;
//        }
//        break;
//    case REALDATA_AUDIO:  /*实时音频流数据*/
//        // 处理码流数据
// /*       if (pDlg->m_nAudioState == 1)
//        {
//            if (!HDVPLAY_InputData(pDlg->m_lPlayHandle, pBuffer, lBufSize))
//            {
//                qDebug() << QString(("HDVPLAY_InputData\n");
//                return;
//            }
//        }
//        break;*/
//    default:
//        break;
//    }
//    return;
//}
//
//// 标准数据回调
//void CALLBACK RawData(long             lRawHandle,
//	S_AV_INFO* pAVInfo,
//	unsigned char* pRawBuffer,
//	unsigned long    lRawBufSize,
//	void* pUserData)
//{
//    return;
//
//}
//
//// 网络库异常状态监测
//void CALLBACK CBNetExceptionMsg(long lLoginID, long lRealHandle,
//	E_NET_EXCEPTION_TYPE eNetMsgType,
//	void* pUserData)
//{
//    return;
//}
//
//
//CameraZB::CameraZB(QWidget* parent):QObject(parent)
//{
//    // 获取来源？
//    m_EncodeType = ENCODE_H264; // ENCODE_MPEG4 ENCODE_H264_Hi3510 ENCODE_H265
//    m_lUserID = -1;
//    m_iChanNum = 0;
//    // 初始化
//    initIPC_HDV();
//    // 登录
//    bool isLogin = loginDev();
//    // login false
//    if (!isLogin)
//    {
//        ;
//    }
//}
//
//CameraZB::~CameraZB()
//{
//    stopIPC_HDV();
//}
//
//bool CameraZB::initIPC_HDV()
//{
//    if (!IPCNET_Init())
//    {
//        QMessageBox::warning(nullptr,QString("tip"),QString("中波相机初始化网络库失败！"));
//        
//        return false;
//    }
//    if (!HDVPLAY_Init())
//    {
//        QMessageBox::warning(nullptr, QString("tip"),QString("中波相机初始化播放库失败！"));
//        return false;
//    }
//    return true;
//}
//
//void CameraZB::stopIPC_HDV()
//{
//    IPCNET_Cleanup();
//    HDVPLAY_Cleanup();
//}
//
//bool CameraZB::loginDev()
//{
//    /*std::string devIp = "127.0.0.1";*/
//    QString devIP = "192.168.1.18";
//    m_lUserID = IPCNET_Login(devIP.toLocal8Bit().constData(), 90, "admin", "admin");
//    if (m_lUserID < 0)
//    {
//        QMessageBox::warning(nullptr, QString("tip"), QString("登录失败"));
//        return false;
//    }
//    return true;
//}
//
//void CameraZB::camPlay()
//{
//    camStop();
//    if (m_lUserID < 0)
//    {
//        QMessageBox::warning(nullptr, QString("tip"), QString("请先登录设备"));
//        return;
//    }
//    S_REALDATA_INFO sRealInfo;
//    sRealInfo.eEncodeType = m_EncodeType;
//    sRealInfo.lChannel = m_iChanNum;
//    sRealInfo.lStreamMode = 1;	// 子码流
//
//    m_lRealDataID = IPCNET_StartRealData(m_lUserID, &sRealInfo, RealData, this);
//    if (m_lRealDataID < 0)
//    {
//        QMessageBox::warning(nullptr, QString("tip"), QString("实时预览开启失败"));
//        return;
//    }
//    IPCNET_SetNetExceptionCallBack(CBNetExceptionMsg, this);
//
//}
//
//void CameraZB::camPlay(HWND wid)
//{
//    camStop();
//    if (m_lUserID < 0)
//    {
//        QMessageBox::warning(nullptr, QString("tip"), QString("请先登录设备"));
//        return;
//    }
//    S_REALDATA_INFO sRealInfo;
//    sRealInfo.eEncodeType = m_EncodeType;
//    sRealInfo.lChannel = m_iChanNum;
//    sRealInfo.lStreamMode = 1;	// 子码流
//
//    m_lRealDataID = IPCNET_StartRealData(m_lUserID, &sRealInfo, RealData, wid);
//    if (m_lRealDataID < 0)
//    {
//        QMessageBox::warning(nullptr, QString("tip"), QString("实时预览开启失败"));
//        return;
//    }
//    IPCNET_SetNetExceptionCallBack(CBNetExceptionMsg, wid);
//}
//
//void CameraZB::camStop()
//{
//    if (m_lRealDataID >= 0)
//    {
//        if (!IPCNET_StopRealData(m_lRealDataID))
//        {
//            
//            QMessageBox::warning(nullptr, QString("tip"), QString("实时预览停止失败"));
//            return;
//        }
//    }
//    if (m_lPlayHandle >= 0)
//    {
//        if (!HDVPLAY_Stop(m_lPlayHandle))
//        {
//            qDebug() << QString("HDVPLAY_Stop Faild!\n");
//        }
//        if (!HDVPLAY_CloseStream(m_lPlayHandle))
//        {
//            qDebug() << QString("HDVPLAY_CloseStream Faild!\n");
//        }
//        m_lPlayHandle = -1;
//    }
//    m_lRealDataID = -1;
//    //GetDlgItem(IDC_STATIC_VIDEO)->RedrawWindow();
//  
//}
