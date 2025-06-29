#pragma once
#include <QtCore/QObject>
#include <QtCore/QList>
#include <QtCore/QByteArray>
#include <QTcpServer>
#include <QTcpSocket>


QT_FORWARD_DECLARE_CLASS(QWebSocketServer)
QT_FORWARD_DECLARE_CLASS(QWebSocket)

#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <QList>

#include "UnmannedVehicleStatus.cpp"

class EchoServer : public QTcpServer
{
    Q_OBJECT
public:
    explicit EchoServer(QObject* parent = nullptr, int port = 12345);
    void startServer();

    void sendUVStatus(QByteArray data);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

signals:
    void sendJson(QJsonObject UVStatus_json);

private slots:
    void onReadyRead();
    void onDisconnected();

private:
    int m_port;
    QList<QTcpSocket*> m_clients;

    UnmannedVehicleStatus UVStatus;
    QJsonObject UVStatus_json;

};