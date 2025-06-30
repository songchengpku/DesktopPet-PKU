#include "stats.h"
#include "ui_stats.h"
#include "backend/Sport_Item.h"  // 包含运动数据定义


#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QBarSet>
#include <QBarSeries>
#include <QPieSeries>
#include <QMessageBox>
#include <QSpacerItem>  // 新增用于垂直居中的间隔项

stats::stats(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::stats)
{
    ui->setupUi(this);
    setWindowTitle("运动统计");
    resize(1200, 600);

    // 初始化UI
    setupUI();

    // 加载运动数据
    loadSportsData();

    // 创建图表
    createBarChart();
    createPieChart();

    // 更新文本统计
    updateTextStats();
}

stats::~stats()
{
    delete ui;
}

void stats::setupUI()
{
    // 创建主布局
    mainLayout = new QHBoxLayout(this);
    mainLayout->setSpacing(20);

    // 创建柱状图区域 (40%宽度)
    barChartView = new QChartView(this);
    barChartView->setMinimumSize(400, 500);
    mainLayout->addWidget(barChartView, 4);

    // 创建饼图区域 (40%宽度)
    pieChartView = new QChartView(this);
    pieChartView->setMinimumSize(400, 500);
    mainLayout->addWidget(pieChartView, 4);

    // 创建文本统计区域 (20%宽度)
    textStatsWidget = new QWidget(this);
    textLayout = new QVBoxLayout(textStatsWidget);
    textLayout->setAlignment(Qt::AlignCenter);  // 设置整体垂直居中

    resetButton = new QPushButton("重置运动数据", textStatsWidget);
    resetButton->setStyleSheet(
        "QPushButton {"
        "   background-color: #FF5722;"
        "   color: white;"
        "   border-radius: 5px;"
        "   padding: 8px 16px;"
        "   font-weight: bold;"
        "}"
        "QPushButton:hover {"
        "   background-color: #E64A19;"
        "}"
        );
    resetButton->setMinimumHeight(40);

    // 将按钮添加到文本布局底部
    textLayout->addWidget(resetButton, 0, Qt::AlignHCenter | Qt::AlignBottom);

    // 连接按钮信号到槽函数
    connect(resetButton, &QPushButton::clicked, this, &stats::onResetClicked);

    // 添加顶部间隔
    textLayout->addStretch(1);

    titleLabel = new QLabel("上周运动统计", textStatsWidget);
    titleLabel->setAlignment(Qt::AlignCenter);
    titleLabel->setStyleSheet("font-size: 18px; font-weight: bold; margin-bottom: 20px;");
    textLayout->addWidget(titleLabel);

    totalTimeLabel = new QLabel(textStatsWidget);
    totalTimeLabel->setAlignment(Qt::AlignCenter);  // 文本居中
    totalTimeLabel->setStyleSheet("font-size: 14px; margin: 10px 0;");
    textLayout->addWidget(totalTimeLabel);

    totalCaloriesLabel = new QLabel(textStatsWidget);
    totalCaloriesLabel->setAlignment(Qt::AlignCenter);  // 文本居中
    totalCaloriesLabel->setStyleSheet("font-size: 14px; margin: 10px 0;");
    textLayout->addWidget(totalCaloriesLabel);

    comparisonLabel = new QLabel(textStatsWidget);
    comparisonLabel->setAlignment(Qt::AlignCenter);  // 文本居中
    comparisonLabel->setStyleSheet("font-size: 14px; margin: 10px 0; color: #FF5722;");
    comparisonLabel->setWordWrap(true);
    textLayout->addWidget(comparisonLabel);

    // 添加底部间隔
    textLayout->addStretch(1);

    textStatsWidget->setLayout(textLayout);
    mainLayout->addWidget(textStatsWidget, 2);

    setLayout(mainLayout);
}

void stats::loadSportsData()
{
    // 使用共享常量 DATA_FILE_PATH (来自 Sport_Item.h)
    QFile file(sports::SportRecord::DATA_FILE_PATH);

    // 检查文件是否存在
    if (!file.exists()) {
        QMessageBox::information(this, "提示", "运动数据文件不存在");
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "错误", "无法打开运动数据文件");
        return;
    }

    // 检查文件是否为空
    if (file.size() == 0) {
        QMessageBox::information(this, "提示", "运动数据文件为空");
        file.close();
        return;
    }

    QByteArray jsonData = file.readAll();
    file.close();

    QJsonParseError error;
    QJsonDocument doc = QJsonDocument::fromJson(jsonData, &error);

    if (error.error != QJsonParseError::NoError) {
        QMessageBox::warning(this, "错误", "JSON解析错误: " + error.errorString());
        return;
    }

    QJsonObject root = doc.object();

    // 检查是否有周数据
    if (!root.contains("weekly_time_data")) {
        QMessageBox::information(this, "提示", "文件中没有周数据");
        return;
    }

    QJsonObject weeklyData = root["weekly_time_data"].toObject();

    // 定义运动项目列表
    QStringList sports = {
        "badminton", "pingpong", "tennis", "basketball",
        "volleyball", "football", "running", "riding",
        "climbing", "swimming"
    };

    // 清空现有数据
    sportTimes.clear();
    sportCalories.clear();

    // 提取各运动项目的时间和卡路里数据
    for (const QString &sport : sports) {
        if (weeklyData.contains(sport)) {
            double time = weeklyData[sport].toDouble();
            double calories = weeklyData[sport + "_calories"].toDouble();

            sportTimes[sport] = time;
            sportCalories[sport] = calories;
        }
    }
}

void stats::createBarChart()
{
    // 检查是否有数据
    if (sportTimes.isEmpty()) {
        QChart *chart = new QChart();
        chart->setTitle("上周运动时间统计 (无数据)");

        // 添加一个空系列避免图表崩溃
        QBarSeries *series = new QBarSeries();
        chart->addSeries(series);

        barChartView->setChart(chart);
        return;
    }

    // 创建柱状图
    QBarSeries *series = new QBarSeries();

    // 定义运动项目的中文名称
    QMap<QString, QString> sportNames = {
        {"badminton", "羽毛球"}, {"pingpong", "乒乓球"}, {"tennis", "网球"},
        {"basketball", "篮球"}, {"volleyball", "排球"}, {"football", "足球"},
        {"running", "跑步"}, {"riding", "骑行"}, {"climbing", "登山"}, {"swimming", "游泳"}
    };

    // 添加数据到柱状图
    for (auto it = sportTimes.constBegin(); it != sportTimes.constEnd(); ++it) {
        if (it.value() > 0) {
            QBarSet *set = new QBarSet(sportNames[it.key()]);
            *set << it.value();
            series->append(set);
        }
    }

    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("上周运动时间统计 (分钟)");
    chart->setAnimationOptions(QChart::SeriesAnimations);

    // 设置坐标轴
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    axisY->setLabelFormat("%d");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    // 设置图表样式
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignBottom);
    chart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));

    barChartView->setChart(chart);
    barChartView->setRenderHint(QPainter::Antialiasing);
}

void stats::createPieChart()
{
    // 计算总时间
    double totalTime = 0;
    for (double time : sportTimes.values()) {
        totalTime += time;
    }

    // 处理无数据情况
    if (totalTime <= 0) {
        QPieSeries *series = new QPieSeries();
        series->append("无数据", 1); // 添加一个占位切片

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle("运动时间占比 (无数据)");

        // 设置透明切片
        QPieSlice *slice = series->slices().at(0);
        slice->setLabelVisible(false);
        slice->setBrush(Qt::transparent);
        slice->setPen(Qt::NoPen);

        pieChartView->setChart(chart);
        pieChartView->setRenderHint(QPainter::Antialiasing);
        return;
    }

    // 创建饼图系列
    QPieSeries *series = new QPieSeries();

    // 添加数据到饼图 (只显示有数据的项目)
    QMap<QString, QString> sportNames = {
        {"badminton", "羽毛球"}, {"pingpong", "乒乓球"}, {"tennis", "网球"},
        {"basketball", "篮球"}, {"volleyball", "排球"}, {"football", "足球"},
        {"running", "跑步"}, {"riding", "骑行"}, {"climbing", "登山"}, {"swimming", "游泳"}
    };

    for (auto it = sportTimes.constBegin(); it != sportTimes.constEnd(); ++it) {
        if (it.value() > 0) {
            double percentage = (it.value() / totalTime) * 100;
            QPieSlice *slice = series->append(sportNames[it.key()], it.value());
            slice->setLabel(QString("%1 %2%").arg(slice->label()).arg(QString::number(percentage, 'f', 1)));
        }
    }

    // 设置饼图样式
    series->setLabelsVisible(true);
    series->setPieSize(0.7);

    // 创建图表
    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->setTitle("运动时间占比");
    chart->legend()->setVisible(true);
    chart->legend()->setAlignment(Qt::AlignRight);
    chart->setBackgroundBrush(QBrush(QColor(240, 240, 240)));

    pieChartView->setChart(chart);
    pieChartView->setRenderHint(QPainter::Antialiasing);
}

void stats::updateTextStats()
{
    // 计算总时间和总卡路里
    double totalTime = 0;
    double totalCalories = 0;

    for (double time : sportTimes.values()) {
        totalTime += time;
    }

    for (double calories : sportCalories.values()) {
        totalCalories += calories;
    }

    // 更新标签文本
    totalTimeLabel->setText(QString("总运动时间: %1 分钟").arg(totalTime));
    totalCaloriesLabel->setText(QString("总消耗卡路里: %1 千卡").arg(totalCalories));

    // 根据是否有数据显示不同的比较信息
    if (totalTime > 0) {
        comparisonLabel->setText("恭喜！您超越了99.99%的用户");
    } else {
        comparisonLabel->setText("暂无运动数据，开始运动吧！");
        comparisonLabel->setStyleSheet("font-size: 14px; margin: 10px 0; color: #2196F3;");
    }
}

// 添加重置按钮的槽函数实现
void stats::onResetClicked()
{
    // 创建确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认重置",
                                  "确定要重置所有运动数据吗？此操作不可撤销！",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        // 创建运动对象并调用重置函数
        sports sport;
        sport.sptRec.reset();  // 调用重置函数

        // 重新加载数据并更新UI
        loadSportsData();
        createBarChart();
        createPieChart();
        updateTextStats();

        QMessageBox::information(this, "操作成功", "所有运动数据已重置！");
    }
}
