#include "PictureSave.h"

PictureSave::PictureSave(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::PictureSaveClass())
{
	ui->setupUi(this);
	this->setWindowTitle("ͼ��洢");
}

PictureSave::~PictureSave()
{
	delete ui;
}
