#include "Date.h"
#include <chrono>
#include <iostream>

Date::Date() //default constructor
{
    month = 3;
    day = 1;
    year = 2026;
}

Date::Date(int m, int d, int y) : month(m), day(d), year(y){}

Date::Date(const Date& other) : month(other.month), day(other.day), year(other.year){}

Date::~Date(){} //destructor

//Setters
void Date::setDay(int d)
{
    day = d;
}
void Date::setMonth(int m)
{
    month = m;
}
void Date::setYear(int y)
{
    year = y;
}

//Getters
int Date::getMonth() const
{
    return month;
}
int Date::getDay() const
{
    return day;
}
int Date::getYear() const
{
    return year;
}

void Date::printDate() const
{
    std::cout << year << "/" << month << "/" << day; //2026/3/1
}




