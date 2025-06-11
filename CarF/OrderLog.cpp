#include "OrderLog.h"
#include "DBHelper.h"
#include "InstructLogDAO.h"
#include <QMessageBox>
#include <QStandardItemModel>

OrderLog::OrderLog(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::OrderLogClass())
	, dbHelper()                     // 初始化 DBHelper（如果有默认构造）
	, instructLogDAO(dbHelper)        // 用 dbHelper 初始化 InstructLogDAO

{
	ui->setupUi(this);
	this->setWindowTitle("指令日志");
}

OrderLog::~OrderLog()
{
	delete ui;
}

void OrderLog::on_btnQueryLog_clicked() {
	//获取关键字条件
	QString typeKeyword = ui->txtKeyWord->text();
	//获取日期条件
	//调用查询
	QList<InstructLog> list= instructLogDAO.findByCondition(typeKeyword, QDateTime(), QDateTime());
	//清空表格
	QTableView* tvwOrderLog =ui->tvwOrderLog;
	// 1. 隐藏自带的垂直行号列
	tvwOrderLog->verticalHeader()->setVisible(false);
	//赋值表格
	QStandardItemModel *model = new QStandardItemModel(list.size(), 4, tvwOrderLog);
	model->setHorizontalHeaderLabels({ "序号", "指令类型", "指令内容", "指令时间" });
	// 2. 创建带居中格式的item
	auto createCenteredItem = [](const QString& text) {
		QStandardItem* item = new QStandardItem(text);
		item->setTextAlignment(Qt::AlignCenter);
		return item;
	};
	for (int i = 0; i < list.size(); ++i) {
		const auto& log = list[i];
		/*model->setItem(i, 0, new QStandardItem(QString::number(i + 1)));
		model->setItem(i, 1, new QStandardItem(log.getType()));
		model->setItem(i, 2, new QStandardItem(log.getContent()));
		model->setItem(i, 3, new QStandardItem(log.getCreateTime().toString("yyyy-MM-dd HH:mm:ss")));*/
		model->setItem(i, 0, createCenteredItem(QString::number(i + 1)));
		model->setItem(i, 1, createCenteredItem(log.getType()));
		model->setItem(i, 2, new QStandardItem(log.getContent())); // 内容不居中
		model->setItem(i, 3, createCenteredItem(log.getCreateTime().toString("yyyy-MM-dd HH:mm:ss")));

		// 存储ID到第一列
		model->item(i, 0)->setData(log.getId(), Qt::UserRole);
	}

	tvwOrderLog->setModel(model);
	//QMessageBox::information(nullptr, "条数", QString::number(list.size()));
}