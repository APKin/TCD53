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

private:
	Ui::ImageStoreClass *ui;
};
