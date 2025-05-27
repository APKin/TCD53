#ifndef CONNECTIONPOOL_H
#define CONNECTIONPOOL_H


#include <QObject>
#include <QTcpSocket>
#include <QList>
#include <QMutex>
#include <QFutureWatcher>
#include <QtConcurrent>

class ConnectionPool : public QObject
{
    Q_OBJECT
public:
    static ConnectionPool* instance()
    {
        static ConnectionPool instance;
        return &instance;
    }

    void addSocket(QTcpSocket *socket)
    {
        QMutexLocker locker(&m_mutex);
        m_sockets.append(socket);
        connect(socket, &QTcpSocket::readyRead, this, &ConnectionPool::onReadyRead);
        connect(socket, &QTcpSocket::disconnected, this, &ConnectionPool::onDisconnected);
    }

private slots:
    void onReadyRead()
    {
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        if (!socket) return;

        // 异步读取数据并处理
        QByteArray data = socket->readAll();
        QFutureWatcher<QByteArray> *watcher = new QFutureWatcher<QByteArray>;
        connect(watcher, &QFutureWatcher<QByteArray>::finished, this, [socket, watcher]() {
            QByteArray response = watcher->result();
            if (socket->state() == QTcpSocket::ConnectedState) {
                socket->write(response);
                socket->flush();
            }
            watcher->deleteLater();
        });

        // 在线程池中处理数据
        QFuture<QByteArray> future = QtConcurrent::run([data]() {
            return processData(data); // 替换为实际数据处理函数
        });
        watcher->setFuture(future);
    }

    void onDisconnected()
    {
        QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
        if (socket) {
            QMutexLocker locker(&m_mutex);
            m_sockets.removeOne(socket);
            socket->deleteLater();
        }
    }

private:
    ConnectionPool() = default;
    QList<QTcpSocket*> m_sockets;
    QMutex m_mutex;

    // 数据处理示例函数
    static QByteArray processData(const QByteArray &data)
    {
        // 实现具体的数据处理逻辑，返回响应
        return QByteArray("Processed: ") + data;
    }
};
#endif // CONNECTIONPOOL_H
