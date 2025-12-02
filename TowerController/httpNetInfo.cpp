#include "httpNetInfo.h"
#include <QJsondocument>
#include <QEventLoop>
httpNetInfo::httpNetInfo()
{
	m_networkManager = new QNetworkAccessManager();
	m_networkReply = nullptr;
	m_timer = new QTimer(this);
	m_timer->setSingleShot(true);
	// 连接超时信号
	connect(m_timer, &QTimer::timeout, this, &httpNetInfo::onRequestTimeout);
}
httpNetInfo::httpNetInfo(QString url_s)
{
	url = QUrl(url_s);

	m_networkManager = new QNetworkAccessManager();
	m_networkReply = nullptr;



	m_timer->setSingleShot(true);
	// 连接超时信号
	connect(m_timer, &QTimer::timeout, this, &httpNetInfo::onRequestTimeout);


}

httpNetInfo::~httpNetInfo()
{
	

	cleanup();
	/*delete nReply;
	nReply = nullptr;*/
}

void httpNetInfo::setUrl(QString url)
{
	this->url = QUrl(url);
}

void httpNetInfo::sendJsonPostRequest( const QJsonObject& jsonData, int timeoutMs)
{
	// 如果已有正在进行的请求，先清理
	if (m_networkReply) {
		qWarning() << "A request is already in progress. Aborting previous request.";
		cleanup();
	}

	// 设置超时时间
	m_timer->start(timeoutMs);

	// 创建网络请求并设置URL
	QNetworkRequest request;
	request.setUrl(url);

	// 设置Content-Type为JSON，这对于服务器识别数据类型很重要:cite[5]:cite[8]
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	// 可选：设置其他请求头，如User-Agent
	// request.setRawHeader("User-Agent", "MyApp/1.0");

	// 将JSON对象转换为字节数组:cite[2]:cite[8]
	QJsonDocument jsonDoc(jsonData);
	QByteArray postData = jsonDoc.toJson(QJsonDocument::Compact); // 使用紧凑格式

	// 发送POST请求:cite[5]:cite[6]
	m_networkReply = m_networkManager->post(request, postData);

	// 连接finished()信号到槽函数，注意网络请求是异步的
	connect(m_networkReply, &QNetworkReply::finished, this, &httpNetInfo::onReplyFinished);

	qDebug() << "HTTPS POST request sent to:" << url.toString();
}

bool httpNetInfo::sendJsonPostRequestSync( const QJsonObject& jsonData, QByteArray& responseData, int timeoutMs)
{
	QNetworkRequest request;
	request.setUrl(url);
	request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

	QJsonDocument jsonDoc(jsonData);
	QByteArray postData = jsonDoc.toJson();

	QNetworkAccessManager localManager;
	QNetworkReply* reply = localManager.post(request, postData);

	QEventLoop eventLoop;
	QTimer timer;
	timer.setSingleShot(true);

	// 连接finished()和timeout()信号到事件循环的quit()槽:cite[4]
	QObject::connect(reply, &QNetworkReply::finished, &eventLoop, &QEventLoop::quit);
	QObject::connect(&timer, &QTimer::timeout, &eventLoop, &QEventLoop::quit);

	timer.start(timeoutMs);
	eventLoop.exec(); // 进入事件循环，等待完成或超时

	bool success = false;
	if (timer.isActive()) {
		// 请求在超时前完成
		timer.stop();
		if (reply->error() == QNetworkReply::NoError) {
			responseData = reply->readAll();
			success = true;
		}
		else {
			qDebug() << "Sync request failed:" << reply->errorString();
		}
	}
	else {
		// 请求超时
		qDebug() << "Sync request timeout";
		reply->abort();
	}

	reply->deleteLater();
	return success;
}

//void httpNetInfo::requestFailed(const QString& errorString)
//{
//	// 停止超时定时器
//	m_timer->stop();
//
//	// 检查网络错误
//	if (m_networkReply->error() == QNetworkReply::NoError) {
//		// 读取服务器返回的所有数据:cite[2]:cite[6]
//		QByteArray responseData = m_networkReply->readAll();
//		qDebug() << "Request successful. Response size:" << responseData.size();
//		emit requestFinished(responseData);
//	}
//	else {
//		// 处理请求错误:cite[1]:cite[6]
//		QString errorString = m_networkReply->errorString();
//		qDebug() << "Request failed:" << errorString;
//		emit requestFailed(errorString);
//	}
//
//	// 清理资源
//	cleanup();
//}

void httpNetInfo::onReplyFinished()
{
	// 停止超时定时器
	m_timer->stop();

	// 检查网络错误
	if (m_networkReply->error() == QNetworkReply::NoError) {
		// 读取服务器返回的所有数据:cite[2]:cite[6]
		QByteArray responseData = m_networkReply->readAll();
		qDebug() << "Request successful. Response size:" << responseData.size();
		emit requestFinished(responseData);
	}
	else {
		// 处理请求错误:cite[1]:cite[6]
		QString errorString = m_networkReply->errorString();
		qDebug() << "Request failed:" << errorString;
		emit requestFailed(errorString);
	}

	// 清理资源
	cleanup();
}

void httpNetInfo::onRequestTimeout()
{
	if (m_networkReply && m_networkReply->isRunning()) {
		qDebug() << "Request timeout. Aborting...";
		m_networkReply->abort(); // 中止请求
		// onReplyFinished 会在abort后由QNetworkReply触发
	}
}

void httpNetInfo::cleanup()
{
	if (m_networkReply) {
		m_networkReply->disconnect(); // 断开所有连接
		m_networkReply->deleteLater(); // 安全地释放资源:cite[1]:cite[10]
		m_networkReply = nullptr;
	}
	if (m_timer->isActive()) {
		m_timer->stop();
	}
}
