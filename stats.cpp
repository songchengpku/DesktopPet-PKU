#include "stats.h"
#include "ui_stats.h"

stats::stats(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stats)
{
    ui->setupUi(this);
}

stats::~stats()
{
    delete ui;
}
