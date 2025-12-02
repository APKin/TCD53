#pragma once

#include <QDialog>
#include "ui_SystemSetting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class SystemSettingClass; };
QT_END_NAMESPACE

class SystemSetting : public QDialog
{
	Q_OBJECT

public:
	SystemSetting(QWidget *parent = nullptr);
	~SystemSetting();
	QString getResult() const { return m_result; } // ·µ»Ø×Ö·û´®

private:
	Ui::SystemSettingClass *ui;
	QString m_result;
private slots:
	void on_pushButton_3_clicked();
	void on_pushButton_clicked();
	void on_pushButton_2_clicked();

	void on_pbBrowse_clicked();
	void on_pbSure_clicked();
	void on_pbOut_clicked();
};
