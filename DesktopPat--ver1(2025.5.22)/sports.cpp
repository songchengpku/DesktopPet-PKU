#include "sports.h"
#include "ui_sports.h"

#include<QDir>
#include <QSizePolicy>
#include<QVBoxLayout>

Sports::Sports(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Sports)
{
    ui->setupUi(this);
    setWindowTitle("运动记录");
    setMinimumSize(480, 320);  // 设置最小窗口尺寸
    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    resetUi();
    loadData();
}


Sports::~Sports()
{
    delete ui;
}

void Sports::resetUi()
{
    // 清理旧布局
    if(layout()) delete layout();

    // 主垂直布局
    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->setContentsMargins(20, 15, 20, 15);
    mainLayout->setSpacing(25);

    //进度条
    QHBoxLayout *progressLayout = new QHBoxLayout;

    // 左侧进度条组
    QVBoxLayout *progressGroup = new QVBoxLayout;
    progressGroup->addWidget(ui->progressDistance);
    progressGroup->addWidget(ui->progressCount);
    progressGroup->setSpacing(15);

    // 重置按钮
    QPushButton *btnReset = new QPushButton("重置", this);
    btnReset->setFixedSize(80, 80);
    btnReset->setStyleSheet(R"(
        QPushButton {
            border-radius: 40px;
            background: #FF6B6B;
            color: white;
            font-size: 16px;
            border: 2px solid #FF5252;
        }
        QPushButton:hover { background: #FF5252; }
        QPushButton:pressed { background: #FF4040; }
    )");
    connect(btnReset, &QPushButton::clicked, this, &Sports::on_btnReset_clicked);

    // 将进度条组和重置按钮水平排列
    progressLayout->addLayout(progressGroup);
    progressLayout->addSpacing(30);
    progressLayout->addWidget(btnReset, 0, Qt::AlignVCenter); // 垂直居中
    mainLayout->addLayout(progressLayout);

    //底部按钮
    QHBoxLayout *bottomLayout = new QHBoxLayout;
    bottomLayout->setContentsMargins(0, 20, 0, 0); // 顶部留白

    // 记录按钮
    ui->btnRecord->setFixedSize(100, 100);
    ui->btnRecord->setStyleSheet(R"(
        QPushButton {
            border-radius: 50px;
            background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
                stop:0 #6D9BF1, stop:1 #4A76C8);
            color: white;
            font-size: 18px;
            border: none;
            min-width: 100px;
            min-height: 100px;
        }
        QPushButton:hover { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #8AB4F8, stop:1 #6D9BF1); }
        QPushButton:pressed { background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #4A76C8, stop:1 #6D9BF1); }
    )");

    // 统计按钮
    ui->btnStats->setFixedSize(100, 100);
    ui->btnStats->setStyleSheet(ui->btnRecord->styleSheet());

    // 添加弹簧和按钮
    bottomLayout->addStretch();
    bottomLayout->addWidget(ui->btnRecord);
    bottomLayout->addStretch();
    bottomLayout->addWidget(ui->btnStats);
    bottomLayout->addStretch();

    mainLayout->addLayout(bottomLayout);

    ui->progressDistance->setFormat("%v km / 85 km");  // %v代表当前值
    ui->progressCount->setFormat("%v 次 / 10 次");

    QString progressStyle = R"(
    QProgressBar {
        border: 2px solid #3A3A3A;
        border-radius: 8px;
        text-align: center;
        background: #F0F0F0;
        padding: 1px;
        font-size: 14px;
        min-height: 30px;
        color: #333333;
        font-family: "Microsoft YaHei";
    }
    QProgressBar::chunk {
        background: qlineargradient(x1:0, y1:0, x2:1, y2:0,
            stop:0 #6D9BF1, stop:1 #4A76C8);
        border-radius: 6px;
    }
)";
    ui->progressDistance->setStyleSheet(progressStyle);
    ui->progressCount->setStyleSheet(progressStyle);
}

void Sports::loadData()
{
    QDir dir("user_data");
    if (!dir.exists()) dir.mkpath(".");

    QString path = QDir("user_data").filePath("runningTask.json");
    QFile file(path);
    if(file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
        sportsData = doc.object();

        int distance = sportsData["distance"].toInt();
        int count = sportsData["count"].toInt();

        ui->progressDistance->setValue(distance);
        ui->progressCount->setValue(count);

        file.close();
    }
    else {
        // 初始化默认数据
        sportsData["distance"] = 0;
        sportsData["count"] = 0;
        saveData();
    }
}

void Sports::saveData()
{
    QDir dir("user_data");
    if (!dir.exists()) {
        dir.mkpath(".");
    }
    QString path = QDir("user_data").filePath("runningTask.json");
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        QJsonDocument doc(sportsData);
        file.write(doc.toJson());
        file.close();
    }
}

void Sports::on_btnRecord_clicked()
{
    if(!recordWin) {
        recordWin = new QDialog(this);
        recordWin->setWindowTitle("运动记录");
        recordWin->resize(400, 300);
        recordWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    recordWin->show();
}

void Sports::on_btnStats_clicked()
{
    if(!statsWin) {
        statsWin = new QDialog(this);
        statsWin->setWindowTitle("统计信息");
        statsWin->resize(400, 300);
        statsWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    statsWin->show();
}

void Sports::on_btnReset_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认重置",
                                  "确定要重置进度吗？此操作不可恢复！",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        sportsData["distance"] = 0;
        sportsData["count"] = 0;
        saveData();
        ui->progressDistance->setValue(0);
        ui->progressCount->setValue(0);
    }
}
