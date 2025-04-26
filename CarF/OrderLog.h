#pragma once

#include <QWidget>
#include "ui_OrderLog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OrderLogClass; };
QT_END_NAMESPACE

class OrderLog : public QWidget
{
	Q_OBJECT

public:
	OrderLog(QWidget *parent = nullptr);
	~OrderLog();

private:
	Ui::OrderLogClass *ui;
};
