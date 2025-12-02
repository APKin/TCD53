#include "StreamSetting.h"

StreamSetting::StreamSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::StreamSettingClass())
{
	ui->setupUi(this);
	this->setWindowTitle(u8"ÏµÍ³ÉèÖÃ");
}

StreamSetting::~StreamSetting()
{
	delete ui;
}

void StreamSetting::setMainView(QString url)
{
	ui->leMainView->setText(url);
}

void StreamSetting::setMoiView(QString url)
{
	ui->leMoiView->setText(url);
}

void StreamSetting::setWarnInfo(QString url)
{
	ui->leWarnInfo->setText(url);
}

void StreamSetting::on_pbSure_clicked()
{
	this->close();
}

void StreamSetting::on_pbCan_clicked()
{
	this->close();
}
