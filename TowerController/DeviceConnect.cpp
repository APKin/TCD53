#include "DeviceConnect.h"

DeviceConnect::DeviceConnect(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::DeviceConnectClass())
{
	ui->setupUi(this);
}

DeviceConnect::~DeviceConnect()
{
	delete ui;
}
