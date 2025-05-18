#include "FFmpegPlayer.h"
extern "C" {
#include "libavcodec/avcodec.h"
#include "libavdevice/avdevice.h"
#include "libavformat/avformat.h"
#include "libswscale/swscale.h"
#include "libavutil/time.h"
#include "libavutil/imgutils.h"
}

#include <QMutex>
#include <QMutexLocker>
#include <QImage>
#include <QtConcurrent/QtConcurrent>

#include "FFmpegPlayer.h"

static void avError(const QString& what, int errNum)
{
    char text[1024];
    av_strerror(errNum, text, sizeof(text));
    fprintf(stdout, "%s: %s\n", what.toLatin1().constData(), text);
}

class FFmpegIniter
{
public:
    FFmpegIniter() {
        avdevice_register_all();
        avformat_network_init();
    }
};


FFmpegPlayer::FFmpegPlayer(QObject* parent)
    : QObject(parent),
    mstoped(false),
    mmutex(new QMutex),
    mwatcher(new QFutureWatcher<void>(this))
{
}

FFmpegPlayer::~FFmpegPlayer()
{
    if (mwatcher->isRunning())
    {
        stop();
        mwatcher->waitForFinished();
    }
    delete mmutex;
}

void FFmpegPlayer::start()
{
    if (mwatcher->isRunning())
    {
        stop();
        mwatcher->waitForFinished();
    }
    mstoped = false;
    auto future = QtConcurrent::run(this, &FFmpegPlayer::run);
    mwatcher->setFuture(future);
}

void FFmpegPlayer::stop()
{
    QMutexLocker locker(mmutex);
    mstoped = true;
}

bool FFmpegPlayer::isRunning() const
{
    return mwatcher->isRunning();
}

void FFmpegPlayer::waitForFinished()
{
    mwatcher->waitForFinished();
}

bool FFmpegPlayer::isStoped() const
{
    auto _this = const_cast<FFmpegPlayer*>(this);
    QMutexLocker locker(_this->mmutex);
    return mstoped;
}

void FFmpegPlayer::run()
{
    static FFmpegIniter initer;

    // 创建输入目标
    AVFormatContext* srcContext = nullptr;
    int code = avformat_open_input(&srcContext, murl.toUtf8(), nullptr, nullptr);
    if (code != 0)
        return avError("avformat_open_input", code);

    code = avformat_find_stream_info(srcContext, nullptr);
    if (code < 0)
        return avError("avformat_find_stream_info", code);

    int srcVideoStreamIndex = -1;
    for (uint i = 0; i < srcContext->nb_streams; ++i)
    {
        if (srcContext->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO)
        {
            srcVideoStreamIndex = i;
            break;
        }
    }
    if (srcVideoStreamIndex == -1)
    {
        qInfo("error find srcVideoStreamIndex!");
        return;
    }

    AVStream* srcStream = srcContext->streams[srcVideoStreamIndex];
    const AVCodec* srcCodec = avcodec_find_decoder(srcStream->codecpar->codec_id);
    AVCodecContext* srcCodecContext = avcodec_alloc_context3(srcCodec);
    code = avcodec_parameters_to_context(srcCodecContext, srcStream->codecpar);
    if (code < 0)
        return avError("copy srcCodecContext", code);

    code = avcodec_open2(srcCodecContext, srcCodec, nullptr);
    if (code < 0)
        return avError("open srcCodecContext", code);

    av_dump_format(srcContext, 0, srcContext->url, 0);

    AVPixelFormat desFormat = AV_PIX_FMT_RGB24;

    SwsContext* swscontext = sws_getContext(srcCodecContext->width, srcCodecContext->height, srcCodecContext->pix_fmt,
        srcCodecContext->width, srcCodecContext->height, desFormat,
        SWS_BICUBIC, nullptr, nullptr, nullptr);

    AVPacket* srcPkt = av_packet_alloc();
    AVFrame* srcFrame = av_frame_alloc();

    AVFrame* desFrame = av_frame_alloc();
    desFrame->width = srcCodecContext->width;
    desFrame->height = srcCodecContext->height;
    desFrame->format = desFormat;
    desFrame->linesize[0] = desFrame->width;
    desFrame->linesize[1] = desFrame->width;
    desFrame->linesize[2] = desFrame->width;

    int bufferSize = av_image_get_buffer_size(desFormat, srcCodecContext->width, srcCodecContext->height, 1);
    uint8_t* buffer = (uint8_t*)av_malloc(bufferSize);
    av_image_fill_arrays(desFrame->data, desFrame->linesize, buffer,
        desFormat, desFrame->width, desFrame->height, 1);

    while (!isStoped())
    {
        // 解码
        code = av_read_frame(srcContext, srcPkt);
        if (code < 0)
        {
            avError("av_read_frame", code);
            break;
        }

        if (srcPkt->stream_index != srcVideoStreamIndex)
            continue;

        code = avcodec_send_packet(srcCodecContext, srcPkt);
        if (code < 0)
        {
            avError("avcodec_send_packet", code);
            continue;
        }

        code = avcodec_receive_frame(srcCodecContext, srcFrame);
        if (code < 0)
        {
            avError("avcodec_receive_frame", code);
            continue;
        }

        AVFrameSideData* sideData = av_frame_get_side_data(srcFrame, AV_FRAME_DATA_SEI_UNREGISTERED);
        if (sideData)
            fprintf(stdout, "side data %d: %s\n", sideData->type, sideData->data + 16);

        sws_scale(swscontext, (const unsigned char* const*)srcFrame->data, srcFrame->linesize, 0, srcFrame->height,
            desFrame->data, desFrame->linesize);

        QImage image(buffer, desFrame->width, desFrame->height, QImage::Format_RGB888);
        emit imageChanged(image.copy());

        av_packet_unref(srcPkt);
    }
    av_free(buffer);
    av_packet_free(&srcPkt);
    av_frame_free(&srcFrame);
    av_frame_free(&desFrame);
    //avcodec_close(srcCodecContext);
    avformat_close_input(&srcContext);
}