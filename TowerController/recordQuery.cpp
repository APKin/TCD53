#include "recordQuery.h"

recordQuery::recordQuery(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::recordQueryClass())
{
	ui->setupUi(this);
}

recordQuery::~recordQuery()
{
	delete ui;
}
