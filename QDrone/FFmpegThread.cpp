#include "FFmpegThread.h"
#include <QMutex>
#include <QImage>
#include <QDebug>
FFmpegThread::FFmpegThread(QObject* parent) : QThread(parent)
{
    setObjectName("FFmpegThread");
    stopped = false;
    isPlay = false;

    frameFinish = false;
    videoWidth = 0;
    videoHeight = 0;
    oldWidth = 0;
    oldHeight = 0;
    videoStreamIndex = -1;
    audioStreamIndex = -1;

    url = "rtsp://admin:Deye123456@192.168.31.65:554/ch1/main/av_stream";

    buffer = NULL;
    avPacket = NULL;
    avFrame = NULL;
    avFrame2 = NULL;
    avFrame3 = NULL;
    avFormatContext = NULL;
    videoCodec = NULL;
    audioCodec = NULL;
    swsContext = NULL;

    options = NULL;
    videoDecoder = NULL;
    audioDecoder = NULL;

    //��ʼ��ע��FFmpeg
    FFmpegThread::initlib();
}

//һ�������ֻ��Ҫ��ʼ��һ�ξ���
void FFmpegThread::initlib()
{
    static QMutex mutex;
    QMutexLocker locker(&mutex);
    static bool isInit = false;
    if (!isInit) {
        //ע��������п��õ��ļ���ʽ�ͽ�����
        // av_register_all();
        //ע�������豸,��Ҫ���ڱ������������֧��
#ifdef ffmpegdevice
        avdevice_register_all();
#endif
        //��ʼ����������ʽ,ʹ��������ʱ������ִ��
        avformat_network_init();

        isInit = true;
        qDebug() << TIMEMS << "init ffmpeg lib ok" << " version:" << FFMPEG_VERSION;
#if 0
        //�������֧�ֵĽ���������
        QStringList listCodeName;
        AVCodec* code = av_codec_next(NULL);
        while (code != NULL) {
            listCodeName << code->name;
            code = code->next;
        }

        qDebug() << TIMEMS << listCodeName;
#endif
    }
}

bool FFmpegThread::init()
{
    //�ڴ�����ǰָ�����ֲ�������:̽��ʱ��/��ʱʱ��/�����ʱ��
    // 
    //��tcp��ʽ��,�����udp��ʽ�򿪽�tcp�滻Ϊudp
    av_dict_set(&options, "rtsp_transport", "tcp", 0);
    //���ó�ʱ�Ͽ�����ʱ��,��λ΢��,3000000��ʾ3��
    av_dict_set(&options, "stimeout", "3000000", 0);
    //���û����С,1080p�ɽ�ֵ����
    av_dict_set(&options, "buffer_size", "8192000", 0);
    //�������ʱ��,��λ΢��,1000000��ʾ1��
    av_dict_set(&options, "max_delay", "1000000", 0);
    //�Զ������߳���
    av_dict_set(&options, "threads", "auto", 0);

    //����Ƶ��
    avFormatContext = avformat_alloc_context();

    int result = avformat_open_input(&avFormatContext, url.toUtf8().constData(), nullptr, &options); // url.toUtf8().constData() ,,url.toStdString().data()
    if (result < 0) {
        qDebug() << TIMEMS << ":" << result << "open input error" << url;
        return false;
    }

    //�ͷ����ò���
    if (options != NULL) {
        av_dict_free(&options);
    }

    //��ȡ����Ϣ
    result = avformat_find_stream_info(avFormatContext, NULL);
    if (result < 0) {
        qDebug() << TIMEMS << "find stream info error";
        return false;
    }

    //----------��Ƶ�����ֿ�ʼ----------
    if (1) {
        videoStreamIndex = av_find_best_stream(avFormatContext, AVMEDIA_TYPE_VIDEO, -1, -1, &videoDecoder, 0);
        if (videoStreamIndex < 0) {
            qDebug() << TIMEMS << "find video stream index error";
            return false;
        }

        //��ȡ��Ƶ��
        AVStream* videoStream = avFormatContext->streams[videoStreamIndex];

        //��ȡ��Ƶ��������,����ָ��������
        //videoCodec = videoStream->codec;

        videoCodec = avcodec_alloc_context3(NULL);
        avcodec_parameters_to_context(videoCodec, videoStream->codecpar);

        videoDecoder = avcodec_find_decoder(videoCodec->codec_id);
        //videoDecoder = avcodec_find_decoder_by_name("h264_qsv");
        if (videoDecoder == NULL) {
            qDebug() << TIMEMS << "video decoder not found";
            return false;
        }

        //���ü��ٽ���
        videoCodec->lowres = videoDecoder->max_lowres;
        videoCodec->flags2 |= AV_CODEC_FLAG2_FAST;

        //����Ƶ������
        result = avcodec_open2(videoCodec, videoDecoder, NULL);
        if (result < 0) {
            qDebug() << TIMEMS << "open video codec error";
            return false;
        }

        //��ȡ�ֱ��ʴ�С

        videoWidth = videoCodec->width;
        videoHeight = videoCodec->height;

        //���û�л�ȡ������򷵻�
        if (videoWidth == 0 || videoHeight == 0) {
            qDebug() << TIMEMS << "find width height error";
            return false;
        }

        QString videoInfo = QString("��Ƶ����Ϣ -> ����: %1  ����: %2  ��ʽ: %3  ʱ��: %4 ��  �ֱ���: %5*%6")
            .arg(videoStreamIndex).arg(videoDecoder->name).arg(avFormatContext->iformat->name)
            .arg((avFormatContext->duration) / 1000000).arg(videoWidth).arg(videoHeight);
        qDebug() << TIMEMS << videoInfo;
    }
    //----------��Ƶ�����ֽ���----------

    //----------��Ƶ�����ֿ�ʼ----------
    if (1) {
        //ѭ��������Ƶ������
        audioStreamIndex = -1;
        for (uint i = 0; i < avFormatContext->nb_streams; i++) {
            if (avFormatContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_AUDIO) {
                audioStreamIndex = i;
                break;
            }
        }

        //��Щû����Ƶ��,�������ﲻ�÷���
        if (audioStreamIndex == -1) {
            qDebug() << TIMEMS << "find audio stream index error";
        }
        else {
            //��ȡ��Ƶ��
            AVStream* audioStream = avFormatContext->streams[audioStreamIndex];
            // audioCodec = audioStream->codec;

            audioCodec = avcodec_alloc_context3(NULL);
            avcodec_parameters_to_context(audioCodec, audioStream->codecpar);

            //��ȡ��Ƶ��������,����ָ��������
            audioDecoder = avcodec_find_decoder(audioCodec->codec_id);
            //audioDecoder = avcodec_find_decoder_by_name("aac");
            if (audioDecoder == NULL) {
                qDebug() << TIMEMS << "audio codec not found";
                return false;
            }

            //����Ƶ������
            result = avcodec_open2(audioCodec, audioDecoder, NULL);
            if (result < 0) {
                qDebug() << TIMEMS << "open audio codec error";
                return false;
            }

            QString audioInfo = QString("��Ƶ����Ϣ -> ����: %1  ����: %2  ������: %3  ������: %4  ����: %5")
                .arg(audioStreamIndex).arg(audioDecoder->name).arg(avFormatContext->bit_rate)
                .arg(audioCodec->channels).arg(audioCodec->sample_rate);
            qDebug() << TIMEMS << audioInfo;
        }
    }
    //----------��Ƶ�����ֽ���----------

    //Ԥ������ڴ�
    avPacket = av_packet_alloc();
    avFrame = av_frame_alloc();
    avFrame2 = av_frame_alloc();
    avFrame3 = av_frame_alloc();

    //�Ƚ���һ���ļ��Ŀ�ȸ߶�,���ı�ʱ,��Ҫ���·����ڴ�
    if (oldWidth != videoWidth || oldHeight != videoHeight) {
        //int byte = avpicture_get_size(AV_PIX_FMT_RGB32, videoWidth, videoHeight);

        int align = 32;
        int byte = av_image_get_buffer_size(AV_PIX_FMT_RGB32, videoWidth, videoHeight, align);

        buffer = (uint8_t*)av_malloc(byte * sizeof(uint8_t));
        oldWidth = videoWidth;
        oldHeight = videoHeight;
    }

    //�������ظ�ʽ
    AVPixelFormat srcFormat = AV_PIX_FMT_YUV420P;
    AVPixelFormat dstFormat = AV_PIX_FMT_RGB32;
    //ͨ����������ȡ�����ʽ
    srcFormat = videoCodec->pix_fmt;

    //Ĭ������ٶȵĽ�����õ�SWS_FAST_BILINEAR����,���ܻᶪʧ����ͼƬ����,�������и��ĳ���������
    int flags = SWS_FAST_BILINEAR;

    //���ٻ���洢һ֡����
    //avpicture_fill((AVPicture *)avFrame3, buffer, dstFormat, videoWidth, videoHeight);
    av_image_fill_arrays(avFrame3->data, avFrame3->linesize, buffer, dstFormat, videoWidth, videoHeight, 1);

    //ͼ��ת��
    swsContext = sws_getContext(videoWidth, videoHeight, srcFormat, videoWidth, videoHeight, dstFormat, flags, NULL, NULL, NULL);

    //�����Ƶ��Ϣ
    //av_dump_format(avFormatContext, 0, url.toStdString().data(), 0);

    //qDebug() << TIMEMS << "init ffmpeg finsh";
    return true;
}

void FFmpegThread::run()
{
    while (!stopped) {
        //���ݱ�־λִ�г�ʼ������
        if (isPlay) {
            this->init();
            isPlay = false;
            continue;
        }

        if (av_read_frame(avFormatContext, avPacket) >= 0) {
            //�жϵ�ǰ������Ƶ������Ƶ
            int index = avPacket->stream_index;
            if (index == videoStreamIndex) {

#if 0
                avcodec_decode_video2(videoCodec, avFrame2, &frameFinish, avPacket);
#else
                frameFinish = avcodec_send_packet(videoCodec, avPacket);
                if (frameFinish < 0) {
                    continue;
                }

                frameFinish = avcodec_receive_frame(videoCodec, avFrame2);
                if (frameFinish < 0) {
                    continue;
                }
#endif

                if (frameFinish >= 0) {
                    //������ת��һ��ͼƬ
                    sws_scale(swsContext, (const uint8_t* const*)avFrame2->data, avFrame2->linesize, 0, videoHeight, avFrame3->data, avFrame3->linesize);

                    QImage image((uchar*)buffer, videoWidth, videoHeight, QImage::Format_RGB32);
                    if (!image.isNull()) {
                        emit receiveImage(image);
                    }

                    msleep(1);
                }
            }
            else if (index == audioStreamIndex) {

            }
        }

        av_packet_unref(avPacket);
        av_freep(avPacket);
        msleep(1);
    }

    //�߳̽������ͷ���Դ
    free();
    stopped = false;
    isPlay = false;
    qDebug() << TIMEMS << "stop ffmpeg thread";
}

void FFmpegThread::setUrl(const QString& url)
{
    this->url = url;
}

void FFmpegThread::free()
{
    if (swsContext != NULL) {
        sws_freeContext(swsContext);
        swsContext = NULL;
    }

    if (avPacket != NULL) {
        av_packet_unref(avPacket);
        avPacket = NULL;
    }

    if (avFrame != NULL) {
        av_frame_free(&avFrame);
        avFrame = NULL;
    }

    if (avFrame2 != NULL) {
        av_frame_free(&avFrame2);
        avFrame2 = NULL;
    }

    if (avFrame3 != NULL) {
        av_frame_free(&avFrame3);
        avFrame3 = NULL;
    }

    if (videoCodec != NULL) {
        avcodec_close(videoCodec);
        videoCodec = NULL;
    }

    if (audioCodec != NULL) {
        avcodec_close(audioCodec);
        audioCodec = NULL;
    }

    if (avFormatContext != NULL) {
        avformat_close_input(&avFormatContext);
        avFormatContext = NULL;
    }

    av_dict_free(&options);
    //qDebug() << TIMEMS << "close ffmpeg ok";
}

void FFmpegThread::play()
{
    //ͨ����־λ���߳�ִ�г�ʼ��
    isPlay = true;
}

void FFmpegThread::pause()
{

}

void FFmpegThread::next()
{

}

void FFmpegThread::stop()
{
    //ͨ����־λ���߳�ֹͣ
    stopped = true;
}