#include "RtspStreamReader.h"
RtspStreamReader::RtspStreamReader(QObject* parent) : QObject(parent) {
    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &RtspStreamReader::readNextFrame);
}

RtspStreamReader::~RtspStreamReader() {
    closeStream();
}

bool RtspStreamReader::openStream(const QString& url) {
    // 打开输入流
    AVDictionary* options = nullptr;
    av_dict_set(&options, "rtsp_transport", "tcp", 0); // 使用TCP传输
    av_dict_set(&options, "stimeout", "5000000", 0);   // 设置超时5秒

    if (avformat_open_input(&formatContext, url.toUtf8().constData(), nullptr, &options) != 0) {
        qWarning() << "Could not open stream";
        return false;
    }

    if (avformat_find_stream_info(formatContext, nullptr) < 0) {
        qWarning() << "Could not find stream information";
        return false;
    }

    // 查找视频流
    for (unsigned int i = 0; i < formatContext->nb_streams; i++) {
        if (formatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            videoStreamIndex = i;
            break;
        }
    }

    if (videoStreamIndex == -1) {
        qWarning() << "Could not find video stream";
        return false;
    }

    // 获取解码器
    AVCodecParameters* codecParameters = formatContext->streams[videoStreamIndex]->codecpar;
    const AVCodec* codec = avcodec_find_decoder(codecParameters->codec_id);
    if (!codec) {
        qWarning() << "Unsupported codec";
        return false;
    }

    // 创建解码器上下文
    codecContext = avcodec_alloc_context3(codec);
    if (avcodec_parameters_to_context(codecContext, codecParameters) < 0) {
        qWarning() << "Could not copy codec context";
        return false;
    }

    // 打开解码器
    if (avcodec_open2(codecContext, codec, nullptr) < 0) {
        qWarning() << "Could not open codec";
        return false;
    }

    // 开始定时器读取帧
    timer->start(33); // ~30fps

    return true;
}

void RtspStreamReader::closeStream() {
    timer->stop();

    if (codecContext) {
        //avcodec_close(codecContext);
        avcodec_free_context(&codecContext);
        codecContext = nullptr;
    }

    if (formatContext) {
        avformat_close_input(&formatContext);
        formatContext = nullptr;
    }

    if (swsContext) {
        sws_freeContext(swsContext);
        swsContext = nullptr;
    }
}

void RtspStreamReader::readNextFrame() {
    //AVPacket packet;
    //av_init_packet(&packet);
    AVPacket* packet = av_packet_alloc();

    if (av_read_frame(formatContext, packet) >= 0) {
        if (packet->stream_index == videoStreamIndex) {
            // 发送包到解码器
            if (avcodec_send_packet(codecContext, packet) == 0) {
                AVFrame* frame = av_frame_alloc();
                if (avcodec_receive_frame(codecContext, frame) == 0) {
                    // 转换帧格式为RGB
                    if (!swsContext) {
                        swsContext = sws_getContext(
                            frame->width, frame->height, (AVPixelFormat)frame->format,
                            frame->width, frame->height, AV_PIX_FMT_RGB32,
                            SWS_BILINEAR, nullptr, nullptr, nullptr);
                    }

                    QImage image(frame->width, frame->height, QImage::Format_RGB32);
                    uint8_t* dest[4] = { image.bits(), nullptr, nullptr, nullptr };
                    int dest_linesize[4] = { static_cast<int>(image.bytesPerLine()), 0, 0, 0 };

                    sws_scale(swsContext, frame->data, frame->linesize, 0,
                        frame->height, dest, dest_linesize);

                    emit frameReady(image);
                }
                av_frame_free(&frame);
            }
        }
        av_packet_unref(packet);
    }
}