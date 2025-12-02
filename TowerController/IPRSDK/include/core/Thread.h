#ifndef _IRAY_THREAD_H_
#define _IRAY_THREAD_H_

#include "inc/base-def.h"

/// @brief 线程类
class Thread
{
public:
	Thread();
	virtual ~Thread();

	/// @brief 线程功能函数，需要由子类实现
	virtual void run() = 0;
	virtual void stop();
	virtual int  start();

	void resume();
	void suspend();

private:
	static DWORD WINAPI __task(LPVOID lpThreadParameter);

private:
	HANDLE handle;
};

#endif