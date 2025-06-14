#pragma once
#include <iostream>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QSqlRecord>     
#include <QtSql/QSqlError>
#include <vector>
#include <utility>
#include <QVariantMap>

class DBHelper
{
	QSqlDatabase db;
public:
	DBHelper() {
		db = QSqlDatabase::addDatabase("QSQLITE", "tower");
		db.setDatabaseName("sqlite3/tower.db");
	}
	bool open() {
		//如果db不为空并且已经打开，则直接返回true
		if (db.isValid() && db.isOpen()) {
			return true;
		}
		db.open();

	}
	QSqlDatabase getDatabase() { 
		// demo 
		if (db.isOpen())
		{
			return db;
		}
		else {
			db = QSqlDatabase::addDatabase("QSQLITE", "tower");
			db.setDatabaseName("sqlite3/tower.db");
			db.open();
		}
		return db; 
	}
	//插入数据，传入参数是表名，多个字段名，多个字段值,返回插入成功与否
	bool insertData(const QString& tableName, QVariantMap& fvMap)
	{
		this->open();
		// 处理字段名和值
		QStringList fields = fvMap.keys();
		QStringList values;
		for (const QVariant& value : fvMap.values()) {
			// 处理字符串转义（防止 SQL 注入）
			QString escapedValue = value.toString().replace("'", "''");
			values << "'" + escapedValue + "'";
		}

		// 构建 SQL 语句
		QString sql = QString("INSERT INTO %1 (%2) VALUES (%3)")
			.arg(tableName)
			.arg(fields.join(", "))
			.arg(values.join(", "));

		QSqlQuery query(db);
		bool success = query.exec(sql);
		return success;
	}
	//根据id更新数据
	bool updateDataById(const QString& tableName, const QString& fieldName, const QString& fieldValue, const QString& id)
	{
		this->open();
		QSqlQuery query(db);
		QString sql = QString("UPDATE %1 SET %2='%3' WHERE id=%4").arg(tableName).arg(fieldName).arg(fieldValue).arg(id);
		bool success = query.exec(sql);
		return success;
	}
	//根据表名，查询并返回最大id
	QString getMaxId(const QString& tableName)
	{
		this->open();
		QSqlQuery query(db);
		QString sql = QString("SELECT MAX(id) FROM %1").arg(tableName);
		query.exec(sql);
		query.next();
		QString maxId = query.value(0).toString();
		return maxId;
	}
	//根据表名，查询并返回id最大的一条数据
	QVariantMap getMaxIdData(const QString& tableName)
	{
		this->open();
		QSqlQuery query(db);
		QString sql = QString("SELECT * FROM %1 WHERE id=(SELECT MAX(id) FROM %1)").arg(tableName);
		bool success = query.exec(sql);
		if (!success)
		{
			return QVariantMap();
		}
		QVariantMap map;
		while (query.next())
		{
			for (int i = 0; i < query.record().count(); i++)
			{
				map[query.record().fieldName(i)] = query.value(i);
			}
		}
		return map;
	}


	//单字段 插入数据，传入参数是表名，字段名，字段值
	bool insertData(const QString& tableName, const QString& fieldName, const QString& fieldValue)
	{
		this->open();
		QSqlQuery query(db);
		QString sql = QString("INSERT INTO %1 (%2) VALUES ('%3')").arg(tableName).arg(fieldName).arg(fieldValue);
		bool success = query.exec(sql);
		return success;
	}
	// 单字段 更新数据，参数为表名、字段名、新字段值、WHERE条件
	bool updateData(const QString& tableName, const QString& fieldName, const QString& fieldValue, const QString& whereCondition)
	{
		this->open();
		QSqlQuery query(db);
		// 使用参数化构造 SQL，注意 WHERE 条件防止全表更新
		QString sql = QString("UPDATE %1 SET %2 = '%3' WHERE %4")
			.arg(tableName)
			.arg(fieldName)
			.arg(fieldValue)
			.arg(whereCondition); // 必须提供条件，例如 "id=1"
		bool success = query.exec(sql);
		return success;
	}
	//更表内id最大的一条数据
	bool updateMaxIdData(const QString& tableName, QVariantMap& fvMap)
	{
		QString maxId = getMaxId(tableName);
		QSqlQuery query(db);
		// 处理字段名和值
		QStringList fields = fvMap.keys();
		QStringList updateFields;
		for (const QString field : fields) {
			// 处理字符串转义（防止 SQL 注入）
			QString updateField = QString("%1='%2'").arg(field).arg(fvMap[field].toString());
			updateFields << updateField;
		}
		QString updateSql = QString("update %1 set %2 where id=%3").arg(tableName).arg(updateFields.join(",")).arg(maxId);
		return query.exec(updateSql);
	}
};
