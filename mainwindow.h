#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QPointer>

#include "schedule.h"
#include "sports.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT
private:
    QPointer<Schedule> scheduleWin;
    QPointer<Sports> sportsWin;
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_ScheButton_clicked();

    void on_SportsButton_clicked();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
