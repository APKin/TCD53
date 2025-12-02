#pragma once

#include <QDialog>
#include "ui_ImageStore.h"

QT_BEGIN_NAMESPACE
namespace Ui { class ImageStoreClass; };
QT_END_NAMESPACE

class ImageStore : public QDialog
{
	Q_OBJECT

public:
	ImageStore(QWidget *parent = nullptr);
	~ImageStore();
	// ∂‘Õ‚ «get
	QString getMainName();
	QString getCurMoni();

	

private:
	Ui::ImageStoreClass *ui;
	QString nameMain;
	QString nameCurMoni;

	
};
