#include "timetable.h"
#include "ui_timetable.h"  // 确保包含这个头文件
#include <QSettings>
#include <QFile>
#include <QTextStream>
#include "timetablesave.h"
#include "timetableclose.h"
#include "timetableclear.h"
#include "timetableremind.h"
#include <QCloseEvent>
#include <QTextEdit>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QDir>

// TextEditDelegate 的实现
TextEditDelegate::TextEditDelegate(QObject *parent)
    : QStyledItemDelegate(parent) {}

QWidget* TextEditDelegate::createEditor(QWidget *parent,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const {
    QTextEdit *editor = new QTextEdit(parent);
    editor->setLineWrapMode(QTextEdit::WidgetWidth);
    editor->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    return editor;
}

void TextEditDelegate::setEditorData(QWidget *editor,
                                     const QModelIndex &index) const {
    QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
    textEdit->setPlainText(index.data(Qt::DisplayRole).toString());
}

void TextEditDelegate::setModelData(QWidget *editor,
                                    QAbstractItemModel *model,
                                    const QModelIndex &index) const {
    QTextEdit *textEdit = static_cast<QTextEdit*>(editor);
    model->setData(index, textEdit->toPlainText(), Qt::DisplayRole);
}

void TextEditDelegate::updateEditorGeometry(QWidget *editor,
                                            const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}

// Timetable 类的实现
Timetable::Timetable(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Timetable)
    , textEditDelegate(new TextEditDelegate(this))
{

    ui->setupUi(this);

    // 设置委托
    ui->tableWidget->setItemDelegate(textEditDelegate);
    ui->tableWidget->setEditTriggers(QAbstractItemView::DoubleClicked |
                                     QAbstractItemView::EditKeyPressed);

    loadTimetable();
    ui->tableWidget->resizeRowsToContents();
    ui->tableWidget->setStyleSheet(
        // 表格整体样式
        "QTableWidget {"
        "   border: 1px solid #D3D3D3;"
        "   border-radius: 10px;"       // 外边框圆角
        "   padding: 2px;"
        "   background-color: white;"
        "   gridline-color: transparent;"  // 隐藏默认网格线
        "}"

        // 表头样式
        "QHeaderView::section {"
        "   background-color: #F5F5F5;"
        "   border: 1px solid #D3D3D3;"
        "   border-radius: 6px;"        // 表头单元格圆角
        "   padding: 4px;"
        "   margin: 1px;"              // 单元格间距
        "}"

        // 表格单元格样式
        "QTableWidget::item {"
        "   border: 1px solid #F0F0F0;"
        "   border-radius: 5px;"       // 单元格圆角
        "   padding: 5px;"
        "   margin: 1px;"
        "}"

        // 选中单元格样式
        "QTableWidget::item:selected {"
        "   background-color: #D8E6F3;"
        "   border: 1px solid #0843ff;"
        "   border-radius: 5px;"
        "}"

        // 角落按钮样式
        "QTableCornerButton::section {"
        "   border: 1px solid #D3D3D3;"
        "   border-top-left-radius: 10px;"  // 左上角圆角匹配表格
        "   background-color: #F5F5F5;"
        "}"
        "QTableWidget {"
        "    background: transparent;"
        "}"
        "QTableWidget::item {"
        "    background: transparent;"
        "}"
        "QHeaderView::horizontal {"
        "    background: transparent;"
        "}"
        "QHeaderView::vertical {"
        "    background: transparent;"
        "}"
        );

    resizeTableToViewport();
    ui->tableWidget->setWordWrap(true);

    QLabel* background = new QLabel(this);
    QPixmap bg(":/resources/background.png");
    background->setPixmap(bg);

    background->setScaledContents(true); // 自动缩放图片
    background->setGeometry(rect());    // 填充整个窗口

    // 确保背景在最底层
    background->lower();
}

// ... 其他成员函数保持不变 ...

Timetable::~Timetable()
{
    delete ui;
}

// 保存数据（支持换行）
void Timetable::saveTimetable()
{
    QDir dir("user_data");
    if (!dir.exists()) dir.mkpath(".");

    QString path = QDir("user_data").filePath("timetable.txt");
    QFile file(path);

    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行写入:" << file.errorString();
        return;
    }


    QTextStream out(&file);  // 确保使用UTF-8编码

    // 写入表头信息
    out << "# 课程表数据（支持换行）\n";
    out << "# 格式: 行,列,内容（换行符替换为\\n）\n";

    int completedCount=0;

    // 遍历表格
    for (int row = 0; row < ui->tableWidget->rowCount(); ++row) {
        for (int col = 0; col < ui->tableWidget->columnCount(); ++col) {
            QTableWidgetItem* item = ui->tableWidget->item(row, col);
            if (item && !item->text().isEmpty()) {
                // 替换换行符为特殊标记
                QString text = item->text();
                text.replace("\n", "\\n");  // 将实际换行符转换为\n字符串

                // 写入行号,列号和内容
                out << row << "," << col << "," << text << "\n";

                completedCount++;
            }
        }
    }

    if(completedCount >= AchievementVI) {
        QMessageBox::information(
            this,
            "恭喜！",
            "恭喜添加20个课程，解锁皮肤「学院风」！"
            );
        // 处理lock.txt文件
        QDir dir("user_data");
        if (!dir.exists()) dir.mkpath(".");

        QString path = QDir("user_data").filePath("lock.txt");
        QFile lockFile(path);

        int first = 1, second = 1, third = 1;
        bool fileExists = false;

        // 尝试读取现有文件
        if(lockFile.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&lockFile);
            in >> first >> second >> third;
            lockFile.close();
            fileExists = true;
        }

        // 修改第一个值为0
        third = 0;

        // 写回文件
        if(lockFile.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream out(&lockFile);
            out << first << " " << second << " " << third;
            lockFile.close();

            QString status = fileExists ? "已更新" : "已创建";
            qDebug() << "lock.txt文件" << status;
        } else {
            qWarning() << "无法写入lock.txt文件";
        }
    }

    file.close();
    saved = true;
}

// 加载数据（支持换行）
void Timetable::loadTimetable()
{
    QDir dir("user_data");
    if (!dir.exists()) dir.mkpath(".");

    QString path = QDir("user_data").filePath("timetable.txt");
    QFile file(path);


    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "无法打开文件进行读取:" << file.errorString();
        return;
    }

    QTextStream in(&file); // 确保使用UTF-8编码

    // 清空现有表格内容
    ui->tableWidget->clearContents();

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();

        // 跳过注释行和空行
        if (line.startsWith("#") || line.isEmpty()) {
            continue;
        }

        // 分割行数据（考虑内容中可能包含逗号的情况）
        int firstComma = line.indexOf(',');
        int secondComma = line.indexOf(',', firstComma + 1);

        if (firstComma != -1 && secondComma != -1) {
            int row = line.left(firstComma).toInt();
            int col = line.mid(firstComma + 1, secondComma - firstComma - 1).toInt();
            QString text = line.mid(secondComma + 1);

            // 还原换行符
            text.replace("\\n", "\n");

            // 确保行列在有效范围内
            if (row >= 0 && row < ui->tableWidget->rowCount() &&
                col >= 0 && col < ui->tableWidget->columnCount()) {
                QTableWidgetItem* item = new QTableWidgetItem(text);
                item->setTextAlignment(Qt::AlignCenter);  // 设置对齐方式
                ui->tableWidget->setItem(row, col, item);
            }
        }
    }

    file.close();
    ui->tableWidget->resizeRowsToContents();  // 加载后调整行高
}

void Timetable::on_tableWidget_cellChanged(int row, int column)
{
    QTableWidgetItem* item = ui->tableWidget->item(row, column);
    if (item) {
        item->setTextAlignment(Qt::AlignCenter);  // 确保新内容居中
    }
    ui->tableWidget->resizeRowToContents(row);
    resizeTableToViewport();
    saved = false;
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
        resizeTableToViewport();
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

// 根据可见内容调整高度
void Timetable::resizeTableToViewport()
{
    ui->tableWidget->resizeRowsToContents();
    int height = ui->tableWidget->horizontalHeader()->height();
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i) {
        height += ui->tableWidget->rowHeight(i);
    }
    ui->tableWidget->setFixedHeight(height + ui->tableWidget->frameWidth() * 2);
}
