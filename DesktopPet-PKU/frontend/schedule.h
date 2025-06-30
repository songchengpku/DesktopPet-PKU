#ifndef SCHEDULE_H
#define SCHEDULE_H

#include <QDialog>
#include <QListWidgetItem>
#include <QJsonArray>
#include<QDir>


namespace Ui {
class Schedule;
}

struct Task {
    QString content;
    int priority;       // 1-3 (1为最高)
    bool completed;
    QDateTime addTime;
};

class Schedule : public QDialog
{
    Q_OBJECT

public:
    explicit Schedule(QWidget *parent = nullptr);
    ~Schedule();
    void loadTasks();
    void saveTasks();
    void updateAchievements(int completedCount);

private slots:
    void onCompleteButtonClicked();
    void on_AddBtn_clicked();
    void on_ClrBtn_clicked();

private:
    Ui::Schedule *ui;
    QJsonArray taskData;
    int totalCompleted = 0;
    int AchievementV=10;//达成成就的值
    void createTaskItem(const Task &task);
    void sortTasks();
    void ensureDataDir();
protected:
    void resizeEvent(QResizeEvent *event) override;
};

#endif // SCHEDULE_H
