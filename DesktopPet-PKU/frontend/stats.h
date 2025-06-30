#ifndef STATS_H
#define STATS_H

#include <QDialog>
#include <QtCharts>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QLabel>
#include<QPushButton>
#include "backend/Sport_Item.h"  // 包含共享常量定义

QT_BEGIN_NAMESPACE
class QChartView;
class QChart;
QT_END_NAMESPACE

namespace Ui {
class stats;
}

class stats : public QDialog
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    ~stats();

private slots:
    void onResetClicked();
private:
    Ui::stats *ui;

    QPushButton *resetButton;
    // 图表视图
    QChartView *barChartView;
    QChartView *pieChartView;

    // 文本统计区域
    QWidget *textStatsWidget;
    QLabel *titleLabel;  // 新增标题标签
    QLabel *totalTimeLabel;
    QLabel *totalCaloriesLabel;
    QLabel *comparisonLabel;

    // 布局
    QHBoxLayout *mainLayout;
    QVBoxLayout *textLayout;  // 新增文本布局

    // 数据
    QMap<QString, double> sportTimes;
    QMap<QString, double> sportCalories;

    // 初始化函数
    void setupUI();
    void loadSportsData();
    void createBarChart();
    void createPieChart();
    void updateTextStats();
};

#endif // STATS_H
