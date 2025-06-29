#pragma once

#include <QDialog>
#include "ui_RecordQuery.h"
#include "ParkPoliceRecord.cpp"
#include "ImgFile.cpp"

QT_BEGIN_NAMESPACE
namespace Ui { class RecordQueryClass; };
QT_END_NAMESPACE

class RecordQuery : public QDialog
{
	Q_OBJECT

public:
	RecordQuery(QWidget *parent = nullptr);
	~RecordQuery();

private:
	Ui::RecordQueryClass *ui;
	ParkPoliceRecordDAL recordDAL;
	ImgFileDAL imgDAL;
private slots:
	void on_btnRecordQuery_clicked();
	void loadDataToTreeView(const QList<ParkPoliceRecord>& records);
	void setupColumnSpans(QTreeView* view);
};
