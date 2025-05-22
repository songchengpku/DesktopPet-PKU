#include "timetable.h"
#include "ui_timetable.h"
#include "timetable_add.h"
#include "timetable_delete.h"
#include "QSettings"
#include "QFile"
#include "QTextStream"
#include "timetablesave.h"
#include "timetableclose.h"
#include "timetableclear.h"
#include "timetableremind.h"
#include "QCloseEvent"

Timetable::Timetable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Timetable)
{
    ui->setupUi(this);
    loadTimetable();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setStyleSheet(
        // 表格主体设置
        "QTableWidget {"
        "    background-color: transparent;"
        "    border: none;"
        "    gridline-color: black;"  // 设置网格线颜色
        "}"

        // 单元格设置
        "QTableWidget::item {"
        "    border: 1px solid black;"  // 单元格边框
        "    background-color: transparent;"  // 单元格背景透明
        "}"

        // 水平表头设置
        "QHeaderView::section:horizontal {"
        "    background-color: transparent;"  // 水平表头背景透明
        "    border: 1px solid black;"       // 水平表头边框
        "    color: black;"                  // 表头文字颜色
        "}"

        // 垂直表头设置
        "QHeaderView::section:vertical {"
        "    background-color: transparent;"  // 垂直表头背景透明
        "    border: 1px solid black;"       // 垂直表头边框
        "    color: black;"                  // 表头文字颜色
        "}"

        // 角落按钮设置（左上角）
        "QTableCornerButton::section {"
        "    background-color: transparent;"  // 角落背景透明
        "    border: 1px solid black;"       // 角落边框
        "}"
        );
}

Timetable::~Timetable()
{
    delete ui;
}

void Timetable::on_add_clicked()
{
    Timetable_add ta;
    ta.exec();
}


void Timetable::on_dlt_clicked()
{
    Timetable_delete td;
    td.exec();
}

// 保存数据
void Timetable::saveTimetable()
{
    QFile file("timetable.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行写入:" << file.errorString();
        return;
    }

    QTextStream out(&file);

    // 写入表头信息(可选)
    out << "# 课程表数据\n";
    out << "# 格式: 行,列,内容\n";

    // 遍历表格
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && !item->text().isEmpty()) {
                // 写入行号,列号和内容,用逗号分隔
                out << row << "," << col << "," << item->text() << "\n";
            }
        }
    }

    file.close();
    saved=true;
}

// 加载数据
void Timetable::loadTimetable()
{
    QFile file("timetable.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行读取:" << file.errorString();
        return;
    }

    QTextStream in(&file);

    // 清空现有表格内容(可选)
    ui->tableWidget->clearContents();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        // 跳过注释行和空行
        if (line.startsWith("#") || line.isEmpty()) {
            continue;
        }

        // 分割行数据
        QStringList parts = line.split(",");
        if (parts.size() >= 3) {
            int row = parts[0].toInt();
            int col = parts[1].toInt();
            QString text = parts[2];

            // 确保行列在有效范围内
            if (row >= 0 && row < ui->tableWidget->rowCount() &&
                col >= 0 && col < ui->tableWidget->columnCount()) {
                ui->tableWidget->setItem(row, col, new QTableWidgetItem(text));
            }
        }
    }

    file.close();
}

void Timetable::on_tableWidget_cellChanged(int row, int column)
{
    ui->tableWidget->resizeRowToContents(row);
    saved=false;
}


void Timetable::on_save_clicked()
{
    TimetableSave ts;
    if(ts.exec()==TimetableSave::Accepted)
        saveTimetable();
}


void Timetable::on_close_clicked()
{
    this->close();
}


void Timetable::on_clear_clicked()
{
    TimetableClear tc;
    if(tc.exec()==TimetableClear::Accepted)
    {
        ui->tableWidget->clearContents();  // 清空所有单元格内容，但保留行列结构
        ui->tableWidget->resizeRowsToContents();
        saveTimetable();
    }
}

void Timetable::closeEvent(QCloseEvent *event)
{
    if(saved)
    {
        TimetableClose tc;
        if(tc.exec() == TimetableClose::Accepted)
            event->accept();
        else
            event->ignore();
    }
    else
    {
        {
            TimetableRemind tr;
            if(tr.exec() == TimetableRemind::Accepted)
                event->accept();
            else
                event->ignore();
        }
    }
}

