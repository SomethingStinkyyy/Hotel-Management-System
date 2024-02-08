#pragma once
#include "Hotel_Room.h"
#include "Convention_Hall.h"
#include "Restaurant.h"
#include "Customer_Functions.h"

//derived class of children of the base class, creating diamond problem
//cost class derived from all the derived class of client
class cost : public Convention_Hall, public Hotel_Room, public Restaurant, public Customer_Functions
{
public:
    //check and update function for polymorphism
    virtual void check() {}
	virtual int update() { return 0; }

	int paid;

	void printBill(string cusID, int roomCost, int restaurantReservationCost, int conventionHallCost, int cabCost)
	{
		if (eduMode) {
			cout << "cost-printBill" << endl;
		}
		string FILEPATH = "./files/Bookings/Receipts/" + cusID + "-receipt.txt";

		ofstream outf(FILEPATH);
		{
			outf << "-------------Receipt-------------" << endl;
			outf << "_________________________________" << endl;

			outf << "Customer Id : " << cusID << endl << endl;
			outf << "Description\t\t Total" << endl;
			outf << "Room Cost :\t\t " << fixed << setprecision(2) << "Rs. " << roomCost << endl;
			outf << "Restaurant Cost :\t    " << fixed << setprecision(2) << "Rs. " << restaurantReservationCost << endl;
			outf << "Convention Hall Cost :\t    " << fixed << setprecision(2) << "Rs. " << conventionHallCost << endl;
			outf << "Cab Cost :\t\t " << fixed << setprecision(2) << "Rs. " << cabCost << endl;

			int totalCost = roomCost + restaurantReservationCost + conventionHallCost + cabCost;
			outf << "_________________________________" << endl;
			outf << "Total Cost :\t\t " << fixed << setprecision(2) << "Rs. " << totalCost << endl;
			outf << "_________________________________" << endl;
			outf << "---------THANK YOU!---------------" << endl;
		}

		outf.close();

	}

	void showBill(string cusID) 
	{
		if (eduMode) {
			cout << "cost-showBill" << endl;
		}
		string FILEPATH = "./files/Bookings/Receipts/" + cusID + "-receipt.txt";

		ifstream inf(FILEPATH);
		{
			if (!inf) {
				cout << "File opening error!" << endl;
			}
			while (!(inf.eof())) {
				inf.getline(all, 999);
				cout << all << endl;
			}
		}

		inf.close();
	}
};

