#include "TowerController.h"
#include <QtWidgets/QApplication>

#include "FFmpegWidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TowerController w;
    w.show();
    //w.showFullScreen();

    //FFmpegWidget fw;
    //fw.show();
    //QString urls = "rtsp://127.0.0.1:8554/mystream";
    //fw.setUrl(urls);
    //fw.open();
    // fw.close();

    return a.exec();
}
