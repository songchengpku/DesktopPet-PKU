#ifndef TIMETABLEREMIND_H
#define TIMETABLEREMIND_H

#include <QDialog>

namespace Ui {
class TimetableRemind;
}

class TimetableRemind : public QDialog
{
    Q_OBJECT

public:
    explicit TimetableRemind(QWidget *parent = nullptr);
    ~TimetableRemind();

private:
    Ui::TimetableRemind *ui;
};

#endif // TIMETABLEREMIND_H
