#include "VideoPlayer.h"

#include <QPainter>
#include <QDebug>

VideoPlayer::VideoPlayer(QWidget *parent)
	: QWidget(parent)
{
	ui.setupUi(this);

	initFFmpeg();
	timer = new QTimer(this);
	connect(timer, &QTimer::timeout, this, &VideoPlayer::updateVideo);

}

VideoPlayer::~VideoPlayer()
{
	close();
	cleanupFFmpeg();
}

void VideoPlayer::initFFmpeg() {
    avformat_network_init();

}

void VideoPlayer::cleanupFFmpeg() {
    avformat_network_deinit();
}

// videoplayer.cpp
bool VideoPlayer::open(const QString& url) {
    // 初始化FFmpeg (7.0.2简化了初始化)
    avformat_network_init();

    // 打开输入
    if (avformat_open_input(&formatContext, url.toUtf8().constData(), nullptr, nullptr) != 0) {
        qDebug() << "Could not open stream";
        return false;
    }

    // 获取流信息
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        qDebug() << "Could not find stream info";
        return false;
    }

    // 查找视频流
    videoStreamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &codec, 0);
    if (videoStreamIndex < 0) {
        qDebug() << "Could not find video stream";
        return false;
    }

    //codec  = avcodec_find_decoder(codecParameters->codec_id);
    //if (!codec) {
    //    qWarning("不支持的解码器");
    //    return false;
    //}
    //codec = avcodec_find_decoder_by_name("h264_cuvid");  // NVIDIA
    //codec = avcodec_find_decoder_by_name("h264_qsv");  // Intel
    //codec = avcodec_find_decoder_by_name("hevc_cuvid");
    //codec = avcodec_find_decoder_by_name("hevc_qsv");
    
    // 设置解码器上下文
    codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar);

    // 打开解码器
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qDebug() << "Could not open codec";
        return false;
    }

    // 初始化帧和转换上下文
    frame = av_frame_alloc();
    frameRGB = av_frame_alloc();

    // 使用新的缓冲区分配方式
    av_image_alloc(frameRGB->data, frameRGB->linesize,
        codecContext->width, codecContext->height,
        AV_PIX_FMT_RGB32, 1);

    // 创建转换上下文
    swsContext = sws_getContext(codecContext->width, codecContext->height, codecContext->pix_fmt,
        codecContext->width, codecContext->height, AV_PIX_FMT_RGB32,
        SWS_BILINEAR, nullptr, nullptr, nullptr);

    // 分配包
    packet = av_packet_alloc();

    timer->start(33);
    return true;
}

void VideoPlayer::updateVideo() {
    int ret;

    while ((ret = av_read_frame(formatContext, packet)) >= 0) {
        if (packet->stream_index == videoStreamIndex) {
            if ((ret = avcodec_send_packet(codecContext, packet)) == 0) {
                while ((ret = avcodec_receive_frame(codecContext, frame)) == 0) {
                    // 转换帧格式
                    sws_scale(swsContext,
                        (const uint8_t* const*)frame->data, frame->linesize,
                        0, codecContext->height,
                        frameRGB->data, frameRGB->linesize);

                    // 更新QImage
                    QImage img(frameRGB->data[0],
                        codecContext->width, codecContext->height,
                        QImage::Format_RGB32);
                    image = img.copy(); // 深拷贝确保线程安全
                    update();
                }
            }
        }
        av_packet_unref(packet);
    }
}

void VideoPlayer::close() {
    timer->stop();

    // 释放资源(7.0.2方式)
    av_packet_free(&packet);
    av_frame_free(&frame);
    av_frame_free(&frameRGB);
    sws_freeContext(swsContext);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);

    // 重置状态
    videoStreamIndex = -1;
    swsContext = nullptr;
    formatContext = nullptr;
    codecContext = nullptr;
}

void VideoPlayer::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);

    QPainter painter(this);

    if (!image.isNull()) {
        // 保持宽高比缩放
        QImage scaled = image.scaled(size(), Qt::KeepAspectRatio);
        painter.drawImage((width() - scaled.width()) / 2,
            (height() - scaled.height()) / 2,
            scaled);
    }
    else {
        // 无图像时绘制黑色背景
        painter.fillRect(rect(), Qt::black);
    }
}
