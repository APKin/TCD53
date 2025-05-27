#include "connectiontask.h"


ConnectionTask::ConnectionTask(qintptr socketDescriptor): m_socketDescriptor(socketDescriptor)
{
    setAutoDelete(true);
}
void ConnectionTask::run()
{
    QTcpSocket* socket = new QTcpSocket;
    if(!socket->setSocketDescriptor(m_socketDescriptor)) {
        delete socket;
        return;
    }

    // 设置非阻塞模式
    socket->setSocketOption(QAbstractSocket::LowDelayOption, 1);
    socket->setSocketOption(QAbstractSocket::KeepAliveOption, 1);

    // 连接管理
    ConnectionHandler handler(socket);
    handler.process();
}
