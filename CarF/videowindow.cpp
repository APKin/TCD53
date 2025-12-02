#include "videowindow.h"
#include "ui_videowindow.h"

VideoWindow::VideoWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoWindow)
{
    ui->setupUi(this);

    this->setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_StyledBackground);

    this->setStyleSheet("background-color: rgb(0, 0, 0);border:2px solid red;");
}

VideoWindow::~VideoWindow()
{
    delete ui;
}

void VideoWindow::setVideoID(int id)
{
    QSettings * pIni = new QSettings(INI_PATH, QSettings::IniFormat);//初始化读取Ini文件对象
    m_width = pIni->value("DECODER/width").toInt();
    m_height = pIni->value("DECODER/height").toInt();
    m_clipValue = pIni->value(QString("DECODER/clipValue_%1").arg(id)).toInt();

    qDebug() << QString("ID: %1, w: %2, h: %3, clip: %4").arg(id).arg(m_width).arg(m_height).arg(m_clipValue);


    m_video = new VideoThread;
    m_thread = new QThread;

    m_video->setVideoID(id);
    m_video->moveToThread(m_thread);
    

    connect(m_video,&VideoThread::signal_RGBBuf,this,&VideoWindow::slot_showFrame);


}

void VideoWindow::start()
{
    m_thread->start();
}

void VideoWindow::stop()
{
    m_thread->terminate();
}

void VideoWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QRect rect(0, 0, this->width(), this->height());
    painter.drawImage(rect, m_image);
    painter.end();
}

void VideoWindow::slot_showFrame(unsigned char *rgbBuf)
{
    QImage image(rgbBuf, m_width, m_height, QImage::Format_RGB888);

    if(m_clipValue != 0)
        m_image = image.copy(m_clipValue, m_clipValue, m_width - m_clipValue * 2, m_height - m_clipValue * 2);
    else
        m_image = image;


    //update();
    ui->label->setPixmap(QPixmap::fromImage(m_image.scaled(ui->label->width(),ui->label->height(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation)));

}



