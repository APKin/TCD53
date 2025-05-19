#include "StreamSetting.h"

StreamSetting::StreamSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::StreamSettingClass())
{
	ui->setupUi(this);
}

StreamSetting::~StreamSetting()
{
	delete ui;
}
