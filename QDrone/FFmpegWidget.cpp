#include "FFmpegWidget.h"
#include <QPainter>
#include <QTimer>

//实时视频显示窗体类
FFmpegWidget::FFmpegWidget(QWidget* parent) : QWidget(parent), ui(new Ui::FFmpegWidgetClass())
{
    ui->setupUi(this);
    thread = new FFmpegThread(this);
    connect(thread, SIGNAL(receiveImage(QImage)), this, SLOT(updateImage(QImage)));
    image = QImage();
}

FFmpegWidget::~FFmpegWidget()
{
    delete ui;
    close();
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
