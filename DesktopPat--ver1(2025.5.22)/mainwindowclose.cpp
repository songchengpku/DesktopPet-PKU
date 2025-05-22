#include "mainwindowclose.h"
#include "ui_mainwindowclose.h"

mainwindowclose::mainwindowclose(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::mainwindowclose)
{
    ui->setupUi(this);
}

mainwindowclose::~mainwindowclose()
{
    delete ui;
}
