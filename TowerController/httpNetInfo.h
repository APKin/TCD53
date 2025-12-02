#pragma once

#include <QNetworkAccessManager>
#include <QUrl>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QTimer>

class httpNetInfo : public QObject
{
	Q_OBJECT
public:
	httpNetInfo();
	httpNetInfo(QString url_s);
	~httpNetInfo();

	void setUrl(QString url);
	// 发送HTTPS POST请求，提交JSON数据
	void sendJsonPostRequest( const QJsonObject& jsonData, int timeoutMs = 5000);
	// 同步方式发送请求（可选，注意会阻塞当前线程）
	bool sendJsonPostRequestSync(const QJsonObject& jsonData, QByteArray& responseData, int timeoutMs = 5000);

signals:
	// 请求完成信号，成功时发射
	void requestFinished(const QByteArray& responseData);
	// 请求失败信号，失败时发射
	void requestFailed(const QString& errorString);

private slots:
	// 处理网络回复
	void onReplyFinished();
	// 处理请求超时
	void onRequestTimeout();

private:
	QNetworkAccessManager* m_networkManager;
	QNetworkReply* m_networkReply;

	QTimer* m_timer;
	// 清理回复对象和定时器
	void cleanup();

	QUrl url;
};

