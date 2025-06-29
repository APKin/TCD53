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

    // 序列化为二进制数据 (21字节)
    void serialize(uint8_t* buffer) const {
        size_t offset = 0;
        std::memcpy(buffer + offset, &timestamp, sizeof(timestamp));
        offset += sizeof(timestamp);

        std::memcpy(buffer + offset, &vehicleId, sizeof(vehicleId));
        offset += sizeof(vehicleId);

        std::memcpy(buffer + offset, &utmEastingCm, sizeof(utmEastingCm));
        offset += sizeof(utmEastingCm);

        std::memcpy(buffer + offset, &utmNorthingCm, sizeof(utmNorthingCm));
        offset += sizeof(utmNorthingCm);

        std::memcpy(buffer + offset, &headingAngle, sizeof(headingAngle));
        offset += sizeof(headingAngle);

        std::memcpy(buffer + offset, &speed, sizeof(speed));
        offset += sizeof(speed);

        std::memcpy(buffer + offset, &batteryLevel, sizeof(batteryLevel));
        offset += sizeof(batteryLevel);

        std::memcpy(buffer + offset, &horizontalInclination, sizeof(horizontalInclination));
        offset += sizeof(horizontalInclination);

        std::memcpy(buffer + offset, &vehicleState, sizeof(vehicleState));
    }

    // 从二进制数据反序列化
    void deserialize(const uint8_t* buffer) {
        size_t offset = 0;
        std::memcpy(&timestamp, buffer + offset, sizeof(timestamp));
        offset += sizeof(timestamp);

        std::memcpy(&vehicleId, buffer + offset, sizeof(vehicleId));
        offset += sizeof(vehicleId);

        std::memcpy(&utmEastingCm, buffer + offset, sizeof(utmEastingCm));
        offset += sizeof(utmEastingCm);

        std::memcpy(&utmNorthingCm, buffer + offset, sizeof(utmNorthingCm));
        offset += sizeof(utmNorthingCm);

        std::memcpy(&headingAngle, buffer + offset, sizeof(headingAngle));
        offset += sizeof(headingAngle);

        std::memcpy(&speed, buffer + offset, sizeof(speed));
        offset += sizeof(speed);

        std::memcpy(&batteryLevel, buffer + offset, sizeof(batteryLevel));
        offset += sizeof(batteryLevel);

        std::memcpy(&horizontalInclination, buffer + offset, sizeof(horizontalInclination));
        offset += sizeof(horizontalInclination);

        std::memcpy(&vehicleState, buffer + offset, sizeof(vehicleState));
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