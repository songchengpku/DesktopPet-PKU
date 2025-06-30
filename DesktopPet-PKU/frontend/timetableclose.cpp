#include "timetableclose.h"
#include "ui_timetableclose.h"

TimetableClose::TimetableClose(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimetableClose)
{
    ui->setupUi(this);
}

TimetableClose::~TimetableClose()
{
    delete ui;
}
