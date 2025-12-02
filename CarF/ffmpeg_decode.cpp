#include "ffmpeg_decode.h"
#pragma warning(disable:4996)
FFmpeg_Decode::FFmpeg_Decode()
{
    pAVCodecCtx = NULL;

    pAVFrame = NULL;
    pAVFrameRGB = NULL;

    pSwsCtx = NULL;

}

int FFmpeg_Decode::FFmpeg_H264DecoderInit(int type)
{
    // 注册ffmpeg插件
    av_register_all();

    // 关闭ffmpeg输出log日志
    av_log_set_level(AV_LOG_QUIET);

    // 创建并查找解码器AVCodec
    AVCodec *pCodec;
    if(type == 0)
    {
        pCodec = avcodec_find_decoder(AV_CODEC_ID_H264);
    }else if(type == 1)
    {
        pCodec = avcodec_find_decoder(AV_CODEC_ID_H265);
    }else
    {
        return -1;
    }

    if(pCodec == NULL)
    {
        qDebug() << "ERROR: FFmpeg_H264DecoderInit -> avcodec_find_decoder...";
        return -1;
    }

    // 创建初始化编解码器上下文AVCodecContext
    AVCodecContext *pCodecCtx = avcodec_alloc_context3(pCodec);
    if(pCodecCtx == NULL)
    {
        qDebug() << "ERROR: FFmpeg_H264DecoderInit -> avcodec_alloc_context3...";
        return -2;
    }

    // 创建，获取编解码器参数AVCodecParameters
    AVCodecParameters *pCodecPara = avcodec_parameters_alloc();
    if(avcodec_parameters_from_context(pCodecPara,pCodecCtx) < 0)
    {
        qDebug() << "ERROR: FFmpeg_H264DecoderInit -> avcodec_parameters_alloc...";
        avcodec_parameters_free(&pCodecPara);
        avcodec_free_context(&pCodecCtx);
        return -3;
    }

    // 初始化解码器
    int ret = FFmpeg_VideoDecoderInit(pCodecPara);

    // 释放
    avcodec_parameters_free(&pCodecPara);
    avcodec_free_context(&pCodecCtx);

    return ret;
}

int FFmpeg_Decode::FFmpeg_VideoDecoderInit(AVCodecParameters *pCodecPara)
{

    if(pCodecPara == NULL)
    {
        qDebug() << "ERROR: FFmpeg_VideoDecoderInit -> pCodecPara is NULL...";
        return -1;
    }

    // 注册解码器
    avcodec_register_all();

    // 查找解码器AVCodec
    pAVCodec = avcodec_find_decoder(pCodecPara->codec_id);
    if(pAVCodec == NULL)
    {
        qDebug() << "ERROR: FFmpeg_VideoDecoderInit -> avcodec_find_decoder...";
        return -2;
    }

    // 创建，初始化编解码器上下文AVCodecContext
    pAVCodecCtx = avcodec_alloc_context3(pAVCodec);
    if(pAVCodecCtx == NULL)
    {
        qDebug() << "ERROR: FFmpeg_VideoDecoderInit -> avcodec_alloc_context3...";
        return -2;
    }

    // 拷贝编解码器参数AVCodecParameters 到 编解码器上下文AVCodecContext
    if(avcodec_parameters_to_context(pAVCodecCtx,pCodecPara) < 0)
    {
        qDebug() << "ERROR: FFmpeg_VideoDecoderInit -> avcodec_parameters_to_context...";
        return -3;
    }

    // 打开解码器
    if(avcodec_open2(pAVCodecCtx,pAVCodec,NULL) < 0)
    {
        qDebug() << "ERROR: FFmpeg_VideoDecoderInit -> avcodec_open2...";
        return -4;
    }

    // 初始化AVPacket, AVFrame
    pAVPacket = (struct AVPacket*)av_malloc(sizeof(struct AVPacket));
    av_init_packet(pAVPacket);

    pAVFrame = av_frame_alloc();
    pAVFrameRGB = av_frame_alloc();

    return 0;
}

int FFmpeg_Decode::FFmpeg_VideoDecoderRelease()
{
    if (pAVCodecCtx != NULL) {
        avcodec_free_context(&pAVCodecCtx);
        pAVCodecCtx = NULL;
    }

    if (pAVFrame != NULL) {
        av_packet_unref(pAVPacket);
        av_free(pAVPacket);
        av_free(pAVFrame);
        pAVFrame = NULL;
    }

    if (pAVFrameRGB) {
        av_frame_unref(pAVFrameRGB);
        av_free(pAVFrameRGB);
        pAVFrameRGB = NULL;
    }

    if (pSwsCtx) {
        sws_freeContext(pSwsCtx);
    }


    return 0;
}

int FFmpeg_Decode::FFmpeg_H264Decode(unsigned char * buffer, int bufSize, int *framePara, unsigned char *RGBBuf)
{
    if (!pAVCodecCtx || !pAVFrame || !buffer || bufSize<=0 || !framePara || !RGBBuf)
        return -1;

    av_frame_unref(pAVFrame);
    av_frame_unref(pAVFrameRGB);

    framePara[0] = 0;
    framePara[1] = 0;

    pAVPacket->data = buffer;
    pAVPacket->size = bufSize;

    int ret = avcodec_send_packet(pAVCodecCtx,pAVPacket);
    if(ret == 0)
    {
        ret = avcodec_receive_frame(pAVCodecCtx,pAVFrame);
        fflush(stdout);
        if(ret == 0)
        {
            framePara[0] = pAVFrame->width;
            framePara[1] = pAVFrame->height;

            //qDebug() << "pAVFrame I P B: " << pAVFrame->pict_type;

            pAVFrameRGB->data[0] = RGBBuf;
            pAVFrameRGB->data[1] = NULL;
            pAVFrameRGB->data[2] = NULL;
            pAVFrameRGB->data[3] = NULL;

            int linesize[4] = { pAVCodecCtx->width * 3, pAVCodecCtx->height * 3, 0, 0 };
            pSwsCtx = sws_getContext(pAVCodecCtx->width,pAVCodecCtx->height,AV_PIX_FMT_YUV420P,pAVCodecCtx->width,pAVCodecCtx->height, AV_PIX_FMT_RGB24, SWS_BILINEAR, NULL, NULL, NULL);
            sws_scale(pSwsCtx, (const uint8_t* const *)pAVFrame->data, pAVFrame->linesize, 0, pAVCodecCtx->height,pAVFrameRGB->data,linesize);
            sws_freeContext(pSwsCtx);

            return 1;
        }else if (ret == AVERROR(EAGAIN))
        {
            return 0;
        }else
        {
            return -1;
        }


    }
    return -2;

}
