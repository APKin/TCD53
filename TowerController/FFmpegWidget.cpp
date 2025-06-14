#include "FFmpegWidget.h"
#include <QPainter>
#include <QTimer>
#include <QDebug>
//实时视频显示窗体类
FFmpegWidget::FFmpegWidget(QWidget* parent) : QWidget(parent), ui(new Ui::FFmpegWidgetClass())
{
    ui->setupUi(this);
    thread = new FFmpegThread(this);
    connect(thread, SIGNAL(receiveImage(QImage)), this, SLOT(updateImage(QImage)));
    image = QImage();
    capPic = false;

}

FFmpegWidget::~FFmpegWidget()
{
    delete ui;
    close();
}

void FFmpegWidget::setCapPic()
{
    capPic = true;
}

void FFmpegWidget::paintEvent(QPaintEvent*)
{
    if (image.isNull()) {
        return;
    }

    //qDebug() << TIMEMS << "paintEvent" << objectName();
    QPainter painter(this);
    painter.drawImage(this->rect(), image);
}

void FFmpegWidget::updateImage(const QImage& image)
{
    //this->image = image.copy();
    this->image = image;
    static int capCal = 0;
    if (capCal < 10 && capPic == true) {
        //QString fileName = QString::number(capCal) + ".png";
        QString filename = QString("image_%1_%2.jpg").arg(QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss")).arg(capCal);
        image.save(filename,"JPG");
        qDebug() << "img save " << filename;
        capCal++;
    }
    if (capCal == 10) {
        capCal = 0;
        capPic == false;
    }
    
    this->update();
}

void FFmpegWidget::setUrl(const QString& url)
{
    thread->setUrl(url);
}

void FFmpegWidget::open()
{
    //qDebug() << TIMEMS << "open video" << objectName();
    clear();

    thread->play();
    thread->start();
}

void FFmpegWidget::pause()
{
    thread->pause();
}

void FFmpegWidget::next()
{
    thread->next();
}

void FFmpegWidget::close()
{
    //qDebug() << TIMEMS << "close video" << objectName();
    if (thread->isRunning()) {
        thread->stop();
        thread->quit();
        thread->wait(500);
    }

    QTimer::singleShot(1, this, SLOT(clear()));
}

void FFmpegWidget::clear()
{
    image = QImage();
    update();
}
