#include "schedule.h"
#include "ui_schedule.h"

#include <QPushButton>
#include <QFile>
#include <QJsonDocument>
#include <QJsonObject>
#include <QHBoxLayout>
#include <QDateTime>
#include <QInputDialog>
#include <QMessageBox>
#include<QVBoxLayout>
#include<QLabel>
#include<QComboBox>
#include<QFormLayout>
#include<algorithm>
#include <QPropertyAnimation>
#include <QGraphicsOpacityEffect>

Schedule::Schedule(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Schedule)
{
    ui->setupUi(this);
    ensureDataDir();
    ui->listWidget->setSizePolicy(
        QSizePolicy::Expanding,  // 水平策略
        QSizePolicy::Expanding   // 垂直策略
        );
    ui->listWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->listWidget->setMinimumWidth(300);
    ui->listWidget->setStyleSheet(
        "QListWidget {"
        "   background: #f5f5f5;"
        "   border: none;"
        "}"
        "QListWidget::Item {"
        "   border-bottom: 1px solid #ddd;"
        "}"
        "QLabel {"
        "   color: #333;"
        "   font: 14px 'Microsoft YaHei';"
        "}"
        );
    setMinimumSize(250, 400);
    loadTasks();
}

Schedule::~Schedule()
{
    delete ui;
}

void Schedule::ensureDataDir()
{
    QDir dir("user_data");
    if (!dir.exists()) {
        dir.mkpath(".");
    }
}
void Schedule::resizeEvent(QResizeEvent *event)
{
    QDialog::resizeEvent(event);
    // 动态调整列表项高度
    const int itemHeight = qMax(40, height()/20);
    for(int i=0; i<ui->listWidget->count(); ++i){
        QListWidgetItem *item = ui->listWidget->item(i);
        item->setSizeHint(QSize(item->sizeHint().width(), itemHeight));
    }
    QFont font = ui->listWidget->font();
    font.setPixelSize(qMax(12, height()/50));
    ui->listWidget->setFont(font);
}

void Schedule::loadTasks()
{
    QString path = QDir("user_data").filePath("tasks.json");
    QFile file(path);

    if(file.open(QIODevice::ReadOnly)) {
        QJsonDocument doc = QJsonDocument::fromJson(file.readAll());

        if(doc.isArray()) {
            taskData = doc.array();
            totalCompleted = std::count_if(taskData.begin(), taskData.end(),
                                           [](const QJsonValue& v) { return v["completed"].toBool(); });
        }
        else if(doc.isObject()) {
            QJsonObject root = doc.object();
            taskData = root["tasks"].toArray();
            totalCompleted = root["total_completed"].toInt();
        }
        file.close();
    }
    sortTasks();
    ui->listWidget->clear();
    ui->listWidget->setUniformItemSizes(true);
    for(const QJsonValue &value : taskData) {
        Task task {
            value["content"].toString(),
            value["priority"].toInt(),
            value["completed"].toBool(),
            QDateTime::fromString(value["time"].toString(), Qt::ISODate)
        };
        createTaskItem(task);
    }
    QGraphicsOpacityEffect *effect = new QGraphicsOpacityEffect(ui->listWidget);
    ui->listWidget->setGraphicsEffect(effect);

    QPropertyAnimation *anim = new QPropertyAnimation(effect, "opacity");
    anim->setDuration(300);
    anim->setStartValue(0);
    anim->setEndValue(1);
    anim->start(QAbstractAnimation::DeleteWhenStopped);
}

void Schedule::saveTasks()
{
    QString path = QDir("user_data").filePath("tasks.json");
    QFile file(path);
    if(file.open(QIODevice::WriteOnly)) {
        QJsonObject root;
        root["tasks"] = taskData;
        root["total_completed"] = totalCompleted;
        QJsonDocument doc(root);
        file.write(doc.toJson());
        file.close();
    }
}

void Schedule::createTaskItem(const Task &task)
{
    QListWidgetItem *item = new QListWidgetItem();
    QWidget *widget = new QWidget();
    QHBoxLayout *layout = new QHBoxLayout(widget);
    layout->setContentsMargins(12, 6, 12, 6);
    layout->setSpacing(8);
    // 优先级标签
    QLabel *priorityLabel = new QLabel(QString::number(task.priority));
    priorityLabel->setFixedWidth(30);
    priorityLabel->setAlignment(Qt::AlignCenter);
    layout->addWidget(priorityLabel);
    // 任务内容标签 - 使用样式表实现截断
    QLabel *contentLabel = new QLabel(task.content);
    contentLabel->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
    contentLabel->setStyleSheet(
        "QLabel {"
        "   text-overflow: ellipsis;"
        "   white-space: nowrap;"
        "}"
        );
    if(task.completed) {
        contentLabel->setStyleSheet(
            "QLabel {"
            "   color: gray;"
            "   text-decoration: line-through;"
            "   text-overflow: ellipsis;"
            "   white-space: nowrap;"
            "}"
            );
    }
    layout->addWidget(contentLabel, 1);
    // 仅在未完成任务显示按钮（最右侧）
    if(!task.completed) {
        QPushButton *completeBtn = new QPushButton("✓");
        completeBtn->setFixedSize(24, 24);
        completeBtn->setStyleSheet(
            "QPushButton { background: #4CAF50; color: white; border-radius: 12px; }"
            "QPushButton:hover { background: #45a049; }"
            );
        connect(completeBtn, &QPushButton::clicked, this, &Schedule::onCompleteButtonClicked);
        layout->addWidget(completeBtn);
    }
    item->setSizeHint(QSize(widget->sizeHint().width(), 40));
    ui->listWidget->addItem(item);
    ui->listWidget->setItemWidget(item, widget);
}

void Schedule::onCompleteButtonClicked()
{
    QPushButton *btn = qobject_cast<QPushButton*>(sender());
    for(int i = 0; i < ui->listWidget->count(); ++i) {
        if(ui->listWidget->itemWidget(ui->listWidget->item(i))->layout()->indexOf(btn) != -1) {
            QJsonObject obj = taskData[i].toObject();
            obj["completed"] = true;
            taskData[i] = obj;
            totalCompleted++;
            saveTasks();
            updateAchievements(totalCompleted);
            loadTasks();
            break;
        }
    }
}


void Schedule::updateAchievements(int completedCount)
{
    if(completedCount == AchievementV) {
        QMessageBox::information(this, "成就解锁", "恭喜完成10个任务！获得'卷王'称号！");
    }
}

void Schedule::sortTasks()
{
    // 转换为QList<QJsonObject>以支持swap操作
    QList<QJsonObject> taskList;
    for (const QJsonValue &value : taskData) {
        taskList.append(value.toObject());
    }
    // 使用标准排序算法
    std::sort(taskList.begin(), taskList.end(),
              [](const QJsonObject &a, const QJsonObject &b) {
                  bool aCompleted = a["completed"].toBool();
                  bool bCompleted = b["completed"].toBool();

                  if (aCompleted == bCompleted) {
                      return a["priority"].toInt() < b["priority"].toInt();
                  }
                  return aCompleted < bCompleted; // 未完成的任务在前
              });
    // 重建JSON数组
    taskData = QJsonArray();
    for (const QJsonObject &obj : taskList) {
        taskData.append(obj);
    }
}

void Schedule::on_AddBtn_clicked()
{
    // 创建对话框
    QDialog dialog(this);
    dialog.setWindowTitle("添加任务");
    dialog.resize(300, 150);
    // 创建控件
    QLineEdit *contentEdit = new QLineEdit(&dialog);
    QComboBox *priorityCombo = new QComboBox(&dialog);
    QDialogButtonBox *buttons = new QDialogButtonBox(
        QDialogButtonBox::Ok | QDialogButtonBox::Cancel,
        &dialog
        );
    QPushButton *okButton = buttons->button(QDialogButtonBox::Ok);
    QPushButton *cancelButton = buttons->button(QDialogButtonBox::Cancel);
    okButton->setText("确定");
    cancelButton->setText("取消");
    // 配置控件
    priorityCombo->addItems({"紧急 (1)", "重要 (2)", "一般 (3)"});
    contentEdit->setPlaceholderText("输入任务内容...");
    // 创建布局
    QFormLayout *layout = new QFormLayout(&dialog);
    layout->addRow("任务内容:", contentEdit);
    layout->addRow("优先级:", priorityCombo);
    layout->addWidget(buttons);
    // 信号连接
    QObject::connect(buttons, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
    QObject::connect(buttons, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

    // 显示对话框
    if(dialog.exec() == QDialog::Accepted)
    {
        const QString content = contentEdit->text().trimmed();
        const int priority = priorityCombo->currentIndex() + 1;

        if(!content.isEmpty()) {
            QJsonObject task;
            task["content"] = content;
            task["priority"] = priority;
            task["completed"] = false;
            task["time"] = QDateTime::currentDateTime().toString(Qt::ISODate);

            taskData.append(task);
            saveTasks();
            loadTasks();
        }
        else {
            QMessageBox::warning(this, "错误", "任务内容不能为空！");
        }
    }
}

void Schedule::on_ClrBtn_clicked()
{
    // 确认对话框
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "确认清除",
                                  "确定要删除所有任务吗？此操作不可恢复！",
                                  QMessageBox::Yes | QMessageBox::No);

    if (reply == QMessageBox::Yes) {
        int keptCompleted = totalCompleted;
        taskData = QJsonArray();
        QJsonObject root;
        root["tasks"] = taskData;
        root["total_completed"] = keptCompleted; // 保留原完成数
        // 保存数据
        QString path = QDir("user_data").filePath("tasks.json");
        QFile file(path);
        if(file.open(QIODevice::WriteOnly)) {
            QJsonDocument doc(root);
            file.write(doc.toJson());
            file.close();
        }
        // 刷新界面
        loadTasks();
    }
}

