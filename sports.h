#ifndef SPORTS_H
#define SPORTS_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QString>
#include <Qvector>
#include <QQueue>
#include <QHash>
#include <QPair>

class sportsData;

class sports
{
    Q_OBJECT
    QML_ELEMENT
    //这里可以补充一些个人的身体信息？
public:
    sports();
    sports(const sports &);
    sports(sports &&);
    sports &operator=(const sports &);
    sports &operator=(sports &&);
    ~sports();

    double basic_energy=0;
    double energy_need=0;
    double protein_need=0;
    double fat_need=0;
    double weight_vector[9]={1,1,1,0,0,0,0,1,2};//默认权重向量

    class SportRecord{
    public:
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
        //累计时长/里程
        double badminton_time=0;      //羽毛球爱好者->羽毛球大师
        double pingpong_time=0;       //乒乓球爱好者->乒乓球大师
        double tennis_time=0;         //网球爱好者->网球大师
        double basketball_time=0;     //篮球爱好者->篮球大师
        double volleyball_time=0;     //排球爱好者->排球大师
        double football_time=0;       //足球爱好者->足球大师
        double running_time=0;     //跑步健将->跑步大师
        double riding_time=0;      //骑行健将->骑行大师
        double climbing_time=0;    //登山健将->登山大师
        double swimming_time=0;       //游泳健将->游泳大师
            //全一级:六边形战士 -> 全二级:满级人类
        //本周时长/里程
        double week_badminton_time=0;
        double week_pingpong_time=0;
        double week_tennis_time=0;
        double week_basketball_time=0;
        double week_volleyball_time=0;
        double week_football_time=0;
        double week_running_time=0;
        double week_riding_time=0;
        double week_climbing_time=0;
        double week_swimming_time=0;

        QVector<QPair<QString,int> > week_bad_vec;
        QVector<QPair<QString,int> > week_pin_vec;
        QVector<QPair<QString,int> > week_ten_vec;
        QVector<QPair<QString,int> > week_bas_vec;
        QVector<QPair<QString,int> > week_vol_vec;
        QVector<QPair<QString,int> > week_foo_vec;
        QVector<QPair<QString,int> > week_run_vec;
        QVector<QPair<QString,int> > week_rid_vec;
        QVector<QPair<QString,int> > week_cli_vec;
        QVector<QPair<QString,int> > week_swi_vec;

        void reset(); //每周更新
        QString get_str() const;
        static SportRecord load(QTextStream& input);
    }sptRec;


    //内部类，存储成就
    class AchievementRecord{
    public:
        //成就名称  --->  0:未获得 1:一级/获得 2:二级 3:三级
        //成就名称看AChievementRecord构造函数
        QHash<QString,int> achievement_map;
        //长度固定，就先暂定5个吧，进一个出一个，用于实现最近成就
        QQueue<QString> qu;
        QString get_str() const;
        static AchievementRecord load(QTextStream& input);
        QVector<QString> check_achievement(SportRecord sr);
        AchievementRecord()
        {
            achievement_map.insert("羽毛球",0);
            achievement_map.insert("乒乓球",0);
            achievement_map.insert("网球",0);
            achievement_map.insert("篮球",0);
            achievement_map.insert("排球",0);
            achievement_map.insert("足球",0);
            achievement_map.insert("跑步",0);
            achievement_map.insert("骑行",0);
            achievement_map.insert("登山",0);
            achievement_map.insert("游泳",0);
            achievement_map.insert("六边形",0);
        }
    }achRec;
    //检查有没有触发新的成就
    QVector<QString> check_achievement();
    bool load();
    bool save();
    void init();
    void reset();

private:
    QSharedDataPointer<sportsData> data;
};


#endif // SPORT_H

