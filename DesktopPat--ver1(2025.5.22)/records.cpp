#include "records.h"
#include "ui_records.h"

records::records(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::records)
{
    ui->setupUi(this);
}

records::~records()
{
    delete ui;
}
