#include "SystemSetting.h"

SystemSetting::SystemSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::SystemSettingClass())
{
	ui->setupUi(this);
	this->setWindowTitle("ϵͳ����");
}

SystemSetting::~SystemSetting()
{
	delete ui;
}
