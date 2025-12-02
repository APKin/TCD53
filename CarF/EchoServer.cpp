#include "echoserver.h"

EchoServer::EchoServer(QObject* parent, int port)
    : QTcpServer(parent), m_port(port)
{
    //UVStatus;
}

void EchoServer::startServer()
{
    if (listen(QHostAddress::Any, m_port)) {
        qDebug() << "Server started on port" << m_port;
    }
    else {
        qCritical() << "Error starting server:" << errorString();
    }
}

void EchoServer::sendUVStatus(QByteArray data)
{
    qDebug() << m_clients.size();
    for (QTcpSocket* client:m_clients)
    {
        client->write(data);
    } 
}

void EchoServer::incomingConnection(qintptr socketDescriptor)
{
    QTcpSocket* client = new QTcpSocket(this);
    client->setSocketDescriptor(socketDescriptor);

    connect(client, &QTcpSocket::readyRead, this, &EchoServer::onReadyRead);
    connect(client, &QTcpSocket::disconnected, this, &EchoServer::onDisconnected);

    m_clients.append(client);
    qDebug() << "New client connected:" << client->peerAddress().toString() << ":" << client->peerPort();
}

void EchoServer::onReadyRead()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    QByteArray data = client->readAll();
    qDebug() << "Received:" << data;
    //
    const uint8_t* buffer = reinterpret_cast<const uint8_t*>(data.constData());
    
    //UVStatus.deserialize(buffer);
    UVStatus_json = UVStatus.toJsonObject();
    if (!UVStatus_json.isEmpty())
    {
        emit sendJson(UVStatus_json);
    }

    // 原样发回给客户端
    client->write(data);
}

void EchoServer::onDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    qDebug() << "Client disconnected:" << client->peerAddress().toString();
    m_clients.removeOne(client);
    client->deleteLater();
}