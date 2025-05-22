#ifndef TIMETABLECLOSE_H
#define TIMETABLECLOSE_H

#include <QDialog>

namespace Ui {
class TimetableClose;
}

class TimetableClose : public QDialog
{
    Q_OBJECT

public:
    explicit TimetableClose(QWidget *parent = nullptr);
    ~TimetableClose();

private:
    Ui::TimetableClose *ui;
};

#endif // TIMETABLECLOSE_H
