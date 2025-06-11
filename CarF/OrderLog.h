#pragma once

#include <QDialog>
#include "ui_OrderLog.h"
#include "DBHelper.h"
#include "InstructLogDAO.h"

QT_BEGIN_NAMESPACE
namespace Ui { class OrderLogClass; };
QT_END_NAMESPACE

class OrderLog : public QDialog
{
	Q_OBJECT

public:
	OrderLog(QWidget *parent = nullptr);
	~OrderLog();

private:
	Ui::OrderLogClass *ui;
	DBHelper dbHelper;               // 如果 DBHelper 需要作为成员
	InstructLogDAO instructLogDAO;   // 声明 InstructLogDAO 成员变量
private slots:
	void on_btnQueryLog_clicked();
};
