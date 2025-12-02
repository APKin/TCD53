#pragma once

#include <QWidget>
#include "ui_PaintWidget.h"

#include <QPainter>
#include <QPaintEvent>
#include <QResizeEvent>

#include <QMutexLocker>

QT_BEGIN_NAMESPACE
namespace Ui { class PaintWidgetClass; };
QT_END_NAMESPACE

class PaintWidget : public QWidget
{
	Q_OBJECT

public:
	PaintWidget(QWidget *parent = nullptr);
	~PaintWidget();
	void setImage(const QImage& image);

protected:
	void paintEvent(QPaintEvent* event) override;

	
private:
	Ui::PaintWidgetClass *ui;
	QImage m_image;

	QMutex m_mutex;
};
