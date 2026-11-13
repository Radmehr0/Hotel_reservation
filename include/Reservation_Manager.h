#ifndef RESERVATION_MANAGER_H
#define RESERVATION_MANAGER_H

#include "Guests_Res_Request.h"


class Reservation_Manager
{
private:
    static const int max_no_of_nights = 7;
    static const int no_of_rooms = 20;
    static const int max_no_of_res = 100;
    Guests_Res_Request* requestsArr[max_no_of_res];
    int requestCounter;
    //2D array
    int calendar[max_no_of_nights][no_of_rooms];

public:
    Reservation_Manager();
    ~Reservation_Manager();

    int processRequest(Guests_Res_Request* req_ptr);
    void printReservationsInfo(int resID) const;
    bool cancelReservation(int resID);
    void printCalendar() const;
};

#endif