#ifndef TIMETABLE_ADD_H
#define TIMETABLE_ADD_H

#include <QDialog>
#include <vector>
#include <utility>

using namespace std;

namespace Ui {
class Timetable_add;
}

class Timetable_add : public QDialog
{
    Q_OBJECT

public:
    explicit Timetable_add(QWidget *parent = nullptr);
    ~Timetable_add();

private slots:
    void on_complete_clicked();

    void on_name_textChanged(const QString &arg1);

    void on_message_textChanged(const QString &arg1);

    void on_weekday1_currentIndexChanged(int index);

    void on_weekday2_currentIndexChanged(int index);

    void on_weekday3_currentIndexChanged(int index);

    void on_weekday4_currentIndexChanged(int index);

    void on_time11_currentIndexChanged(int index);

    void on_time12_currentIndexChanged(int index);

    void on_time21_currentIndexChanged(int index);

    void on_time22_currentIndexChanged(int index);

    void on_time31_currentIndexChanged(int index);

    void on_time32_currentIndexChanged(int index);

    void on_time41_currentIndexChanged(int index);

    void on_time42_currentIndexChanged(int index);

private:
    Ui::Timetable_add *ui;
    QString name;
    QString message;
    vector<int> weekday;
    vector<pair<int,int>> period;
};

#endif // TIMETABLE_ADD_H
