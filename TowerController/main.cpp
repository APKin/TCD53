#include "TowerController.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    TowerController w;
    w.show();
    return a.exec();
}
