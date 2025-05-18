#pragma once

#include <QMainWindow>
#include "ui_QtWidgetsClass.h"
#include "RtspStreamReader.h"
QT_BEGIN_NAMESPACE
namespace Ui { class QtWidgetsClassClass; };
QT_END_NAMESPACE

class QtWidgetsClass : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgetsClass(QWidget *parent = nullptr);
	~QtWidgetsClass();

private:
	Ui::QtWidgetsClassClass *ui;
	RtspStreamReader* streamReader;
};
