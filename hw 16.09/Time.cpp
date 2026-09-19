#include "Time.h"
#include <ctime>
#include <iostream>

using namespace std;

Time::Time()
{
    time_t current = time(nullptr);
    tm info{};
    localtime_s(&info, &current);

    hour = info.tm_hour;
    minutes = info.tm_min;
    seconds = info.tm_sec;
    format = true;
}

Time::Time(int hour, int minutes, int seconds, bool format)
{
    this->hour = hour;
    this->minutes = minutes;
    this->seconds = seconds;
    this->format = format;
}

Time::Time(const Time& obj)
{
    hour = obj.hour;
    minutes = obj.minutes;
    seconds = obj.seconds;
    format = obj.format;
}

Time& Time::operator=(const Time& obj)
{
    if (this != &obj) {
        hour = obj.hour;
        minutes = obj.minutes;
        seconds = obj.seconds;
        format = obj.format;
    }
    return *this;
}

void Time::setHour(int hour)
{
    if (hour >= 0 && hour < 24) this->hour = hour;
}

int Time::getHour() const { return hour; }

void Time::setMinutes(int minutes)
{
    if (minutes >= 0 && minutes < 60) this->minutes = minutes;
}

int Time::getMinutes() const { return minutes; }

void Time::setSeconds(int seconds)
{
    if (seconds >= 0 && seconds < 60) this->seconds = seconds;
}

int Time::getSeconds() const { return seconds; }

void Time::setFormat(bool format) { this->format = format; }

bool Time::getFormat() const { return format; }

bool Time::valid() const
{
    return hour >= 0 && hour < 24 &&
           minutes >= 0 && minutes < 60 &&
           seconds >= 0 && seconds < 60;
}

void Time::tickTime()
{
    if (++seconds == 60) {
        seconds = 0;
        if (++minutes == 60) {
            minutes = 0;
            if (++hour == 24) hour = 0;
        }
    }
}

void Time::untickTime()
{
    if (--seconds < 0) {
        seconds = 59;
        if (--minutes < 0) {
            minutes = 59;
            if (--hour < 0) hour = 23;
        }
    }
}

void Time::showTime() const
{
    if (format) {
        cout << hour / 10 << hour % 10 << ":"
             << minutes / 10 << minutes % 10 << ":"
             << seconds / 10 << seconds % 10 << endl;
    }
    else {
        int displayHour = hour % 12;
        if (displayHour == 0) displayHour = 12;

        cout << displayHour / 10 << displayHour % 10 << ":"
             << minutes / 10 << minutes % 10 << ":"
             << seconds / 10 << seconds % 10
             << (hour < 12 ? " AM" : " PM") << endl;
    }
}

string Time::toString() const
{
    if (format) {
        return to_string(hour / 10) + to_string(hour % 10) + ":" +
               to_string(minutes / 10) + to_string(minutes % 10) + ":" +
               to_string(seconds / 10) + to_string(seconds % 10);
    }

    int displayHour = hour % 12;
    if (displayHour == 0) displayHour = 12;

    return to_string(displayHour / 10) + to_string(displayHour % 10) + ":" +
           to_string(minutes / 10) + to_string(minutes % 10) + ":" +
           to_string(seconds / 10) + to_string(seconds % 10) +
           (hour < 12 ? " AM" : " PM");
}

bool Time::operator==(const Time& obj) const
{
    return hour == obj.hour && minutes == obj.minutes && seconds == obj.seconds;
}

bool Time::operator!=(const Time& obj) const
{
    return !(*this == obj);
}

bool Time::operator>(const Time& obj) const
{
    return hour * 3600 + minutes * 60 + seconds >
           obj.hour * 3600 + obj.minutes * 60 + obj.seconds;
}

bool Time::operator<(const Time& obj) const
{
    return !(*this > obj) && (*this != obj);
}

bool Time::operator>=(const Time& obj) const
{
    return (*this > obj) || (*this == obj);
}

bool Time::operator<=(const Time& obj) const
{
    return (*this < obj) || (*this == obj);
}

Time& Time::operator+=(float s)
{
    for (int i = 0; i < static_cast<int>(s); i++) {
        this->tickTime();
    }

    return *this;
}

Time& Time::operator-=(float s)
{
    for (int i = 0; i < static_cast<int>(s); i++) {
        this->untickTime();
    }

    return *this;
}

Time& Time::operator+=(int m)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 60; j++) {
            this->tickTime();
        }
    }

    return *this;
}

Time& Time::operator-=(int m)
{
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < 60; j++) {
            this->untickTime();
        }
    }

    return *this;
}

Time& Time::operator+=(long h)
{
    for (long i = 0; i < h; i++) {
        for (int j = 0; j < 3600; j++) {
            this->tickTime();
        }
    }

    return *this;
}

Time& Time::operator-=(long h)
{
    for (long i = 0; i < h; i++) {
        for (int j = 0; j < 3600; j++) {
            this->untickTime();
        }
    }

    return *this;
}

Time Time::operator+(float s) const
{
    Time temp = *this;
    temp += s;
    return temp;
}

Time Time::operator-(float s) const
{
    Time temp = *this;
    temp -= s;
    return temp;
}

Time Time::operator+(int m) const
{
    Time temp = *this;
    temp += m;
    return temp;
}

Time Time::operator-(int m) const
{
    Time temp = *this;
    temp -= m;
    return temp;
}

Time Time::operator+(long h) const
{
    Time temp = *this;
    temp += h;
    return temp;
}

Time Time::operator-(long h) const
{
    Time temp = *this;
    temp -= h;
    return temp;
}
