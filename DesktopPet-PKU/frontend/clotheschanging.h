// ClothesChanging.h
#ifndef CLOTHESCHANGING_H
#define CLOTHESCHANGING_H

#include <QDialog>

namespace Ui {
class ClothesChanging;
}

class ClothesChanging : public QDialog
{
    Q_OBJECT

public:
    explicit ClothesChanging(QWidget *parent = nullptr);
    ~ClothesChanging();

    int getSelectedChoice() const { return choice; }  // 新增获取选择的方法

signals:
    void skinChanged(int choice);  // 新增信号

private slots:
    void on_complete_clicked();
    void on_suit1_clicked();
    void on_suit2_clicked();
    void on_suit3_clicked();
    void on_suit4_clicked();

private:
    Ui::ClothesChanging *ui;
    QString defaultStyle = "QPushButton { border: none; }";
    QString selectedStyle = "QPushButton { border: 5px solid orange; border-radius: 8px}";
    int choice = 0;  // 0表示未选择
    int is2locked=true;
    int is3locked=true;
    int is4locked=true;
    void reset();
};

#endif // CLOTHESCHANGING_H
