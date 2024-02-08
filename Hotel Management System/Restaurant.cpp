#include "Restaurant.h"

using namespace std;

Restaurant::Restaurant() {
    if (eduMode) {
        cout << "Restaurant-Constructor" << endl;
    }
}

Restaurant::~Restaurant() {
    if (eduMode) {
        cout << "Restaurant-Destructor" << endl;
    }
}

//outputting all restaurant reservations
void Restaurant::check()
{
    if (eduMode) {
        cout << "Restaurant-check" << endl;
    }
    //opening text file to read
    ifstream inf("./files/Bookings/restaurant.txt");

    //if the text file is not available
    if (!inf)
    {
        cout << endl << "Unable to open Restaurant file" << endl;
    }

    int numOfDiners, resCost;
    string day, time, cusID;

    while (!(inf.eof()))
    {
        inf >> day >> time >> numOfDiners >> resCost >> cusID;

        cout << cusID << " " << day << " " << time << " No. of Diners:" << numOfDiners << " Rs. " << resCost << endl;
    }
}

//booking the restaurant
int Restaurant::update()
{
    if (eduMode) {
        cout << "Restaurant-update" << endl;
    }
    cout << "\tA Three Course Meal will be provided, items differing based on reserved time. \nPrice per meal per pax = Rs.5000";
    cout << "\n\n";

    //taking necessary infos to book a time
    string targetDay, targetTime, cusID;
    int numOfDiners;

    cout << "Enter Customer ID:";
    cin >> cusID;

    cout << "Enter the Required date(eg:- 23/02/2022): ";
    cin >> targetDay;

    cout << "Enter the Required time(eg:- 07.00 / 11.00): ";
    cin >> targetTime;

    cout << "Enter the number of diners: ";
    cin >> numOfDiners;

    //cost for reservations
    int resCost = numOfDiners*5000;

    cout << "Total Cost: Rs." << resCost;

    //opening the text file to append and return the cost
    ofstream outf("./files/Bookings/restaurant.txt", ios::app);

    outf << endl << targetDay << " " << targetTime << " " << numOfDiners << " " << resCost << " " << cusID;
    outf.close();
    return resCost;
}
