#ifndef FFMPEG_DECODE_H
#define FFMPEG_DECODE_H

#define _CRT_SECURE_NO_WARNINGS
#include <QDebug>

extern "C"
{
#include "libavutil/opt.h"
#include "libavutil/time.h"
#include "libavutil/frame.h"
#include "libavutil/pixdesc.h"
#include "libavutil/avassert.h"
#include "libavutil/imgutils.h"
#include "libavutil/ffversion.h"
#include "libavcodec/avcodec.h"
#include "libswscale/swscale.h"
#include "libswresample/swresample.h"
#include "libavformat/avformat.h"
#include "libavfilter/avfilter.h"
#include "libavdevice/avdevice.h"


}


class FFmpeg_Decode
{
public:
    FFmpeg_Decode();
    ~FFmpeg_Decode();

    int FFmpeg_H264DecoderInit(int type);
    int FFmpeg_VideoDecoderInit(AVCodecParameters *pCodecPara);

    int FFmpeg_VideoDecoderRelease(void);
    int FFmpeg_H264Decode(unsigned char * buffer, int bufSize, int *framePara, unsigned char *RGBBuf);

private:
    struct AVCodecContext *pAVCodecCtx;
    struct AVCodec *pAVCodec;
    struct AVPacket *pAVPacket;
    struct AVFrame *pAVFrame;
    struct SwsContext* pSwsCtx;
    struct AVFrame *pAVFrameRGB;

};

#endif // FFMPEG_DECODE_H
