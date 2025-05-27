#ifndef HIGHCONCURRENCYTCPSERVER_H
#define HIGHCONCURRENCYTCPSERVER_H

#include <QtNetwork>
#include <QThreadPool>
#include <QAtomicInt>
#include "connectiontask.h"

class HighConcurrencyTcpServer : public QTcpServer {
    Q_OBJECT
public:
    explicit HighConcurrencyTcpServer(QObject* parent = nullptr);

    void start(quint16 port);

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    QThreadPool* m_threadPool;
    QAtomicInt m_connectionCount;
};

#endif // HIGHCONCURRENCYTCPSERVER_H
