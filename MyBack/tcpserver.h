#ifndef TCPSERVER_H
#define TCPSERVER_H
#include <QTcpServer>
#include <QTcpSocket>
#include <QThreadPool>
#include "connectionpool.h"

class TcpServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit TcpServer(QObject *parent = nullptr)
        : QTcpServer(parent)
    {
        // 初始化线程池（根据需求设置线程数）
        QThreadPool::globalInstance()->setMaxThreadCount(10);
    }

protected:
    void incomingConnection(qintptr socketDescriptor) override
    {
        // 创建Socket并交由连接池管理
        QTcpSocket *socket = new QTcpSocket;
        if (socket->setSocketDescriptor(socketDescriptor)) {
            ConnectionPool::instance()->addSocket(socket);
        } else {
            delete socket;
        }
    }
};


#endif // TCPSERVER_H
