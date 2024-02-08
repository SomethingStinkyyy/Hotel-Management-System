#include "Convention_Hall.h"

using namespace std;

Convention_Hall::Convention_Hall() {
    if (eduMode) {
        cout << "Convention_Hall-Constructor" << endl;
    }
}

Convention_Hall::~Convention_Hall() {
    if (eduMode) {
        cout << "Convention_Hall-Destructor" << endl;
    }
}

void Convention_Hall::check()
{
    if (eduMode) {
        cout << "Convention_Hall-check" << endl;
    }
    //opening the text file and getting necessary info
    ifstream inf("./files/Bookings/conventionhall.txt");

    if (!inf)
    {
        cout << endl << "Unable to open conventionhall file" << endl;
    }

    string day, time, hallBook, targetDay, targetTime, result = "Not Booked";

    cout << endl << "Enter the date(eg:- 23/02/2022): "; 
    cin >> targetDay;

    cout << endl << "Enter the time(eg:- 07.00 / 11.00): "; 
    cin >> targetTime;

    //If the required time exists then the result(res) will be changed to booked
    while (!inf.eof())
    {
        inf >> day >> time >> hallBook;
        cout << "\n" << day << " " << time << " " << hallBook << endl;

        if (day == targetDay && time == targetTime)
        {
            result = "Booked";
        }
    }
    //if any of the previous booking not resembles then it will show not booked and closing the file
    cout << endl << result << endl;
    inf.close();
}

void Convention_Hall :: checkAll()
{
    if (eduMode) {
        cout << "Convention_Hall-checkAll" << endl;
    }
    //opening text file to read
    ifstream inf("./files/Bookings/conventionhall.txt");

    //if the text file is not available
    if (!inf)
    {
        cout << endl << "Unable to open Convention Hall file" << endl;
    }


    int hrs;
    string day, cusID;
    float time;

    while (!inf.eof())
    {
        inf >> day >> fixed >> setprecision(2) >> time >> cusID;

        cout << cusID << " " << day << " " << fixed << setprecision(2) << time << endl;
    }
}

int Convention_Hall::update()
{
    if (eduMode) {
        cout << "Convention_Hall-update" << endl;
    }
    cout << "\tPrice for one hour use of Convention Hall = Rs.20000";
    cout << "\n\n";

    //taking necessary infos to book a time
    string targetDay, cusID;
    int hrs;
    float targetTime;

    cout << "Enter Customer ID:";
    cin >> cusID;

    cout << "Enter the Required date(eg:- 23/02/2022): ";
    cin >> targetDay;

    cout << "Enter the Required time(eg:- 07.00 / 11.00): ";
    cin >> setprecision(2) >> targetTime;

    cout << "Enter the number of hours: ";
    cin >> hrs;

    //calculating the cost
    int hallCost = hrs*20000;

    //opening the text file to append and return the cost
    ofstream outf("./files/Bookings/conventionhall.txt", ios::app);

    for (int i = 0; i < hrs; i++)
    {
        if (targetTime + (i * 1) > 24)
        {
            targetTime = targetTime - 24;
        }
        outf << endl << targetDay << " " << fixed << setprecision(2) << targetTime + (i*1) << " " << cusID;
    }

    cout << "\n\n Total Cost = Rs." << hallCost;

    outf.close();
    return hallCost;
}


