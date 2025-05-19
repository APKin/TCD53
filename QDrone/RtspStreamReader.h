#pragma once
#include <QObject>
extern "C" {
#include <libavformat/avformat.h>
#include <libavcodec/avcodec.h>
#include <libavutil/avutil.h>
#include <libswscale/swscale.h>
}

#include <QDebug>
#include <QImage>
#include <QTimer>

class RtspStreamReader : public QObject {
    Q_OBJECT
public:
    RtspStreamReader(QObject* parent = nullptr);
    ~RtspStreamReader();

    bool openStream(const QString& url);
    void closeStream();

signals:
    void frameReady(const QImage& image);

private slots:
    void readNextFrame();

private:
    AVFormatContext* formatContext = nullptr;
    AVCodecContext* codecContext = nullptr;
    int videoStreamIndex = -1;
    QTimer* timer = nullptr;
    SwsContext* swsContext = nullptr;
};
