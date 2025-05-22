#ifndef TODOLIST_H
#define TODOLIST_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>
#include <QVector>
#include <QString>

class TodoListData;

class TodoItem {
public:
    TodoItem(const QString &name, int priority, bool completed = false);

    QString getName() const;
    int getPriority() const;
    bool isCompleted() const;

    void setName(const QString &name);
    void setPriority(int priority);
    void setCompleted(bool completed);

private:
    QString m_name;
    int m_priority;
    bool m_completed;
};


class TodoList : public QObject {
    Q_OBJECT
    QML_ELEMENT
public:
    TodoList();
    TodoList(const TodoList &);
    TodoList(TodoList &&);
    TodoList &operator=(const TodoList &);
    TodoList &operator=(TodoList &&);
    ~TodoList();

    explicit TodoList(QObject *parent = nullptr);

    // 添加新项目
    void addItem(const QString &name, int priority);

    // 删除项目
    void removeItem(int index);

    // 清空列表
    void clearAll();

    // 获取项目数量
    int count() const;

    // 获取指定项目
    TodoItem getItem(int index) const;

    // 标记完成状态
    void setCompleted(int index, bool completed);

    // 获取所有项目
    QVector<TodoItem> getAllItems() const;

signals:
    // 列表改变信号
    void listChanged();

private:
    QVector<TodoItem> m_items;
    QSharedDataPointer<TodoListData> data;
};

#endif // TODOLIST_H
