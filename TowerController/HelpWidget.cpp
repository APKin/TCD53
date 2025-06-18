#include "HelpWidget.h"
#include <QDebug>
HelpWidget::HelpWidget(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::HelpWidgetClass())
{
	ui->setupUi(this);
    init();
    
}

HelpWidget::~HelpWidget()
{
	delete ui;
}

void HelpWidget::init()
{
    currentIndex = 0;
    // 后续读取
    QString fileN = "D:\\QtProject\\untitled1\\pdf.pdf";
    QPdfium pdf(fileN);
    qDebug() << pdf.isValid();
    int pagenumber = pdf.pageCount();
    for (int i = 0; i < pagenumber; i++) {
        QPdfiumPage page = pdf.page(i); // pdf.page(0)
        qDebug() << i << ":" << page.width();
        QImage image = page.image(1); //renders it 3 times bigger // page.image(1)
        images.append(image);

        //ui->label->setPixmap(QPixmap::fromImage(image));
    }
}

void HelpWidget::paintEvent(QPaintEvent* event)
{
    Q_UNUSED(event);
    QPainter painter(this);
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    if (images.isEmpty()) {
        painter.drawText(rect(), Qt::AlignCenter, "No images to display");
        return;
    }

    const QImage& currentImage = images[currentIndex];
    if (currentImage.isNull()) {
        painter.drawText(rect(), Qt::AlignCenter, "Image is null");
        return;
    }

    // 计算缩放后的尺寸，保持宽高比
    QSize scaledSize = currentImage.size().scaled(size(), Qt::KeepAspectRatio);
    // 计算绘制的起始位置，使图片居中
    int x = (width() - scaledSize.width()) / 2;
    int y = (height() - scaledSize.height()) / 2;

    painter.drawImage(QRect(x, y, scaledSize.width(), scaledSize.height()),
        currentImage,
        currentImage.rect());

}

void HelpWidget::wheelEvent(QWheelEvent* event)
{
    if (images.isEmpty()) {
        event->ignore();
        return;
    }

    QPoint numDegrees = event->angleDelta() / 8; // 获取滚轮滚动的角度
    if (!numDegrees.isNull()) {
        if (numDegrees.y() > 0) {
            // 向上滚动：上一张
            currentIndex = (currentIndex == 0) ? images.size() - 1 : currentIndex - 1;
        }
        else {
            // 向下滚动：下一张
            currentIndex = (currentIndex + 1) % images.size();
        }
        update(); // 触发重绘
        event->accept();
    }
    else {
        event->ignore();
    }
}
