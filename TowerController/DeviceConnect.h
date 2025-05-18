#pragma once

#include <QDialog>
#include "ui_DeviceConnect.h"

QT_BEGIN_NAMESPACE
namespace Ui { class DeviceConnectClass; };
QT_END_NAMESPACE

class DeviceConnect : public QDialog
{
	Q_OBJECT

public:
	DeviceConnect(QWidget *parent = nullptr);
	~DeviceConnect();

private:
	Ui::DeviceConnectClass *ui;
};
