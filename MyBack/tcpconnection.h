#ifndef TCPCONNECTION_H
#define TCPCONNECTION_H

#include <QObject>
#include <QtNetwork>
#include <QObject>
#include <QTimer>
#include <QQueue>
#include <QMutex>
#include <QDebug>

class TcpConnection : public QObject
{
    Q_OBJECT
public:
    explicit TcpConnection(const QString& host, quint16 port,QObject *parent = nullptr);

    void connectToHost();

    QTcpSocket* socket() const;

    bool isConnected() const;

    void setAutoReconnect(bool enable);

    void resetReconnectAttempts();


private:
    void setupConnections();

    void scheduleReconnect();

signals:
    void connected();
    void disconnected();
    void connectionLost();

private slots:
    void handleConnected();

    void handleDisconnected();

    void handleError(QAbstractSocket::SocketError error);

private:
    QTcpSocket* m_socket;
    QString m_host;
    quint16 m_port;
    bool m_autoReconnect;
    int m_reconnectAttempts;
};

#endif // TCPCONNECTION_H
