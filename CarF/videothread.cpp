#include "videothread.h"

VideoThread::VideoThread(QObject *parent) : QObject(parent)
{
    m_sock = new QUdpSocket(this);
    m_ffmpeg_decoder = new FFmpeg_Decode();
}

void VideoThread::setVideoID(int id)
{
    m_id = id;
    QSettings * pIni = new QSettings(INI_PATH, QSettings::IniFormat);//初始化读取Ini文件对象
    m_width = pIni->value("DECODER/width").toInt();
    m_height = pIni->value("DECODER/height").toInt();

    // 初始化FFMPEG(h264:0, h265:1)
    int ret = m_ffmpeg_decoder->FFmpeg_H264DecoderInit(0);
    if(ret < 0)
    {
        qDebug() << "ffmpeg init failed!...  ret: " << ret;
        return;
    }

    // 初始化UDP网络
    switch (id) {
        case 0:m_port = pIni->value("NETWORK/port_0").toInt();break;
        case 1:m_port = pIni->value("NETWORK/port_1").toInt();break;
        case 2:m_port = pIni->value("NETWORK/port_2").toInt();break;
        case 3:m_port = pIni->value("NETWORK/port_3").toInt();break;
        case 4:m_port = pIni->value("NETWORK/port_4").toInt();break;

        default:break;
    }

    m_ip = pIni->value("NETWORK/ip").toString();
    m_groupIp = pIni->value("NETWORK/groupIP").toString();

    // 枚举所有可用网卡，筛选出支持组播且活跃的网卡
    QList<QNetworkInterface> interfaces = QNetworkInterface::allInterfaces();
    QNetworkInterface targetInterface;
    foreach (const QNetworkInterface& iface, interfaces) {
        // 检查网卡是否活跃且支持组播
        if (!(iface.flags() & QNetworkInterface::IsUp) ||
            !(iface.flags() & QNetworkInterface::IsRunning) ||
            !(iface.flags() & QNetworkInterface::CanMulticast)) {
            continue;
        }

        // 根据IP地址段筛选
        QList<QNetworkAddressEntry> entries = iface.addressEntries();
        foreach (const QNetworkAddressEntry& entry, entries) {
            if (entry.ip().protocol() == QAbstractSocket::IPv4Protocol &&
                entry.ip().toString().startsWith(m_ip)) {
                targetInterface = iface;
                break;
            }
        }
        if (targetInterface.isValid()) break;
    }

    if (!targetInterface.isValid()) {
        qDebug() << "netip=" << targetInterface.name() ;
        qDebug() << "未找到可用的组播网卡";
        return;
    }

    //windows上必须绑定AnyIPv4不然就会绑定失败,linux可以绑定具体的组播ip
    bool isOK = m_sock->bind(QHostAddress::AnyIPv4, m_port, QUdpSocket::ShareAddress);
    qDebug() << m_sock->localAddress();
    if(!isOK)
    {
        qDebug() << QString("udp socket bind failed!...  ip: %1, port: %2").arg(m_ip).arg(m_port);
        return;
    }

    isOK = m_sock->joinMulticastGroup(QHostAddress(m_groupIp), targetInterface);
    if(isOK == false){
        qDebug()<<QString("组播jion失败%1").arg(m_ip)
                << m_sock->localAddress()<< m_sock->localPort();
        return;
    }

    connect(m_sock,&QUdpSocket::readyRead,this,[this]()
    {
        //qDebug() << "id: " << m_id << " widget thread id: " << QThread::currentThreadId();
        int arr_size = m_sock->pendingDatagramSize();
        QByteArray arr(arr_size,0);
        m_sock->readDatagram(arr.data(),arr.size());
        //qDebug() << "arr.count: " << arr.count();

        int frmPara[5];
        unsigned char* rgbBuf = new unsigned char[m_width * m_height * 3];

        int ret = m_ffmpeg_decoder->FFmpeg_H264Decode((unsigned char *)arr.data(), arr.size(), frmPara, rgbBuf);
        if(ret > 0)
        {
            emit signal_RGBBuf(rgbBuf);
        }
        else
        {
            //qDebug() << "FFmpeg_H264Decode  ret: " << ret;
        }
    });

}
