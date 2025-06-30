#include "timetableclear.h"
#include "ui_timetableclear.h"

TimetableClear::TimetableClear(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimetableClear)
{
    ui->setupUi(this);
}

TimetableClear::~TimetableClear()
{
    delete ui;
}
