#include <QtWidgets/QApplication>

#include "VideoPlayer.h"
#include "RtspStreamReader.h"
#include "QtWidgetsClass.h"
#include "FFmpegWidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //VedioClass vc;
    //QString url = "rtsp://localhost:8554/mystream";
    //vc.setUrls(url);
    //vc.init();
    //vc.openStream();
    //QtWidgetsClass w;
    //w.show();
    //VideoPlayer player;
    //player.resize(800, 600);
    //player.show();
    //// Ìæ»»ÎªÄãµÄRTSP URL
    //player.open("rtsp://127.0.0.1:8554/mystream");

    // rtsp://localhost:8554/mystream
    // rtsp://192.168.40.159:8554/live/test1080H264

    FFmpegWidget fw;
    fw.show();
    QString urls = "rtsp rtsp://127.0.0.1:8554/mystream";
    fw.setUrl(urls);
    fw.open();

    // fw.close();

    return a.exec();
}


#include <iostream>
