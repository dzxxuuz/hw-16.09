#include "Bus.h"
#include <iostream>
using namespace std;
Bus::Bus()
{
    startTime = Time(6, 0, 0);
    endTime = Time(11, 0, 0);
    routeMinutes = 30;
    restMinutes = 10;
}

Bus::Bus(const Time & startTime, const Time & endTime, int routeMinutes, int restMinutes)
{
    this->startTime = startTime;
    this->endTime = endTime;
    this->routeMinutes = routeMinutes;
    this->restMinutes = restMinutes;
}

void Bus::setStartTime(const Time & t)
{
    startTime = t;
}

void Bus::setEndTime(const Time & t)
{
    endTime = t;
}

void Bus::setRouteMinutes(int minutes)
{
    routeMinutes = minutes;
}

void Bus::setRestMinutes(int minutes)
{
    restMinutes = minutes;
}

Time Bus::getStartTime() const
{
    return startTime;
}

Time Bus::getEndTime() const
{
    return endTime;
}

int Bus::getRouteMinutes() const
{
    return routeMinutes;
}

int Bus::getRestMinutes() const
{
    return restMinutes;
}

void Bus::showSchedule() const
{
    Time current = startTime;
    bool fromA = true;

    while (current <= endTime)
    {
        if (fromA)
            cout << "A: " << current << '\n';
        else
            cout << "B: " << current << '\n';

        current += routeMinutes;
        current += restMinutes;

        fromA = !fromA;
    }
}
