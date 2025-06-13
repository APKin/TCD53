#pragma once
#include "DBHelper.h"
#include <QDateTime>
#include <QString>

// 图片文件实体类
class ImgFile {
public:
    qint64 id = 0;              // 图片ID
    QString path;               // 图片路径
    QString number;             // 图片编号
    QString create_time;        // 创建时间
    QString record_id;          // 关联警情ID

    // 转换为QVariantMap用于数据库操作
    QVariantMap toVariantMap() const {
        return {
            {"path", path},
            {"number", number},
            {"create_time", create_time},
            {"record_id", record_id}
        };
    }

    // 从QVariantMap加载数据
    void fromVariantMap(const QVariantMap& map) {
        id = map.value("id", 0).toLongLong();
        path = map.value("path").toString();
        number = map.value("number").toString();
        create_time = map.value("create_time").toString();
        record_id = map.value("record_id").toString();
    }
};

// 图片文件数据访问层
class ImgFileDAL {
private:
    DBHelper dbHelper;
    const QString tableName = "img_file";

public:
    // 创建表（如果不存在）
    bool createTable() {

        QString sql = R"(
            CREATE TABLE IF NOT EXISTS img_file (
                id INTEGER PRIMARY KEY AUTOINCREMENT,
                path TEXT NOT NULL,
                number TEXT NOT NULL,
                create_time TEXT NOT NULL,
                record_id TEXT NOT NULL
            );
        )";

        QSqlQuery query(dbHelper.getDatabase());
        return query.exec(sql);
    }

    // 插入新图片
    bool insert(ImgFile& imgFile) {
        if (imgFile.create_time.isEmpty()) {
            imgFile.create_time = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss");
        }

        QVariantMap data = imgFile.toVariantMap();
        bool success = dbHelper.insertData(tableName, data);

        if (success) {
            QString idStr = dbHelper.getMaxId(tableName);
            imgFile.id = idStr.toLongLong();
        }
        return success;
    }

    // 更新图片信息
    bool update(const ImgFile& imgFile) {
        if (imgFile.id <= 0) return false;

        QVariantMap data = imgFile.toVariantMap();
        QString whereCondition = QString("id = %1").arg(imgFile.id);

        foreach(const QString & field, data.keys()) {
            if (field != "id") {
                if (!dbHelper.updateData(tableName, field, data[field].toString(), whereCondition)) {
                    return false;
                }
            }
        }
        return true;
    }

    // 删除图片
    bool remove(qint64 id) {
        QString whereCondition = QString("id = %1").arg(id);
        QSqlQuery query(dbHelper.getDatabase());
        return query.exec(QString("DELETE FROM %1 WHERE %2").arg(tableName).arg(whereCondition));
    }

    // 获取所有图片
    QList<ImgFile> getAll() {
        QList<ImgFile> images;
        QSqlQuery query(dbHelper.getDatabase());

        if (query.exec("SELECT * FROM " + tableName)) {
            while (query.next()) {
                ImgFile img;
                QVariantMap map;
                QSqlRecord rec = query.record();
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }
                img.fromVariantMap(map);
                images.append(img);
            }
        }
        return images;
    }

    // 按ID获取图片
    ImgFile getById(qint64 id) {
        ImgFile img;
        QSqlQuery query(dbHelper.getDatabase());

        query.prepare("SELECT * FROM " + tableName + " WHERE id = :id");
        query.bindValue(":id", id);

        if (query.exec() && query.next()) {
            QVariantMap map;
            QSqlRecord rec = query.record();
            for (int i = 0; i < rec.count(); i++) {
                map[rec.fieldName(i)] = query.value(i);
            }
            img.fromVariantMap(map);
        }
        return img;
    }

    // 根据警情ID获取图片列表
    QList<ImgFile> getByRecordId(const QString& recordId) {
        QList<ImgFile> images;
        QSqlQuery query(dbHelper.getDatabase());

        query.prepare("SELECT * FROM " + tableName + " WHERE record_id = :record_id");
        query.bindValue(":record_id", recordId);

        if (query.exec()) {
            while (query.next()) {
                ImgFile img;
                QVariantMap map;
                QSqlRecord rec = query.record();
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }
                img.fromVariantMap(map);
                images.append(img);
            }
        }
        return images;
    }

    // 根据多个警情ID获取图片列表
    QList<ImgFile> getByRecordIds(const QList<QString>& recordIds) {
        QList<ImgFile> images;
        if (recordIds.isEmpty()) return images;

        QString sql = "SELECT * FROM " + tableName + " WHERE record_id IN (";
        for (int i = 0; i < recordIds.size(); i++) {
            sql += i ? ", ?" : "?";
        }
        sql += ")";

        QSqlQuery query(dbHelper.getDatabase());
        query.prepare(sql);

        for (int i = 0; i < recordIds.size(); i++) {
            query.addBindValue(recordIds[i]);
        }

        if (query.exec()) {
            while (query.next()) {
                ImgFile img;
                QVariantMap map;
                QSqlRecord rec = query.record();
                for (int i = 0; i < rec.count(); i++) {
                    map[rec.fieldName(i)] = query.value(i);
                }
                img.fromVariantMap(map);
                images.append(img);
            }
        }
        return images;
    }

    // 获取最新图片
    ImgFile getLatest() {
        ImgFile img;
        QVariantMap data = dbHelper.getMaxIdData(tableName);
        if (!data.isEmpty()) {
            img.fromVariantMap(data);
        }
        return img;
    }
};