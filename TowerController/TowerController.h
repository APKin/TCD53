#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TowerController.h"
#include "FFmpegWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class TowerControllerClass; };
QT_END_NAMESPACE

class TowerController : public QMainWindow
{
    Q_OBJECT

public:
    TowerController(QWidget *parent = nullptr);
    ~TowerController();

private:
    Ui::TowerControllerClass *ui;
private slots:
    void on_btnRecordQuery_clicked();
    void on_btnSystenSettings_clicked();
    void onBtnStreamSettingClicked();
    void onBtnDeviceContorlClicked();
    void onBtnHelpClicked();

    void on_pushButton_7_clicked();
};
