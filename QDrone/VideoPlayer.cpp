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
    // ��ʼ��FFmpeg (7.0.2���˳�ʼ��)
    avformat_network_init();

    // ������
    if (avformat_open_input(&formatContext, url.toUtf8().constData(), nullptr, nullptr) != 0) {
        qDebug() << "Could not open stream";
        return false;
    }

    // ��ȡ����Ϣ
    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        qDebug() << "Could not find stream info";
        return false;
    }

    // ������Ƶ��
    videoStreamIndex = av_find_best_stream(formatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &codec, 0);
    if (videoStreamIndex < 0) {
        qDebug() << "Could not find video stream";
        return false;
    }

    //codec  = avcodec_find_decoder(codecParameters->codec_id);
    //if (!codec) {
    //    qWarning("��֧�ֵĽ�����");
    //    return false;
    //}
    //codec = avcodec_find_decoder_by_name("h264_cuvid");  // NVIDIA
    //codec = avcodec_find_decoder_by_name("h264_qsv");  // Intel
    //codec = avcodec_find_decoder_by_name("hevc_cuvid");
    //codec = avcodec_find_decoder_by_name("hevc_qsv");
    
    // ���ý�����������
    codecContext = avcodec_alloc_context3(codec);
    avcodec_parameters_to_context(codecContext, formatContext->streams[videoStreamIndex]->codecpar);

    // �򿪽�����
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qDebug() << "Could not open codec";
        return false;
    }

    // ��ʼ��֡��ת��������
    frame = av_frame_alloc();
    frameRGB = av_frame_alloc();

    // ʹ���µĻ��������䷽ʽ
    av_image_alloc(frameRGB->data, frameRGB->linesize,
        codecContext->width, codecContext->height,
        AV_PIX_FMT_RGB32, 1);

    // ����ת��������
    swsContext = sws_getContext(codecContext->width, codecContext->height, codecContext->pix_fmt,
        codecContext->width, codecContext->height, AV_PIX_FMT_RGB32,
        SWS_BILINEAR, nullptr, nullptr, nullptr);

    // �����
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
                    // ת��֡��ʽ
                    sws_scale(swsContext,
                        (const uint8_t* const*)frame->data, frame->linesize,
                        0, codecContext->height,
                        frameRGB->data, frameRGB->linesize);

                    // ����QImage
                    QImage img(frameRGB->data[0],
                        codecContext->width, codecContext->height,
                        QImage::Format_RGB32);
                    image = img.copy(); // ���ȷ���̰߳�ȫ
                    update();
                }
            }
        }
        av_packet_unref(packet);
    }
}

void VideoPlayer::close() {
    timer->stop();

    // �ͷ���Դ(7.0.2��ʽ)
    av_packet_free(&packet);
    av_frame_free(&frame);
    av_frame_free(&frameRGB);
    sws_freeContext(swsContext);
    avcodec_free_context(&codecContext);
    avformat_close_input(&formatContext);

    // ����״̬
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
        // ���ֿ�߱�����
        QImage scaled = image.scaled(size(), Qt::KeepAspectRatio);
        painter.drawImage((width() - scaled.width()) / 2,
            (height() - scaled.height()) / 2,
            scaled);
    }
    else {
        // ��ͼ��ʱ���ƺ�ɫ����
        painter.fillRect(rect(), Qt::black);
    }
}
