#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>
#include<QLineEdit>
#include "backend/Sport_Item.h"


namespace Ui {
class records;
}

class records : public QDialog
{
    Q_OBJECT

public:
    explicit records(QWidget *parent = nullptr);
    ~records();

private slots:
    void on_runButton_clicked();

    void on_badmintonBtn_clicked();

    void on_pingpongBtn_clicked();

    void on_tennisBtn_clicked();

    void on_basketballBtn_clicked();

    void on_volleyballBtn_clicked();

    void on_footballBtn_clicked();

    void on_ridingBtn_clicked();

    void on_climbingBtn_clicked();

    void on_swimmingBtn_clicked();
    // 实时卡路里计算
    void calculateRunningCalories();
    void calculateBadmintonCalories();
    void calculatePingpongCalories();
    void calculateTennisCalories();
    void calculateBasketballCalories();
    void calculateVolleyballCalories();
    void calculateFootballCalories();
    void calculateRidingCalories();
    void calculateClimbingCalories();
    void calculateSwimmingCalories();

private:
    Ui::records *ui;
    sports *m_sports; // 运动数据对象

    // 通用记录函数
    void recordSport(QLineEdit *timeEdit, double *totalTime, double *weeklyTime,
                     QVector<QPair<QString, int>> *weeklyVec, double calorieRate);
};

#endif // RECORDS_H
