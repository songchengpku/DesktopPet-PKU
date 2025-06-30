#include "timetablesave.h"
#include "ui_timetablesave.h"

TimetableSave::TimetableSave(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TimetableSave)
{
    ui->setupUi(this);
}

TimetableSave::~TimetableSave()
{
    delete ui;
}
