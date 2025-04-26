#pragma once

#include <QDialog>
#include "ui_PictureSave.h"

QT_BEGIN_NAMESPACE
namespace Ui { class PictureSaveClass; };
QT_END_NAMESPACE

class PictureSave : public QDialog
{
	Q_OBJECT

public:
	PictureSave(QWidget *parent = nullptr);
	~PictureSave();

private:
	Ui::PictureSaveClass *ui;
};
