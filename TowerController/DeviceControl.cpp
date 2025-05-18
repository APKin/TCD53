#include "DeviceControl.h"

DeviceControl::DeviceControl(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DeviceControlClass())
{
	ui->setupUi(this);
}

DeviceControl::~DeviceControl()
{
	delete ui;
}
