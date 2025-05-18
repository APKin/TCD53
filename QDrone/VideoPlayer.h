#pragma once

#include <QWidget>
#include "ui_VideoPlayer.h"

#include <QImage>
#include <QTimer>
#include <QPaintEvent>

extern "C" {
#include <libavcodec/avcodec.h>
#include <libavformat/avformat.h>
#include <libswscale/swscale.h>
#include <libavutil/imgutils.h> 
}


class VideoPlayer : public QWidget
{
	Q_OBJECT

public:
	VideoPlayer(QWidget *parent = nullptr);
	~VideoPlayer();

    bool open(const QString& url);
    void close();

protected:
    void paintEvent(QPaintEvent* event) override;

private slots:
    void updateVideo();

private:
    const AVCodec* codec = nullptr;
    AVPacket* packet = nullptr;

    AVFormatContext* formatContext = nullptr;
    AVCodecContext* codecContext = nullptr;
    int videoStreamIndex = -1;
    AVFrame* frame = nullptr;
    AVFrame* frameRGB = nullptr;
    SwsContext* swsContext = nullptr;
    QTimer* timer = nullptr;
    QImage image;
    uint8_t* buffer = nullptr;

    void initFFmpeg();
    void cleanupFFmpeg();
private:
	Ui::VideoPlayerClass ui;
};
