#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "timetable.h"
#include "mainwindowclose.h"
#include "clotheschanging.h"
#include <QMouseEvent>
#include <QLabel>
#include <QMovie>
#include <random>
#include <cmath>
#include <QFile>
#include <QTextStream>
#include <QTimer>
#include "chatdialog.h"

int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> distrib(min, max);
    return distrib(gen);
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_isDragging(false),
    scene(nullptr)  // 初始化scene为nullptr
{
    ui->setupUi(this);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    // 创建定时器
    m_timer = new QTimer(this);
    connect(m_timer, &QTimer::timeout, this, &MainWindow::updateAttributes);
    m_timer->start(1000); // 每秒触发一次，便于精确控制不同属性的下降速度

    // 创建场景并设置透明
    scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::transparent);

    // 设置GraphicsView
    ui->pet->setScene(scene);
    ui->pet->setRenderHint(QPainter::Antialiasing);
    ui->pet->setRenderHint(QPainter::SmoothPixmapTransform);
    ui->pet->setStyleSheet("background: transparent; border: 0px;");
    ui->pet->setFrameShape(QFrame::NoFrame);

    // 安装事件过滤器到pet视图
    ui->pet->viewport()->installEventFilter(this);

    QDir dataDir0("user_data");
    if (!dataDir0.exists()) {
        dataDir0.mkpath(".");
    }

    // 2. 定义 lock.txt 的路径
    QString lockFilePath = dataDir0.filePath("lock.txt");
    QFile lockFile(lockFilePath);

    // 3. 检查 lock.txt 是否存在
    if (!lockFile.exists()) {
        // 如果文件不存在，就创建它并写入默认值
        qDebug() << "lock.txt not found. Creating with default locked state (1 1 1).";

        if (lockFile.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&lockFile);
            // 默认所有皮肤都锁定，用 1 表示锁定，0 表示解锁
            out << "1 1 1";
            lockFile.close();
        } else {
            // 如果因为权限等问题无法创建，打印警告
            qWarning() << "Fatal: Could not create lock.txt!";
        }
    }

    // 加载图片
    QPixmap image1(":/resources/stable.png");
    QPixmap image2(":/resources/work.png");
    QPixmap image3(":/resources/sports.png");
    QPixmap image4(":/resources/study.png");

    // 1. 确保 user_data 文件夹存在
    QDir dataDir("user_data");
    if (!dataDir.exists()) {
        dataDir.mkpath(".");
    }

    // 2. 构建 choice.txt 的路径
    QString path1 = dataDir.filePath("choice.txt");
    QFile file(path1);

    // 3. 检查文件是否存在
    if (!file.exists()) {
        // 文件不存在 -> 创建并写入默认值
        qDebug() << "choice.txt not found. Creating it with default value '1'.";
        if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QTextStream out(&file);
            out << "1"; // 将默认皮肤编号 "1" 写入文件
            file.close();
            choice = 1; // 将变量 'choice' 设置为默认值
        } else {
            // 如果因为某些原因（如权限问题）无法创建文件，也设置一个默认值以防程序出错
            qWarning() << "Could not create choice.txt! Using default value '1'.";
            choice = 1;
        }
    } else {
        // 文件存在 -> 正常读取
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            bool ok;
            int readChoice = in.readLine().toInt(&ok);
            file.close();

            // 检查读取是否成功以及值是否在有效范围内
            if (ok && readChoice >= 1 && readChoice <= 4) {
                choice = readChoice;
            } else {
                // 如果文件内容为空或格式错误，则使用默认值
                qDebug() << "Invalid content in choice.txt. Using default value '1'.";
                choice = 1;
            }
        } else {
            // 如果文件存在但无法读取，也设置一个默认值
            qWarning() << "Could not open choice.txt for reading! Using default value '1'.";
            choice = 1;
        }
    }

    switch (choice) {
    case 1:
        if(!image1.isNull())
        {
            scene->clear();
            scene->addPixmap(image1);
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        }
        break;
    case 2:
        if(!image2.isNull())
        {
            scene->clear();
            scene->addPixmap(image2);
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        }
        break;
    case 3:
        if(!image3.isNull())
        {
            scene->clear();
            scene->addPixmap(image3);
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        }
        break;
    case 4:
        if(!image4.isNull())
        {
            scene->clear();
            scene->addPixmap(image4);
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
        }
        break;
    }

    ui->eating->setIcon(QIcon(":/resources/eating.png"));
    ui->eating->setIconSize(QSize(20, 20));
    ui->bathing->setIcon(QIcon(":/resources/bathing.png"));
    ui->bathing->setIconSize(QSize(20, 20));
    ui->dressing->setIcon(QIcon(":/resources/dressing.png"));
    ui->dressing->setIconSize(QSize(20, 20));

    satiety=randomInt(0,100);
    cleanliness=randomInt(0,100);
    favorability=randomInt(0,100);

    ui->satiety->setValue(satiety);
    ui->cleanliness->setValue(cleanliness);
    ui->favorability->setValue(favorability);

    ui->timetable->setStyleSheet("background-color: #38b8d6;");
    ui->shedule->setStyleSheet("background-color: #e9adf5;");
    ui->sportmanagement->setStyleSheet("background-color: #38d231;");
    ui->chatButton->setStyleSheet("background-color: #FF9A76;");

    ui->satiety->setStyleSheet(
        "QProgressBar {"
        "    border: 1px solid #999999;"          // 边框颜色
        "    border-radius: 5px;"                 // 圆角半径
        "    background: #f0f0f0;"                // 背景色
        "    text-align: center;"                 // 文字居中
        "    color: #333333;"                     // 文字颜色
        "    height: 10px;"                       // 高度
        "}"
        "QProgressBar::chunk {"
        "    background-color: #ff9933;"          // 进度条颜色(蓝色)
        "    border-radius: 5px;"                 // 与边框相同的圆角
        "    width: 1px;"                         // 关键设置：使进度条连续
        "}"
        );
    ui->cleanliness->setStyleSheet(
        "QProgressBar {"
        "    border: 1px solid #999999;"          // 边框颜色
        "    border-radius: 5px;"                 // 圆角半径
        "    background: #f0f0f0;"                // 背景色
        "    text-align: center;"                 // 文字居中
        "    color: #333333;"                     // 文字颜色
        "    height: 10px;"                       // 高度
        "}"
        "QProgressBar::chunk {"
        "    background-color: #66ccff;"          // 进度条颜色(蓝色)
        "    border-radius: 5px;"                 // 与边框相同的圆角
        "    width: 1px;"                         // 关键设置：使进度条连续
        "}"
        );
    ui->favorability->setStyleSheet(
        "QProgressBar {"
        "    border: 1px solid #999999;"          // 边框颜色
        "    border-radius: 5px;"                 // 圆角半径
        "    background: #f0f0f0;"                // 背景色
        "    text-align: center;"                 // 文字居中
        "    color: #333333;"                     // 文字颜色
        "    height: 10px;"                       // 高度
        "}"
        "QProgressBar::chunk {"
        "    background-color: #ff99cc;"          // 进度条颜色(蓝色)
        "    border-radius: 5px;"                 // 与边框相同的圆角
        "    width: 1px;"                         // 关键设置：使进度条连续
        "}"
        );

    ui->satiety->setFixedHeight(15);
    ui->cleanliness->setFixedHeight(15);
    ui->favorability->setFixedHeight(15);
}

MainWindow::~MainWindow()
{

    delete ui;
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    // 处理pet视图中的鼠标事件
    if (obj == ui->pet->viewport()) {
        QMouseEvent *mouseEvent = static_cast<QMouseEvent *>(event);
        switch(event->type()) {
        case QEvent::MouseButtonPress:
            if (mouseEvent->button() == Qt::LeftButton) {
                m_isDragging = true;
                m_dragStartPosition = mouseEvent->globalPos();
                m_windowStartPosition = this->pos();
                return true;  // 事件已处理
            }
            break;
        case QEvent::MouseMove:
            if (m_isDragging && (mouseEvent->buttons() & Qt::LeftButton)) {
                QPoint delta = mouseEvent->globalPos() - m_dragStartPosition;
                this->move(m_windowStartPosition + delta);
                return true;  // 事件已处理
            }
            break;
        case QEvent::MouseButtonRelease:
            if (mouseEvent->button() == Qt::LeftButton) {
                m_isDragging = false;
                return true;  // 事件已处理
            }
            break;
        default:
            break;
        }
    }
    return QMainWindow::eventFilter(obj, event);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
        m_isDragging = true;
        m_dragStartPosition = event->globalPos();
        m_windowStartPosition = this->pos();
        event->accept();
    }
    QWidget::mousePressEvent(event);
}

void MainWindow::mouseMoveEvent(QMouseEvent *event)
{
    if (m_isDragging && (event->buttons() & Qt::LeftButton))
    {
        QPoint delta = event->globalPos() - m_dragStartPosition;
        this->move(m_windowStartPosition + delta);
        event->accept();
    }
    QWidget::mouseMoveEvent(event);
}

void MainWindow::on_timetable_clicked()
{
    Timetable t;
    t.exec();
}

void MainWindow::on_shedule_clicked()
{
    if(!scheduleWin)
    {
        scheduleWin=new Schedule(this);
        scheduleWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    scheduleWin->show();
}

void MainWindow::on_sportmanagement_clicked()
{
    if(!sportsWin)
    {
        sportsWin=new Sports(this);
        sportsWin->setAttribute(Qt::WA_DeleteOnClose);
    }
    sportsWin->show();
}

void MainWindow::on_close_clicked()
{
    mainwindowclose mc;
    if (mc.exec() == mainwindowclose::Accepted)
        this->close();
}

void MainWindow::on_eating_clicked()
{
    //播放吃饭动画
    satiety+=randomInt(12,24);
    if(satiety>100)
        satiety=100;
    cleanliness-=randomInt(6,12);
    if(cleanliness<0)
        cleanliness=0;
    favorability+=randomInt(8,16);
    if(favorability>100)
        favorability=100;
    ui->satiety->setValue(satiety);
    ui->cleanliness->setValue(cleanliness);
    ui->favorability->setValue(favorability);
}

void MainWindow::on_bathing_clicked()
{
    //播放洗澡动画
    cleanliness+=randomInt(12,24);
    if(cleanliness>100)
        cleanliness=100;
    satiety-=randomInt(6,12);
    if(satiety<0)
        satiety=0;
    favorability+=randomInt(8,16);
    if(favorability>100)
        favorability=100;
    ui->satiety->setValue(satiety);
    ui->cleanliness->setValue(cleanliness);
    ui->favorability->setValue(favorability);
}

void MainWindow::on_dressing_clicked()
{
    ClothesChanging cc(this);

    // 连接信号
    connect(&cc, &ClothesChanging::skinChanged, this, [this](int choice) {
        // 根据choice值执行不同操作
        switch(choice) {
        case 1:
            // 执行皮肤1的操作
            scene->clear();
            scene->addPixmap(QPixmap(":/resources/stable.png"));
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
            qDebug() << "已切换到皮肤1";
            break;
        case 2:
            // 执行皮肤2的操作
            scene->clear();
            scene->addPixmap(QPixmap(":/resources/work.png"));
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
            qDebug() << "已切换到皮肤2";
            break;
        case 3:
            // 执行皮肤3的操作
            scene->clear();
            scene->addPixmap(QPixmap(":/resources/sports.png"));
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
            qDebug() << "已切换到皮肤3";
            break;
        case 4:
            // 执行皮肤4的操作
            scene->clear();
            scene->addPixmap(QPixmap(":/resources/study.png"));
            ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
            qDebug() << "已切换到皮肤4";
            break;
        default:
            break;
        }

        // 更新宠物显示
        ui->pet->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    });

    // 显示对话框
    if(cc.exec() == QDialog::Accepted) {
        // 也可以在这里通过cc.getSelectedChoice()获取选择
        qDebug() << "用户选择了:" << cc.getSelectedChoice();
    }
}

// 新增的定时更新属性函数
void MainWindow::updateAttributes()
{
    static int satietyCounter = 0;
    static int favorabilityCounter = 0;
    static int cleanlinessCounter = 0;

    // 每10秒satiety下降1
    if (++satietyCounter >= 11) {
        satietyCounter = 0;
        if (satiety > 0) {
            satiety--;
            ui->satiety->setValue(satiety);
        }
    }

    // 每20秒favorability下降1
    if (++favorabilityCounter >= 18) {
        favorabilityCounter = 0;
        if (favorability > 0) {
            favorability--;
            ui->favorability->setValue(favorability);
        }
    }

    // 每30秒cleanliness下降1
    if (++cleanlinessCounter >= 29) {
        cleanlinessCounter = 0;
        if (cleanliness > 0) {
            cleanliness--;
            ui->cleanliness->setValue(cleanliness);
        }
    }
}

// void MainWindow::closeEvent(QCloseEvent *event)
// {
//     // 1. 强制加载为静态图片
//     QPixmap goodbyePixmap;
//     goodbyePixmap.load(":/resources/goodbye.png");
//     if(goodbyePixmap.isNull()) {
//         event->accept();
//         return;
//     }

//     // 转换为静态图像
//     QImage staticImage = goodbyePixmap.toImage();
//     goodbyePixmap = QPixmap::fromImage(staticImage);

//     // 2. 创建并显示 splash
//     QSplashScreen* splash = new QSplashScreen(goodbyePixmap, Qt::WindowStaysOnTopHint);
//     splash->setAttribute(Qt::WA_DeleteOnClose);
//     splash->show();

//     // 3. 使用QTimer确保顺序关闭
//     QTimer::singleShot(2000, this, [=](){
//         splash->close();
//         QTimer::singleShot(100, this, &QMainWindow::close); // 延迟100ms确保完全关闭
//     });

//     //event->ignore();
// }

void MainWindow::on_chatButton_clicked()
{
    // 创建并显示对话界面
    ChatDialog *chatDialog = new ChatDialog(this);
    chatDialog->setWindowTitle("DeepSeek AI 对话");
    chatDialog->resize(600, 500);
    chatDialog->setAttribute(Qt::WA_DeleteOnClose); // 关闭时自动删除
    chatDialog->show();
}
