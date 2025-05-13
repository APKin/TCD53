#include "SystemSetting.h"
#include <QApplication>
#include <QFileDialog>
#include <QDebug>
#include <QMessageBox>

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

void SystemSetting::on_pushButton_3_clicked()
{
    //打开目录选择
    QString folder = QFileDialog::getExistingDirectory(
        nullptr, // 父窗口
        "Select Directory", // 对话框标题
        QDir::homePath(), // 默认路径
        QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks
    );
    // 查找 QLineEdit 控件并设置值
    ui->lineEdit->setText(folder);
}
void SystemSetting::on_pushButton_clicked() {
    this->close();
}
void SystemSetting::on_pushButton_2_clicked() {
    //保存配置
    m_result = ui->lineEdit->text();
    accept();
}
