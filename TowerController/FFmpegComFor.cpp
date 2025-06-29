#include "FFmpegComFor.h"

int FFmpegComFor::CompressAndForward()
{
    // 1. 初始化FFmpeg

    avformat_network_init();
    // 设置地址
    const char* input_url = url.toUtf8().constData();
    const char* output_url = outUrl.toUtf8().constData(); // 或UDP地址
    //

    // 2. 打开输入流
    AVFormatContext* in_format_ctx = nullptr;
    if (avformat_open_input(&in_format_ctx, input_url, nullptr, nullptr) != 0) {
        fprintf(stderr, "无法打开输入流\n");
        return -1;
    }

    if (avformat_find_stream_info(in_format_ctx, nullptr) < 0) {
        fprintf(stderr, "无法获取流信息\n");
        return -1;
    }

    // 查找视频流索引
    int video_stream_idx = -1;
    for (int i = 0; i < in_format_ctx->nb_streams; i++) {
        if (in_format_ctx->streams[i]->codecpar->codec_type == AVMEDIA_TYPE_VIDEO) {
            video_stream_idx = i;
            break;
        }
    }

    if (video_stream_idx == -1) {
        fprintf(stderr, "未找到视频流\n");
        return -1;
    }

    // 3. 配置输出编码器
    AVCodec* out_codec = avcodec_find_encoder(AV_CODEC_ID_H264);
    if (!out_codec) {
        fprintf(stderr, "未找到H264编码器\n");
        return -1;
    }

    AVCodecContext* out_codec_ctx = avcodec_alloc_context3(out_codec);
    AVStream* in_stream = in_format_ctx->streams[video_stream_idx];
    AVCodecParameters* in_codecpar = in_stream->codecpar;

    // 设置编码参数
    out_codec_ctx->width = in_codecpar->width;
    out_codec_ctx->height = in_codecpar->height;
    out_codec_ctx->pix_fmt = AV_PIX_FMT_YUV420P;
    out_codec_ctx->bit_rate = 500000;  // 500 kbps
    out_codec_ctx->time_base = (AVRational){ 1, 25 };  // 帧率
    out_codec_ctx->gop_size = 10;
    out_codec_ctx->max_b_frames = 1;

    // 开启高质量模式
    av_opt_set(out_codec_ctx->priv_data, "preset", "slow", 0);

    if (avcodec_open2(out_codec_ctx, out_codec, nullptr) < 0) {
        fprintf(stderr, "无法打开编码器\n");
        return -1;
    }

    // 4. 设置输出流
    AVFormatContext* out_format_ctx = nullptr;
    avformat_alloc_output_context2(&out_format_ctx, nullptr, "flv", output_url);
    if (!out_format_ctx) {
        fprintf(stderr, "无法创建输出上下文\n");
        return -1;
    }

    AVStream* out_stream = avformat_new_stream(out_format_ctx, nullptr);
    avcodec_parameters_from_context(out_stream->codecpar, out_codec_ctx);
    out_stream->time_base = out_codec_ctx->time_base;

    // 打开输出IO
    if (!(out_format_ctx->oformat->flags & AVFMT_NOFILE)) {
        if (avio_open(&out_format_ctx->pb, output_url, AVIO_FLAG_WRITE) < 0) {
            fprintf(stderr, "无法打开输出IO\n");
            return -1;
        }
    }

    if (avformat_write_header(out_format_ctx, nullptr) < 0) {
        fprintf(stderr, "写头失败\n");
        return -1;
    }

    // 5. 处理帧
    AVFrame* frame = av_frame_alloc();
    AVFrame* tmp_frame = av_frame_alloc();
    AVPacket* in_pkt = av_packet_alloc();
    AVPacket* out_pkt = av_packet_alloc();

    // 图像转换上下文（如果需要格式转换）
    struct SwsContext* sws_ctx = sws_getContext(
        in_codecpar->width, in_codecpar->height, (AVPixelFormat)in_codecpar->format,
        out_codec_ctx->width, out_codec_ctx->height, out_codec_ctx->pix_fmt,
        SWS_BICUBIC, nullptr, nullptr, nullptr);

    while (av_read_frame(in_format_ctx, in_pkt) >= 0) {
        if (in_pkt->stream_index == video_stream_idx) {
            // 解码（伪代码，需完整实现）
            // ...

            // 格式转换
            sws_scale(sws_ctx, frame->data, frame->linesize, 0,
                in_codecpar->height, tmp_frame->data, tmp_frame->linesize);

            // 编码
            avcodec_send_frame(out_codec_ctx, tmp_frame);
            while (avcodec_receive_packet(out_codec_ctx, out_pkt) == 0) {
                out_pkt->stream_index = out_stream->index;
                av_packet_rescale_ts(out_pkt, out_codec_ctx->time_base, out_stream->time_base);
                av_interleaved_write_frame(out_format_ctx, out_pkt);
                av_packet_unref(out_pkt);
            }
        }
        av_packet_unref(in_pkt);
    }

    // 6. 清理资源
    av_write_trailer(out_format_ctx);
    av_frame_free(&frame);
    av_frame_free(&tmp_frame);
    av_packet_free(&in_pkt);
    av_packet_free(&out_pkt);
    avcodec_free_context(&out_codec_ctx);
    avformat_close_input(&in_format_ctx);
    if (out_format_ctx && !(out_format_ctx->oformat->flags & AVFMT_NOFILE))
        avio_closep(&out_format_ctx->pb);
    avformat_free_context(out_format_ctx);
    sws_freeContext(sws_ctx);
}

void FFmpegComFor::setUrl(const QString& url)
{
    this->url = url;
}

void FFmpegComFor::setOutUrl(const QString& outUrl)
{
    this->outUrl = outUrl;
}
