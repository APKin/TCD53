#include "TowerController.h"
#include <QMessageBox>
#include <SystemSetting.h>
#include <ParkPoliceRecord.cpp>
#include <RecordQuery.h>

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
//ParkPoliceRecordDAL dal;
//记录查询按钮点击事件
void TowerController::on_btnRecordQuery_clicked()
{
    // 创建表（首次运行）
    //dal.createTable();
    RecordQuery* secondWin = new RecordQuery(this);
    secondWin->exec();
}
//系统设置按钮点击事件
void TowerController::on_btnSystenSettings_clicked() {

    SystemSetting* secondWin = new SystemSetting(this);
    secondWin->exec();
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