#include "mainwindowclose.h"
#include "ui_mainwindowclose.h"
#include <QCloseEvent>
#include <QPixmap>

mainwindowclose::mainwindowclose(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::mainwindowclose),
    goodbyeLabel(new QLabel(this))
{
    ui->setupUi(this);

    // 初始化再见标签
    goodbyeLabel->setAlignment(Qt::AlignCenter);

    // 加载再见图片（确保图片路径正确）
    QPixmap goodbyePixmap("resources/goodbye.png");  // 使用资源文件中的图片
    goodbyeLabel->setPixmap(goodbyePixmap);
    goodbyeLabel->setFixedSize(goodbyePixmap.size());
    goodbyeLabel->hide();  // 初始时隐藏
}

mainwindowclose::~mainwindowclose()
{
    delete ui;
}

void mainwindowclose::closeEvent(QCloseEvent *event)
{
    // 阻止默认关闭行为
    event->ignore();

    // 显示再见图片
    goodbyeLabel->move((width() - goodbyeLabel->width()) / 2,
                       (height() - goodbyeLabel->height()) / 2);
    goodbyeLabel->show();

    // 使用QTimer::singleShot延迟1秒后关闭
    QTimer::singleShot(1000, this, [this]() {
        this->accept();  // 关闭对话框
    });
}
