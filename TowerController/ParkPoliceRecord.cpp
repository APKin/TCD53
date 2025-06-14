#pragma once
#include "DBHelper.h"
#include <QDateTime>
#include <QString>
#include <ImgFile.cpp>

// 警情记录实体类
class ParkPoliceRecord {
public:
    int id = 0;                 // 记录ID
    QString create_time;        // 创建时间
    QString record_time;        // 记录时间
    QString police_type;        // 警情类型（文本形式）
    double longitude = 0.0;     // 经度
    double latitude = 0.0;      // 纬度
    double height = 0.0;        // 高度
    double direction = 0.0;     // 方向
    double pitch = 0.0;         // 俯仰
    double distance = 0.0;      // 距离
    QString alarm_number;       // 告警编号
    QString target_name;        // 目标名称

    QList<ImgFile> images;      // 图片列表

    // 转换为QVariantMap用于数据库操作
    QVariantMap toVariantMap() const {
        return {
            {"create_time", create_time},
            {"record_time", record_time},
            {"police_type", police_type},
            {"longitude", longitude},
            {"latitude", latitude},
            {"height", height},
            {"direction", direction},
            {"pitch", pitch},
            {"distance", distance},
            {"alarm_number", alarm_number},
            {"target_name", target_name}  // 添加目标名称字段
        };
    }

    // 从QVariantMap加载数据
    void fromVariantMap(const QVariantMap& map) {
        id = map.value("id", 0).toInt();
        create_time = map.value("create_time").toString();
        record_time = map.value("record_time").toString();
        police_type = map.value("police_type").toString();  // 改为文本类型
        longitude = map.value("longitude", 0.0).toDouble();
        latitude = map.value("latitude", 0.0).toDouble();
        height = map.value("height", 0.0).toDouble();
        direction = map.value("direction", 0.0).toDouble();
        pitch = map.value("pitch", 0.0).toDouble();
        distance = map.value("distance", 0.0).toDouble();
        alarm_number = map.value("alarm_number").toString();
        target_name = map.value("target_name").toString();  // 加载目标名称
    }
};

// 警情记录数据访问层
class ParkPoliceRecordDAL {
private:
    DBHelper dbHelper;
    const QString tableName = "park_police_record";

public:
    // 创建表（如果不存在）
    bool createTable() {

        QString sql = R"(
            CREATE TABLE IF NOT EXISTS park_police_record (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                create_time TEXT NOT NULL,
                record_time TEXT NOT NULL,
                police_type TEXT NOT NULL,  -- 改为TEXT类型
                longitude REAL NOT NULL,
                latitude REAL NOT NULL,
                height REAL NOT NULL,
                direction REAL NOT NULL,
                pitch REAL NOT NULL,
                distance REAL NOT NULL,
                alarm_number TEXT NOT NULL, -- 改为TEXT类型
                target_name TEXT            -- 添加目标名称字段
            );
        )";

        QSqlQuery query(dbHelper.getDatabase());
        return query.exec(sql);
    }

    // 插入新记录
    bool insertRecord(ParkPoliceRecord& record) {
        QVariantMap data = record.toVariantMap();
        bool success = dbHelper.insertData(tableName, data);

        if (success) {
            QString idStr = dbHelper.getMaxId(tableName);
            record.id = idStr.toInt();
        }
        return success;
    }

    // 更新记录（按ID）
    bool updateRecord(const ParkPoliceRecord& record) {
        if (record.id <= 0) return false;

        QVariantMap data = record.toVariantMap();
        QString whereCondition = QString("id = %1").arg(record.id);

        foreach(const QString & field, data.keys()) {
            if (field != "id") {
                if (!dbHelper.updateData(tableName, field, data[field].toString(), whereCondition)) {
                    return false;
                }
            }
        }
        return true;
    }

    // 删除记录（按ID）
    bool deleteRecord(int id) {
        QString whereCondition = QString("id = %1").arg(id);
        return dbHelper.updateData(tableName, "id", "-1", whereCondition);
    }

    // 获取所有记录
    QList<ParkPoliceRecord> getAllRecords() {
        QList<ParkPoliceRecord> records;
        QSqlQuery query(dbHelper.getDatabase());

        if (query.exec("SELECT * FROM " + tableName)) {
            while (query.next()) {
                ParkPoliceRecord record;
                QVariantMap map;
                QSqlRecord rec = query.record();
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }
                record.fromVariantMap(map);
                records.append(record);
            }
        }
        return records;
    }

    // 按ID获取记录
    ParkPoliceRecord getRecordById(int id) {
        ParkPoliceRecord record;
        QSqlQuery query(dbHelper.getDatabase());

        query.prepare("SELECT * FROM " + tableName + " WHERE id = :id");
        query.bindValue(":id", id);


        if (query.exec() && query.next()) {
            QVariantMap map;
            QSqlRecord rec = query.record();
            for (int i = 0; i < rec.count(); i++) {
                map[rec.fieldName(i)] = query.value(i);
            }
            record.fromVariantMap(map);
        }
        return record;
    }
    // 条件查询（增强版）
    QList<ParkPoliceRecord> findByCondition(
        const QString& keyword = QString(),
        const QDate& startDate = QDate(),
        const QDate& endDate = QDate())
    {
        QList<ParkPoliceRecord> records;
        QString sql = "SELECT * FROM " + tableName + " WHERE 1=1";
        QVariantMap params;

        // 关键字搜索（目标名称或警情类型）
        if (!keyword.isEmpty()) {
            sql += " AND (target_name LIKE :keyword OR police_type LIKE :keyword)";
            params[":keyword"] = "%" + keyword + "%";
        }

        // 时间范围查询（修改这里，不再使用date()函数）
        if (startDate.isValid()) {
            sql += " AND record_time >= :start_date";
            params[":start_date"] = startDate.toString("yyyy-MM-dd") + " 00:00:00";
        }
        if (endDate.isValid()) {
            sql += " AND record_time <= :end_date";
            params[":end_date"] = endDate.toString("yyyy-MM-dd") + " 23:59:59";
        }

        sql += " ORDER BY record_time DESC";
        dbHelper.open();
        QSqlQuery query(dbHelper.getDatabase());
        query.prepare(sql);

        // 绑定参数
        for (auto it = params.constBegin(); it != params.constEnd(); ++it) {
            query.bindValue(it.key(), it.value());
        }
        if (query.exec()) {
            while (query.next()) {
                ParkPoliceRecord record;
                QVariantMap map;
                QSqlRecord rec = query.record();
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }
                record.fromVariantMap(map);
                records.append(record);
            }
        }

        return records;
    }
};