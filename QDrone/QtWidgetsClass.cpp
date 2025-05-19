#include "QtWidgetsClass.h"


QtWidgetsClass::QtWidgetsClass(QWidget *parent)
	: QMainWindow(parent)
	, ui(new Ui::QtWidgetsClassClass())
{
	ui->setupUi(this);

    streamReader = new RtspStreamReader(this);
    connect(streamReader, &RtspStreamReader::frameReady, this, [this](const QImage& image) {
        QPixmap pixmap = QPixmap::fromImage(image);
        qDebug() << "setPixmap";
        ui->videoLabel->setPixmap(pixmap.scaled(ui->videoLabel->size(), Qt::KeepAspectRatio));
        });

    if (!streamReader->openStream("rtsp://127.0.0.1:8554/mystream")) {
        qWarning() << "Failed to open RTSP stream";
    }
    else
    {
        qDebug() << "123";
    }
}

QtWidgetsClass::~QtWidgetsClass()
{
	delete ui;
    delete streamReader;
}
