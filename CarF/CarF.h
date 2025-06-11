#pragma once

#include <QtWidgets/QMainWindow>
#include <QString>
#include "ui_CarF.h"
#include "OrderLog.h"
#include "PictureSave.h"
#include "SystemSetting.h"

class CarF : public QMainWindow
{
    Q_OBJECT

public:
    CarF(QWidget *parent = nullptr);
    ~CarF();
    static QString imageSavePath; // 声明静态变量（不初始化）
private:
    Ui::CarFClass ui;

    std::unique_ptr<OrderLog> OrderLog_;
    std::unique_ptr<PictureSave> PictureSave_;
    std::unique_ptr<SystemSetting> SystemSetting_;
private slots:
    //打开系统设置界面
    void on_pushButton_clicked();
    //void saveStringToFile(   QString& text, const QString& filename);
    QString getImagePath();
    //保存图像存储路径
    void saveStringToFile(const QString& text, const QString& filename);
    //读取文件存储路径配置
    QString readFileIfExists(const QString& filename);
    //无人车控制 自动前进
    void on_btnAutoDisplay_clicked();
    //无人车控制 停止
    void on_btnStop_clicked();
    //指令日志
    void on_btnOrderLog_clicked();
};
