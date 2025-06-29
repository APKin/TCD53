#pragma once
// 引ffmpeg
#include "ffmpeghead.h"

// ffmpeg 压缩和转发 test

class FFmpegComFor
{
public:
	int CompressAndForward();


	// 地址和输出地址，需要先set否则无法运行
	QString url;                    //视频流地址
	QString outUrl; // 转发地址

	//设置视频流地址
	void setUrl(const QString& url);
	void setOutUrl(const QString& outUrl);
};

