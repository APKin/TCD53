#include "LaserComand.h"
#include <QDataStream>

uint32_t LaserComand::calculateCRC(const QByteArray& data)
{
	int len = data.length();
	uint8_t* data_ = (uint8_t*)data.data();

    uint32_t sum = 0;  // 使用32位防止溢出

    for (size_t i = 0; i < len; ++i) {
        sum += data_[i];
    }
    // 取后8
    return static_cast<uint8_t>(sum & 0xFF);
	
}

QByteArray LaserComand::lightOutLar()
{
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x00) << qint8(0x00) << qint8(0x01) << qint8(0x00) << qint8(0x01) << qint8(0x00);
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    return byteArray;
}

QByteArray LaserComand::lightCloseLar()
{
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x00) << qint8(0x00) << qint8(0x00) << qint8(0x00) << qint8(0x01) << qint8(0x00);
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    return byteArray;
}

QByteArray LaserComand::longBauOutLar()
{
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D)<< qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x03) << qint8(0x00) << qint8(0x01) << qint8(0x00) << qint8(0x01) << qint8(0x00);
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    return byteArray;
}

QByteArray LaserComand::longBauCloseLar()
{
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x03) << qint8(0x00) << qint8(0x00) << qint8(0x00) << qint8(0x01) << qint8(0x00);
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    return byteArray;
}

QByteArray LaserComand::changeDW(int index)
{
    short DW = quint8(index);
    
    if (index <= 10 &&index >0 )
    {
        DW = quint8(index);//01
    }else 
    {
        return QByteArray();
    }
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x10) << qint8(0x10) << qint8(0x01) << qint8(0x00) << DW;
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    char* mData = byteArray.data();
    return byteArray;
}

QByteArray LaserComand::mradSet(int mradIndex)
{
    short mradIndex_;
    if (mradIndex == 0)
    {
        mradIndex_ = 0;
    }
    else
    {
        mradIndex_ = 1;
    }
     

    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << 0x7E << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x10) << qint8(0x10) << qint8(0x01) << qint8(0x00) <<  mradIndex_;
    stream << calculateCRC(byteArray);
    stream << 0xE7;

    return byteArray;
    
}

QByteArray LaserComand::longBauPowerRate(short rate)
{

    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0x7E) << qint8(0x0D) << qint8(0x00) << qint8(0x01) << qint8(0x82) << qint8(0x74) << qint8(0x10) << qint8(0x01) << qint8(0x00) << rate;
    stream << calculateCRC(byteArray);
    stream << qint8(0xE7);

    return byteArray;
}

QByteArray LaserComand::blueOutLar()
{

    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0xFE) << qint8(0x68) << qint8(0x01) << qint8(0x07) << qint8(0x02) << qint8(0x01) << qint8(0x00) << qint8(0x71);

    return byteArray;
}

QByteArray LaserComand::blueCloseLar()
{
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);
    stream << qint8(0xFE) << qint8(0x68) << qint8(0x01) << qint8(0x07) << qint8(0x02) << qint8(0x00) << qint8(0x00) << qint8(0x70);

    return byteArray;
}

QByteArray LaserComand::blueDW(short DW)
{
    // 换挡
    DW *= 50;
    QByteArray  byteArray;
    QDataStream stream(&byteArray, QIODevice::WriteOnly);
    stream.setByteOrder(QDataStream::LittleEndian);


    //stream << qint8(0xFE) << qint8(0x68) << qint8((0x01) << qint8(0x07) << qint8(0x02) << DW ;
    stream << qint8(0xFE) << qint8(0x68) << qint8(0x01) << qint8(0x07) << qint8(0x02) << DW;
    stream << calculateCRC(byteArray);

    char* barrr = byteArray.data();
    return byteArray;
}
