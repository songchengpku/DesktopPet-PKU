#include "TodoList.h"

#include <utility>

class TodoListData : public QSharedData
{
public:
};

TodoList::TodoList()
    : data(new TodoListData)
{}

TodoList::TodoList(const TodoList &rhs)
    : data{rhs.data}
{}

TodoList::TodoList(TodoList &&rhs)
    : data{std::move(rhs.data)}
{}

TodoList &TodoList::operator=(const TodoList &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

TodoList &TodoList::operator=(TodoList &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

TodoList::~TodoList() {}


// TodoItem 实现
TodoItem::TodoItem(const QString &name, int priority, bool completed)
    : m_name(name), m_priority(priority), m_completed(completed) {}

QString TodoItem::getName() const { return m_name; }
int TodoItem::getPriority() const { return m_priority; }
bool TodoItem::isCompleted() const { return m_completed; }

void TodoItem::setName(const QString &name) { m_name = name; }
void TodoItem::setPriority(int priority) { m_priority = priority; }
void TodoItem::setCompleted(bool completed) { m_completed = completed; }

// TodoList 实现
TodoList::TodoList(QObject *parent) : QObject(parent) {}

void TodoList::addItem(const QString &name, int priority) {
    m_items.append(TodoItem(name, priority));
    emit listChanged();
}

void TodoList::removeItem(int index) {
    if (index >= 0 && index < m_items.size()) {
        m_items.remove(index);
        emit listChanged();
    }
}

void TodoList::clearAll() {
    m_items.clear();
    emit listChanged();
}

int TodoList::count() const {
    return m_items.size();
}

TodoItem TodoList::getItem(int index) const {
    if (index >= 0 && index < m_items.size()) {
        return m_items.at(index);
    }
    return TodoItem("", 0);
}

void TodoList::setCompleted(int index, bool completed) {
    if (index >= 0 && index < m_items.size()) {
        m_items[index].setCompleted(completed);
        emit listChanged();
    }
}

QVector<TodoItem> TodoList::getAllItems() const {
    return m_items;
}
