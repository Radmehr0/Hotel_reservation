#include "Information.h"
#include "Date.h"
#include <iostream>
#include <array>
#include <cstring>
#include <string>

using namespace std;

Information::Information() : birthDate()
{
    firstName[0] = '\0';
    lastName[0] = '\0';
}

Information::Information(const char* fName, const char* lName, const Date& d) : birthDate(d)
{
    setFirstName(fName);
    setLastName(lName);
}

Information::Information(const Information& other) : firstName(other.firstName), lastName(other.lastName), birthDate(other.birthDate){}

Information::~Information(){}

//setters
void Information::setFirstName(const char* fName)
{
    if (!fName)
    {
        firstName[0] = '\0';
        return; //exit function
    }
    strncpy(firstName.data(), fName, firstName.size() - 1); //array.data() returns a pointer to first element
    firstName[firstName.size() - 1] = '\0';
}

void Information::setLastName(const char* lName)
{
    if (!lName)
    {
        lastName[0] = '\0';
        return;
    }
    strncpy(lastName.data(), lName, lastName.size() - 1);
    lastName[lastName.size() - 1] = '\0';
}
void Information::setBirthDate(const Date& d)
{
    birthDate = d;
}

//getters
const char* Information::getFirstName() const
{
    return firstName.data();
}
const char* Information::getLastName() const
{
    return lastName.data();
}
Date Information::getBirthDate() const
{
    return birthDate;
}
//Printing info
void Information::printInfo() const
{
    cout << firstName.data() << " " << lastName.data() << " (";
    birthDate.printDate();
    cout << ") "<< endl;
}




