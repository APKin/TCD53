#include "TowerController.h"
#include <QMessageBox>
#include <SystemSetting.h>
#include <ParkPoliceRecord.cpp>

TowerController::TowerController(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TowerControllerClass())
{
    ui->setupUi(this);
}

TowerController::~TowerController()
{
    delete ui;
}
// 初始化DAL
ParkPoliceRecordDAL dal;
//记录查询按钮点击事件
void TowerController::on_btnRecordQuery_clicked()
{
    // 创建表（首次运行）
    dal.createTable();
}
//系统设置按钮点击事件
void TowerController::on_btnSystenSettings_clicked() {

    SystemSetting* secondWin = new SystemSetting(this);
    if (secondWin->exec() == QDialog::Accepted) { // 模态显示对话框
        //imageSavePath = secondWin->getResult(); // 获取输入的文本
        //更新入库
        //QString maxId = db->getMaxId("img_path");
        //db->updateData("img_path", "url", imageSavePath, maxId);
        //saveStringToFile(imageSavePath, "imageSavePath.bin");  // 自动创建 subdir 目录和 example.txt 文件
    }
    else {
        QMessageBox::information(nullptr, "取消操作", "您取消了输入。");
    }
}
//推流设置按钮点击事件
void TowerController::onBtnStreamSettingClicked() {

}
//设备控制指令设置按钮点击事件
void TowerController::onBtnDeviceContorlClicked() {

}
//帮助按钮点击事件
void TowerController::onBtnHelpClicked() {

}