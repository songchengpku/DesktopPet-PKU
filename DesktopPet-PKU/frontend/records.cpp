#include "frontend/records.h"
#include "frontend/sports.h"
#include "ui_records.h"
#include <QMessageBox>
#include <QDate>
#include <QIntValidator>
#include<QDoubleValidator>


records::records(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::records)
{
    ui->setupUi(this);

    // 设置全局样式
    this->setStyleSheet(R"(
        /*  主窗口样式*/
        QDialog {
            background: qlineargradient(x1:0, y1:0, x2:1, y2:1,
                stop:0 #a1c4fd, stop:1 #c2e9fb);
            font-family: 'Segoe UI', Arial, sans-serif;
        }

        /*  运动卡片样式  */
        QFrame {
            background-color: rgba(255, 255, 255, 0.8);
            border-radius: 12px;
            border: 1px solid #e0e4eb;
            padding: 12px;
            box-shadow: 0 2px 8px rgba(0, 0, 0, 0.05);
        }

        /* 跑步卡片 */
        #runframe {
            background-color: rgba(232, 245, 233, 0.9); /* 浅绿色 */
        }

        /* 羽毛球卡片 */
        #badmintonframe {
            background-color: rgba(227, 242, 253, 0.9); /* 浅蓝色 */
        }

        /* 乒乓球卡片 */
        #pingpongframe {
            background-color: rgba(255, 243, 224, 0.9); /* 浅橙色 */
        }

        /* 网球卡片 */
        #tennisframe {
            background-color: rgba(245, 230, 255, 0.9); /* 浅紫色 */
        }

        /* 篮球卡片 */
        #basketballframe {
            background-color: rgba(255, 235, 238, 0.9); /* 浅红色 */
        }

        /* 排球卡片 */
        #volleyballframe {
            background-color: rgba(224, 247, 250, 0.9); /* 浅青色 */
        }

        /* 足球卡片 */
        #footballframe {
            background-color: rgba(230, 245, 230, 0.9); /* 浅绿色 */
        }

        /* 骑行卡片 */
        #ridingframe {
            background-color: rgba(243, 229, 245, 0.9); /* 浅紫色 */
        }

        /* 登山卡片 */
        #climbingframe {
            background-color: rgba(255, 224, 224, 0.9); /* 浅粉色 */
        }

        /* 游泳卡片 */
        #swimmingframe {
            background-color: rgba(224, 247, 250, 0.9); /* 浅青色 */
        }


        /*  标题标签样式  */
        QLabel[objectName^="runLabel"] {
            font-size: 16px;
            font-weight: 500;
            color: #4a5568;
            min-width: 80px;
        }

        /*  输入框样式  */
        QLineEdit {
            background: white;
            border: 1px solid #d0d7e0;
            border-radius: 8px;
            padding: 8px;
            font-size: 14px;
            color: #4a5568;
            selection-background-color: #c5d9f1;
        }

        QLineEdit:focus {
            border: 1px solid #a0aec0;
            background-color: #f8fafc;
        }

        /*  单位标签样式  */
        QLabel:not([objectName^="runLabel"]) {
            color: #718096;
            font-size: 13px;
        }

        /*  卡路里标签样式  */
        QLabel[objectName$="CalLabel"] {
            color: #4c8bf5;
            font-weight: 500;
            font-size: 13px;
            margin-top: 5px;
            height: 20px; /* 固定高度 */
            min-height: 20px; /* 确保最小高度 */
        }
        /*  滚动条样式  */
        QScrollBar:vertical {
            background: rgba(200, 200, 200, 50);
            width: 10px;
            border-radius: 5px;
        }

        QScrollBar::handle:vertical {
            background: rgba(150, 150, 150, 100);
            min-height: 30px;
            border-radius: 5px;
        }

        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0px;
        }

        /* 标题样式 */
        #label_title {
            font-size: 24px;
            font-weight: 600;
            color: #4a5568;
            padding: 10px 0;
            text-align: center;
        }

        /* 分组框样式 */
        QGroupBox {
            border: 1px solid #e2e8f0;
            border-radius: 10px;
            margin-top: 16px;
            padding-top: 20px;
            font-weight: 500;
            color: #4a5568;
            background-color: rgba(255, 255, 255, 0.7);
        }
        /* 按钮样式 */
            QPushButton {
                border: none;
                border-radius: 8px;
                padding: 8px 16px;
                font-size: 14px;
                min-width: 60px;
            }
        // /* 跑步按钮 */
        // #runButton { background-color: #48bb78; } /* 绿色 */
        // #runButton:hover { background-color: #38a169; }

        // /* 羽毛球按钮 */
        // #badmintonBtn { background-color: #4299e1; } /* 蓝色 */
        // #badmintonBtn:hover { background-color: #3182ce; }

        // /* 乒乓球按钮 */
        // #pingpongBtn { background-color: #ed8936; } /* 橙色 */
        // #pingpongBtn:hover { background-color: #dd6b20; }

        // /* 网球按钮 */
        // #tennisBtn { background-color: #9f7aea; } /* 紫色 */
        // #tennisBtn:hover { background-color: #805ad5; }

        // /* 篮球按钮 */
        // #basketballBtn { background-color: #f56565; } /* 红色 */
        // #basketballBtn:hover { background-color: #e53e3e; }

        // /* 其他运动按钮 */
        // #volleyballBtn { background-color: #0bc5ea; } /* 青色 */
        // #volleyballBtn:hover { background-color: #00a3c4; }

        // #footballBtn { background-color: #38a169; } /* 深绿 */
        // #footballBtn:hover { background-color: #2f855a; }

        // #ridingBtn { background-color: #b779e2; } /* 浅紫 */
        // #ridingBtn:hover { background-color: #9f7aea; }

        // #climbingBtn { background-color: #ed64a6; } /* 粉色 */
        // #climbingBtn:hover { background-color: #d53f8c; }

        // #swimmingBtn { background-color: #4fd1c5; } /* 青绿 */
        // #swimmingBtn:hover { background-color: #38b2ac; }

        QPushButton:hover {
            background-color: #3a7be0;
        }

        QPushButton:pressed {
            background-color: #2c6bd8;
        }

        QGroupBox::title {
            subcontrol-origin: margin;
            subcontrol-position: top center;
            padding: 0 10px;
            background-color: transparent;
        }
    )");
    // 为所有输入框设置验证器
    ui->runDisEdit->setValidator(new QDoubleValidator(0, 50, 2, this));//跑步里程
    ui->runTimeEdit->setValidator(new QIntValidator(0, 600, this));    // 跑步时间
    ui->badmintonTime->setValidator(new QIntValidator(0, 600, this));  // 羽毛球时间
    ui->pingpongTime->setValidator(new QIntValidator(0, 600, this));   // 乒乓球时间
    ui->tennisTime->setValidator(new QIntValidator(0, 600, this));
    ui->basketballTime->setValidator(new QIntValidator(0, 600, this));
    ui->volleyballTime->setValidator(new QIntValidator(0, 600, this));
    ui->footballTime->setValidator(new QIntValidator(0, 600, this));
    ui->ridingTime->setValidator(new QIntValidator(0, 600, this));
    ui->climbingTime->setValidator(new QIntValidator(0, 600, this));
    ui->swimmingTime->setValidator(new QIntValidator(0, 600, this));
    // 连接信号槽实现实时卡路里计算
    connect(ui->runTimeEdit, &QLineEdit::textChanged, this, &records::calculateRunningCalories);
    connect(ui->runDisEdit, &QLineEdit::textChanged, this, &records::calculateRunningCalories);
    connect(ui->badmintonTime, &QLineEdit::textChanged, this, &records::calculateBadmintonCalories);
    connect(ui->pingpongTime, &QLineEdit::textChanged, this, &records::calculatePingpongCalories);
    connect(ui->tennisTime, &QLineEdit::textChanged, this, &records::calculateTennisCalories);
    connect(ui->basketballTime, &QLineEdit::textChanged, this, &records::calculateBasketballCalories);
    connect(ui->volleyballTime, &QLineEdit::textChanged, this, &records::calculateVolleyballCalories);
    connect(ui->footballTime, &QLineEdit::textChanged, this, &records::calculateFootballCalories);
    connect(ui->ridingTime, &QLineEdit::textChanged, this, &records::calculateRidingCalories);
    connect(ui->climbingTime, &QLineEdit::textChanged, this, &records::calculateClimbingCalories);
    connect(ui->swimmingTime, &QLineEdit::textChanged, this, &records::calculateSwimmingCalories);
}

records::~records()
{
    delete ui;
}

void records::calculateRunningCalories() {
    QString timeStr = ui->runTimeEdit->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::Running_cal;
        ui->runCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->runCalLabel->setText("预计消耗: 0 卡路里");
    }
}

// 实时计算羽毛球卡路里
void records::calculateBadmintonCalories() {
    QString timeStr = ui->badmintonTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::badminton_cal;
        ui->badmintonCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->badmintonCalLabel->setText("预计消耗: 0 卡路里");
    }
}

void records::calculatePingpongCalories() {
    QString timeStr = ui->pingpongTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::pingpong_cal;
        ui->pingpongCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->pingpongCalLabel->setText("预计消耗: 0 卡路里");
    }
}

void records::calculateTennisCalories() {
    QString timeStr = ui->tennisTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::tennis_cal;
        ui->tennisCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->tennisCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateBasketballCalories() {
    QString timeStr = ui->basketballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::basketball_cal;
        ui->basketballCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->basketballCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateVolleyballCalories() {
    QString timeStr = ui->volleyballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::volleyball_cal;
        ui->volleyCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->volleyCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateFootballCalories() {
    QString timeStr = ui->footballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::football_cal;
        ui->footbalCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->footbalCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateRidingCalories() {
    QString timeStr = ui->ridingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::Riding_cal;
        ui->ridingCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->ridingCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateClimbingCalories() {
    QString timeStr = ui->climbingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::climbing_cal;
        ui->climbingCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->climbingCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::calculateSwimmingCalories() {
    QString timeStr = ui->swimmingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);
    if (ok && duration > 0) {
        double calories = duration * sports::SportRecord::swimming_cal;
        ui->swimmingCalLabel->setText(QString("预计消耗: %1 卡路里").arg(calories, 0, 'f', 1));
    } else {
        ui->swimmingCalLabel->setText("预计消耗: 0 卡路里");
    }
}
void records::on_runButton_clicked()
{
    // 获取跑步时间和距离
    QString timeStr = ui->runTimeEdit->text();
    QString disStr = ui->runDisEdit->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的跑步时间");
        return;
    }

    double distance = disStr.toDouble(&ok);
    if (!ok || distance < 0) {
        QMessageBox::warning(this, "错误", "请输入有效的跑步距离");
        return;
    }
    // 添加跑步记录
    ui->runTimeEdit->clear();
    ui->runDisEdit->clear();
    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addRunningRecord(date, duration, distance);
    QMessageBox::information(this, "成功", "跑步记录已添加！");

    // 1. 创建透明窗口容器
    QWidget* gifContainer = new QWidget(nullptr, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    gifContainer->setAttribute(Qt::WA_TranslucentBackground);
    gifContainer->setFixedSize(400, 367); // 设置固定尺寸

    // 2. 设置 GIF 动画
    QMovie* movie = new QMovie(":/resources/running.gif", QByteArray(), gifContainer);
    QLabel* gifLabel = new QLabel(gifContainer);
    gifLabel->setMovie(movie);
    gifLabel->setAlignment(Qt::AlignCenter);
    gifLabel->setGeometry(0, 0, 400, 367); // 填充容器

    // 3. 播放完成后自动关闭
    QObject::connect(movie, &QMovie::finished, [=]() {
        movie->deleteLater();
        gifContainer->close();
        gifContainer->deleteLater();
    });

    // 4. 开始播放并显示
    movie->start();
    gifContainer->show();

    // 5. 安全超时关闭（防止GIF损坏无限循环）
    QTimer::singleShot(3000, [=]() { // 最多3秒超时
        if (movie->state() == QMovie::Running) {
            movie->stop();
            gifContainer->close();
            gifContainer->deleteLater();
        }
    });

    // 如果跑步里程大于2km，更新进度
    if (distance > 2.0) {
        Sports msports;
        msports.updateRunningProgress(distance);
    }

}


void records::on_badmintonBtn_clicked()
{
    QString timeStr = ui->badmintonTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的羽毛球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addBadmintonRecord(date, duration);

    ui->badmintonTime->clear();
    QMessageBox::information(this, "成功", "羽毛球记录已添加！");

    // 1. 创建透明窗口容器
    QWidget* gifContainer = new QWidget(nullptr, Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    gifContainer->setAttribute(Qt::WA_TranslucentBackground);
    gifContainer->setFixedSize(400, 400); // 设置固定尺寸

    // 2. 设置 GIF 动画
    QMovie* movie = new QMovie(":/resources/badminton.gif", QByteArray(), gifContainer);
    QLabel* gifLabel = new QLabel(gifContainer);
    gifLabel->setMovie(movie);
    gifLabel->setAlignment(Qt::AlignCenter);
    gifLabel->setGeometry(0, 0, 400, 400); // 填充容器

    // 3. 播放完成后自动关闭
    QObject::connect(movie, &QMovie::finished, [=]() {
        movie->deleteLater();
        gifContainer->close();
        gifContainer->deleteLater();
    });

    // 4. 开始播放并显示
    movie->start();
    gifContainer->show();

    // 5. 安全超时关闭（防止GIF损坏无限循环）
    QTimer::singleShot(2000, [=]() { // 最多2秒超时
        if (movie->state() == QMovie::Running) {
            movie->stop();
            gifContainer->close();
            gifContainer->deleteLater();
        }
    });

}


void records::on_pingpongBtn_clicked()
{
    QString timeStr = ui->pingpongTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的乒乓球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addPingpongRecord(date, duration);

    ui->pingpongTime->clear();
    QMessageBox::information(this, "成功", "乒乓球记录已添加！");
}


void records::on_tennisBtn_clicked()
{
    QString timeStr = ui->tennisTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的网球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addTennisRecord(date, duration);

    ui->tennisTime->clear();
    QMessageBox::information(this, "成功", "网球记录已添加！");
}


void records::on_basketballBtn_clicked()
{
    QString timeStr = ui->basketballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的篮球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addBasketballRecord(date, duration);

    ui->basketballTime->clear();
    QMessageBox::information(this, "成功", "篮球记录已添加！");
}


void records::on_volleyballBtn_clicked()
{
    QString timeStr = ui->volleyballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的排球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addVolleyballRecord(date, duration);

    ui->volleyballTime->clear();
    QMessageBox::information(this, "成功", "排球记录已添加！");
}


void records::on_footballBtn_clicked()
{
    QString timeStr = ui->footballTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的足球时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addFootballRecord(date, duration);

    ui->footballTime->clear();
    QMessageBox::information(this, "成功", "足球记录已添加！");
}


void records::on_ridingBtn_clicked()
{
    QString timeStr = ui->ridingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的骑行时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addRidingRecord(date, duration);

    ui->ridingTime->clear();
    QMessageBox::information(this, "成功", "骑行记录已添加！");
}


void records::on_climbingBtn_clicked()
{
    QString timeStr = ui->climbingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的登山时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addClimbingRecord(date, duration);

    ui->climbingTime->clear();
    QMessageBox::information(this, "成功", "登山记录已添加！");
}


void records::on_swimmingBtn_clicked()
{
    QString timeStr = ui->swimmingTime->text();
    bool ok;
    int duration = timeStr.toInt(&ok);

    if (!ok || duration <= 0) {
        QMessageBox::warning(this, "错误", "请输入有效的游泳时间");
        return;
    }

    QString date = QDate::currentDate().toString("yyyy-MM-dd");
    m_sports->sptRec.addSwimmingRecord(date, duration);

    ui->swimmingTime->clear();
    QMessageBox::information(this, "成功", "游泳记录已添加！");

}

