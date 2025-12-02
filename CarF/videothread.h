#ifndef VIDEOTHREAD_H
#define VIDEOTHREAD_H

#include <QObject>
#include <QDebug>
#include <QUdpSocket>
#include <QThread>
#include <QNetworkInterface>

#include <QSettings>
#include <QImage>
#define INI_PATH "./ini/cfg.ini"

#include "ffmpeg_decode.h"


class VideoThread : public QObject
{
    Q_OBJECT
public:
    explicit VideoThread(QObject *parent = nullptr);

    void setVideoID(int id);


signals:
    void signal_RGBBuf(unsigned char *rgbBuf);


private:
    int m_id;
    // udp socket
    QUdpSocket *m_sock;
    QString m_ip = "";
    QString m_groupIp = "";
    int m_port = 0;

    void slot_readData();

    // ffmpeg video
    FFmpeg_Decode *m_ffmpeg_decoder;
    int m_width = 0;
    int m_height = 0;



};

#endif // VIDEOTHREAD_H
