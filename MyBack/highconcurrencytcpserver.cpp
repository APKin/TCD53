#include "highconcurrencytcpserver.h"

HighConcurrencyTcpServer::HighConcurrencyTcpServer(QObject *parent): QTcpServer(parent),
    m_threadPool(new QThreadPool(this)) {
    m_threadPool->setMaxThreadCount(QThread::idealThreadCount() * 2);
}

void HighConcurrencyTcpServer::start(quint16 port)
{
    if(!listen(QHostAddress::Any, port)) {
        qCritical() << "Server start failed:" << errorString();
        return;
    }
    qInfo() << "Server started on port" << port;
}

void HighConcurrencyTcpServer::incomingConnection(qintptr socketDescriptor)
{
    // 使用QRunnable处理新连接
    auto task = new ConnectionTask(socketDescriptor);
    m_threadPool->start(task);
}
