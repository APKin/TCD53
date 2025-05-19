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

private:
	Ui::SystemSettingClass *ui;
};
