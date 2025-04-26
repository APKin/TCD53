#include "PictureSave.h"

PictureSave::PictureSave(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::PictureSaveClass())
{
	ui->setupUi(this);
	this->setWindowTitle("Í¼Ïñ´æ´¢");
}

PictureSave::~PictureSave()
{
	delete ui;
}
