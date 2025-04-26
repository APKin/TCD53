#pragma once

#include <QtWidgets/QMainWindow>
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

private:
    Ui::CarFClass ui;

    std::unique_ptr<OrderLog> OrderLog_;
    std::unique_ptr<PictureSave> PictureSave_;
    std::unique_ptr<SystemSetting> SystemSetting_;

};
