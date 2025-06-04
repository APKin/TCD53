#include "mainwindow.h"

#include <QApplication>
#include "tcpconnectionpool.h"
#include "tcpserver.h"

#include <chrono>
#include <iostream>

int64_t get_current_timestamp() {
    auto now = std::chrono::system_clock::now();
    return std::chrono::duration_cast<std::chrono::seconds>(
        now.time_since_epoch()
    ).count();
}
// 毫秒，应用这个
int64_t get_current_timestamp_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
        std::chrono::system_clock::now().time_since_epoch()
    ).count();
}

QString get_timestamp_ms_String(){
    return QString::number(get_current_timestamp_ms());
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    qDebug() << get_current_timestamp();
    int64_t time_ms = get_current_timestamp_ms();
    QString Stime_ms = QString::number(time_ms);
    qDebug() << get_timestamp_ms_String();
//    // 创建连接池
//    TcpConnectionPool pool("127.0.0.1", 8080, 5);

//    // 获取连接
//    TcpConnection* conn = pool.acquireConnection();

//    if(conn && conn->isConnected()) {
//        // 使用连接
//        conn->socket()->write("Hello Server");
//        // 归还连接
//        pool.releaseConnection(conn);
//    } else {
//        qWarning() << "No available connections";
//    }


//    TcpServer server;
//        if (!server.listen(QHostAddress::Any, 1234)) {
//            qCritical() << "Server could not start!";
//            return 1;
//        }
//        qInfo() << "Server listening on port 1234...";
    return a.exec();
}
