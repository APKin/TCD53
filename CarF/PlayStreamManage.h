#pragma once
#include <map>
#include "PlayStream.h"

class CPlayStreamManage
{
public:
	CPlayStreamManage(void);
	~CPlayStreamManage(void);

private:
	std::map<long, CPlayStream*> m_mapPlayStreamInfo;

public:
	int PLAY_GetLastError();
	int PLAY_Setup();
	void PLAY_Cleanup();
	int PLAY_Open(const char *pStrIP, WORD wPort, const char *pStrUserName, const char *pStrPassword);
	int PLAY_Close(int nLoginID);
	int PLAY_StartRealPlay(int nLoginID, int nStreamMode, void *hWnd);
	int PLAY_StopRealPlay(int nPlayHandle);
	int PLAY_CapturePicture(int nPlayHandle, const char *sPicFileName);
};

extern CPlayStreamManage g_sPlayStreamManage;