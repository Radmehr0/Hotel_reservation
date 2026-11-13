#include "Guests.h"
#include "Date.h"
#include "Information.h"
#include <iostream>
#include <array>
#include <sstream>

using namespace std;

Guests::Guests() : checkIN(), checkOUT(), guestsInfo(), roomNumber(1), guestCount(0){}

Guests::Guests(const Date& chIN, const Date& chOUT, int rNum) : checkIN(chIN), checkOUT(chOUT), guestsInfo{}, roomNumber(rNum), guestCount(0){}

Guests::Guests(const Guests& other): checkIN(other.checkIN),checkOUT(other.checkOUT), guestsInfo(other.guestsInfo), roomNumber(other.roomNumber), guestCount(other.guestCount){}

Guests::~Guests(){}

//setters
void Guests::setCheckIN(const Date& dIN)
{
    checkIN = dIN;
}
void Guests::setCheckOUT(const Date& dOUT)
{
    checkOUT = dOUT;
}
void Guests::setRoomNumber(int rNum)
{
    roomNumber = rNum;
}

// adding guest function
bool Guests::addGuest(const Information& info)
{
    if (guestCount >= 4)
        return false;
    guestsInfo[guestCount] = info;      //because it has already single element inside doesn't need -1 for index
    guestCount++;
    return true;
}

//getters
Date Guests::getCheckIN() const
{
    return checkIN;
}
Date Guests::getCheckOUT() const
{
    return checkOUT;
}
Information Guests::getGuestsInfo(int index) const
{
    if (index < 0 || index >= guestCount)
        return Information();
    return guestsInfo[index];
}
int Guests::getRoomNumber() const
{
    return roomNumber;
}
int Guests::getGuestCount() const
{
    return static_cast<int>(guestCount);
}

//print function
void Guests::printGuests() const
{
    cout << toString();
}

//toString function
string Guests::toString() const
{
    ostringstream out; //std::ostringstream class uses string buffer and treat a string as an output stream

    out << "Room Number: " << roomNumber << "\n";  // out same as cout

    // Check in and Check out date using Date getters
    out << "Check-IN: "<< checkIN.getYear() << "/"<< checkIN.getMonth() << "/"<< checkIN.getDay() << "\n";
    out << "Check-OUT: "<< checkOUT.getYear() << "/"<< checkOUT.getMonth() << "/"<< checkOUT.getDay() << "\n";
    out << "Guest Count: " << guestCount << "\n";

    // Printing guest info
    for (int i = 0; i < guestCount; i++)
    {
        Date dateofBirth = guestsInfo[i].getBirthDate();
        out << "Guest " << (i + 1) << ": " << guestsInfo[i].getFirstName() << " "<< guestsInfo[i].getLastName()
            << " (Date of birth: "<< dateofBirth.getYear() << "/"<< dateofBirth.getMonth() << "/"<< dateofBirth.getDay()<<")\n";
    }
    return out.str(); //returning a copy of the string object and str() method
}




