#include "Cabs.h"

using namespace std;

Cabs::Cabs() {

	if (eduMode) 
	{
		cout << "Cabs-Constructor" << endl;
	}
	
	stdcab_rate = 150;
	luxcab_rate = 350;
	
}

Cabs::~Cabs() 
{
	if (eduMode) 
	{
		cout << "Cabs-Destructor" << endl;
	}
}

int Cabs::stdCabBooking()
{
	if (eduMode) 
	{
		cout << "Cabs-stdCabBooking" << endl;
	}

	cout << "    ABC STANDARD CABS    \n";

	cout << "\nEstimating cost for your trip,\n";
	cout << "Enter kilometers expected to travel : ";
	cin >> kilometers;

	int hireCab;
	cabCost = kilometers * stdcab_rate;
	cout << "\nStandard Cab Cost = Rs." << cabCost << endl << endl;
	cout << "Enter any key to proceed: ";
	cin >> hireCab;

	CLS();

	lastcabCost = cabCost;

	cout << "Enter the following details, " << endl;
	ofstream out("./files/Cabs/Cab-Bookings.txt", ios::app);
	{
		cout << "Enter customer ID: ";
		cin >> cusId;
		cout << "Enter Name(first and last names only) : ";
		cin >> f_name;
		cin >> l_name;
		cout << "Enter Mobile No : ";
		cin >> mobileNo;
		cout << "Enter Date (DD/MM/YY) : ";
		cin >> date;
		cout << "Enter Time at which cab is required(HH:MIN) [in 24 HR format from 00:00 to 24:00] : ";
		cin >> time;
	}

	out << "\nStandard Cab Booking for, \nCustomer Id : " << cusId << "\nName : " << f_name << " " << l_name << "\nMobile No : " << mobileNo << "\nDate : " << date << "\nTime : " << time << endl;
	out.close();
	cout << "You have succesfully booked a standard cab." << endl;

	cout << "Return to menu and recieve the receipt" << endl;

	return cabCost;

}

int Cabs::luxCabBooking()
{
	if (eduMode) 
	{
		cout << "Cabs-luxCabBooking" << endl;
	}
	cout << "    ABC LUXURY CABS    \n";

	cout << "\nEstimating cost for your trip,\n";
	cout << "Enter kilometers to travel : ";
	cin >> kilometers;

	int hireCab;
	cabCost = kilometers * luxcab_rate;
	cout << "\nLuxury Cab Cost: Rs." << cabCost << "\n";
	cout << "Press any key to proceed: ";
	cin >> hireCab;

	CLS();

	lastcabCost = cabCost;
	cout << "Enter the following details, " << "\n";
	ofstream out("./files/Cabs/Cab-Bookings.txt", ios::app);
	{
		cout << "Enter customer ID: ";
		cin >> cusId;
		cout << "Enter Name(first and last names only) : ";
		cin >> f_name;
		cin >> l_name;
		cout << "Enter Mobile No : ";
		cin >> mobileNo;
		cout << "Enter Date (DD/MM/YY) : ";
		cin >> date;
		cout << "Enter Time at which cab is required(HH:MIN) [in 24 HR format from 00:00 to 24:00] : ";
		cin >> time;
	}

	out << "\nStandard Cab Booking for, \n Customer Id : " << cusId << "\nName : " << f_name << " " << l_name << "\nMobile No : " << mobileNo << " ,\nat " << time << "in 24 HR format" << endl;
	out.close();

	cout << "You have successfully booked a luxury cab" << endl;
	cout << "Return to menu and recieve the receipt" << endl;

	return cabCost;
}

	void Cabs::printRecords()
	{
		if (eduMode) 
		{
			cout << "Cabs-printRecords" << endl;
		}
		ifstream in("./files/Cabs/Cab-Bookings.txt");
		{
			if (!in)
			{
				cout << "File error" << endl;
			}

			while (!(in.eof()))
			{
				in.getline(all, 999);
				cout << all << endl;
			}

			in.close();
		}


	}