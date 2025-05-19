#pragma once

#include <QDialog>
#include "ui_StreamSetting.h"

QT_BEGIN_NAMESPACE
namespace Ui { class StreamSettingClass; };
QT_END_NAMESPACE

class StreamSetting : public QDialog
{
	Q_OBJECT

public:
	StreamSetting(QWidget *parent = nullptr);
	~StreamSetting();

private:
	Ui::StreamSettingClass *ui;
};
