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

	QString getstorePath();

private:
	void init();

public:
signals:
	void plusMoni(int index);
	void reduceMoni(int index);
	// 重设大小
	void resizeMoni(int index, int height);

private slots:
	void on_btnFloderSetting_clicked();

	void on_pbPlus_clicked();
	void on_pbReduce_clicked();

private:
	Ui::SystemSettingClass* ui;
	int viewNum;
};
