#pragma once

#include <QDialog>
#include "ui_DeviceControl.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DeviceControlClass; };
QT_END_NAMESPACE

class DeviceControl : public QDialog
{
	Q_OBJECT

public:
	DeviceControl(QWidget *parent = nullptr);
	~DeviceControl();

private:
	Ui::DeviceControlClass *ui;
};
