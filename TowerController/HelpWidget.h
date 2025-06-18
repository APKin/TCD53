#pragma once

#include <QDialog>
#include "ui_HelpWidget.h"
#include "qpdfium.h"
#include <QPainter>
#include <QWheelEvent>
#include <QVector>

QT_BEGIN_NAMESPACE
namespace Ui { class HelpWidgetClass; };
QT_END_NAMESPACE

class HelpWidget : public QDialog
{
	Q_OBJECT

public:
	HelpWidget(QWidget *parent = nullptr);
	~HelpWidget();

	void init();

protected:

	void paintEvent(QPaintEvent* event) override;

	void wheelEvent(QWheelEvent* event) override;

private:
	Ui::HelpWidgetClass *ui;

	QVector<QImage> images;
	int currentIndex;
};
