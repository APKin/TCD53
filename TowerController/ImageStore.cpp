#include "ImageStore.h"
#include <QDateTime>
ImageStore::ImageStore(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::ImageStoreClass())
{
	ui->setupUi(this);

	nameMain = "Main" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
	nameCurMoni = "Moni" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");

	ui->mainImgeName->setText(nameMain);
	ui->curImageSave->setText(nameCurMoni);
	//ui->mainImgeName
	//	curImageSave
}

ImageStore::~ImageStore()
{
	delete ui;
}

QString ImageStore::getMainName()
{
	nameMain = "Main" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
	ui->mainImgeName->setText(nameMain);

	return nameMain;
}

QString ImageStore::getCurMoni()
{
	nameCurMoni = "Moni" + QDateTime::currentDateTime().toString("yyyyMMdd_hhmmss");
	ui->curImageSave->setText(nameCurMoni);

	return nameCurMoni;
}
