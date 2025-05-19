#pragma once

#include <QMainWindow>
#include "ui_QtWidgets.h"

QT_BEGIN_NAMESPACE
namespace Ui { class QtWidgetsClass; };
QT_END_NAMESPACE

class QtWidgets : public QMainWindow
{
	Q_OBJECT

public:
	QtWidgets(QWidget *parent = nullptr);
	~QtWidgets();

private:
	Ui::QtWidgetsClass *ui;
};
