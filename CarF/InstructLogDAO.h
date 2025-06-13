#pragma once
#include "InstructLog.h"
#include "DBHelper.h"
#include <QList>

class InstructLogDAO
{
public:
    explicit InstructLogDAO(DBHelper& dbHelper) : dbHelper(dbHelper) {}

    // 插入记录
    bool insert(const InstructLog& log);

    // 更新记录 (根据ID)
    bool update(const InstructLog& log);

    // 删除记录 (根据ID)
    bool remove(qint64 id);

    // 根据ID查询
    InstructLog findById(qint64 id);

    // 查询所有记录
    QList<InstructLog> findAll();

    // 条件查询 (类型/内容模糊匹配 + 时间范围)
    QList<InstructLog> findByCondition(const QString typeKeyword,
        const QDateTime startTime,
        const QDateTime endTime);

private:
    DBHelper dbHelper;

    // 从查询结果构建实体对象
    InstructLog buildFromQuery(const QSqlQuery& query);
};