#include "timetableremind.h"
#include "ui_timetableremind.h"

TimetableRemind::TimetableRemind(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimetableRemind)
{
    ui->setupUi(this);
}

TimetableRemind::~TimetableRemind()
{
    delete ui;
}
