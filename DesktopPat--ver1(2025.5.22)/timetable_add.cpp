#include "timetable_add.h"
#include "ui_timetable_add.h"

using namespace std;

Timetable_add::Timetable_add(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Timetable_add)
{
    ui->setupUi(this);
    name="";
    message="";
    weekday={0,0,0,0};
    period={{0,0},{0,0},{0,0},{0,0}};
}

Timetable_add::~Timetable_add()
{
    delete ui;
}


void Timetable_add::on_complete_clicked()
{
    if(!name.isEmpty())
    {
        //存储课表信息
        name="";
        message="";
        weekday={0,0,0,0};
        period={{0,0},{0,0},{0,0},{0,0}};
    }
    this->close();
}


void Timetable_add::on_name_textChanged(const QString &arg1)
{
    name=arg1;
}


void Timetable_add::on_message_textChanged(const QString &arg1)
{
    message=arg1;
}


void Timetable_add::on_weekday1_currentIndexChanged(int index)
{
    weekday[0]=index;
}


void Timetable_add::on_weekday2_currentIndexChanged(int index)
{
    weekday[1]=index;
}


void Timetable_add::on_weekday3_currentIndexChanged(int index)
{
    weekday[2]=index;
}


void Timetable_add::on_weekday4_currentIndexChanged(int index)
{
    weekday[3]=index;
}


void Timetable_add::on_time11_currentIndexChanged(int index)
{
    period[0].first=index;
}


void Timetable_add::on_time12_currentIndexChanged(int index)
{
    period[0].second=index;
}


void Timetable_add::on_time21_currentIndexChanged(int index)
{
    period[1].first=index;
}


void Timetable_add::on_time22_currentIndexChanged(int index)
{
    period[1].second=index;
}


void Timetable_add::on_time31_currentIndexChanged(int index)
{
    period[2].first=index;
}


void Timetable_add::on_time32_currentIndexChanged(int index)
{
    period[2].second=index;
}


void Timetable_add::on_time41_currentIndexChanged(int index)
{
    period[3].first=index;
}


void Timetable_add::on_time42_currentIndexChanged(int index)
{
    period[3].second=index;
}

