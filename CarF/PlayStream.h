#pragma once

#include "IPCSDK_Net.h"
#pragma comment(lib, "IPCSDK_Net.lib")

#include "HDVSDK_Play.h"
#pragma comment(lib, "HDVSDK_Play.lib")

class CPlayStream
{
public:
	CPlayStream(int nHandle, int nStreamMode, void *hWnd);
	~CPlayStream(void);

	int StartRealPlay(void);
	void StopRealPlay(void);
	int CapturePicture(const char *sPicFileName);

private:
	int m_nHandle;
	int m_nStreamMode;
	int m_lRealDataID;

public:
	int m_lPlayHandle;
	void *m_hWnd;

	int m_nPicture;
	char *m_cPicture;
};