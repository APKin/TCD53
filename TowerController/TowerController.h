#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TowerController.h"

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
};
