#include "OrderLog.h"

OrderLog::OrderLog(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::OrderLogClass())
{
	ui->setupUi(this);
	this->setWindowTitle("ָ����־");
}

OrderLog::~OrderLog()
{
	delete ui;
}
