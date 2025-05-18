#include "TowerController.h"

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
