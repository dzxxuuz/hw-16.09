#pragma once

#include <string>

class Time
{
    int hour;
    int minutes;
    int seconds;
    bool format; // true = utc (24-hours), false = am/pm (12-hours), тільки для виведення часу на екран

public:
    Time(); // Поточний локальний час
    Time(int hour, int minutes, int seconds, bool format = true);
    Time(const Time& obj); // Визначити: чи потрібен Конструктор Копіювання?
    Time& operator = (const Time& obj); // Визначити: чи потрібен Оператор Присвоювання?

    void setHour(int hour);
    int getHour() const;

    void setMinutes(int minutes);
    int getMinutes() const;

    void setSeconds(int seconds);
    int getSeconds() const;

    void setFormat(bool format);
    bool getFormat() const;

    bool valid() const; // Перевірка на правильність даних
    void tickTime(); // Додавання однієї секунди
    void untickTime(); // Віднімання однієї секунди
    void showTime() const; // Демонстрація часу на екран з урахуванням встановленого формату
    std::string toString() const;

    // -------- Оператори порівняння (Comparison operators) --------
    bool operator == (const Time& obj) const;
    bool operator != (const Time& obj) const;
    bool operator >  (const Time& obj) const;
    bool operator <  (const Time& obj) const;
    bool operator >= (const Time& obj) const;
    bool operator <= (const Time& obj) const;

    // -------- Оператори присвоювання (Assignment operators) --------
    Time& operator += (float s);
    Time& operator -= (float s);

    Time& operator += (int m);   // add minutes
    Time& operator -= (int m);

    Time& operator += (long h);  // add hours
    Time& operator -= (long h);

    // -------- Арифметичні оператори (Arithmetic operators) --------
    Time operator + (float s) const; // add seconds
    Time operator - (float s) const;

    Time operator + (int m) const;   // add minutes
    Time operator - (int m) const;

    Time operator + (long h) const;  // add hours
    Time operator - (long h) const;

    // Доопрацювання

    // -------- Increment / Decrement --------
    Time& operator--();     
    Time operator--(int);   

    Time& operator++();     
    Time operator++(int);   


    // -------- Friend arithmetic operators --------
    friend Time operator+(float seconds, const Time& a);
    friend Time operator-(float seconds, const Time& a);

    friend Time operator+(int minutes, const Time& a);
    friend Time operator-(int minutes, const Time& a);

    friend Time operator+(long hours, const Time& a);
    friend Time operator-(long hours, const Time& a);


    // -------- Input / Output --------
    friend std::ostream& operator<<(std::ostream& os, const Time& t);
    friend std::istream& operator>>(std::istream& is, Time& t);
};
