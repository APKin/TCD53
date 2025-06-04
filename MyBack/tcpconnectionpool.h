#ifndef TCPCONNECTIONPOOL_H
#define TCPCONNECTIONPOOL_H

#include <QObject>
#include <QMutex>
#include "tcpconnection.h"
class TcpConnectionPool : public QObject {
    Q_OBJECT
public:
    TcpConnectionPool(const QString& host, quint16 port, int maxConnections = 5, QObject* parent = nullptr);

    TcpConnection* acquireConnection();

    void releaseConnection(TcpConnection* connection);

private:
    TcpConnection* createConnection();

    void handleLostConnection(TcpConnection* conn);

    QString m_host;
    quint16 m_port;
    int m_maxConnections;
    QList<TcpConnection*> m_allConnections;
    QQueue<TcpConnection*> m_availableConnections;
    QMutex m_mutex;
};
#endif // TCPCONNECTIONPOOL_H
