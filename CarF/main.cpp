 #include "CarF.h"
#include <QApplication>
#include "DBHelper.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
        CarF w;
        w.show();


    return a.exec();
}
