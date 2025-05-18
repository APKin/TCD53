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
    //����ͼ�񲢻���
    void updateImage(const QImage& image);

public slots:
    //������Ƶ����ַ
    void setUrl(const QString& url);

    //���豸
    void open();
    //��ͣ
    void pause();
    //����
    void next();
    //�ر��豸
    void close();
    //���
    void clear();
private:
	Ui::FFmpegWidgetClass *ui;
};
