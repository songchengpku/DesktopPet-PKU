// ClothesChanging.cpp
#include "clotheschanging.h"
#include "ui_clotheschanging.h"
#include <QFile>
#include<QDir>
ClothesChanging::ClothesChanging(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::ClothesChanging)
{
    ui->setupUi(this);
    reset();

    ui->suit1->setIcon(QIcon(":/resources/stable.png"));
    ui->suit1->setIconSize(QSize(100, 100));
    ui->suit2->setIcon(QIcon(":/resources/work.png"));
    ui->suit2->setIconSize(QSize(100, 100));
    ui->suit3->setIcon(QIcon(":/resources/sports.png"));
    ui->suit3->setIconSize(QSize(100, 100));
    ui->suit4->setIcon(QIcon(":/resources/study.png"));
    ui->suit4->setIconSize(QSize(100, 100));

    QDir dir1("user_data");
    if (!dir1.exists()) dir1.mkpath(".");

    QString path1 = QDir("user_data").filePath("choice.txt");
    QFile file1(path1);
    if (file1.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in1(&file1);
        choice = in1.readLine().toInt();  // 读取第一行并转换为整数
        file1.close();
    }



    QDir dir2("user_data");
    if (!dir2.exists()) dir2.mkpath(".");

    QString path2 = QDir("user_data").filePath("lock.txt");
    QFile file2(path2);
    if (file2.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream in2(&file2);
        in2>>is2locked>>is3locked>>is4locked;
        file2.close();
    }


    QPixmap image(":/resources/lock.png");
    if (image.isNull())
        qDebug() << "Error: Failed to load image!";


    QGraphicsScene*scene2=new QGraphicsScene(this);
    QGraphicsScene*scene3=new QGraphicsScene(this);
    QGraphicsScene*scene4=new QGraphicsScene(this);

    ui->lock2->setScene(scene2);
    scene2->addPixmap(image);
    ui->lock2->setStyleSheet("background: transparent; border: 0px;");  // 移除背景和边框
    ui->lock2->setVisible(is2locked);

    ui->lock3->setScene(scene3);
    scene3->addPixmap(image);
    ui->lock3->setStyleSheet("background: transparent; border: 0px;");  // 移除背景和边框
    ui->lock3->setVisible(is3locked);

    ui->lock4->setScene(scene4);
    scene4->addPixmap(image);
    ui->lock4->setStyleSheet("background: transparent; border: 0px;");  // 移除背景和边框
    ui->lock4->setVisible(is4locked);

    ui->lock2->fitInView(scene2->itemsBoundingRect(), Qt::KeepAspectRatio);
    ui->lock3->fitInView(scene3->itemsBoundingRect(), Qt::KeepAspectRatio);
    ui->lock4->fitInView(scene4->itemsBoundingRect(), Qt::KeepAspectRatio);
}

ClothesChanging::~ClothesChanging()
{
    QFile file(":/resources/choice.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QTextStream out(&file);
        out << choice;
        file.close();
    }
    delete ui;
}

void ClothesChanging::on_complete_clicked()
{
    if(choice != 0) {
        emit skinChanged(choice);  // 发射信号
    }
    this->accept();  // 改为accept()以便主窗口能获取返回值
}

void ClothesChanging::reset()
{
    ui->suit1->setStyleSheet(defaultStyle);
    ui->suit2->setStyleSheet(defaultStyle);
    ui->suit3->setStyleSheet(defaultStyle);
    ui->suit4->setStyleSheet(defaultStyle);
}

void ClothesChanging::on_suit1_clicked()
{
    reset();
    ui->suit1->setStyleSheet(selectedStyle);
    choice=1;
}

void ClothesChanging::on_suit2_clicked()
{
    reset();
    ui->suit2->setStyleSheet(selectedStyle);
    choice=2;
}

void ClothesChanging::on_suit3_clicked()
{
    reset();
    ui->suit3->setStyleSheet(selectedStyle);
    choice=3;
}

void ClothesChanging::on_suit4_clicked()
{
    reset();
    ui->suit4->setStyleSheet(selectedStyle);
    choice=4;
}


