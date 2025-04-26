#include "SystemSetting.h"

SystemSetting::SystemSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::SystemSettingClass())
{
	ui->setupUi(this);
	this->setWindowTitle("œµÕ≥…Ë÷√");
}

SystemSetting::~SystemSetting()
{
	delete ui;
}
