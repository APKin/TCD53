//#include "ffmpeg.h"
//
//FFmpegThread::FFmpegThread(QObject* parent) : QThread(parent)
//{
//    // 初始化代码保持不变...
//}
//
//void FFmpegThread::initlib()
//{
//    static QMutex mutex;
//    QMutexLocker locker(&mutex);
//    static bool isInit = false;
//    if (!isInit) {
//        // FFmpeg 7.0不再需要av_register_all()
//        // 初始化网络流格式
//        avformat_network_init();
//        isInit = true;
//        qDebug() << TIMEMS << "初始化FFmpeg库完成" << "版本:"; //  << FFMPEG_VERSION;
//    }
//}
//
//bool FFmpegThread::init()
//{
//    // 参数设置保持不变...
//
//    // 打开视频流
//    avFormatContext = avformat_alloc_context();
//    int result = avformat_open_input(&avFormatContext, url.toUtf8().constData(), NULL, &options);
//    if (result < 0) {
//        qDebug() << TIMEMS << "打开输入流错误" << url;
//        return false;
//    }
//
//    // 释放参数
//    if (options) {
//        av_dict_free(&options);
//    }
//
//    // 获取流信息
//    result = avformat_find_stream_info(avFormatContext, NULL);
//    if (result < 0) {
//        qDebug() << TIMEMS << "查找流信息错误";
//        return false;
//    }
//
//    //----------视频流部分----------
//    videoStreamIndex = av_find_best_stream(avFormatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &videoCodec, 0);
//    if (videoStreamIndex < 0) {
//        qDebug() << TIMEMS << "查找视频流索引错误";
//        return false;
//    }
//
//    // 获取视频流和解码器上下文
//    AVStream* videoStream = avFormatContext->streams[videoStreamIndex];
//    videoCodecCtx = avcodec_alloc_context3(videoCodec);
//    avcodec_parameters_to_context(videoCodecCtx, videoStream->codecpar);
//
//    // 设置解码器参数
//    videoCodecCtx->lowres = videoCodec->max_lowres;
//    videoCodecCtx->flags2 |= AV_CODEC_FLAG2_FAST;
//
//    // 打开视频解码器
//    result = avcodec_open2(videoCodecCtx, videoCodec, NULL);
//    if (result < 0) {
//        qDebug() << TIMEMS << "打开视频解码器错误";
//        return false;
//    }
//
//    // 获取分辨率
//    videoWidth = videoCodecCtx->width;
//    videoHeight = videoCodecCtx->height;
//
//    //----------音频流部分----------
//    // 类似视频流的处理，这里省略...
//
//    // 分配帧和包
//    avPacket = av_packet_alloc();
//    avFrame = av_frame_alloc();
//    avFrameRGB = av_frame_alloc();
//
//    // 分配图像缓冲区
//    if (oldWidth != videoWidth || oldHeight != videoHeight) {
//        av_free(buffer);
//        buffer = (uint8_t*)av_malloc(av_image_get_buffer_size(AV_PIX_FMT_RGB32, videoWidth, videoHeight, 1));
//        oldWidth = videoWidth;
//        oldHeight = videoHeight;
//    }
//
//    // 设置SWSContext进行图像转换
//    swsContext = sws_getContext(videoWidth, videoHeight, videoCodecCtx->pix_fmt,
//        videoWidth, videoHeight, AV_PIX_FMT_RGB32,
//        SWS_BILINEAR, NULL, NULL, NULL);
//
//    av_image_fill_arrays(avFrameRGB->data, avFrameRGB->linesize, buffer,
//        AV_PIX_FMT_RGB32, videoWidth, videoHeight, 1);
//
//    return true;
//}
//
//void FFmpegThread::run()
//{
//    while (!stopped) {
//        if (isPlay) {
//            this->init();
//            isPlay = false;
//            continue;
//        }
//
//        if (av_read_frame(avFormatContext, avPacket) >= 0) {
//            if (avPacket->stream_index == videoStreamIndex) {
//                // 发送包到解码器
//                int ret = avcodec_send_packet(videoCodecCtx, avPacket);
//                if (ret < 0) {
//                    av_packet_unref(avPacket);
//                    continue;
//                }
//
//                // 接收解码后的帧
//                while (ret >= 0) {
//                    ret = avcodec_receive_frame(videoCodecCtx, avFrame);
//                    if (ret == AVERROR(EAGAIN) || ret == AVERROR_EOF) {
//                        break;
//                    }
//                    else if (ret < 0) {
//                        qDebug() << "解码错误";
//                        break;
//                    }
//
//                    // 转换帧格式为RGB32
//                    sws_scale(swsContext, (const uint8_t* const*)avFrame->data,
//                        avFrame->linesize, 0, videoHeight,
//                        avFrameRGB->data, avFrameRGB->linesize);
//
//                    // 创建QImage并发送信号
//                    QImage image(buffer, videoWidth, videoHeight, QImage::Format_RGB32);
//                    if (!image.isNull()) {
//                        emit receiveImage(image);
//                    }
//                }
//            }
//            av_packet_unref(avPacket);
//        }
//        msleep(1);
//    }
//    free();
//}
//
//void FFmpegThread::setUrl(const QString& url)
//{
//    this->url = url;
//}
//
//void FFmpegThread::free()
//{
//    if (swsContext != NULL) {
//        sws_freeContext(swsContext);
//        swsContext = NULL;
//    }
//
//    if (avPacket != NULL) {
//        av_packet_unref(avPacket);
//        avPacket = NULL;
//    }
//
//    if (avFrame != NULL) {
//        av_frame_free(&avFrame);
//        avFrame = NULL;
//    
//
//    if (videoCodec != NULL) {
//        avcodec_close(videoCodec);
//        videoCodec = NULL;
//    }
//
//    if (audioCodec != NULL) {
//        avcodec_close(audioCodec);
//        audioCodec = NULL;
//    }
//
//    if (avFormatContext != NULL) {
//        avformat_close_input(&avFormatContext);
//        avFormatContext = NULL;
//    }
//
//    av_dict_free(&options);
//    //qDebug() << TIMEMS << "close ffmpeg ok";
//}
//
//void FFmpegThread::play()
//{
//    //通过标志位让线程执行初始化
//    isPlay = true;
//}
//
//void FFmpegThread::pause()
//{
//
//}
//
//void FFmpegThread::next()
//{
//
//}
//
//void FFmpegThread::stop()
//{
//    //通过标志位让线程停止
//    stopped = true;
//}