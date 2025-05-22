#ifndef MAINWINDOWCLOSE_H
#define MAINWINDOWCLOSE_H

#include <QDialog>

namespace Ui {
class mainwindowclose;
}

class mainwindowclose : public QDialog
{
    Q_OBJECT

public:
    explicit mainwindowclose(QWidget *parent = nullptr);
    ~mainwindowclose();

private:
    Ui::mainwindowclose *ui;
};

#endif // MAINWINDOWCLOSE_H
