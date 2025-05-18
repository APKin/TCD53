#include "ImageStore.h"

ImageStore::ImageStore(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::ImageStoreClass())
{
	ui->setupUi(this);
}

ImageStore::~ImageStore()
{
	delete ui;
}
