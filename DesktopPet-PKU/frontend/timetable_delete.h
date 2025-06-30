#ifndef TIMETABLE_DELETE_H
#define TIMETABLE_DELETE_H

#include <QDialog>

namespace Ui {
class Timetable_delete;
}

class Timetable_delete : public QDialog
{
    Q_OBJECT

public:
    explicit Timetable_delete(QWidget *parent = nullptr);
    ~Timetable_delete();

private slots:
    void on_complete_clicked();

private:
    Ui::Timetable_delete *ui;
};

#endif // TIMETABLE_DELETE_H
