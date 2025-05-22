#include "sports.h"
#include <QFile>
#include <QDebug>
#include <utility>

class sportsData : public QSharedData
{
public:
};

sports::sports()
    : data(new sportsData)
{}

sports::sports(const sports &rhs)
    : data{rhs.data}
{}

sports::sports(sports &&rhs)
    : data{std::move(rhs.data)}
{}

sports &sports::operator=(const sports &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

sports &sports::operator=(sports &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

sports::~sports() {}



double exercise_level[5] = {1.0,1.2,1.375,1.55,1.725};
double protein_rate[5] = {0.9,0.9,1.1,1.4,1.6};

/*void sports::init()
{

    basic_energy = 10*weight + 6.25*height -5*age -161 + 166*gender;
    energy_need = basic_energy * exercise_level[target] * 0.35;
    protein_need = weight * protein_rate[target] *0.35;
    if(gender==0) protein_need *= 0.85;
    fat_need = (energy_need/45)*0.35;
    if(target<=1){
        weight_vector[5]+=10;
        if(target<=1) weight_vector[0]+=1;
    }
    if(target>=3) weight_vector[1]+=0.5;
    if(preference[0]==1) weight_vector[3]-=100;
    if(preference[0]==2) weight_vector[3]+=10;
    if(preference[1]==1) weight_vector[4]-=100;
    if(preference[1]==2) weight_vector[4]+=10;
    if(preference[3]==1) weight_vector[6]-=1;
    if(preference[2]==1) weight_vector[7]=2;
    if(preference[2]==1) weight_vector[8]=0.5;
    if(preference[2]==2) weight_vector[7]=0.5;
    if(preference[2]==2) weight_vector[8]=2;
}*/

const double sports::SportRecord::badminton_cal=6.126;
const double sports::SportRecord::pingpong_cal=4.9;
const double sports::SportRecord::tennis_cal=9.8;
const double sports::SportRecord::basketball_cal=7.35;
const double sports::SportRecord::volleyball_cal=4.9;
const double sports::SportRecord::football_cal=9.8;
const double sports::SportRecord::Running_cal=12.25;
const double sports::SportRecord::Riding_cal=9.8;
const double sports::SportRecord::climbing_cal=9.8;
const double sports::SportRecord::swimming_cal=8.6;

QString sports::SportRecord::get_str() const{
    QString str;
    str += QString::number(badminton_time,'f',2)+',';
    str += QString::number(pingpong_time,'f',2)+',';
    str += QString::number(tennis_time,'f',2)+',';
    str += QString::number(basketball_time,'f',2)+',';
    str += QString::number(volleyball_time,'f',2)+',';
    str += QString::number(football_time,'f',2)+',';
    str += QString::number(running_time,'f',2)+',';
    str += QString::number(riding_time,'f',2)+',';
    str += QString::number(climbing_time,'f',2)+',';
    str += QString::number(swimming_time,'f',2)+',';
    str += '\n';
    str += QString::number(week_badminton_time,'f',2)+',';
    str += QString::number(week_pingpong_time,'f',2)+',';
    str += QString::number(week_tennis_time,'f',2)+',';
    str += QString::number(week_basketball_time,'f',2)+',';
    str += QString::number(week_volleyball_time,'f',2)+',';
    str += QString::number(week_football_time,'f',2)+',';
    str += QString::number(week_running_time,'f',2)+',';
    str += QString::number(week_riding_time,'f',2)+',';
    str += QString::number(week_climbing_time,'f',2)+',';
    str += QString::number(week_swimming_time,'f',2)+',';
    str += '\n';
    if(week_bad_vec.size()==0) str += "NULL";
    else for(auto pr : week_bad_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_pin_vec.size()==0) str += "NULL";
    else for(auto pr : week_pin_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_ten_vec.size()==0) str += "NULL";
    else for(auto pr : week_ten_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_bas_vec.size()==0) str += "NULL";
    else for(auto pr : week_bas_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_vol_vec.size()==0) str += "NULL";
    else for(auto pr : week_vol_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_foo_vec.size()==0) str += "NULL";
    else for(auto pr : week_foo_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_run_vec.size()==0) str += "NULL";
    else for(auto pr : week_run_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_rid_vec.size()==0) str += "NULL";
    else for(auto pr : week_rid_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_cli_vec.size()==0) str += "NULL";
    else for(auto pr : week_cli_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    if(week_swi_vec.size()==0) str += "NULL";
    else for(auto pr : week_swi_vec) str += pr.first+','+QString::number(pr.second)+',';
    str += '\n';
    return str;
}

sports::SportRecord sports::SportRecord::load(QTextStream& input) {
    sports::SportRecord record;
    QString str ;
    input>>str;
    assert(str[0]=='%');
    input>>str;
    QStringList parts = str.split(',');
    record.badminton_time = parts[0].toDouble();
    record.pingpong_time = parts[1].toDouble();
    record.tennis_time = parts[2].toDouble();
    record.basketball_time = parts[3].toDouble();
    record.volleyball_time = parts[4].toDouble();
    record.football_time = parts[5].toDouble();
    record.running_time = parts[6].toDouble();
    record.riding_time = parts[7].toDouble();
    record.climbing_time = parts[8].toDouble();
    record.swimming_time = parts[9].toDouble();
    input>>str;
    parts = str.split(',');
    record.week_badminton_time = parts[0].toDouble();
    record.week_pingpong_time = parts[1].toDouble();
    record.week_tennis_time = parts[2].toDouble();
    record.week_basketball_time = parts[3].toDouble();
    record.week_volleyball_time = parts[4].toDouble();
    record.week_football_time = parts[5].toDouble();
    record.week_running_time = parts[6].toDouble();
    record.week_riding_time = parts[7].toDouble();
    record.week_climbing_time = parts[8].toDouble();
    record.week_swimming_time = parts[9].toDouble();
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_bad_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_pin_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_ten_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_bas_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_vol_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_foo_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_run_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_rid_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_cli_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    input>>str;
    if(str[0]!='N')
    {
        parts = str.split(',');
        for(int i=0;i<parts.size()-1;i+=2) record.week_swi_vec.append(qMakePair(parts[i],parts[i+1].toInt()));
    }
    return record;
}

void sports::SportRecord::reset()
{
    week_badminton_time = 0;
    week_pingpong_time = 0;
    week_tennis_time = 0;
    week_basketball_time = 0;
    week_volleyball_time = 0;
    week_football_time = 0;
    week_running_time = 0;
    week_riding_time = 0;
    week_climbing_time = 0;
    week_swimming_time = 0;
    week_bad_vec.clear();
    week_pin_vec.clear();
    week_ten_vec.clear();
    week_bas_vec.clear();
    week_vol_vec.clear();
    week_foo_vec.clear();
    week_run_vec.clear();
    week_rid_vec.clear();
    week_cli_vec.clear();
    week_swi_vec.clear();
}



sports::AchievementRecord sports::AchievementRecord::load(QTextStream& input) {
    sports::AchievementRecord record;
    QString str;
    while(1) {
        input>>str;
        if(str[0]=='%') break;
        QStringList parts = str.split(',');
        if (parts.size() >= 2) {
            QString achievement = parts[0];
            int value = parts[1].toInt();
            record.achievement_map[achievement] = value;
        }
    }
    input>>str;
    QStringList parts = str.split(',');
    if(str[0]=='N'||str[0]=='%') return record;
    for(auto tempstr : parts)
    {
        if(tempstr==""||tempstr[0]=='N') break;
        record.qu.enqueue(tempstr);
    }
    return record;
}


QVector<QString> sports::AchievementRecord::check_achievement(SportRecord sr)
{
    int originalsize=qu.size();
    int flag=3;

    if(sr.badminton_time>=600 && achievement_map["羽毛球"]<=1)
    {
        achievement_map["羽毛球"]=3;
        qu.enqueue("羽神");
    }else if(sr.badminton_time>=180 && achievement_map["羽毛球"]<=0)
    {
        achievement_map["羽毛球"]=1;
        qu.enqueue("羽坛小将");
    }
    flag = fmin(flag,achievement_map["羽毛球"]);
    if(sr.pingpong_time>=600 && achievement_map["乒乓球"]<=1)
    {
        achievement_map["乒乓球"]=3;
        qu.enqueue("乒神");
    }else if(sr.pingpong_time>=180 && achievement_map["乒乓球"]<=0)
    {
        achievement_map["乒乓球"]=1;
        qu.enqueue("乒坛小将");
    }
    flag = fmin(flag,achievement_map["乒乓球"]);
    if(sr.tennis_time>=600 && achievement_map["网球"]<=1)
    {
        achievement_map["网球"]=3;
        qu.enqueue("网球大师");
    }else if(sr.tennis_time>=180 && achievement_map["网球"]<=0)
    {
        achievement_map["网球"]=1;
        qu.enqueue("网球小将");
    }
    flag = fmin(flag,achievement_map["网球"]);
    if(sr.basketball_time>=600 && achievement_map["篮球"]<=1)
    {
        achievement_map["篮球"]=3;
        qu.enqueue("想你了，牢大！");
    }else if(sr.basketball_time>=180 && achievement_map["篮球"]<=0)
    {
        achievement_map["篮球"]=1;
        qu.enqueue("篮球新秀");
    }
    flag = fmin(flag,achievement_map["篮球"]);
    if(sr.volleyball_time>=600 && achievement_map["排球"]<=1)
    {
        achievement_map["排球"]=3;
        qu.enqueue("排球大师");
    }else if(sr.volleyball_time>=180 && achievement_map["排球"]<=0)
    {
        achievement_map["排球"]=1;
        qu.enqueue("排球新秀");
    }
    flag = fmin(flag,achievement_map["排球"]);
    if(sr.football_time>=600 && achievement_map["足球"]<=1)
    {
        achievement_map["足球"]=3;
        qu.enqueue("足球大师");
    }else if(sr.football_time>=180 && achievement_map["足球"]<=0)
    {
        achievement_map["足球"]=1;
        qu.enqueue("足球新秀");
    }
    flag = fmin(flag,achievement_map["足球"]);
    if(sr.running_time>=600 && achievement_map["跑步"]<=1)
    {
        achievement_map["跑步"]=3;
        qu.enqueue("人生是一场马拉松~");
    }else if(sr.running_time>=180 && achievement_map["跑步"]<=0)
    {
        achievement_map["跑步"]=1;
        qu.enqueue("初级跑者");
    }
    flag = fmin(flag,achievement_map["跑步"]);
    if(sr.riding_time>=600 && achievement_map["骑行"]<=1)
    {
        achievement_map["骑行"]=3;
        qu.enqueue("人车合一！");
    }else if(sr.riding_time>=180 && achievement_map["骑行"]<=0)
    {
        achievement_map["骑行"]=1;
        qu.enqueue("初级骑手");
    }
    flag = fmin(flag,achievement_map["骑行"]);
    if(sr.climbing_time>=600 && achievement_map["登山"]<=1)
    {
        achievement_map["登山"]=3;
        qu.enqueue("山顶洞人");
    }else if(sr.climbing_time>=180 && achievement_map["登山"]<=0)
    {
        achievement_map["登山"]=1;
        qu.enqueue("驴友");
    }
    flag = fmin(flag,achievement_map["登山"]);
    if(sr.swimming_time>=600 && achievement_map["游泳"]<=1)
    {
        achievement_map["游泳"]=3;
        qu.enqueue("弄潮儿");
    }else if(sr.swimming_time>=180 && achievement_map["游泳"]<=0)
    {
        achievement_map["游泳"]=1;
        qu.enqueue("狗刨式");
    }
    flag = fmin(flag,achievement_map["游泳"]);
    if(flag==3 && achievement_map["六边形"]<=2){
        achievement_map["六边形"]=3;
        qu.enqueue("古希腊无所不能的神");
    }else if(flag==1 && achievement_map["六边形"]<=0)
    {
        achievement_map["六边形"]=2;
        qu.enqueue("六边形战士");
    }

    QVector<QString> newach;  //qu是最近达成的五个成就，newach是这次发现新完成的成就
    if (qu.size()>originalsize){
        for (int i=originalsize;i<qu.size();i++)
            newach.append(qu[i]);
    }
    while(qu.size()>5)
        qu.dequeue();
    return newach;
}

/*QVector<QString> sports::check_achievement(){
    return achRec.check_achievement(sptRec,foodRec);
}*/

time_t trans(QString str){
    int index_m=str.indexOf("月");
    int index_d=str.indexOf("日");
    QString year_str=str.mid(0,4);
    int year=year_str.toInt();
    QString mon_str=str.mid(5,index_m-5);
    int mon=mon_str.toInt();
    QString day_str=str.mid(index_m+1,index_d-index_m-1);
    int day=day_str.toInt();
    tm t1={0,0,0,day,mon-1,year-1900,0,0,0};
    return mktime(&t1);
}

void sports::reset(){
    bool shouldReset=false;
    time_t now = time(nullptr);
    tm* nowtm = localtime(&now);
    tm t2={0,0,0,nowtm->tm_mday,nowtm->tm_mon,nowtm->tm_year,0,0,0};
    time_t _t2=mktime(&t2);
    _t2-=((nowtm->tm_wday+6)%7)*86400;

    /*if(!shouldReset && !foodRec.week_record.empty() && trans(foodRec.week_record[0].first)<_t2)
        shouldReset=true;*/
    if(!shouldReset && !sptRec.week_bad_vec.empty() && trans(sptRec.week_bad_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_pin_vec.empty() && trans(sptRec.week_pin_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_ten_vec.empty() && trans(sptRec.week_ten_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_bas_vec.empty() && trans(sptRec.week_bas_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_vol_vec.empty() && trans(sptRec.week_vol_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_foo_vec.empty() && trans(sptRec.week_foo_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_run_vec.empty() && trans(sptRec.week_run_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_rid_vec.empty() && trans(sptRec.week_rid_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_cli_vec.empty() && trans(sptRec.week_cli_vec[0].first)<_t2)
        shouldReset=true;
    if(!shouldReset && !sptRec.week_swi_vec.empty() && trans(sptRec.week_swi_vec[0].first)<_t2)
        shouldReset=true;

    if(shouldReset){
        sptRec.reset();
        save();
    }

}
