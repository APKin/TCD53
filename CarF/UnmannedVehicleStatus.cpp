#include <cstdint>
#include <ctime>
#include <string>
#include <iomanip>
#include <sstream>
#include <cstring>
#include <QJsonObject>   // 替换为 Qt JSON 头文件
#include <QJsonDocument> // 可选：用于调试输出


class UnmannedVehicleStatus {
public:
    // 字段定义（驼峰形式）
    uint32_t timestamp;        // Unix时间戳(秒)
    uint8_t vehicleId;        // 车辆ID
    uint32_t utmEastingCm;   // UTM东向坐标(cm)
    uint32_t utmNorthingCm;  // UTM北向坐标(cm)
    int16_t headingAngle;     // 航向角(0.1°)
    uint16_t speed;            // 速度(0.1 m/s)
    uint8_t batteryLevel;     // 电量百分比(0-100)
    int16_t horizontalInclination; // 水平倾角(0.1°)
    uint8_t vehicleState;     // 车辆状态

    // 构造函数
    UnmannedVehicleStatus() = default;

    // 跨平台安全的获取格式化时间字符串
    std::string getFormattedTime() const {
        std::time_t raw_time = static_cast<std::time_t>(timestamp);
        struct std::tm time_info;

        // 更简单的跨平台时间转换
#ifdef _WIN32
        localtime_s(&time_info, &raw_time);
#else
        localtime_r(&raw_time, &time_info);
#endif

        std::ostringstream oss;
        oss << std::put_time(&time_info, "%Y-%m-%d %H:%M:%S");
        return oss.str();
    }

    // 实用方法：获取实际航向角(度)
    double getActualHeading() const {
        return static_cast<double>(headingAngle) / 10.0;
    }

    // 实用方法：获取实际速度(m/s)
    double getActualSpeed() const {
        return static_cast<double>(speed) / 10.0;
    }

    // 实用方法：获取实际水平倾角(度)
    double getActualInclination() const {
        return static_cast<double>(horizontalInclination) / 10.0;
    }

    // 实用方法：获取UTM东向坐标(米)
    double getUtmEastingM() const {
        return static_cast<double>(utmEastingCm) / 100.0;
    }

    // 实用方法：获取UTM北向坐标(米)
    double getUtmNorthingM() const {
        return static_cast<double>(utmNorthingCm) / 100.0;
    }
    // 序列化为二进制数据 (21字节) 到 QByteArray
    void serialize(QByteArray& buffer) const {
        // 确保有足够空间
        if (buffer.size() < static_cast<int>(size())) {
            buffer.resize(size());
        }

        uint8_t* data = reinterpret_cast<uint8_t*>(buffer.data());
        size_t offset = 0;
        std::memcpy(data + offset, &timestamp, sizeof(timestamp));
        offset += sizeof(timestamp);

        std::memcpy(data + offset, &vehicleId, sizeof(vehicleId));
        offset += sizeof(vehicleId);

        std::memcpy(data + offset, &utmEastingCm, sizeof(utmEastingCm));
        offset += sizeof(utmEastingCm);

        std::memcpy(data + offset, &utmNorthingCm, sizeof(utmNorthingCm));
        offset += sizeof(utmNorthingCm);

        std::memcpy(data + offset, &headingAngle, sizeof(headingAngle));
        offset += sizeof(headingAngle);

        std::memcpy(data + offset, &speed, sizeof(speed));
        offset += sizeof(speed);

        std::memcpy(data + offset, &batteryLevel, sizeof(batteryLevel));
        offset += sizeof(batteryLevel);

        std::memcpy(data + offset, &horizontalInclination, sizeof(horizontalInclination));
        offset += sizeof(horizontalInclination);

        std::memcpy(data + offset, &vehicleState, sizeof(vehicleState));
    }

    // 从 QByteArray 反序列化
    void deserialize(const QByteArray& buffer) {
        if (buffer.size() < static_cast<int>(size())) {
            return; // 数据不足
        }

        const uint8_t* data = reinterpret_cast<const uint8_t*>(buffer.constData());
        size_t offset = 0;
        std::memcpy(&timestamp, data + offset, sizeof(timestamp));
        offset += sizeof(timestamp);

        std::memcpy(&vehicleId, data + offset, sizeof(vehicleId));
        offset += sizeof(vehicleId);

        std::memcpy(&utmEastingCm, data + offset, sizeof(utmEastingCm));
        offset += sizeof(utmEastingCm);

        std::memcpy(&utmNorthingCm, data + offset, sizeof(utmNorthingCm));
        offset += sizeof(utmNorthingCm);

        std::memcpy(&headingAngle, data + offset, sizeof(headingAngle));
        offset += sizeof(headingAngle);

        std::memcpy(&speed, data + offset, sizeof(speed));
        offset += sizeof(speed);

        std::memcpy(&batteryLevel, data + offset, sizeof(batteryLevel));
        offset += sizeof(batteryLevel);

        std::memcpy(&horizontalInclination, data + offset, sizeof(horizontalInclination));
        offset += sizeof(horizontalInclination);

        std::memcpy(&vehicleState, data + offset, sizeof(vehicleState));
    }

    // 静态方法：从二进制帧数据解析对象 (使用 QByteArray 接口)
    static bool fromFrame(const QByteArray& frameData, UnmannedVehicleStatus& outStatus) {
        const size_t frameLength = frameData.size();
        const uint8_t* data = reinterpret_cast<const uint8_t*>(frameData.constData());

        // 检查最小帧长度
        constexpr size_t MIN_FRAME_SIZE = 2 + 1 + 1 + 1 + 2; // SOF+MsgType+Length+CRC+EOF
        if (frameLength < MIN_FRAME_SIZE) {
            return false;
        }

        // 检查SOF (Start of Frame)
        if (data[0] != 0xAA || data[1] != 0x55) {
            return false;
        }

        // 检查MsgType是否为状态信息 (0x01)
        const uint8_t msgType = data[2];
        if (msgType != 0x01) {
            return false;
        }

        // 获取Payload长度
        const uint8_t payloadLength = data[3];
        constexpr size_t EXPECTED_PAYLOAD_SIZE = 21; // 状态信息大小
        if (payloadLength != EXPECTED_PAYLOAD_SIZE) {
            return false;
        }

        // 检查总帧长度
        const size_t expectedFrameSize = 2 + 1 + 1 + payloadLength + 1 + 2; // SOF+MsgType+Length+Payload+CRC+EOF
        if (frameLength < expectedFrameSize) {
            return false;
        }

        // 计算并验证CRC
        uint8_t calculatedCrc = 0;
        // 计算MsgType + Length + Payload的XOR
        for (size_t i = 2; i < 4 + payloadLength; i++) {
            calculatedCrc ^= data[i];
        }

        const uint8_t receivedCrc = data[4 + payloadLength];
        if (calculatedCrc != receivedCrc) {
            return false;
        }

        // 检查EOF (End of Frame)
        const size_t eofPos = 4 + payloadLength + 1;
        if (data[eofPos] != 0x0D || data[eofPos + 1] != 0x0A) {
            return false;
        }

        // 提取Payload部分并反序列化
        QByteArray payload = frameData.mid(4, payloadLength);
        outStatus.deserialize(payload);
        return true;
    }
    // 检查结构体大小
    static constexpr size_t size() {
        return sizeof(timestamp) +
            sizeof(vehicleId) +
            sizeof(utmEastingCm) +
            sizeof(utmNorthingCm) +
            sizeof(headingAngle) +
            sizeof(speed) +
            sizeof(batteryLevel) +
            sizeof(horizontalInclination) +
            sizeof(vehicleState);
    }

    // 将对象转为 QJsonObject
    QJsonObject toJsonObject() const {
        QJsonObject json;
        json["timestamp"] = static_cast<qint64>(timestamp);
        json["vehicleId"] = vehicleId;
        json["utmEastingCm"] = static_cast<qint64>(utmEastingCm);
        json["utmNorthingCm"] = static_cast<qint64>(utmNorthingCm);
        json["headingAngle"] = headingAngle;
        json["speed"] = speed;
        json["batteryLevel"] = batteryLevel;
        json["horizontalInclination"] = horizontalInclination;
        json["vehicleState"] = vehicleState;
        return json;
    }
    // 创建外层包装的 QJsonObject
    QJsonObject toWrappedJsonObject() const {
        QJsonObject wrapper;
        wrapper["type"] = "status";  // 固定值

        // 将内层对象转为 JSON 字符串
        QJsonObject inner = toJsonObject();
        QJsonDocument doc(inner);
        QString contentStr = doc.toJson(QJsonDocument::Compact);

        wrapper["content"] = contentStr;
        return wrapper;
    }

    // 可选：保留字符串输出功能（如果需要）
    std::string toJsonString() const {
        QJsonObject json = toJsonObject();
        QJsonDocument doc(json);
        return doc.toJson(QJsonDocument::Indented).toStdString();
    }
};

// 确保结构体大小不变
static_assert(UnmannedVehicleStatus::size() == 21,
    "UnmannedVehicleStatus size must be 21 bytes");