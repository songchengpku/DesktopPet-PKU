#ifndef SPORTS_H
#define SPORTS_H

#include <QDialog>
#include <QJsonObject>
#include <QPointer>
#include <QFile>
#include <QJsonDocument>
#include <QMessageBox>

namespace Ui {
class Sports;
}

class Sports : public QDialog
{
    Q_OBJECT

public:
    explicit Sports(QWidget *parent = nullptr);
    ~Sports();

private slots:
    void on_btnRecord_clicked();
    void on_btnStats_clicked();
    void on_btnReset_clicked();

private:
    Ui::Sports *ui;
    QJsonObject sportsData;
    QPointer<QDialog> recordWin;
    QPointer<QDialog> statsWin;

    void loadData();
    void saveData();
    void resetUi();
};

#endif // SPORTS_H
