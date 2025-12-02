#pragma once
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>

QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <QList>

class EchoServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit EchoServer(QObject* parent = nullptr, int port = 12345);
    ~EchoServer();
   
    void startServer();

    void connectRemote(QString ip,int port);

    void sendInfo2Remote(QByteArray info);

    void sendInfo(QString ip, int port ,QByteArray info);
protected:
    void incomingConnection(qintptr socketDescriptor) override;

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    int m_port;
    QList<QTcpSocket*> m_clients;

    QTcpSocket* mRemoteClient;
};