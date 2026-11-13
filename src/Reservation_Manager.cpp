#include "Reservation_Manager.h"
#include "Guests_Res_Request.h"
#include <iomanip>

Reservation_Manager::Reservation_Manager()
{
    requestCounter = 0;
    for (int n = 0; n < max_no_of_nights; n++)
    {
        for (int r = 0; r < no_of_rooms; r++)
            calendar[n][r] = 0;
    }

    for (int i = 0; i < max_no_of_res; i++)
        requestsArr[i] = nullptr;           // to avoid garbage pointer value
}
Reservation_Manager::~Reservation_Manager()
{
    for (int i = 0; i < requestCounter; i++)
    {
        delete requestsArr[i];
        requestsArr[i] = nullptr;
    }
}

int Reservation_Manager::processRequest(Guests_Res_Request* req_ptr)
{
    if (req_ptr == nullptr)
        return -1;
    if (requestCounter >= max_no_of_res)
    {
        delete req_ptr;
        return -1;
    }

    Guests g = req_ptr->getGuests();
    int roomIndex = g.getRoomNumber() - 1;
    int startDayIndex = g.getCheckIN().getDay() - 1;
    int numNights = req_ptr->getNumberofNights();

    if (roomIndex < 0 || roomIndex >= no_of_rooms ||
        startDayIndex < 0 || startDayIndex >= max_no_of_nights ||
        numNights <= 0 || (startDayIndex + numNights) > max_no_of_nights)
    {
        cout << "Reservation ID: " << req_ptr->getReservationID()
             << " FAILED: INVALID dates or room\n";
        delete req_ptr;
        return -1;
    }

    for (int i = 0; i < numNights; i++)
    {
        if (calendar[startDayIndex + i][roomIndex] != 0)
        {
            cout << "Reservation ID: " << req_ptr->getReservationID()
                 << " FAILED: Room is occupied.\n";
            delete req_ptr;
            return -1;
        }
    }

    int id = req_ptr->getReservationID();
    for (int i = 0; i < numNights; i++)
        calendar[startDayIndex + i][roomIndex] = id;
    requestsArr[requestCounter++] = req_ptr;
    cout << "Reservation ID: " << id << " CONFIRMED!\n";
    return id;
}


void Reservation_Manager::printReservationsInfo(int resID) const
{
    bool found = false;
    for (int i = 0; i < requestCounter; i++)
    {
        if (requestsArr[i] != nullptr && requestsArr[i]->getReservationID() == resID)
        {
            cout << "Reservation Info: "<<endl;
            requestsArr[i]->printRequest();
            found = true;
            break;
        }
    }
    if (!found)
        cout << "Reservation ID: " << resID << " NOT FOUND!" << endl;
}

//Cancel function
bool Reservation_Manager::cancelReservation(int resID)
{
    int foundIndex = -1;
    for (int i = 0; i < requestCounter; i++)
    {
        if (requestsArr[i] != nullptr && requestsArr[i]->getReservationID() == resID)
        {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex == -1)
    {
        cout << "Reservation ID: " << resID << " NOT FOUND!\n";
        return false;
    }

    Guests_Res_Request* req_ptr = requestsArr[foundIndex];
    Guests g = req_ptr->getGuests();

    int roomIndex = g.getRoomNumber() - 1;
    int startDayIndex = g.getCheckIN().getDay() - 1;
    int numNights = req_ptr->getNumberofNights();

    // clear calendar
    for (int i = 0; i < numNights; i++)
        calendar[startDayIndex + i][roomIndex] = 0;

    int id = req_ptr->getReservationID();
    delete req_ptr;

    // shift array left from foundIndex
    for (int j = foundIndex; j < requestCounter - 1; j++)
        requestsArr[j] = requestsArr[j + 1];

    requestsArr[requestCounter - 1] = nullptr;
    requestCounter--;

    cout << "Reservation ID: " << id << " CANCELLED successfully!\n";
    return true;
}

//Calendar Printing
void Reservation_Manager::printCalendar() const
{
    const int firstColumWidth = 12; // Width for "Night\Room" and "Mar X"
    const int roomColumWidth = 4;   // Width for room numbers/IDs
    cout << endl;

    cout << left << setw(firstColumWidth) << "Night\\Room";
    for (int c = 1; c <= no_of_rooms; c++) {
        cout << right << setw(roomColumWidth) << c;
    }
    cout << endl;

    string line (firstColumWidth + (no_of_rooms * roomColumWidth), '-'); //----------------
    cout << line << endl;

    for (int r = 0; r < max_no_of_nights; r++)
    {
        string dateLabel = "Mar " + to_string(r + 1); //Mar 1
        cout << left << setw(firstColumWidth) << dateLabel;
        for (int c = 0; c < no_of_rooms; c++)
        {
            cout << right << setw(roomColumWidth) << calendar[r][c];
        }
        cout << endl;
    }
    cout << endl;
}





