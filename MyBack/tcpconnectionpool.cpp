#include "tcpconnectionpool.h"

TcpConnectionPool::TcpConnectionPool(const QString &host, quint16 port, int maxConnections, QObject *parent): QObject(parent), m_host(host), m_port(port), m_maxConnections(maxConnections)
{

}

TcpConnection *TcpConnectionPool::acquireConnection()
{
        QMutexLocker locker(&m_mutex);

        // 尝试获取可用连接
        if(!m_availableConnections.isEmpty()) {
            return m_availableConnections.dequeue();
        }

        // 创建新连接
        if(m_allConnections.size() < m_maxConnections) {
            auto conn = createConnection();
            m_allConnections.append(conn);
            return conn;
        }

        return nullptr; // 或实现等待逻辑
}

void TcpConnectionPool::releaseConnection(TcpConnection *connection)
{
       QMutexLocker locker(&m_mutex);
       if(connection->isConnected()) {
           m_availableConnections.enqueue(connection);
       } else {
           // 处理失效连接
           m_allConnections.removeOne(connection);
           connection->deleteLater();
       }
}

TcpConnection *TcpConnectionPool::createConnection()
{
        auto conn = new TcpConnection(m_host, m_port, this);
        connect(conn, &TcpConnection::connectionLost, this, [this, conn]() {
            handleLostConnection(conn);
        });
        return conn;
}

void TcpConnectionPool::handleLostConnection(TcpConnection *conn)
{
    QMutexLocker locker(&m_mutex);
    m_allConnections.removeOne(conn);
    conn->deleteLater();

    // 自动补充新连接
    if(m_allConnections.size() < m_maxConnections) {
        m_availableConnections.enqueue(createConnection());
    }
}
