#pragma once

#include "ffmpeghead.h"
#include <QThread>
class FFmpegThread :public QThread
{
	Q_OBJECT

public:
    explicit FFmpegThread(QObject* parent = 0);
    static void initlib();

protected:
    void run();

private:
    volatile bool stopped;          //�߳�ֹͣ��־λ
    volatile bool isPlay;           //������Ƶ��־λ

    int frameFinish;                //һ֡���
    int videoWidth;                 //��Ƶ���
    int videoHeight;                //��Ƶ�߶�
    int oldWidth;                   //��һ����Ƶ���
    int oldHeight;                  //��һ����Ƶ�߶�
    int videoStreamIndex;           //��Ƶ������
    int audioStreamIndex;           //��Ƶ������

    QString url;                    //��Ƶ����ַ

    uint8_t* buffer;                //�洢�����ͼƬbuffer
    AVPacket* avPacket;             //������
    AVFrame* avFrame;               //֡����
    AVFrame* avFrame2;              //֡����
    AVFrame* avFrame3;              //֡����
    AVFormatContext* avFormatContext;//��ʽ����
    AVCodecContext* videoCodec;     //��Ƶ������
    AVCodecContext* audioCodec;     //��Ƶ������
    SwsContext* swsContext;         //����ͼƬ���ݶ���

    AVDictionary* options;          //��������
    AVCodec* videoDecoder;          //��Ƶ����
    AVCodec* audioDecoder;          //��Ƶ����

signals:
    //�յ�ͼƬ�ź�
    void receiveImage(const QImage& image);

public slots:
    //������Ƶ����ַ
    void setUrl(const QString& url);

    //��ʼ����Ƶ����
    bool init();
    //�ͷŶ���
    void free();
    //������Ƶ����
    void play();
    //��ͣ����
    void pause();
    //��������
    void next();
    //ֹͣ�ɼ��߳�
    void stop();
};

