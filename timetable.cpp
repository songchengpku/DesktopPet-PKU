#include "timetable.h"

#include <utility>

class timetableData : public QSharedData
{
public:
};

timetable::timetable()
    : data(new timetableData)
{}

timetable::timetable(const timetable &rhs)
    : data{rhs.data}
{}

timetable::timetable(timetable &&rhs)
    : data{std::move(rhs.data)}
{}

timetable &timetable::operator=(const timetable &rhs)
{
    if (this != &rhs)
        data = rhs.data;
    return *this;
}

timetable &timetable::operator=(timetable &&rhs)
{
    if (this != &rhs)
        data = std::move(rhs.data);
    return *this;
}

timetable::~timetable() {}
