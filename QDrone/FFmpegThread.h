#pragma once

#include "ffmpeghead.h"
#include <QThread>
class FFmpegThread :public QThread
{
	Q_OBJECT

public:
    explicit FFmpegThread(QObject* parent = 0);
    static void initlib();

protected:
    void run();

private:
    volatile bool stopped;          //线程停止标志位
    volatile bool isPlay;           //播放视频标志位

    int frameFinish;                //一帧完成
    int videoWidth;                 //视频宽度
    int videoHeight;                //视频高度
    int oldWidth;                   //上一次视频宽度
    int oldHeight;                  //上一次视频高度
    int videoStreamIndex;           //视频流索引
    int audioStreamIndex;           //音频流索引

    QString url;                    //视频流地址

    uint8_t* buffer;                //存储解码后图片buffer
    AVPacket* avPacket;             //包对象
    AVFrame* avFrame;               //帧对象
    AVFrame* avFrame2;              //帧对象
    AVFrame* avFrame3;              //帧对象
    AVFormatContext* avFormatContext;//格式对象
    AVCodecContext* videoCodec;     //视频解码器
    AVCodecContext* audioCodec;     //音频解码器
    SwsContext* swsContext;         //处理图片数据对象

    AVDictionary* options;          //参数对象
    AVCodec* videoDecoder;          //视频解码
    AVCodec* audioDecoder;          //音频解码

signals:
    //收到图片信号
    void receiveImage(const QImage& image);

public slots:
    //设置视频流地址
    void setUrl(const QString& url);

    //初始化视频对象
    bool init();
    //释放对象
    void free();
    //播放视频对象
    void play();
    //暂停播放
    void pause();
    //继续播放
    void next();
    //停止采集线程
    void stop();
};

