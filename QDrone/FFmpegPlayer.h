#pragma once

#include <QObject>

class QMutex;
template<typename> class QFutureWatcher;

class FFmpegPlayer : public QObject
{
    Q_OBJECT

public:
    FFmpegPlayer(QObject* parent = nullptr);
    ~FFmpegPlayer();

    inline void setUrl(const QString& url) { murl = url; }

    void start();
    void stop();
    bool isRunning() const;
    void waitForFinished();

signals:
    void imageChanged(const QImage& img);

protected:
    void run();

private:
    bool isStoped() const;

private:
    QString murl;
    QMutex* mmutex;
    bool mstoped;
    QFutureWatcher<void>* mwatcher;
};