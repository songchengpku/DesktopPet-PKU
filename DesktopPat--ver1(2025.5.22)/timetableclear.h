#ifndef TIMETABLECLEAR_H
#define TIMETABLECLEAR_H

#include <QDialog>

namespace Ui {
class TimetableClear;
}

class TimetableClear : public QDialog
{
    Q_OBJECT

public:
    explicit TimetableClear(QWidget *parent = nullptr);
    ~TimetableClear();

private:
    Ui::TimetableClear *ui;
};

#endif // TIMETABLECLEAR_H
