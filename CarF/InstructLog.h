#pragma once
#include <QString>
#include <QDateTime>

class InstructLog
{
public:
    InstructLog() = default;

    // Getters
    qint64 getId() const { return id; }
    QString getType() const { return type; }
    QString getContent() const { return content; }
    QDateTime getCreateTime() const { return createTime; }

    // Setters
    void setId(qint64 id) { this->id = id; }
    void setType(const QString& type) { this->type = type; }
    void setContent(const QString& content) { this->content = content; }
    void setCreateTime(const QDateTime& time) { this->createTime = time; }

private:
    qint64 id = 0;          // ID
    QString type;           // 指令类型
    QString content;        // 指令内容
    QDateTime createTime;   // 指令时间
};