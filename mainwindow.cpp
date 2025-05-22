#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ScheButton_clicked()
{
    if(!scheduleWin)
    {
        scheduleWin=new Schedule(this);
        scheduleWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    scheduleWin->show();
}


void MainWindow::on_SportsButton_clicked()
{
    if(!sportsWin)
    {
        sportsWin=new Sports(this);
        sportsWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    sportsWin->show();
}

