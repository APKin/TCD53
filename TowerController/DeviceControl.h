#pragma once

#include <QDialog>
#include "ui_DeviceControl.h"
#include "httpNetInfo.h"
#include "RadarJson.h"
#include "Global.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DeviceControlClass; };
QT_END_NAMESPACE


class DeviceControl : public QDialog
{
	Q_OBJECT

public:
	DeviceControl(QWidget *parent = nullptr);
	~DeviceControl();
	
	void setUrl(QString url);
	// 显示前查询当前新数据
	void QueryAllInfo();

signals:
	// comId 命令号 
	void laserRadarCommand(int comId,QString command);

	void portInfoChanged(portInfo_ info);
public slots:
	// 全景拼接
	void on_pbImg_clicked();

	void on_pbCutLR_clicked();

	void on_bpSetIp_clicked();

	void on_pbBWmod_clicked();

	void on_pbAGC_clicked();

	//void dealReplyInfo(QJsonObject jsonData);

	// 激光

	/*void  on__returnPressed();

	void on__currentIndexChanged(const QString& arg1);*/

	void on_leRDdataPort_returnPressed();

	void on_leRDdevPort_returnPressed();

	void  on_leDstIP_returnPressed();

	void  on_leRDIP_returnPressed();

	void  on_leZBIP_returnPressed();

	void on_cbRDSpeed_currentIndexChanged(const QString& arg1);

	void on_cbRDWork_currentIndexChanged(int index);

	void on_cbRDZL_currentIndexChanged(int index);

	

	void on_pbChangePortnfo_clicked();

	void on_pbScanSeriPort_clicked();
private:
	Ui::DeviceControlClass *ui;

	httpNetInfo mNet;
	RadarJson rJson;
	QString url_;
	bool isInit;
	bool isScanPort;
};
