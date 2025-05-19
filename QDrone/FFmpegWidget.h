#pragma once

#include <QWidget>
#include "ui_FFmpegWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class FFmpegWidgetClass; };
QT_END_NAMESPACE

#include "ffmpegthread.h"

class FFmpegWidget : public QWidget
{
	Q_OBJECT

public:
	FFmpegWidget(QWidget *parent = nullptr);
	~FFmpegWidget();
protected:
    void paintEvent(QPaintEvent*);

private:
    FFmpegThread* thread;
    QImage image;

private slots:
    //接收图像并绘制
    void updateImage(const QImage& image);

public slots:
    //设置视频流地址
    void setUrl(const QString& url);

    //打开设备
    void open();
    //暂停
    void pause();
    //继续
    void next();
    //关闭设备
    void close();
    //清空
    void clear();
private:
	Ui::FFmpegWidgetClass *ui;
};
