#pragma once

#include <QWidget>
#include "ui_recordQuery.h"

QT_BEGIN_NAMESPACE
namespace Ui { class recordQueryClass; };
QT_END_NAMESPACE

class recordQuery : public QWidget
{
	Q_OBJECT

public:
	recordQuery(QWidget *parent = nullptr);
	~recordQuery();

private:
	Ui::recordQueryClass *ui;
};
