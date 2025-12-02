#include "DeviceControl.h"
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>

DeviceControl::DeviceControl(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DeviceControlClass())
{
	ui->setupUi(this);
	isInit = false;
	ui->rbHight->setChecked(true);

	QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

	QStringList ports;
	// 遍历并打印串口信息
	foreach(const QSerialPortInfo & portInfo, availablePorts) {

		ports << portInfo.portName();
	}
	ui->comboBoxSeriPort->clear();
	ui->comboBoxSeriPort->addItems(ports);

	//
	ui->sbDataSite->setValue(8);
	ui->sbStopSite->setValue(0);
	ui->leBT->setText(QString::number(115200));
	
	// 雷达
	QStringList RDSpeed;
	//300， 600，1200
	RDSpeed << QString::number(300) << QString::number(600) << QString::number(1200);
	ui->cbRDSpeed->addItems(RDSpeed);
	
	QStringList RDWork;
	//0:正常模式， 1： 低功耗模式
	RDWork << u8"正常模式" << u8"低功耗模式";
	ui->cbRDWork->addItems(RDWork);

	QStringList RDZL;
	// 0:正常帧率， 1： 50 % 帧率； 2 : 25 % 帧率
	RDZL << u8"正常帧率" << u8"50%帧率" << u8"25%帧率";
	ui->cbRDZL->addItems(RDZL);

	isInit = true;
	isScanPort = false;
}

DeviceControl::~DeviceControl()
{
	delete ui;
}

void DeviceControl::setUrl(QString url)
{
	url_ = url;
	mNet.setUrl(url_);
}
void DeviceControl::QueryAllInfo()
{
	// 需要执行多个 查询命令 用于初始化
	// 查询命令
	// 全景拼接
	QJsonObject jsonData = rJson.QuerySplicing();
	mNet.sendJsonPostRequest(jsonData, 500);
	
	// 左右
	jsonData = rJson.QuerySplicing();
	mNet.sendJsonPostRequest(jsonData, 500);
	// IP
	jsonData = rJson.QueryIP();
	mNet.sendJsonPostRequest(jsonData, 500);
	//BW mod
	jsonData = rJson.QueryBWMode();
	mNet.sendJsonPostRequest(jsonData, 500);
	//AGC
	jsonData = rJson.QueryAGC();
	mNet.sendJsonPostRequest(jsonData, 500);
	// 对比度
	jsonData = rJson.QueryLight();
	mNet.sendJsonPostRequest(jsonData, 500);
	// 明暗度
	jsonData = rJson.QuerySplicing();
	mNet.sendJsonPostRequest(jsonData, 500);
	

}
// leImg, leCutL leCutR  cbBlack cbWhite cbManual  cbAuto0 cbAuto1


void  DeviceControl::on_pbImg_clicked() {
	qDebug() << "123";
	
	int value = ui->leImg->text().toInt();
	QJsonObject jsonData = rJson.setSplicing(value);
	mNet.sendJsonPostRequest(jsonData,500);
}

void DeviceControl::on_pbCutLR_clicked()
{
	int valueL = ui->leCutL->text().toInt();
	int valueR = ui->leCutR->text().toInt();
	QJsonObject jsonData = rJson.setLRPic(valueL, valueR);
	mNet.sendJsonPostRequest(jsonData, 500);
}

void DeviceControl::on_bpSetIp_clicked()
{
}

void DeviceControl::on_pbBWmod_clicked()
{

}

void DeviceControl::on_pbAGC_clicked()
{
}

void DeviceControl::on_leRDdataPort_returnPressed()
{
	emit laserRadarCommand(0, ui->leRDdataPort->text());
}

void DeviceControl::on_leRDdevPort_returnPressed()
{
	emit laserRadarCommand(1, ui->leRDdevPort->text());
}

void DeviceControl::on_leDstIP_returnPressed()
{
	emit laserRadarCommand(2, ui->leDstIP->text());
}

void DeviceControl::on_leRDIP_returnPressed()
{
	emit laserRadarCommand(3, ui->leRDIP->text());
}

void DeviceControl::on_leZBIP_returnPressed()
{
	emit laserRadarCommand(4, ui->leZBIP->text());
}

void DeviceControl::on_cbRDSpeed_currentIndexChanged(const QString& arg1)
{
	// 是否初始化
	if (!isInit)
	{
		return;
	}
	emit laserRadarCommand(5, arg1);
}


void DeviceControl::on_cbRDWork_currentIndexChanged(int index)
{
	// 是否初始化
	if (!isInit)
	{
		return;
	}
	emit laserRadarCommand(6, QString::number(index));
}

void DeviceControl::on_cbRDZL_currentIndexChanged(int index)
{
	// 是否初始化
	if (!isInit)
	{
		return;
	}
	emit laserRadarCommand(7, QString::number(index));
}

void DeviceControl::on_pbChangePortnfo_clicked()
{
	portInfo_ info;
	info.portName = ui->comboBoxSeriPort->currentText();
	info.BaudRate = ui->leBT->text().toInt();
	info.DataBits = ui->sbDataSite->value();
	info.Parity = ui->sbStopSite->value();
	if (ui->rbHight->isChecked())
	{
		info.isHigh = true;
	}
	else {
		info.isHigh = false;
	}
	emit portInfoChanged(info);
}

void DeviceControl::on_pbScanSeriPort_clicked()
{
	isScanPort = true;
	QList<QSerialPortInfo> availablePorts = QSerialPortInfo::availablePorts();

	QStringList ports;
	// 遍历并打印串口信息
	foreach(const QSerialPortInfo & portInfo, availablePorts) {
		qDebug() << "Port Name:" << portInfo.portName();        // 例如: "COM1", "COM2"
		qDebug() << "Description:" << portInfo.description();    // 设备描述
		qDebug() << "Manufacturer:" << portInfo.manufacturer();  // 制造商信息
		qDebug() << "System Location:" << portInfo.systemLocation(); // 系统路径
		qDebug() << "===================================";

		ports << portInfo.portName();
	}
	ui->comboBoxSeriPort->clear();
	ui->comboBoxSeriPort->addItems(ports);

	isScanPort = false;
}
