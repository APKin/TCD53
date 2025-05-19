#pragma once

#include <QDialog>
#include "ui_HelpWidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class HelpWidgetClass; };
QT_END_NAMESPACE

class HelpWidget : public QDialog
{
	Q_OBJECT

public:
	HelpWidget(QWidget *parent = nullptr);
	~HelpWidget();

private:
	Ui::HelpWidgetClass *ui;
};
