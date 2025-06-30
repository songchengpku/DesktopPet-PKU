#include "frontend/mainwindow.h"
#include <QApplication>
#include <QSplashScreen>
#include <QMovie>
#include <QLabel>
#include <QTimer>
#include <QSplashScreen>
#include <QScreen>  // 用于获取屏幕信息
#include <QGuiApplication>  // 包含QGuiApplication

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // 1. 创建并设置启动画面
    QSplashScreen splash;
    splash.setWindowFlags(Qt::WindowStaysOnTopHint | Qt::FramelessWindowHint);
    splash.setAttribute(Qt::WA_TranslucentBackground);

    // 2. 加载GIF动画
    QMovie movie(":/resources/welcome.gif"); // 使用资源文件路径或绝对路径
    QLabel label(&splash);
    label.setMovie(&movie);
    label.setAlignment(Qt::AlignCenter);

    // 3. 获取主屏幕信息并计算居中位置（兼容Qt5/Qt6）
    QScreen *primaryScreen = QGuiApplication::primaryScreen();
    QRect screenGeometry = primaryScreen->geometry();
    int x = (screenGeometry.width() - 250) / 2;  // 250是原窗口宽度
    int y = (screenGeometry.height() - 250) / 2; // 250是原窗口高度

    // 4. 设置窗口和标签位置
    splash.setGeometry(x, y, 250, 250);  // 保持原尺寸
    label.setGeometry(0, 0, 250, 250);   // 标签填满窗口

    // 5. 显示启动画面并开始播放动画
    movie.start();
    splash.show();

    // 6. 创建主窗口（保持原有逻辑）
    MainWindow w;
    w.resize(800, 600);

    // 7. 定时关闭（保持原有2000ms延迟）
    QTimer::singleShot(2000, &splash, [&]() {
        splash.finish(&w);
        w.show();
    });

    return a.exec();
}
