#include "tcpconnection.h"

TcpConnection::TcpConnection(const QString &host, quint16 port, QObject *parent) : QObject(parent), m_host(host), m_port(port), m_autoReconnect(true), m_reconnectAttempts(0)
{
    m_socket = new QTcpSocket(this);
    setupConnections();
    connectToHost();
}

void TcpConnection::connectToHost()
{
    if(m_socket->state() == QAbstractSocket::UnconnectedState) {
        m_socket->connectToHost(m_host, m_port);
    }
}

QTcpSocket *TcpConnection::socket() const
{
    return m_socket;
}

bool TcpConnection::isConnected() const
{
    return m_socket->state() == QAbstractSocket::ConnectedState;
}

void TcpConnection::setAutoReconnect(bool enable)
{
    m_autoReconnect = enable;
}

void TcpConnection::resetReconnectAttempts()
{
    m_reconnectAttempts = 0;
}

void TcpConnection::setupConnections()
{
    connect(m_socket, &QTcpSocket::connected, this, &TcpConnection::handleConnected);
    connect(m_socket, &QTcpSocket::disconnected, this, &TcpConnection::handleDisconnected);
    connect(m_socket, QOverload<QAbstractSocket::SocketError>::of(&QTcpSocket::error),
            this, &TcpConnection::handleError); // error? errorOccurred
}

void TcpConnection::scheduleReconnect()
{
        const int maxAttempts = 5;
        if(++m_reconnectAttempts > maxAttempts) {
            emit connectionLost();
            return;
        }

        int delay = qMin(1000 * (1 << (m_reconnectAttempts - 1)), 30000); // Exponential backoff
        QTimer::singleShot(delay, this, [this] {
            qDebug() << "Reconnecting attempt" << m_reconnectAttempts;
            connectToHost();
        });
}

void TcpConnection::handleConnected()
{
    resetReconnectAttempts();
    emit connected();
}

void TcpConnection::handleDisconnected()
{
       emit disconnected();
       if(m_autoReconnect) {
           scheduleReconnect();
       }
   }
void TcpConnection::handleError(QAbstractSocket::SocketError error)
{
        qWarning() << "Socket error:" << error << m_socket->errorString();
        if(m_autoReconnect && m_socket->state() != QAbstractSocket::ConnectedState) {
            scheduleReconnect();
        }
    }
