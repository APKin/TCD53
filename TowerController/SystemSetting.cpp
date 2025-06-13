#include "SystemSetting.h"
#include <QFileDialog>

SystemSetting::SystemSetting(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::SystemSettingClass())
{
	ui->setupUi(this);
	this->setWindowTitle("系统设置");
}

SystemSetting::~SystemSetting()
{
	delete ui;
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