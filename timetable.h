#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QDialog>

namespace Ui {
class Timetable;
}

class Timetable : public QDialog
{
    Q_OBJECT

public:
    explicit Timetable(QWidget *parent = nullptr);
    ~Timetable();
    void saveTimetable();
    void loadTimetable();
    bool saved=true;
protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void on_add_clicked();

    void on_dlt_clicked();

    void on_save_clicked();

    void on_tableWidget_cellChanged(int row, int column);

    void on_close_clicked();

    void on_clear_clicked();

private:
    Ui::Timetable *ui;
};

#endif // TIMETABLE_H
