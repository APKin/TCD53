#include "StdAfx.h"
#include "Play.h"
//#include <time.inl>


CPlay::CPlay(void)
{
	m_lUserID = -1;
	m_nPlayHandle = -1;
}


CPlay::~CPlay(void)
{
	StopPlay();
}


int CPlay::Play(const char *cIp, void *hWnd)
{
	StopPlay();

	m_lUserID = g_sPlayStreamManage.PLAY_Open(cIp, 90, "admin", "admin");
	if (m_lUserID < 0)
	{
		return -1001;
	}

	m_nPlayHandle = g_sPlayStreamManage.PLAY_StartRealPlay(m_lUserID, 1, hWnd);
	if (m_nPlayHandle < 0)
	{
		return -1002;
	}

	return 1;
}

void CPlay::StopPlay()
{
	if (m_nPlayHandle >= 0)
	{
		g_sPlayStreamManage.PLAY_StopRealPlay(m_nPlayHandle);
		m_nPlayHandle = -1;
	}

	if (m_lUserID >= 0)
	{
		g_sPlayStreamManage.PLAY_Close(m_lUserID);
		m_lUserID = -1;
	}
}

//int CPlay::Snap(CStringW strDir, CStringW strJpgName)
//{
//	while(strDir.Right(1) == "\\")
//	{
//		strDir.Delete(strDir.GetLength() - 1);
//	}
//
//	if (!FileOperate::IsFolderExist(strDir))
//	{
//		if (!FileOperate::CreateFolder(strDir))
//		{
//			return -100001;
//		}
//	}
//
//	struct tm *t;
//	time_t tt;
//	time(&tt);
//	t = localtime(&tt);
//	CStringW strTime;
//	strTime.Format(L"%4d-%02d-%02d_%02d-%02d-%02d_%d_%s.jpg", 
//		t->tm_year+1900, t->tm_mon+1, t->tm_mday, 
//		t->tm_hour, t->tm_min, t->tm_sec, t, strJpgName);
//
//	if (m_nPlayHandle > 0)
//	{
//		int nRet = g_sPlayStreamManage.PLAY_CapturePicture(m_nPlayHandle, (CStringA)(strDir + L"\\" + strTime));
//		if (nRet > 0)
//		{
//			return 0;
//		}
//		else
//		{
//			return nRet;
//		}
//	}
//	else
//	{
//		return -100002;
//	}
//}