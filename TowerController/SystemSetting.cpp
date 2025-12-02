#include "SystemSetting.h"
#include <QFileDialog>
#include <qdebug.h>

SystemSetting::SystemSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::SystemSettingClass())
{
	ui->setupUi(this);
	this->setWindowTitle("系统设置");
	viewNum = 2;
	init();
	
}

SystemSetting::~SystemSetting()
{
	delete ui;
}

QString SystemSetting::getstorePath()
{
	return ui->txtSavePath->text();
}

void SystemSetting::init()
{
	ui->mainViewHeigh->setText(QString::number(this->height()));
	ui->leViewwidth1->setText(QString::number(this->height()));
	ui->leViewwidth2->setText(QString::number(this->height()));
	ui->leViewwidth3->setText(QString::number(this->height()));
	ui->leViewwidth4->setText(QString::number(this->height()));
	ui->leViewwidth5->setText(QString::number(this->height()));

	ui->spViewsite3->setEnabled(false);
	ui->leViewwidth3->setEnabled(false);
								 
	ui->spViewsite4->setEnabled(false);
	ui->leViewwidth4->setEnabled(false);
								 
	ui->spViewsite5->setEnabled(false);
	ui->leViewwidth5->setEnabled(false);

	ui->txtSavePath->setText("image");
	
}

void SystemSetting::on_pbPlus_clicked()
{
	qDebug() << "+";
	if (viewNum >= 2 && viewNum <5)
	{
		viewNum += 1;
		if (viewNum == 3)
		{
			ui->spViewsite3->setDisabled(false);
			ui->leViewwidth3->setDisabled(false);
			emit plusMoni(3);
		}
		if (viewNum == 4)
		{
			ui->spViewsite4->setDisabled(false);
			ui->leViewwidth4->setDisabled(false);
			emit plusMoni(4);
		}
		if (viewNum == 5)
		{
			ui->spViewsite5->setDisabled(false);
			ui->leViewwidth5->setDisabled(false);
			emit plusMoni(5);
		}
	}
}

void SystemSetting::on_pbReduce_clicked()
{
	qDebug() << "-";

	if (viewNum > 2 && viewNum <= 5)
	{
		viewNum -= 1;
		if (viewNum == 2)
		{
			ui->spViewsite3->setDisabled(true);
			ui->leViewwidth3->setDisabled(true);
			emit reduceMoni(3);
		}
		if (viewNum == 3)
		{
			ui->spViewsite4->setDisabled(true);
			ui->leViewwidth4->setDisabled(true);
			emit reduceMoni(4);
		}
		if (viewNum == 4)
		{
			ui->spViewsite5->setDisabled(true);
			ui->leViewwidth5->setDisabled(true);
			emit reduceMoni(5);
		}
	}

}


//帮助按钮点击事件
void SystemSetting::on_btnFloderSetting_clicked() {
	//打开目录选择
	QString folder = QFileDialog::getExistingDirectory(
		nullptr, // 父窗口
		"Select Directory", // 对话框标题
		QDir::homePath(), // 默认路径
		QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
	);
	ui->txtSavePath->setText(folder);
}