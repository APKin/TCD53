#pragma once
#include "PlayStreamManage.h"
#include "FileOperate.h"

class CPlay
{
public:
	CPlay(void);
	~CPlay(void);

private:
	long m_lUserID;
	long m_nPlayHandle;

public:
	int Play(const char *cIp, void *hWnd);
	void StopPlay();
	//int Snap(CStringW strDir, CStringW strJpgName);
};

