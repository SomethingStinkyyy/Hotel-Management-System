#include "Customer.h"

Customer::Customer() //DEFAULT CONSTRUCTOR
{
	if (eduMode) {
		cout << "Customer-Constructor" << endl;
	}
	LOGIN_SUCCESSFUL = false;
}

Customer::~Customer() {
	if (eduMode) {
		cout << "Customer-Destructor" << endl;
	}
}

//LOGIN VALIDATION FUNCTION [OVERLOADED]
bool Customer::LOGIN_VALIDATION()
{
	if (eduMode) 
	{
		cout << "Customer-LOGIN_VALIDATION" << endl;
	}

	cout << "Enter your password: " << flush;
	cin >> customerPassword;

	SET_PASSWORD(customerPassword);
	string CUSTOMER_FILE_PATH = "./files/Customers/" + GET_USERNAME() + ".txt";

	fstream CHECK_FILE_EXIST;

	CHECK_FILE_EXIST.open(CUSTOMER_FILE_PATH.c_str(), ios::in);

	if (CHECK_FILE_EXIST.is_open())
	{
		CHECK_FILE_EXIST.close();

		DECRYPT(CUSTOMER_FILE_PATH.c_str());

		string CHECK = GET_LOGIN_DATA(CUSTOMER_FILE_PATH.c_str());

		try //exception handling in case of unsuccesful login
		{
			if (CHECK == GET_PASSWORD())
			{
				cout << "LOGIN SUCCESSFUL...!" << endl;
				LOGIN_SUCCESSFUL = true;
				ENCRYPT(CUSTOMER_FILE_PATH.c_str());
				return TRUE;
			}

			else
			{
				ENCRYPT(CUSTOMER_FILE_PATH.c_str());
				throw LOGIN_SUCCESSFUL;
			}
		}

		catch (bool LOGIN_SUCCESSFUL)
		{
			UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL);
			CLS();
			cout << flush;
			TITLE();
			cout << "Login failed, Try Again..." << endl << endl;

			bool itsStudent = FALSE;
			return FALSE;



		}
	}

	else
	{
		CLS();
		cout << flush;
		TITLE();
		cout << "Login failed, Try Again..." << endl << endl;
		bool itsStudent = FALSE;
		return FALSE;
	}
}

//REGISTRATION OR LOGIN
int Customer::REGISTRATION_MENU(int choice)
{
	CLS();
	if (eduMode)
	{
		cout << "Customer-REGISTRATION_MENU" << endl;
	}

	TITLE();
	cout << "\n\n";
	cout << "          >> Welcome!\n\n";
	cout << "           ____________________________________________" << endl;
	cout << "          |1. Are you a returning Customer?            |" << endl;
    cout << "          |   Login to an existing account             |" << endl;
	cout << "          |2. Are you a new Customer?                  |" << endl;
	cout << "          |   Create a new account                     |" << endl;
	cout << "          |3. Return to Previous Menu                  |" << endl;
	cout << "          |4. Exit                                     |" << endl;

	{
		cout << "\n          Choice: ";


		try     //Exception Handling incase of Wrong Input 
		{
			cin >> choice;
			if ((choice <= 4) && (choice >= 1))
			{
				return choice;
			}
			else
			{
				throw choice;
			}
		}
		catch (int choice)
		{
			cout << '\a';
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
			CLS();
			cout << flush;
			for (int i = 3; i > 0; i--)
			{
				cout << "\n\n\n";
				cout << "          ___________________________________________________\n";
				cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
				cout << "         |___________________________________________________|\n";
				Sleep(1000);
				CLS();
			}
			REGISTRATION_MENU(choice);
		}
	}
}

//CUSTOMER MAIN MENU [OVERLOADED]
int Customer::MAIN_MENU(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Customer-MAIN_MENU" << endl;
	}
	TITLE();
	cout << "          Welcome..." << endl << endl << endl;

	cout << "         -------------Hotel Customer Portal------------" << endl;
	cout << "               -------------Main Menu-------------     " << endl;
	cout << "           ____________________________________________" << endl;
	cout << "          |1. Book a Room                              |" << endl;
	cout << "          |2. Make a Restaurant Reservation            |" << endl;
	cout << "          |3. Book the Convention Hall                 |" << endl;
	cout << "          |4. Book a Cab                               |" << endl;
	cout << "          |5. Get Bill                                 |" << endl;
	cout << "          |6. Change Password                          |" << endl;
	cout << "          |7. Log Out                                  |" << endl;
	cout << "          |8. Exit                                     |" << endl;


	{
		cout << "\n          Choice: ";


		try     //Exception Handling incase of Wrong Input 
		{ 
			cin >> choice;
			if ((choice <= 8) && (choice >= 1))
			{
				return choice;
			}
			else
			{
				throw choice;
			}
		}
		catch (int choice)
		{
			cout << '\a';
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
			CLS();
			cout << flush;
			for (int i = 3; i > 0; i--)
			{
				cout << "\n\n\n";
				cout << "          ___________________________________________________\n";
				cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
				cout << "         |___________________________________________________|\n";
				Sleep(1000);
				CLS();
			}
			MAIN_MENU(choice);
		}
	}
}

int Customer::ROOM_BOOKING_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) 
	{
		cout << "Customer-ROOM_BOOKING_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check Available Rooms                    |" << endl;
	cout << "          |2. Check Booked Rooms                       |" << endl;
	cout << "          |3. Book a Room                              |" << endl;
	cout << "          |4. Return to Main Menu                      |" << endl;
	cout << "          |5. Exit                                     |" << endl;
	{
		cout << "\n          Choice: ";

		try     //Exception Handling incase of Wrong Input
		{
			cin >> choice;
			if ((choice <= 5) && (choice >= 1))
			{
				return choice;
			}
			else
			{
				throw choice;
			}
		}
		catch (int choice)
		{
			cout << '\a';
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
			CLS();
			cout << flush;
			for (int i = 3; i > 0; i--)
			{
				cout << "\n\n\n";
				cout << "          ___________________________________________________\n";
				cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
				cout << "         |___________________________________________________|\n";
				Sleep(1000);
				CLS();
			}
			ROOM_BOOKING_MANAGEMENT(choice);
		}
	}

}

int Customer::CONVENTION_HALL_BOOKING_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Customer-CONVENTION_HALL_BOOKING_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check if Convention Hall is free         |" << endl;
	cout << "          |2. Make a Booking                           |" << endl;
	cout << "          |3. Return to Main Menu                      |" << endl;
	cout << "          |4. Exit                                     |" << endl;
	{
		cout << "\n          Choice: ";

		try     //Exception Handling incase of Wrong Input
		{
			cin >> choice;
			if ((choice <= 4) && (choice >= 1))
			{
				return choice;
			}
			else
			{
				throw choice;
			}
		}
		catch (int choice)
		{
			cout << '\a';
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
			CLS();
			cout << flush;
			for (int i = 3; i > 0; i--)
			{
				cout << "\n\n\n";
				cout << "          ___________________________________________________\n";
				cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
				cout << "         |___________________________________________________|\n";
				Sleep(1000);
				CLS();
			}
			CONVENTION_HALL_BOOKING_MANAGEMENT(choice);
		}
	}
}

int Customer::RESTAURANT_RESERVATION_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode)
	{
		cout << "Customer-RESTAURANT_RESERVATION_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check Restaurant Reservations            |" << endl;
	cout << "          |2. Make a Reservation                       |" << endl;
	cout << "          |3. Return to Main Menu                      |" << endl;
	cout << "          |4. Exit                                     |" << endl;
	{
		cout << "\n          Choice: ";

		try     //Exception Handling incase of Wrong Input
		{
			cin >> choice;
			if ((choice <= 4) && (choice >= 1))
			{
				return choice;
			}
			else
			{
				throw choice;
			}
		}
		catch (int choice)
		{
			cout << '\a';
			cin.clear();
			cin.ignore(256, '\n');
			choice = 0;
			CLS();
			cout << flush;
			for (int i = 3; i > 0; i--)
			{
				cout << "\n\n\n";
				cout << "          ___________________________________________________\n";
				cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
				cout << "         |___________________________________________________|\n";
				Sleep(1000);
				CLS();
			}
			RESTAURANT_RESERVATION_MANAGEMENT(choice);
		}
	}
}

int Customer::CAB_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) 
	{
		cout << "Customer-CAB_MANAGEMENT" << endl;
	}
	TITLE();

	cout << "Experience a travel experience like no other with ABC cabs...\n\n";

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Rent a Standard Cab                      |" << endl;
	cout << "          |2. Rent a Luxury Cab                        |" << endl;
	cout << "          |3. Return to Main Menu                      |" << endl;
	cout << "          |4. Exit                                     |" << endl;

	cout << "\n          Choice: ";

	try     //Exception Handling incase of Wrong Input
	{
		cin >> choice;
		if ((choice <= 4) && (choice >= 1))
		{
			return choice;
		}
		else
		{
			throw choice;
		}
	}
	catch (int choice)
	{
		cout << '\a';
		cin.clear();
		cin.ignore(256, '\n');
		choice = 0;
		CLS();
		cout << flush;
		for (int i = 3; i > 0; i--)
		{
			cout << "\n\n\n";
			cout << "          ___________________________________________________\n";
			cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
			cout << "         |___________________________________________________|\n";
			Sleep(1000);
			CLS();
		}
		CAB_MANAGEMENT(choice);
	}
}

//CHANGE PASSWORD [OVERLOADED]
void Customer::CHANGE_PASSWORD()
{
	CLS();
	if (eduMode) {
		cout << "Customer-CHANGE_PASSWORD" << endl;
	}
	TITLE();
	cout << "              ________________________________________________\n";
	cout << "             |             CHANGE YOUR PASSWORD               |\n";
	cout << "             |________________________________________________|\n";
	cout << "\n";

	string newPassword;
	cout << "               >> Enter your new password: ";
	cin >> newPassword;

	string filePath = "./files/Customers/" + GET_USERNAME() + ".txt";
	ofstream OVER_WRITE;

	OVER_WRITE.open(filePath.c_str());
	{
		OVER_WRITE << newPassword;
	}
	OVER_WRITE.close();

	ENCRYPT(filePath.c_str());

	cout << "              ________________________________________________\n";
	cout << "             |           PASSWORD CHANGED SUCCESSFULLY...     |\n";
	cout << "             |________________________________________________|\n";
	cout << "\n";
}
