#include "CarStatus.h"
#include <QBuffer>
#include <QDebug>
CarStatus::CarStatus()
{
}

CarStatus::~CarStatus()
{
}

GETValue CarStatus::parseXmlWithStream_GET(QByteArray& getInfo)
{
    QBuffer buffer;
    buffer.setData(getInfo);

    if (!buffer.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open buffer for reading";
        return GETValue();
    }

    // 创建XML流读取器
    QXmlStreamReader xml(&buffer);

    // 解析XML数据
    //while (!xml.atEnd()) {
    //    xml.readNext();

    //    if (xml.isStartElement()) {
    //        QString currentElement = xml.name().toString();
    //        QString currentText;
    //        // 处理根元素
    //        if (currentElement == "Message") {
    //            qDebug() << "Found library element";
    //        }
    //        // 处理元素
    //        else if (currentElement == "book") {
    //            //bookData.clear();
    //            //bookData["id"] = xml.attributes().value("id").toString();
    //            qDebug() << "Book ID:" << xml.attributes().value("id").toString();
    //        }
    //        // 处理book的子元素
    //        //else if (!bookData.isEmpty()) {
    //        //    currentText.clear();
    //        //}
    //    }
    //    // 处理元素文本内容
    //    else if (xml.isCharacters() && !xml.isWhitespace() && !bookData.isEmpty()) {
    //        currentText += xml.text();
    //    }
    //    // 处理结束元素
    //    else if (xml.isEndElement()) {
    //        QString elementName = xml.name().toString();

    //        if (elementName == "book") {
    //            qDebug() << "Book data:" << bookData;
    //        /*    emit bookParsed(bookData);*/
    //            bookData.clear();
    //        }
    //        else if (bookData.contains(elementName)) {
    //            bookData[elementName] = currentText.trimmed();
    //        }
    //    }
    //}

    // 检查错误
    if (xml.hasError()) {
        qWarning() << "XML parsing error:" << xml.errorString();
    }

    buffer.close();

    
	return GETValue();
}

SETValue CarStatus::parseXmlWithStream_SET(QByteArray& setInfo)
{
	return SETValue();
}
