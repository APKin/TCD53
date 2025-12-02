#include "StdAfx.h"
#include "PlayStreamManage.h"

CPlayStreamManage g_sPlayStreamManage;

CPlayStreamManage::CPlayStreamManage(void)
{
	PLAY_Setup();
}


CPlayStreamManage::~CPlayStreamManage(void)
{
	PLAY_Cleanup();
}


int CPlayStreamManage::PLAY_GetLastError()
{
	return IPCNET_GetLastError();
}

int CPlayStreamManage::PLAY_Setup()
{
	if (!HDVPLAY_Init())
	{
		return -1;
	}
	if (!IPCNET_Init())
	{
		return -1;
	}

	return 0;
}

void CPlayStreamManage::PLAY_Cleanup()
{
	IPCNET_Cleanup();
	HDVPLAY_Cleanup();
}

int CPlayStreamManage::PLAY_Open(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword)
{
	return IPCNET_Login(pStrIP, wPort, pStrUserName, pStrPassword);
}

int CPlayStreamManage::PLAY_Close(int nLoginID)
{
	return IPCNET_Logout(nLoginID);
}

int CPlayStreamManage::PLAY_StartRealPlay(int nLoginID, int nStreamMode, void *hWnd)
{
	static long lPlayStreamID = 0;

	CPlayStream *pPlayStream = new CPlayStream(nLoginID, nStreamMode, hWnd);
	if (pPlayStream == NULL)
	{
		return -1;
	}

	if (pPlayStream->StartRealPlay() == -1)
	{
		if (pPlayStream != NULL)
		{
			pPlayStream->StopRealPlay();
			delete pPlayStream;
			pPlayStream = NULL;
		}
		return -1;
	}

	lPlayStreamID++;
	m_mapPlayStreamInfo[lPlayStreamID] = pPlayStream;
	return lPlayStreamID;
}

int CPlayStreamManage::PLAY_StopRealPlay(int nPlayHandle)
{
	std::map<long, CPlayStream*>::iterator iter = m_mapPlayStreamInfo.find(nPlayHandle);
	if (iter == m_mapPlayStreamInfo.end())
	{
		return -1;
	}

	CPlayStream *pPlayStreamInfo = (*iter).second;
	if (pPlayStreamInfo != NULL)
	{
		pPlayStreamInfo->StopRealPlay();
		delete pPlayStreamInfo;
		pPlayStreamInfo = NULL;
	}
	return 0;
}

int CPlayStreamManage::PLAY_CapturePicture(int nPlayHandle, const char *sPicFileName)
{
	std::map<long, CPlayStream*>::iterator iter = m_mapPlayStreamInfo.find(nPlayHandle);
	if (iter == m_mapPlayStreamInfo.end())
	{
		return -10001;
	}

	CPlayStream *pPlayStreamInfo = (*iter).second;
	if (pPlayStreamInfo != NULL)
	{
		return pPlayStreamInfo->CapturePicture(sPicFileName);
	}

	return -10002;
}