#ifndef VIDEOWINDOW_H
#define VIDEOWINDOW_H

#include <QWidget>
#include <QDebug>
#include <QThread>
#include <QPainter>
#include <QRect>


#include <QSettings>
#include <QImage>

#define INI_PATH "./ini/cfg.ini"

#include "videothread.h"

namespace Ui {
class VideoWindow;
}

class VideoWindow : public QWidget
{
    Q_OBJECT

public:
    explicit VideoWindow(QWidget *parent = nullptr);
    ~VideoWindow();

    void setVideoID(int id);

    void start();

    void stop();

protected:
    void paintEvent(QPaintEvent *event);

public slots:
    void slot_showFrame(unsigned char *rgbBuf);


private:
    Ui::VideoWindow *ui;

    VideoThread *m_video;
    QThread *m_thread;

    int m_clipValue = 0;

    int m_width = 0;
    int m_height = 0;

    QImage m_image;

};

#endif // VIDEOWINDOW_H
