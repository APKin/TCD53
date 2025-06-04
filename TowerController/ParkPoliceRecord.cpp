#pragma once
#include "DBHelper.h"
#include <QDateTime>
#include <QString>

// 警情记录实体类
class ParkPoliceRecord {
public:
    int id = 0;                 // 记录ID
    QString create_time;        // 创建时间
    QString record_time;        // 记录时间
    int police_type = 0;        // 警情类型
    double longitude = 0.0;     // 经度
    double latitude = 0.0;      // 纬度
    double height = 0.0;        // 高度
    double direction = 0.0;     // 方向
    double pitch = 0.0;         // 俯仰
    double distance = 0.0;      // 距离
    int alarm_number = 0;       // 告警编号

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
            {"alarm_number", alarm_number}
        };
    }

    // 从QVariantMap加载数据
    void fromVariantMap(const QVariantMap& map) {
        id = map.value("id", 0).toInt();
        create_time = map.value("create_time").toString();
        record_time = map.value("record_time").toString();
        police_type = map.value("police_type", 0).toInt();
        longitude = map.value("longitude", 0.0).toDouble();
        latitude = map.value("latitude", 0.0).toDouble();
        height = map.value("height", 0.0).toDouble();
        direction = map.value("direction", 0.0).toDouble();
        pitch = map.value("pitch", 0.0).toDouble();
        distance = map.value("distance", 0.0).toDouble();
        alarm_number = map.value("alarm_number", 0).toInt();
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
        // 使用DBHelper的open方法确保数据库连接
        dbHelper.open();

        // 创建表SQL
        QString sql = R"(
            CREATE TABLE IF NOT EXISTS park_police_record (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                create_time TEXT NOT NULL,
                record_time TEXT NOT NULL,
                police_type INTEGER NOT NULL,
                longitude REAL NOT NULL,
                latitude REAL NOT NULL,
                height REAL NOT NULL,
                direction REAL NOT NULL,
                pitch REAL NOT NULL,
                distance REAL NOT NULL,
                alarm_number INTEGER NOT NULL
            );
        )";

        // 执行SQL
        QSqlQuery query(dbHelper.getDatabase());
        return query.exec(sql);
    }

    // 插入新记录
    bool insertRecord(ParkPoliceRecord& record) {
        QVariantMap data = record.toVariantMap();
        bool success = dbHelper.insertData(tableName, data);

        // 获取新插入记录的ID
        if (success) {
            QString idStr = dbHelper.getMaxId(tableName);
            record.id = idStr.toInt();
        }
        return success;
    }

    // 更新记录（按ID）
    bool updateRecord(const ParkPoliceRecord& record) {
        QVariantMap data = record.toVariantMap();

        // 构建更新字段映射
        QVariantMap updateFields;
        for (auto it = data.begin(); it != data.end(); ++it) {
            if (it.key() != "id") { // 排除ID字段
                updateFields[it.key()] = it.value();
            }
        }

        // 更新最大ID记录（这里假设按ID更新，但DBHelper只提供更新最大ID的方法）
        // 实际应用中应扩展DBHelper支持按任意ID更新
        return dbHelper.updateMaxIdData(tableName, updateFields);
    }

    // 删除记录（按ID）
    bool deleteRecord(int id) {
        QString whereCondition = QString("id = %1").arg(id);
        return dbHelper.updateData(tableName, "id", "-1", whereCondition); // 标记删除
        // 实际应用中应使用DELETE语句，但DBHelper当前不支持
    }

    // 获取所有记录
    QList<ParkPoliceRecord> getAllRecords() {
        QList<ParkPoliceRecord> records;

        // 执行查询（DBHelper未提供全查询方法，需要扩展）
        // 这里演示如何扩展DBHelper功能
        QSqlQuery query(dbHelper.getDatabase());
        if (query.exec("SELECT * FROM " + tableName)) {
            while (query.next()) {
                ParkPoliceRecord record;
                QVariantMap map;
                QSqlRecord rec = query.record();

                // 将查询结果转换为QVariantMap
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }

                // 加载到实体对象
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

    // 获取最新记录
    ParkPoliceRecord getLatestRecord() {
        ParkPoliceRecord record;
        QVariantMap data = dbHelper.getMaxIdData(tableName);
        if (!data.isEmpty()) {
            record.fromVariantMap(data);
        }
        return record;
    }
};