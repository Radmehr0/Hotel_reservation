#include <iostream>
#include <limits>
#include <iomanip>

#include "Date.h"
#include "Information.h"
#include "Guests.h"
#include "Guests_Res_Request.h"
#include "Reservation_Manager.h"

using namespace std;

int main()
{
    cout << "========== Welcome to \"Cplusplus\" Hotel ==========" << endl << endl;

    //creating manger object
    Reservation_Manager manager;

    //Test 1) creating reservation for Rad and Jay (Mar 1 - 4, room 7)

    Information guest1("Jiajun", "Zhang", Date(1, 1, 2001));
    Information guest2("Rad", "Mahmoudi", Date(7, 28, 2004));

    Guests room7_stay(Date(3, 1, 2026), Date(3, 4, 2026), 7);
    room7_stay.addGuest(guest1);
    room7_stay.addGuest(guest2);

    Guests_Res_Request* request1 = new Guests_Res_Request(room7_stay);          //dynamic allocation
    int reservation_ID_1 = manager.processRequest(request1);
    cout <<endl;
    cout << "========== Test 1 Calendar ==========" << endl;
    manager.printCalendar();

    cout << "========== Test 1 Guests into ==========" << endl;
    room7_stay.printGuests();
    cout << endl;


    // Test 2) Conflicting reservation (Mar 2 - 5, room 7)

    Guests room7_wanted(Date(3, 2, 2026), Date(3, 5, 2026), 7);
    room7_wanted.addGuest(Information("Nara", "Black", Date(6, 11, 2005)));

    Guests_Res_Request* request2 = new Guests_Res_Request(room7_wanted);
    int reservation_ID_2 = manager.processRequest(request2);                //fail and delete req2 inside processRequest
    cout << endl;

    cout << "========== Test 2 Conflict Calendar =========="<< endl;
    manager.printCalendar();


    // Test 3) Second reservation to test date from test 2 (Mar 2 - 5, room 5)

    Guests room5_stay(Date(3, 2, 2026), Date(3, 5, 2026), 5);
    room5_stay.addGuest(Information("Jamie", "Smith", Date(2, 15, 2000)));

    Guests_Res_Request* request3 = new Guests_Res_Request(room5_stay);
    int reservation_ID_3 = manager.processRequest(request3);
    cout << endl;

    cout << "========== Test 3 Calendar ==========" << endl;
    manager.printCalendar();

    cout << "========== Test 3 Guests into ==========" << endl;
    room5_stay.printGuests();
    cout << endl;


    //Test 4) 5th guest in room shouldn't be saved (Mar 1 - 2, room 1)

    Guests room1_wanted(Date(3, 1, 2026), Date(3, 2, 2026), 1);
    room1_wanted.addGuest(Information("Person", "1", Date(1, 1, 2000)));
    room1_wanted.addGuest(Information("Person", "2", Date(1, 2, 2000)));
    room1_wanted.addGuest(Information("Person", "3", Date(1, 3, 2000)));
    room1_wanted.addGuest(Information("Person", "4", Date(1, 4, 2000)));
    room1_wanted.addGuest(Information("Person", "5", Date(1, 5, 2000))); //fail
    cout << endl;

    Guests_Res_Request* request4 = new Guests_Res_Request(room1_wanted);
    int reservation_ID_4 = manager.processRequest(request4);
    cout << endl;

    cout << "========== Test 4 Calendar ==========" << endl;
    manager.printCalendar();

    cout << "========== Test 4 Guests into ==========" << endl;
    room1_wanted.printGuests();
    cout << endl;


    // Test 5) canceling reservation ID 3
    cout << "========== Test 5 canceling reservation ID 3 ==========" << endl;
    manager.cancelReservation(reservation_ID_3);

    cout << "========== Test 5 Calendar after Cancellation ==========" << endl;
    manager.printCalendar();
    cout << endl;

    //Final test) Interactive mode

    cout << "========== Final Test User Input Reservation ==========" << endl;
    int roomNum;
    int check_IN_Day, check_OUT_Day;
    int numGuests;

    cout << "Enter your room number (1-20):" << endl;
    cin >> roomNum;
    cout << "Enter check-in day in March:" << endl;
    cin >> check_IN_Day;
    cout << "Enter check-out day in March:" << endl;
    cin >> check_OUT_Day;
    cout << "Enter number of guests (1-4):" << endl;
    cin >> numGuests;

    if (roomNum < 1 || roomNum > 20 || check_IN_Day < 1 || check_IN_Day > 7 || check_OUT_Day < 2 || check_OUT_Day > 8 || check_OUT_Day <= check_IN_Day || numGuests < 1 || numGuests > 4)
    {
        cerr << "INVALID Input!" << endl;
        return -1;
    }

    Guests User(Date(3, check_IN_Day, 2026), Date(3, check_OUT_Day, 2026), roomNum);


    cin.ignore(numeric_limits<streamsize>::max(), '\n');                //Clear any leftover newline before reading names safely

    for (int i = 0; i < numGuests; i++)
    {
        string fName, lName;
        int monthBirth, dayBirth, yearBirth;

        cout << "Guest " << (i + 1) << " first name:" << endl;
        getline(cin, fName);
        cout << "Guest " << (i + 1) << " last name:" << endl;
        getline(cin, lName);
        cout << "Guest " << (i + 1) << " birth month (1-12):" << endl;
        cin >> monthBirth;
        cout << "Guest " << (i + 1) << " birth day (1-31):" << endl;
        cin >> dayBirth;
        cout << "Guest " << (i + 1) << " birth year (e.g., 2000):" << endl;
        cin >> yearBirth;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        Information inf(fName.c_str(), lName.c_str(), Date(monthBirth, dayBirth, yearBirth));    //std::string -> const char*

        //safety for 5th input
        if (!User.addGuest(inf)) {
            cerr << "Could not add more guests!!" << endl;
            break;
        }
    }

    Guests_Res_Request* userReq = new Guests_Res_Request(User);
    int userResID = manager.processRequest(userReq);
    cout << endl;

    cout << "========== Calendar after User reservation ==========" << endl;
    manager.printCalendar();

    if (userResID != -1)
    {
        cout << "Reservation successful! ID = " << userResID << endl;
        cout << "Reservation details:\n";
        manager.printReservationsInfo(userResID); // prints stored request info
    }
    else
    {
        cerr << "Reservation failed." << endl;
    }

    return 0;
}