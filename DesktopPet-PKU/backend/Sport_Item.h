#ifndef SPORT_ITEM_H
#define SPORT_ITEM_H

#include <QObject>
#include <QSharedData>
#include <QString>
#include <QVector>
#include <QPair>
#include <QJsonObject>
#include <QJsonArray>
#include <QFile>
#include <QDir>
#include <QDebug>
#include <QtQml>

class sportsData : public QSharedData
{
public:
};

class sports : public QObject
{
    Q_OBJECT
    QML_ELEMENT

public:
    sports();
    sports(const sports &);
    sports(sports &&);
    sports &operator=(const sports &);
    sports &operator=(sports &&);
    ~sports();

    class SportRecord {
    public:
        // 卡路里常量
        static const double badminton_cal;
        static const double pingpong_cal;
        static const double tennis_cal;
        static const double basketball_cal;
        static const double volleyball_cal;
        static const double football_cal;
        static const double Running_cal;
        static const double Riding_cal;
        static const double climbing_cal;
        static const double swimming_cal;

        // 重置函数
        void reset();

        // 文件路径
        static const QString DATA_FILE_PATH;

        // 运动记录函数
        void addBadmintonRecord(const QString& date, int duration);
        void addPingpongRecord(const QString& date, int duration);
        void addTennisRecord(const QString& date, int duration);
        void addBasketballRecord(const QString& date, int duration);
        void addVolleyballRecord(const QString& date, int duration);
        void addFootballRecord(const QString& date, int duration);
        void addRunningRecord(const QString& date, int duration, double distance);
        void addRidingRecord(const QString& date, int duration);
        void addClimbingRecord(const QString& date, int duration);
        void addSwimmingRecord(const QString& date, int duration);

    private:
        // JSON文件操作
        QJsonObject readSportsJson() const;
        void writeSportsJson(const QJsonObject& json) const;
        QJsonObject createBaseJsonStructure() const;

        // JSON更新辅助
        void updateJsonField(QJsonObject& root,
                             const QString& timeKey, double timeValue,
                             const QString& weeklyKey, double weeklyValue,
                             const QString& recordKey, const QJsonArray& records) const;
    } sptRec;

private:
    QSharedDataPointer<sportsData> data;
};

#endif // SPORT_ITEM_H
