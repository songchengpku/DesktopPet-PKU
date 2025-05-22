#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timetable.h"
#include "mainwindowclose.h"
#include "QMouseEvent"
#include "iostream"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint); // 隐藏边框和标题栏
    setAttribute(Qt::WA_TranslucentBackground); // 设置背景透明
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_timetable_clicked()
{
    Timetable t;
    t.exec();
}


void MainWindow::on_close_clicked()
{
    mainwindowclose mc;
    if(mc.exec()==mainwindowclose::Accepted)
        this->close();
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        m_dragPosition = event->globalPos() - frameGeometry().bottomLeft();
        event->accept();
    }
    QWidget::mousePressEvent(event); // 确保其他鼠标事件正常处理
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (event->buttons() & Qt::LeftButton) {
        move(event->globalPos() - m_dragPosition);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}
