#pragma once
#include "Time.h"
class Bus
{
private:
	Time startTime;
	Time endTime;

	int routeMinutes;
	int restMinutes;

public:
	Bus();
	Bus(const Time& startTime, const Time& endTime, int routeMinutes,int restMinutes);

    void setStartTime(const Time& t);
    void setEndTime(const Time& t);
    void setRouteMinutes(int minutes);
    void setRestMinutes(int minutes);

    Time getStartTime() const;
    Time getEndTime() const;
    int getRouteMinutes() const;
    int getRestMinutes() const;

    void showSchedule() const;
};

