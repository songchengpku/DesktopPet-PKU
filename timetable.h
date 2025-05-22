#ifndef TIMETABLE_H
#define TIMETABLE_H

#include <QMainWindow>
#include <QObject>
#include <QQuickItem>
#include <QSharedDataPointer>
#include <QWidget>

class timetableData;

class timetable
{
    Q_OBJECT
    QML_ELEMENT
public:
    timetable();
    timetable(const timetable &);
    timetable(timetable &&);
    timetable &operator=(const timetable &);
    timetable &operator=(timetable &&);
    ~timetable();

private:
    QSharedDataPointer<timetableData> data;
};

#endif // TIMETABLE_H
