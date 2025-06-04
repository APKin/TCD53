#ifndef CONNECTIONTASK_H
#define CONNECTIONTASK_H

#include <QtNetwork>
#include <QThreadPool>
#include <QAtomicInt>
#include "connectionhandler.h"

class ConnectionTask : public QRunnable {
public:
    explicit ConnectionTask(qintptr socketDescriptor);

    void run() override ;

private:
    qintptr m_socketDescriptor;
};
#endif // CONNECTIONTASK_H
