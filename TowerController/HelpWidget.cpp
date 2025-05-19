#include "HelpWidget.h"

HelpWidget::HelpWidget(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::HelpWidgetClass())
{
	ui->setupUi(this);
}

HelpWidget::~HelpWidget()
{
	delete ui;
}
