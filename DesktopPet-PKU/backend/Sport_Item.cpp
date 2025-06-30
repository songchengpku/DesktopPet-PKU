#include "backend/Sport_Item.h"

// 文件路径常量
const QString sports::SportRecord::DATA_FILE_PATH = "user_data/sportsData.json";

// 卡路里常量定义
const double sports::SportRecord::badminton_cal = 6.126;
const double sports::SportRecord::pingpong_cal = 4.9;
const double sports::SportRecord::tennis_cal = 9.8;
const double sports::SportRecord::basketball_cal = 7.35;
const double sports::SportRecord::volleyball_cal = 4.9;
const double sports::SportRecord::football_cal = 9.8;
const double sports::SportRecord::Running_cal = 12.25;
const double sports::SportRecord::Riding_cal = 9.8;
const double sports::SportRecord::climbing_cal = 9.8;
const double sports::SportRecord::swimming_cal = 8.6;

//构造函数/析构函数
sports::sports() : data(new sportsData) {}
sports::sports(const sports &rhs) : data{rhs.data} {}
sports::sports(sports &&rhs) : data{std::move(rhs.data)} {}
sports &sports::operator=(const sports &rhs) {
    if (this != &rhs) data = rhs.data;
    return *this;
}
sports &sports::operator=(sports &&rhs) {
    if (this != &rhs) data = std::move(rhs.data);
    return *this;
}
sports::~sports() {}


void sports::SportRecord::reset() {
    // 创建一个全新的基础JSON结构（所有值为0，数组为空）
    QJsonObject resetJson = createBaseJsonStructure();

    // 将重置后的JSON写入文件
    writeSportsJson(resetJson);
}

//JSON文件操作
QJsonObject sports::SportRecord::readSportsJson() const {
    QFile file(DATA_FILE_PATH);
    if (!file.exists() || file.size() == 0) {
        return createBaseJsonStructure();
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << "Failed to open sports data file";
        return createBaseJsonStructure();
    }

    QByteArray jsonData = file.readAll();
    file.close();

    if (jsonData.isEmpty()) {
        return createBaseJsonStructure();
    }

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);

    if (error.error != QJsonParseError::NoError) {
        qWarning() << "JSON parse error:" << error.errorString();
        return createBaseJsonStructure();
    }

    return doc.object();
}

void sports::SportRecord::writeSportsJson(const QJsonObject& json) const {
    // 确保目录存在
    QDir().mkpath(QFileInfo(DATA_FILE_PATH).absolutePath());

    QFile file(DATA_FILE_PATH);
    if (file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(json);
        file.write(doc.toJson(QJsonDocument::Indented));
        file.close();
    } else {
        qWarning() << "Failed to write sports data file";
    }
}

QJsonObject sports::SportRecord::createBaseJsonStructure() const {
    QJsonObject root;

    // 初始化时间数据
    QJsonObject timeData;
    timeData["badminton"] = 0;
    timeData["pingpong"] = 0;
    timeData["tennis"] = 0;
    timeData["basketball"] = 0;
    timeData["volleyball"] = 0;
    timeData["football"] = 0;
    timeData["running"] = 0;
    timeData["running_distance"] = 0;
    timeData["riding"] = 0;
    timeData["climbing"] = 0;
    timeData["swimming"] = 0;

    root["time_data"] = timeData;

    // 初始化周数据
    QJsonObject weeklyData;
    weeklyData["badminton"] = 0;
    weeklyData["pingpong"] = 0;
    weeklyData["tennis"] = 0;
    weeklyData["basketball"] = 0;
    weeklyData["volleyball"] = 0;
    weeklyData["football"] = 0;
    weeklyData["running"] = 0;
    weeklyData["running_distance"] = 0;
    weeklyData["riding"] = 0;
    weeklyData["climbing"] = 0;
    weeklyData["swimming"] = 0;

    weeklyData["badminton_calories"] = 0;
    weeklyData["pingpong_calories"] = 0;
    weeklyData["tennis_calories"] = 0;
    weeklyData["basketball_calories"] = 0;
    weeklyData["volleyball_calories"] = 0;
    weeklyData["football_calories"] = 0;
    weeklyData["running_calories"] = 0;
    weeklyData["riding_calories"] = 0;
    weeklyData["climbing_calories"] = 0;
    weeklyData["swimming_calories"] = 0;
    root["weekly_time_data"] = weeklyData;

    // 初始化记录数组
    root["badminton_records"] = QJsonArray();
    root["pingpong_records"] = QJsonArray();
    root["tennis_records"] = QJsonArray();
    root["basketball_records"] = QJsonArray();
    root["volleyball_records"] = QJsonArray();
    root["football_records"] = QJsonArray();
    root["running_records"] = QJsonArray();
    root["riding_records"] = QJsonArray();
    root["climbing_records"] = QJsonArray();
    root["swimming_records"] = QJsonArray();

    return root;
}

//JSON更新辅助函数
void sports::SportRecord::updateJsonField(
    QJsonObject& root,
    const QString& timeKey, double timeValue,
    const QString& weeklyKey, double weeklyValue,
    const QString& recordKey, const QJsonArray& records) const
{
    // 确保存在时间数据对象
    if (!root.contains("time_data") || !root["time_data"].isObject()) {
        root["time_data"] = QJsonObject();
    }

    // 确保存在周数据对象
    if (!root.contains("weekly_time_data") || !root["weekly_time_data"].isObject()) {
        root["weekly_time_data"] = QJsonObject();
    }

    // 更新时间数据
    QJsonObject timeData = root["time_data"].toObject();
    timeData[timeKey] = timeValue;
    root["time_data"] = timeData;

    // 更新周数据
    QJsonObject weeklyData = root["weekly_time_data"].toObject();
    weeklyData[weeklyKey] = weeklyValue;
    root["weekly_time_data"] = weeklyData;

    // 更新记录数组
    root[recordKey] = records;
}

// 羽毛球记录
void sports::SportRecord::addBadmintonRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["badminton_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * badminton_cal;
    double totalTime = timeData["badminton"].toDouble() + duration;
    double weeklyTime = weeklyData["badminton"].toDouble() + duration;
    double weeklyCalories = weeklyData["badminton_calories"].toDouble() + calories;

    timeData["badminton"] = totalTime;
    weeklyData["badminton"] = weeklyTime;
    weeklyData["badminton_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["badminton_records"] = records;
    writeSportsJson(root);
}

// 乒乓球记录
void sports::SportRecord::addPingpongRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["pingpong_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * pingpong_cal;
    double totalTime = timeData["pingpong"].toDouble() + duration;
    double weeklyTime = weeklyData["pingpong"].toDouble() + duration;
    double weeklyCalories = weeklyData["pingpong_calories"].toDouble() + calories;

    timeData["pingpong"] = totalTime;
    weeklyData["pingpong"] = weeklyTime;
    weeklyData["pingpong_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["pingpong_records"] = records;
    writeSportsJson(root);
}

// 网球记录
void sports::SportRecord::addTennisRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["tennis_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * tennis_cal;
    double totalTime = timeData["tennis"].toDouble() + duration;
    double weeklyTime = weeklyData["tennis"].toDouble() + duration;
    double weeklyCalories = weeklyData["tennis_calories"].toDouble() + calories;

    timeData["tennis"] = totalTime;
    weeklyData["tennis"] = weeklyTime;
    weeklyData["tennis_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["tennis_records"] = records;
    writeSportsJson(root);
}

// 篮球记录
void sports::SportRecord::addBasketballRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["basketball_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * basketball_cal;
    double totalTime = timeData["basketball"].toDouble() + duration;
    double weeklyTime = weeklyData["basketball"].toDouble() + duration;
    double weeklyCalories = weeklyData["basketball_calories"].toDouble() + calories;

    timeData["basketball"] = totalTime;
    weeklyData["basketball"] = weeklyTime;
    weeklyData["basketball_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["basketball_records"] = records;
    writeSportsJson(root);
}

// 排球记录
void sports::SportRecord::addVolleyballRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["volleyball_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * volleyball_cal;
    double totalTime = timeData["volleyball"].toDouble() + duration;
    double weeklyTime = weeklyData["volleyball"].toDouble() + duration;
    double weeklyCalories = weeklyData["volleyball_calories"].toDouble() + calories;

    timeData["volleyball"] = totalTime;
    weeklyData["volleyball"] = weeklyTime;
    weeklyData["volleyball_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["volleyball_records"] = records;
    writeSportsJson(root);
}

// 足球记录
void sports::SportRecord::addFootballRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["football_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * football_cal;
    double totalTime = timeData["football"].toDouble() + duration;
    double weeklyTime = weeklyData["football"].toDouble() + duration;
    double weeklyCalories = weeklyData["football_calories"].toDouble() + calories;

    timeData["football"] = totalTime;
    weeklyData["football"] = weeklyTime;
    weeklyData["football_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["football_records"] = records;
    writeSportsJson(root);
}

// 跑步记录
void sports::SportRecord::addRunningRecord(const QString& date, int duration, double distance) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["running_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * Running_cal;
    double totalTime = timeData["running"].toDouble() + duration;
    double totalDistance = timeData["running_distance"].toDouble() + distance;
    double weeklyTime = weeklyData["running"].toDouble() + duration;
    double weeklyDistance = weeklyData["running_distance"].toDouble() + distance;
    double weeklyCalories = weeklyData["running_calories"].toDouble() + calories;

    timeData["running"] = totalTime;
    timeData["running_distance"] = totalDistance;
    weeklyData["running"] = weeklyTime;
    weeklyData["running_distance"] = weeklyDistance;
    weeklyData["running_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["distance"] = distance;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["running_records"] = records;
    writeSportsJson(root);
}

// 骑行记录
void sports::SportRecord::addRidingRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["riding_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * Riding_cal;
    double totalTime = timeData["riding"].toDouble() + duration;
    double weeklyTime = weeklyData["riding"].toDouble() + duration;
    double weeklyCalories = weeklyData["riding_calories"].toDouble() + calories;

    timeData["riding"] = totalTime;
    weeklyData["riding"] = weeklyTime;
    weeklyData["riding_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["riding_records"] = records;
    writeSportsJson(root);
}

// 登山记录
void sports::SportRecord::addClimbingRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["climbing_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * climbing_cal;
    double totalTime = timeData["climbing"].toDouble() + duration;
    double weeklyTime = weeklyData["climbing"].toDouble() + duration;
    double weeklyCalories = weeklyData["climbing_calories"].toDouble() + calories;

    timeData["climbing"] = totalTime;
    weeklyData["climbing"] = weeklyTime;
    weeklyData["climbing_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["climbing_records"] = records;
    writeSportsJson(root);
}

// 游泳记录
void sports::SportRecord::addSwimmingRecord(const QString& date, int duration) {
    QJsonObject root = readSportsJson();
    QJsonArray records = root["swimming_records"].toArray();
    QJsonObject timeData = root["time_data"].toObject();
    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    double calories = duration * swimming_cal;
    double totalTime = timeData["swimming"].toDouble() + duration;
    double weeklyTime = weeklyData["swimming"].toDouble() + duration;
    double weeklyCalories = weeklyData["swimming_calories"].toDouble() + calories;

    timeData["swimming"] = totalTime;
    weeklyData["swimming"] = weeklyTime;
    weeklyData["swimming_calories"] = weeklyCalories;

    QJsonObject newRecord;
    newRecord["date"] = date;
    newRecord["duration"] = duration;
    newRecord["calories"] = calories;
    records.append(newRecord);

    root["time_data"] = timeData;
    root["weekly_time_data"] = weeklyData;
    root["swimming_records"] = records;
    writeSportsJson(root);
}
