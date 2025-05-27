#include "connectionhandler.h"

ConnectionHandler::ConnectionHandler(QTcpSocket *socket): m_socket(socket), m_buffer(new QByteArray(4096, 0))
{
    setupConnections();
}

void ConnectionHandler::process()
{
    // 异步读取数据
    if(m_socket->bytesAvailable() > 0) {
        readData();
    }
}

void ConnectionHandler::setupConnections()
{
    connect(m_socket, &QTcpSocket::readyRead,
            [this]() { readData(); });
    connect(m_socket, &QTcpSocket::disconnected,
            [this]() { cleanup(); });
}

void ConnectionHandler::readData()
{
    while(m_socket->bytesAvailable() > 0) {
        qint64 bytesRead = m_socket->read(m_buffer->data(), m_buffer->size());
        if(bytesRead > 0) {
            processData(bytesRead);
        }
    }
}

void ConnectionHandler::processData(qint64 size)
{
//        // 使用零拷贝技术处理数据
//        QByteArrayView dataView(m_buffer->constData(), size);

//        // 协议解析逻辑...
//        // 业务处理逻辑...

//        // 示例：简单回显
//        m_socket->write(dataView.constData(), dataView.size());
}

void ConnectionHandler::cleanup(){
    m_socket->deleteLater();
    delete m_buffer;
}
