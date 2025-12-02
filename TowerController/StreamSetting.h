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

	void setMainView(QString url);

	void setMoiView(QString url);

	void setWarnInfo(QString url);
	
private slots:
	//
	void on_pbSure_clicked();

	void on_pbCan_clicked();

	// È¡ÏûtextChange²Û
	//void on_XXX_textChanged(const QString& arg1);

private:
	Ui::StreamSettingClass *ui;
};
