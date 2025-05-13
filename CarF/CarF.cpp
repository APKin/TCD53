#include "CarF.h"
#include "DBHelper.h"
//#include "sqlite3.h"
#include <QMessageBox>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QDebug>

// 定义并初始化静态变量
QString CarF::imageSavePath = NULL;
DBHelper* db = new DBHelper();
CarF::CarF(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    // 获取图片保存路径
    imageSavePath = getImagePath();
    //QString filename = "imageSavePath.bin";
    //QString content = readFileIfExists(filename);
    //db = new DBHelper();
    //if (!content.isEmpty()) {
    //    imageSavePath = content;
    //}
    //else {
    //    //初始化配置路径
    //    imageSavePath = QCoreApplication::applicationDirPath();
    //    saveStringToFile(imageSavePath, "imageSavePath.bin");


    //}
}

CarF::~CarF()
{
    
}

// 在源文件（.cpp）中实现：
void CarF::on_pushButton_clicked()
{
    SystemSetting *secondWin = new SystemSetting(this);
    if (secondWin->exec() == QDialog::Accepted) { // 模态显示对话框
        imageSavePath= secondWin->getResult(); // 获取输入的文本
        //更新入库
        QString maxId=db->getMaxId("img_path");
        db->updateData("img_path", "url", imageSavePath, maxId);
        //saveStringToFile(imageSavePath, "imageSavePath.bin");  // 自动创建 subdir 目录和 example.txt 文件
    }
    else {
        QMessageBox::information(nullptr, "取消操作", "您取消了输入。");
    }
}
/*
* 查询img_path表最后一条数据，如果没有则创建一条默认数据并写入数据库，返回该数据
*/
QString CarF::getImagePath()
{
    QString lastImagePath= "D:/CarF/image/";
    QVariantMap maxIdData = db->getMaxIdData("img_path");
    if (maxIdData.isEmpty()) {
        QVariantMap map;
        map["url"]= lastImagePath;
        db->insertData("img_path", map);
    }
    else {
        QString lastImagePath = maxIdData["url"].toString();
    }
    return lastImagePath;
}
/*
* 保存图像存储路径
*/
void CarF::saveStringToFile(const QString& text, const QString& filename) {
    // 1. 提取文件路径的目录部分
    QFileInfo fileInfo(filename);
    QDir dir;

    // 2. 如果目录不存在，递归创建所有缺失的目录
    if (!dir.mkpath(fileInfo.absolutePath())) {
        qDebug() << "无法创建目录:" << fileInfo.absolutePath();
        return;
    }

    // 3. 打开文件并写入内容
    QFile file(filename);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qDebug() << "无法创建或写入文件:" << file.errorString();
        return;
    }

    QTextStream stream(&file);
    //stream.setEncoding(QStringConverter::Utf8);  // 可选：设置编码为 UTF-8
    stream << text;  // 写入字符串

    // 文件会在 QFile 对象销毁时自动关闭

    // 3. 插入数据
    //db->insertData("img_path", "url", imageSavePath);

}

/*
* 读取文件存储路径配置
*/
QString CarF::readFileIfExists(const QString& filename) {
    // 1. 检查文件是否存在
    QFileInfo fileInfo(filename);
    if (!fileInfo.exists() || !fileInfo.isFile()) {
        qDebug() << "文件不存在或不是普通文件:" << filename;
        return QString();
    }

    // 2. 打开文件
    QFile file(filename);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "无法打开文件:" << file.errorString();
        return QString();
    }

    // 3. 读取内容
    QTextStream stream(&file);
   // stream.setEncoding(QStringConverter::Utf8);  // 设置编码（需与写入时一致）
    QString content = stream.readAll();

    file.close();
    return content;
}
/*
* 无人车控制 自动前进
*/
void CarF::on_btnAutoDisplay_clicked() {
    //对接设备后，此处改为向第三方发送控制指令
    QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("控制无人车前进"));
}
/*
* 无人车控制 停止
*/
void CarF::on_btnStop_clicked() {
    //对接设备后，此处改为向第三方发送控制指令
    QMessageBox::information(this,
        QString::fromUtf8("提示"),
        QString::fromUtf8("停止"));
}