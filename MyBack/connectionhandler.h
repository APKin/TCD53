#ifndef CONNECTIONHANDLER_H
#define CONNECTIONHANDLER_H

#include <QtNetwork>
#include <QThreadPool>
#include <QAtomicInt>
#include <QObject>
class ConnectionHandler :public QObject {
    Q_OBJECT
public:
    explicit ConnectionHandler(QTcpSocket* socket);

    void process();

private:
    void setupConnections();

    void readData();

    void processData(qint64 size);

    void cleanup();

    QTcpSocket* m_socket;
    QByteArray* m_buffer;
};
#endif // CONNECTIONHANDLER_H
