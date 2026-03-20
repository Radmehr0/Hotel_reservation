#ifndef GUESTS_H
#define GUESTS_H

#include "Date.h"
#include "Information.h"
#include <iostream>
#include <array>

using namespace std;

class Guests
{
private:
    Date checkIN;
    Date checkOUT;
    array <Information, 4> guestsInfo;          //max 4 guests
    int roomNumber;
    size_t guestCount; //needed for other classes

public:
    Guests();
    Guests(const Date& chIN, const Date& chOUT, int rNum);
    Guests(const Guests& other);
    ~Guests();

    //setters
    void setCheckIN(const Date& dIN);
    void setCheckOUT(const Date& dOUT);
    void setRoomNumber(int rNum);

    //function to add a guest
    bool addGuest(const Information& info);

    //getters
    Date getCheckIN() const;
    Date getCheckOUT() const;
    Information getGuestsInfo(int index) const;
    int getRoomNumber() const;
    int getGuestCount() const;

    //print functions
    void printGuests() const;
    string toString() const;
};

#endif