#ifndef RECORDS_H
#define RECORDS_H

#include <QDialog>

namespace Ui {
class records;
}

class records : public QDialog
{
    Q_OBJECT

public:
    explicit records(QWidget *parent = nullptr);
    ~records();

private:
    Ui::records *ui;
};

#endif // RECORDS_H
