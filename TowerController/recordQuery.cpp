#include "RecordQuery.h"
#include <QStandardItemModel>

RecordQuery::RecordQuery(QWidget *parent)
	: QDialog(parent)
	, ui(new Ui::RecordQueryClass())
{
	ui->setupUi(this);
	//初始化为今年
    ui->detEnd->setDate(QDate::currentDate());
	// 初始化treeView
	QStandardItemModel* model = new QStandardItemModel(this);
	model->setHorizontalHeaderLabels({ "目标", "方向", "俯仰", "距离", "经纬高", "时间" });
	ui->treeView->setModel(model);
	ui->treeView->setEditTriggers(QAbstractItemView::NoEditTriggers); // 禁止编辑
}

RecordQuery::~RecordQuery()
{
	delete ui;
}
void RecordQuery::on_btnRecordQuery_clicked() {
	QString keyword = ui->txtKeyWord->text();
	QDate beginDate = ui->detBegin->date();
	QDate endDate = ui->detEnd->date();
	//设置条件
	//查询告警记录
	QList<ParkPoliceRecord> list = recordDAL.findByCondition(keyword, beginDate, endDate);
	//根据告警记录查询图片列表
    if (!list.isEmpty()) {

        // 2. 获取警情ID集合
        QList<QString> recordIds;
        for (const auto& record : list) {
            recordIds.append(QString::number(record.id));
        }

        // 3. 批量查询关联图片
        QList<ImgFile> allImages = imgDAL.getByRecordIds(recordIds);

        // 4. 按警情ID分组图片
        QMap<int, QList<ImgFile>> imagesMap; // key: 警情ID, value: 图片列表
        for (const auto& img : allImages) {
            int recordId = img.record_id.toInt();
            imagesMap[recordId].append(img);
        }

        // 5. 将图片关联到对应警情记录
        for (auto& record : list) {
            if (imagesMap.contains(record.id)) {
                record.images = imagesMap[record.id];
            }
        }
    }
    loadDataToTreeView(list);
}
void RecordQuery::loadDataToTreeView(const QList<ParkPoliceRecord>& records)
{
    // 获取模型（确保模型已初始化，构造函数中已初始化）
    QStandardItemModel* model = qobject_cast<QStandardItemModel*>(ui->treeView->model());
    Q_ASSERT(model); // 确保模型存在

    // 清空数据（保留表头）
    model->removeRows(0, model->rowCount());

    // 添加数据行
    for (const auto& record : records) {
        QList<QStandardItem*> items;

        // 目标名称（空值检查）
        items << new QStandardItem(record.target_name.isEmpty() ? "N/A" : record.target_name);

        // 方向（格式化为整数度）
        items << new QStandardItem(QString::number(record.direction, 'f', 0) + "°");

        // 俯仰（格式化为整数度）
        items << new QStandardItem(QString::number(record.pitch, 'f', 0) + "°");

        // 距离（保留1位小数）
        items << new QStandardItem(QString::number(record.distance, 'f', 1) + "m");

        // 经纬高（合并显示）
        QString coordStr = QString("N%1°%2'%3'' E%4°%5'%6'' %7m")
            .arg(qAbs(record.latitude), 0, 'f', 0)   // 纬度整数部分
            .arg((qAbs(record.latitude) - floor(qAbs(record.latitude))) * 60, 0, 'f', 0)  // 分
            .arg((((qAbs(record.latitude) - floor(qAbs(record.latitude))) * 60) -
                floor((qAbs(record.latitude) - floor(qAbs(record.latitude))) * 60)) * 60, 0, 'f', 0)  // 秒
            .arg(qAbs(record.longitude), 0, 'f', 0)   // 经度整数部分
            .arg((qAbs(record.longitude) - floor(qAbs(record.longitude))) * 60, 0, 'f', 0)  // 分
            .arg((((qAbs(record.longitude) - floor(qAbs(record.longitude))) * 60) -
                floor((qAbs(record.longitude) - floor(qAbs(record.longitude))) * 60)) * 60, 0, 'f', 0)  // 秒
            .arg(record.height, 0, 'f', 1);  // 高度
        items << new QStandardItem(coordStr);

        // 记录时间
        items << new QStandardItem(record.record_time);

        // 将ID作为隐藏数据存储在第一列
        items.first()->setData(record.id, Qt::UserRole);

        model->appendRow(items);
    }

    // 设置排序（默认按时间降序）
    model->sort(5, Qt::DescendingOrder);
}