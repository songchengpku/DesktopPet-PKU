#ifndef MAINWINDOWCLOSE_H
#define MAINWINDOWCLOSE_H

#include <QDialog>
#include <QCloseEvent>
#include <QLabel>
#include <QTimer>

namespace Ui {
class mainwindowclose;
}

class mainwindowclose : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowclose(QWidget *parent = nullptr);
    ~mainwindowclose();

protected:
    void closeEvent(QCloseEvent *event) override;  // 重写关闭事件处理函数

private:
    Ui::mainwindowclose *ui;
    QLabel *goodbyeLabel;  // 用于显示再见图片的标签
};

#endif // MAINWINDOWCLOSE_H
