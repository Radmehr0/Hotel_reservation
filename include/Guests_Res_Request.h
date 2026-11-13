#ifndef RES_REQUEST_H
#define RES_REQUEST_H

#include "Guests.h"

class Guests_Res_Request
{
private:
    Guests guests;
    static int counter;
    int reservationID;
    int numberofNights;
    // For calculation number of night "day of Check out" - "day fo Check in"
    int numberofNightsCalculation(const Guests& g) const;

public:
    Guests_Res_Request();
    Guests_Res_Request(const Guests& g);
    Guests_Res_Request(const Guests_Res_Request& other);
    ~Guests_Res_Request();

    //getters
    Guests getGuests() const;
    int getReservationID() const;
    int getNumberofNights() const;

    //print function
    void printRequest() const;
};

#endif