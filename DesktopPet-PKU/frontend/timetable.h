#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QDialog>
#include <QStyledItemDelegate>

// 前向声明 Ui 命名空间
namespace Ui {
class Timetable;
}

// 新增 TextEditDelegate 类声明
class TextEditDelegate : public QStyledItemDelegate {
    Q_OBJECT
public:
    explicit TextEditDelegate(QObject *parent = nullptr);
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const override;
    void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                              const QModelIndex &index) const override;
};

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
    void on_save_clicked();
    void on_tableWidget_cellChanged(int row, int column);
    void on_close_clicked();
    void on_clear_clicked();
    void resizeTableToViewport();

private:
    Ui::Timetable *ui;
    TextEditDelegate *textEditDelegate; // 新增委托成员变量
    const int AchievementVI=100;
};

#endif // TIMETABLE_H
