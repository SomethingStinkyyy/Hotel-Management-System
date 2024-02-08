#include "Customer_Functions.h"
#include <iostream>
#include <fstream>
using namespace std;

Customer_Functions::Customer_Functions() {
	if (eduMode) {
		cout << "Customer_Functions-Constructor" << endl;
	}
}

Customer_Functions::~Customer_Functions() {
	if (eduMode) {
		cout << "Customer_Functions-Destructor" << endl;
	}
}

void Customer_Functions::discounts()
{
	if (eduMode) {
		cout << "Customer_Functions-discounts" << endl;
	}
	discount_rate = 1000;
}

//1.1 ADD A NEW CUSTOMER [based on ID]
void Customer_Functions::addCustomer()
{
	if (eduMode) {
		cout << "Customer_Functions-addCustomer" << endl;
	}
	CLS();
	TITLE();
	cout << "              __________________________________________________\n";
	cout << "             |               CUSTOMER REGISTRATION              |\n";
	cout << "             |__________________________________________________|\n";
	cout << "\n";

	string ID;
	cout << "(NOTE: You may only create one account per ID)\n";
	cout << "                      Enter Customer's ID(NIC): ";
	cin >> ID;

	string FILE_PATH = "./files/Customers/" + ID + ".txt";

	if (CHECK_EXISTING_FILE(FILE_PATH.c_str()))
	{
		cout << "\n\n\n";
		cout << "          _____________________________________________________________________\n";
		cout << "         |  Customer already exists. Contact Staff for any problems or errors. |\n";
		cout << "         |_____________________________________________________________________|\n";
	}
	else
	{
		string PASSWORD;
		cout << "                      Set a Password: "; //setting a password for the new customer account
		cin >> PASSWORD;

		fstream ADD;
		ADD.open(FILE_PATH.c_str(), ios::app); //made a file named as Customer's ID, and added the password
		{
			ADD << PASSWORD;
		}
		ADD.close();

		ENCRYPT(FILE_PATH.c_str()); //encrypting the password

		ofstream out("./files/Customers/Customer-Records/" + ID + ".txt", ios::app);
		{
			cout << "\n\nEnter Name(first and last names only) : ";
			cin >> f_name;
			cin >> l_name;
			cout << "Enter Age : ";
			cin >> age;
			cout << "Enter Mobile No : ";
			cin >> mobileNo;
			cout << "Enter Gender : ";
			cin >> gender;
		}

		out << "\nCustomer Id : " << ID << "\nName : " << f_name << " " << l_name << "\nAge : " << age << "\nMobile No : " << mobileNo << "\nGender : " << gender << endl;
		out.close();
		cout << "\n SAVED \n Note: Details of Customer stored in Customer-Records folder" << endl;

		cout << "\n\n\n";
		cout << "          __________________________________________________\n";
		cout << "         |  Registration Successful...                      |\n";
		cout << "         |__________________________________________________|\n";
	}
}


void Customer_Functions::showCustomerIDs()
{
	if (eduMode) {
		cout << "Customer_Functions-showCustomerIDs" << endl;
	}

	cout << "              ________________________________________________\n";
	cout << "             |         RECORD OF CURRENT CUSTOMER IDs         |\n";
	cout << "             |________________________________________________|\n";
	cout << "\n";

	string FILE_PATH = "./files/Customers/Customer-Records/";

	for (auto& p : filesystem::directory_iterator(FILE_PATH))
	{
		cout << p.path() << endl;
	}
}

void Customer_Functions::showCustomerDetails()
{
	if (eduMode) {
		cout << "Customer_Functions-showCustomerDetails" << endl;
	}

	string ID;
	cout << "              Enter Customer ID: ";
	cin >> ID;

	string FILE_PATH = "./files/Customers/Customer-Records/" + ID + ".txt";

	ifstream in(FILE_PATH);
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

	FILE_PATH = "./files/Customers/" + ID + ".txt";

	ifstream inn(FILE_PATH);
	{
		if (!inn)
		{
			cout << "File error" << endl;
		}

		while (!(inn.eof()))
		{
			inn.getline(all, 999);
			string password = all;

			for (unsigned int x = 0; x < password.length(); x++)
			{
				password[x] -= 3;// by using the simple ceasar cipher algorithm
							  //subtract a number from each character 
							  //and decrypt the string character by character
			}

			cout << "password: " << password << endl;
		}

		inn.close();
	}

	cout << "\n";

}
