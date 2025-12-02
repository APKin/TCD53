#include "InstructLogDAO.h"
#include <QSqlQuery>
#include <QDebug>

// 插入记录
bool InstructLogDAO::insert(const InstructLog& log)
{
    QVariantMap data;
    data["type"] = log.getType();
    data["content"] = log.getContent();
    data["create_time"] = log.getCreateTime().toString("yyyy-MM-dd HH:mm:ss");

    return dbHelper.insertData("instruct_log", data);
}

// 更新记录
bool InstructLogDAO::update(const InstructLog& log)
{
    QSqlQuery query(dbHelper.getDatabase());

    query.prepare("UPDATE instruct_log SET "
        "type = :type, "
        "content = :content, "
        "create_time = :create_time "
        "WHERE id = :id");

    query.bindValue(":type", log.getType());
    query.bindValue(":content", log.getContent());
    query.bindValue(":create_time", log.getCreateTime().toString("yyyy-MM-dd HH:mm:ss"));
    query.bindValue(":id", log.getId());

    return query.exec();
}

// 删除记录
bool InstructLogDAO::remove(qint64 id)
{
    QSqlQuery query(dbHelper.getDatabase());
    query.prepare("DELETE FROM instruct_log WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// 根据ID查询
InstructLog InstructLogDAO::findById(qint64 id)
{
    QSqlQuery query(dbHelper.getDatabase());
    query.prepare("SELECT * FROM instruct_log WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        return buildFromQuery(query);
    }
    return InstructLog(); // 返回空对象
}

// 查询所有记录
QList<InstructLog> InstructLogDAO::findAll()
{
    QList<InstructLog> logs;
    QSqlQuery query("SELECT * FROM instruct_log", dbHelper.getDatabase());

    while (query.next()) {
        logs.append(buildFromQuery(query));
    }
    return logs;
}

// 条件查询
QList<InstructLog> InstructLogDAO::findByCondition(
    const QString typeKeyword,
    const QDateTime startTime,
    const QDateTime endTime)
{
    QList<InstructLog> logs;
    QString sql = "SELECT * FROM instruct_log WHERE 1=1";
    QVariantMap params;

    // 模糊匹配
    if (!typeKeyword.isEmpty()) {
        sql += " AND (type LIKE :type or content LIKE :content) ";
        params[":type"] = "%" + typeKeyword + "%";
        params[":content"] = "%" + typeKeyword + "%";
    }


    // 开始时间过滤
    if (startTime.isValid()) {
        sql += " AND create_time >= :start_time";
        params[":start_time"] = startTime.toString("yyyy-MM-dd HH:mm:ss");
    }

    // 结束时间过滤
    if (endTime.isValid()) {
        sql += " AND create_time <= :end_time";
        params[":end_time"] = endTime.toString("yyyy-MM-dd HH:mm:ss");
    }

    sql += " ORDER BY create_time C";
    dbHelper.open();
    QSqlQuery query(dbHelper.getDatabase());
    query.prepare(sql);

    // 绑定参数
    for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (query.exec()) {
        while (query.next()) {
            logs.append(buildFromQuery(query));
        }
    }
    else {
        qDebug() << "Query failed:" << query.lastError().text();
    }

    return logs;
}

// 从查询结果构建实体对象
InstructLog InstructLogDAO::buildFromQuery(const QSqlQuery& query)
{
    InstructLog log;
    log.setId(query.value("id").toLongLong());
    log.setType(query.value("type").toString());
    log.setContent(query.value("content").toString());
    log.setCreateTime(query.value("create_time").toDateTime());
    return log;
}