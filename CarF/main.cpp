#include "CarF.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CarF w;
    w.show();
    return a.exec();
}
