#ifndef SPORTS_H
#define SPORTS_H

#include <QDialog>
#include <QJsonObject>
#include <QPointer>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>
#include"records.h"
#include"stats.h"


namespace Ui {
class Sports;
}

class Sports : public QDialog
{
    Q_OBJECT

public:
    explicit Sports(QWidget *parent = nullptr);
    ~Sports();
    // 添加公共方法供records访问
    void updateRunningProgress(double distance);
    bool isProgressFull() const;

private slots:
    void on_btnRecord_clicked();
    void on_btnStats_clicked();
    void on_btnReset_clicked();
public slots:
    void refreshData();
private:
    Ui::Sports *ui;
    QJsonObject sportsData;
    QPointer<records> recordWin;
    QPointer<stats> statsWin;

    void loadData();
    void saveData();
    void resetUi();
};

#endif // SPORTS_H
