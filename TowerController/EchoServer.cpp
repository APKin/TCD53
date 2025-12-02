#include "echoserver.h"

EchoServer::EchoServer(QObject* parent, int port)
    : QTcpServer(parent), m_port(port)
{
    mRemoteClient = new QTcpSocket;
}

EchoServer::~EchoServer()
{
    delete mRemoteClient;
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

void EchoServer::connectRemote(QString ip, int port)
{
    mRemoteClient->connectToHost(ip,port);
}

void EchoServer::sendInfo2Remote(QByteArray info)
{
    
    if (mRemoteClient->waitForConnected()) {
        mRemoteClient->write(info);
        mRemoteClient->flush(); // 可选，确保数据立即发送
    }
    else
    {
        qDebug() << "client send info to Remote error";
    }
}

void EchoServer::sendInfo(QString ip, int port, QByteArray info)
{
    QTcpSocket client;
    client.connectToHost(ip, port);
    if (client.waitForConnected()) {
        client.write(info);
        client.flush(); // 可选，确保数据立即发送
    }
    else
    {
        qDebug() << "client send info error: ip:"<< ip << "port:" << port;
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

    // 长度:4字节
    int size_4 = 123;
    QByteArray data_;
    data_.push_back(size_4);
    data_.push_back(data);

    // 原样发回给客户端
    client->write(data_);
}

void EchoServer::onDisconnected()
{
    QTcpSocket* client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    qDebug() << "Client disconnected:" << client->peerAddress().toString();
    m_clients.removeOne(client);
    client->deleteLater();
}