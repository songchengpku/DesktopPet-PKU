#ifndef TIMETABLESAVE_H
#define TIMETABLESAVE_H

#include <QDialog>

namespace Ui {
class TimetableSave;
}

class TimetableSave : public QDialog
{
    Q_OBJECT

public:
    explicit TimetableSave(QWidget *parent = nullptr);
    ~TimetableSave();

private:
    Ui::TimetableSave *ui;
};

#endif // TIMETABLESAVE_H
