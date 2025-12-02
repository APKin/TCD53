#include "QtWidgetsClass.h"

QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::QtWidgetsClassClass())
{
	ui->setupUi(this);
}

QtWidgetsClass::~QtWidgetsClass()
{
	delete ui;
}
