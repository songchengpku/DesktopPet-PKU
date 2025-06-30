#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsView>

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

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_timetable_clicked();

    void on_close_clicked();

    void on_eating_clicked();

    void on_bathing_clicked();

    void on_dressing_clicked();

    void on_shedule_clicked();

    void on_sportmanagement_clicked();

    void updateAttributes();

    void on_chatButton_clicked(); // 处理聊天按钮点击


private:
    Ui::MainWindow *ui;
    QPointer<Schedule> scheduleWin;
    QPointer<Sports> sportsWin;

protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    bool eventFilter(QObject *obj, QEvent *event) override;  // 新增事件过滤器
    //void closeEvent(QCloseEvent *event) override;
private:
    QPoint m_dragStartPosition;
    QPoint m_windowStartPosition;
    bool m_isDragging;
    QGraphicsScene *scene;
    QTimer *m_timer;
    int satiety=0;
    int cleanliness=0;
    int favorability=0;
    int choice=1;
};
#endif // MAINWINDOW_H
