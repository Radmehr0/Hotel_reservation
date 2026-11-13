#ifndef INFORMATION_H
#define INFORMATION_H

#include "Date.h"
#include <iostream>
#include <array>
#include <string>

using namespace std;

class Information
{
private:
    static size_t const maxNameSize = 50;   //const class variable
    array <char,maxNameSize> firstName;
    array <char, maxNameSize> lastName;
    Date birthDate;                         //class composition

public:
    Information();
    Information(const char* fName, const char* lName, const Date& d);
    Information (const Information& other);
    ~Information();

    //setters
    void setFirstName(const char* fName);
    void setLastName(const char* lName);
    void setBirthDate(const Date& d);

    //getters
    const char* getFirstName() const;
    const char* getLastName() const;
    Date getBirthDate() const;

    //print function
    void printInfo() const;
};

#endif