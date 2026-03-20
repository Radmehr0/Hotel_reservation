#ifndef DATE_H
#define DATE_H

#include <iostream>

using namespace std;

class Date
{
private:
    int month;
    int day;
    int year;

public:
    Date();
    Date(int m, int d, int y);
    Date(const Date& other); //copy constructor
    ~Date();

    //setters
    void setMonth(int m);
    void setDay(int d);
    void setYear(int y);

    //getters
    int getMonth() const;
    int getDay() const;
    int getYear() const;

    //Print function
    void printDate() const;
};

#endif
