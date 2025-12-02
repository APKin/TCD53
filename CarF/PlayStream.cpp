#include "StdAfx.h"
#include "PlayStream.h"

// 实时预览回调实时码流
void CALLBACK RealData(long lRealHandle, E_REALDATA_TYPE eDataType, unsigned char *pBuffer, unsigned long lBufSize, void *pUserData)
{
	CPlayStream *pDlg = (CPlayStream*)pUserData;
	switch (eDataType)  // 根据码流数据类型不同，分别处理不同的数据
	{
	case REALDATA_HEAD:    /* 实时流的头数据 */
		pDlg->m_lPlayHandle = HDVPLAY_OpenStream(pBuffer,lBufSize);
		if(pDlg->m_lPlayHandle < 0)
		{
			AtlTrace("HDVPLAY_OpenStream\n");
			return;
		}
		if(!HDVPLAY_Play(pDlg->m_lPlayHandle, (HWND)pDlg->m_hWnd, true))
		{
			AtlTrace("HDVPLAY_Play\n");
			return;
		}
		break;
	case REALDATA_VIDEO:  /*实时视频流数据*/
		// 处理码流数据
		if(!HDVPLAY_InputData(pDlg->m_lPlayHandle, pBuffer, lBufSize))
		{
			AtlTrace("HDVPLAY_InputData\n");
			return;
		}
		break;
	default:
		break;
	}
	return;
}

CPlayStream::CPlayStream(int nHandle, int nStreamMode, void *hWnd)
	: m_nHandle(nHandle)
	, m_nStreamMode(nStreamMode)
	, m_hWnd(hWnd)
{
	m_lPlayHandle = -1;
	m_lRealDataID = -1;

	m_nPicture = 2 * 1024 * 1024;
	m_cPicture = new char[m_nPicture];
}


CPlayStream::~CPlayStream(void)
{
	if (m_cPicture)
	{
		delete m_cPicture;
		m_cPicture = NULL;
	}
}

int CPlayStream::StartRealPlay()
{
	S_REALDATA_INFO sRealInfo;
	sRealInfo.eEncodeType = ENCODE_H264;
	sRealInfo.lChannel = 0;
	sRealInfo.lStreamMode = m_nStreamMode;
	m_lRealDataID = IPCNET_StartRealData(m_nHandle, &sRealInfo, RealData, this);

	return m_lRealDataID;
}

void CPlayStream::StopRealPlay()
{
	if (m_lRealDataID >= 0)
	{
		IPCNET_StopRealData(m_lRealDataID);
		m_lRealDataID = -1;
	}

	if (m_lPlayHandle >= 0)
	{
		HDVPLAY_Stop(m_lPlayHandle);
		m_lPlayHandle = -1;
	}
}

int CPlayStream::CapturePicture(const char *sPicFileName)
{
	if (m_nHandle >= 0)
	{
		if (m_cPicture)
		{
			int nRet = IPCNET_CapturePicture(m_nHandle, m_cPicture, m_nPicture, 3000, 80);
			if (nRet > 0)
			{
				FILE *fp = fopen(sPicFileName, "wb+");
				if (fp != NULL)
				{
					fwrite(m_cPicture, 1, nRet, fp);
					fclose(fp);
					fp = NULL;
					return 0;//成功
				}
				else
				{
					//-1009:写文件失败
					return -1009;
				}
			}
			else
			{
				//-1001:打开Http端口失败
				//-1002:连接设备失败
				//-1003:发送请求失败
				//-1004:发送请求失败
				//-1005:图片大小异常
				//-1006:缓冲区太小
				//-1007:图片接收异常
				//-1008:设置超时失败
				return nRet;
			}
		}
	}

	//设备未登录
	return -1010;
}