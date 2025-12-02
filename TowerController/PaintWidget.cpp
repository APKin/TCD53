#include "PaintWidget.h"

PaintWidget::PaintWidget(QWidget *parent)
	: QWidget(parent)
	, ui(new Ui::PaintWidgetClass())
{
	ui->setupUi(this);
}

PaintWidget::~PaintWidget()
{
	delete ui;
}

void PaintWidget::setImage(const QImage& image)
{
	m_image = image;
	update(); // ¥•∑¢÷ÿªÊ
}

void PaintWidget::paintEvent(QPaintEvent* event)
{
	QMutexLocker locker(&m_mutex);
	QPainter painter(this);
	if (!m_image.isNull()) {
		painter.drawImage(rect(), m_image);
	}
}
