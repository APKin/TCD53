 #include "CarF.h"
#include <QApplication>

#include <QFile>

int main(int argc, char* argv[])
{

	QApplication a(argc, argv);

    QFile file("ini//style.qss"); // 指定qss文件路径
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QString styleSheet = QLatin1String(file.readAll());
        a.setStyleSheet(styleSheet);
        file.close();
    }
    else
    {
        std::cout << "QSS load fail" << std::endl;
    }

	CarF w;
	w.showMaximized();


	return a.exec();
}
