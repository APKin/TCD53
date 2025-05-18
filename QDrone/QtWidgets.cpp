#include "QtWidgets.h"

QtWidgets::QtWidgets(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::QtWidgetsClass())
{
	ui->setupUi(this);
}

QtWidgets::~QtWidgets()
{
	delete ui;
}
