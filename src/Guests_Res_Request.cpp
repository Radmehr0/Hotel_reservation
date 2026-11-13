#include "Guests_Res_Request.h"
#include "Guests.h"
#include <iostream>

using namespace std;

int Guests_Res_Request::counter = 0; //static var initialization

int Guests_Res_Request::numberofNightsCalculation(const Guests& g) const
{
    int arrivingDay = g.getCheckIN().getDay();
    int leavingDay = g.getCheckOUT().getDay();
    return leavingDay - arrivingDay; // march 5 - march 1 = 4 nights
}

Guests_Res_Request::Guests_Res_Request() : guests(), reservationID(0), numberofNights(0)
{
    counter++;
    reservationID = counter;
    numberofNights = numberofNightsCalculation(guests);
}

Guests_Res_Request::Guests_Res_Request(const Guests& g) : guests(g), reservationID(0), numberofNights(0)
{
    counter++;
    reservationID = counter;
    numberofNights = numberofNightsCalculation(guests);
}

Guests_Res_Request::Guests_Res_Request(const Guests_Res_Request& other) : guests(other.guests), reservationID(other.reservationID), numberofNights(other.numberofNights) {}

Guests_Res_Request::~Guests_Res_Request(){}

//getters
Guests Guests_Res_Request::getGuests() const
{
    return guests;
}
int Guests_Res_Request::getReservationID() const
{
    return reservationID;
}
int Guests_Res_Request::getNumberofNights() const
{
    return numberofNights;
}

//print function
void Guests_Res_Request::printRequest() const
{
    cout << "ReservationID: " << reservationID << endl;
    cout << "Number of Nights: " << numberofNights << endl;
    cout << guests.toString();
}




