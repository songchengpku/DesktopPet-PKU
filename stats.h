#ifndef STATS_H
#define STATS_H

#include <QDialog>

namespace Ui {
class stats;
}

class stats : public QDialog
{
    Q_OBJECT

public:
    explicit stats(QWidget *parent = nullptr);
    ~stats();

private:
    Ui::stats *ui;
};

#endif // STATS_H
