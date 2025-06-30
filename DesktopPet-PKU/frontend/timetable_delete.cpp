#include "timetable_delete.h"
#include "ui_timetable_delete.h"

Timetable_delete::Timetable_delete(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Timetable_delete)
{
    ui->setupUi(this);
}

Timetable_delete::~Timetable_delete()
{
    delete ui;
}

void Timetable_delete::on_complete_clicked()
{
    //删除课表信息
    this->close();
}

