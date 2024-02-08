#include "Admin.h"
#include <algorithm>

Admin::Admin() //Default Constructor
{
	if (eduMode) {
		cout << "Admin-Constructor" << endl;
	}
	LOGIN_SUCCESSFUL = FALSE; //setting success of login to false intially
	
}

Admin::~Admin() {
	if (eduMode) {
		cout << "Admin-Destructor" << endl;
	}
}

void Admin::SET_USERNAME(string username) //setter for the username
{
	if (eduMode) 
	{
		cout << "Admin-SET_USERNAME" << endl;
	}
	USERNAME = username;
}

string Admin::GET_USERNAME() //getter for username
{
	if (eduMode) {
		cout << "Admin-GET_USERNAME" << endl;
	}
	return USERNAME;
}

void Admin::SET_PASSWORD(string password) //setter for password
{
	if (eduMode) {
		cout << "Admin-SET_PASSWORD" << endl;
	}
	PASSWORD = password;
}
string Admin::GET_PASSWORD() //getter for password
{
	if (eduMode) {
		cout << "Admin-GET_PASSWORD" << endl;
	}
	return PASSWORD;
}

//LOGIN FUNCTION
bool Admin::LOGIN(bool ITS_ADMIN)
{
	if (eduMode) {
		cout << "Admin-LOGIN" << endl;
	}

	cout << "               LOGIN            \n\n";
	cout << "Enter Username: " << flush; //flush is used to sent the output to the OS because COUT is line buffered
	cin >> USERNAME;

	LOWER_USERNAME = USERNAME;

	transform(LOWER_USERNAME.begin(), LOWER_USERNAME.end(), LOWER_USERNAME.begin(), ::tolower); //function that converts the string
	//into lower case, making it easier to compare uppercase+lowercase inputs from the user

	if (LOWER_USERNAME == "admin")
	{
		ITS_ADMIN = true;
		return ITS_ADMIN;
	}
	else
	{
		ITS_ADMIN = FALSE;
		return ITS_ADMIN;
	}
}

//FUNCTION FOR LOGIN VALIDATION
bool Admin::LOGIN_VALIDATION()
{
	if (eduMode) {
		cout << "Admin-LOGIN_VALIDATION" << endl;
	}
	cout << "Enter Password: " << flush;
	cin >> PASSWORD;

	string ADMIN_FILE_PATH = "./files/Admin/ADMIN_USERNAME.txt"; //the file path containing the admins username
	string CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str()); //this function returns with a line [username] from the text file

	try //Exception handling in case of unsuccesful login
	{
		if (CHECK == USERNAME)
		{
			ADMIN_FILE_PATH = "./files/Admin/ADMIN_PASSWORD.txt"; //now the admin file we care about is the one with the password
			DECRYPT(ADMIN_FILE_PATH.c_str()); //calling the decrypt function so that we can obtain the actual password from encryption
			
			CHECK = GET_LOGIN_DATA(ADMIN_FILE_PATH.c_str()); //this functions returns with a line [password] from the text file above

			if (CHECK == PASSWORD)
			{
				cout << "LOGIN SUCCESFUL!" << endl;
				LOGIN_SUCCESSFUL = true;

				ENCRYPT(ADMIN_FILE_PATH.c_str()); //re-encrypting the password
				
				return true;
			}

			else 
			{ //when password is wrong
				ENCRYPT(ADMIN_FILE_PATH.c_str()); //even if the login fails, the password must be re-encrypted
				throw LOGIN_SUCCESSFUL; //throwing the exception
			}
		}
		else
		{ //when username is wrong
			throw LOGIN_SUCCESSFUL; //Username does not match, so it might be a student or bad username input
		}
	}
	catch (bool LOGIN_SUCCESSFUl) //catch the thrown exception
	{
		UNREFERENCED_PARAMETER(LOGIN_SUCCESSFUL); //online solution for warnings when catching the bool
		CLS(); //clear screen

		cout << flush;//NOTE ON flush: endl adds an end of line characters to the output before flushing the buffers. flush only flushes. 
		
		TITLE(); //show title screen 
		cout << "Login Failed, please try again..." << endl << endl;
		bool ITS_ADMIN = false;
		return FALSE;
	}
}

//GETTING USERNAME AND PASSWORD
string Admin::GET_LOGIN_DATA(const string& FILE_NAME)
{
	if (eduMode) {
		cout << "Admin-GET_LOGIN_DATA" << endl;
	}
	string LINE;
	fstream READ; //fstream is a combination of ifstream and ofstream

	READ.open(FILE_NAME.c_str(), ios::in); //creates a file for READ, associates it with the stream
	{
		if (READ.is_open()) //if file exists = true, then
		{
			getline(READ, LINE); //reads a line from the file [username/password] to LINE
		}
	}
	READ.close(); //closes the READ file associated with the stream

	return LINE; //returning the read data
}

//ADMIN's MAIN MENU
int Admin::MAIN_MENU(int choice)
{
	CLS();
	if (eduMode) 
	{
		cout << "Admin-ADMIN_MAIN_MENU" << endl;
	}
	TITLE();

	cout << "You have logged in as ADMINISTRATOR..." << endl << endl << endl;

	cout << "-------------Hotel Management System------------" << endl;
	cout << "---------------Main Menu-----------------"   << endl;
	cout << "__________________________________________"  << endl;
	cout << "|                                        | " << endl;
	cout << "| Customer Management       -> 1         | " << endl;
	cout << "| Booking Management        -> 2         | " << endl;
	cout << "| Cabs Management           -> 3         | " << endl;
	cout << "| Charges and Bill          -> 4         | " << endl;
	cout << "| Change Password           -> 5         |"  << endl;
	cout << "| Log Out                   -> 6         |"  << endl;
	cout << "| Exit                      -> 7         | " << endl;
	cout << "|________________________________________| " << endl << endl << endl;
	{
		cout << "\n          Choice: ";

		try //Exception Handling incase of Wrong Input
		{      
			cin >> choice;
			if ((choice <= 7) && (choice >= 1)) //the choice is within an acceptable range
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
			for (int i = 3; i > 0; i--) //wait for 3 seconds
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

int Admin::ADMIN_CUSTOMER_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Admin-ADMIN_CUSTOMER_MANAGEMENT" << endl;
	}
	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Register New Customer                    |" << endl;
	cout << "          |2. Remove Customer                          |" << endl; 
	cout << "          |3. View List of Customer IDs                |" << endl;
	cout << "          |4. View Details of a Customer               |" << endl;
	cout << "          |5. Return to Main Menu                      |" << endl;
	cout << "          |6. Exit                                     |" << endl;
	{
		cout << "\n          Choice: ";

		try     //Exception Handling incase of Wrong Input
		{
			cin >> choice;
			if ((choice <= 6) && (choice >= 1))
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
			ADMIN_CUSTOMER_MANAGEMENT(choice);
		}
	}
}

void Admin::REMOVE_CUSTOMER()
{
	CLS();
	TITLE();

	cout << "              __________________________________________________\n";
	cout << "             |                 REMOVE A CUSTOMER                |\n";
	cout << "             |__________________________________________________|\n";
	cout << "\n";
	cout << "            >> Please be aware, that removing a Customer will also remove all of his/her submitted reservations!" << endl << endl;

	string ID;
	cout << "              Enter Customer's ID(NIC): ";
	cin >> ID;

	string FILE_PATH = "./files/Customers/" + ID + ".txt";

	if (!CHECK_EXISTING_FILE(FILE_PATH.c_str()))
	{
		cout << "\n\n\n";
		cout << "          __________________________________________________\n";
		cout << "         |  No Customer exists under this ID number...      |\n";
		cout << "         |__________________________________________________|\n";
	}
	else
	{
		remove(FILE_PATH.c_str());//removing customer
		string FILE_PATH = "./files/Customers/Customer-Records/" + ID + ".txt";//...changing path to recorded details
		remove(FILE_PATH.c_str());//removing recorded details

		cout << "\n\n\n";
		cout << "          __________________________________________________\n";
		cout << "         |  Customer Removed Successfully...                |\n";
		cout << "         |__________________________________________________|\n";
	}


}

int Admin::CAB_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Admin-ADMIN_CAB_MANAGEMENT" << endl;
	}
	TITLE();

	cout << "Experience a travel experience like no other with ABC cabs...\n\n";

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Rent a Standard Cab                      |" << endl;
	cout << "          |2. Rent a Luxury Cab                        |" << endl;
	cout << "          |3. View Cab Booking Records                 |" << endl;
	cout << "          |4. Return to Main Menu                      |" << endl;
	cout << "          |5. Exit                                     |" << endl;

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
			CAB_MANAGEMENT(choice);
		}
}

int Admin::BOOKING_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Admin-BOOKING_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Hotel Room Booking                       |" << endl;
	cout << "          |2. Convention Hall Booking                  |" << endl;
	cout << "          |3. Restaurant Reservations                  |" << endl;
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
			BOOKING_MANAGEMENT(choice);
		}
	}
}

int Admin::ROOM_BOOKING_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Admin-ROOM_BOOKING_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check Available Rooms                    |" << endl;
	cout << "          |2. Check Booked Rooms                       |" << endl;
	cout << "          |3. Book a Room                              |" << endl;
	cout << "          |4. Checkout a Customer                      |" << endl;
	cout << "          |5. Return to Booking Management Menu        |" << endl;
	cout << "          |6. Exit                                     |" << endl;
	{
		cout << "\n          Choice: ";

		try     //Exception Handling incase of Wrong Input
		{
			cin >> choice;
			if ((choice <= 6) && (choice >= 1))
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

int Admin::CONVENTION_HALL_BOOKING_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) {
		cout << "Admin-CONVENTION_HALL_BOOKING_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check if Convention Hall is free         |" << endl;
	cout << "          |2. Make a Booking                           |" << endl;
	cout << "          |3. Convention Hall Booking Records          |" << endl;
	cout << "          |4. Return to Booking Management Menu        |" << endl;
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
			CONVENTION_HALL_BOOKING_MANAGEMENT(choice);
		}
	}

}

int Admin :: RESTAURANT_RESERVATION_MANAGEMENT(int choice)
{
	CLS();
	if (eduMode) 
	{
		cout << "Admin-RESTAURANT_RESERVATION_MANAGEMENT" << endl;
	}

	TITLE();

	cout << "          >> Please choose one of the following options:\n\n";

	cout << "           ____________________________________________" << endl;
	cout << "          |1. Check Restaurant Reservations            |" << endl;
	cout << "          |2. Make a Reservation                       |" << endl;
	cout << "          |3. Return to Booking Management Menu        |" << endl;
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

//CHANGE PASSWORD
void Admin::CHANGE_PASSWORD()
{
	CLS();
	if (eduMode) {
		cout << "Admin-CHANGE_PASSWORD" << endl;
	}
	TITLE();
	cout << "              ________________________________________________\n";
	cout << "             |             CHANGE YOUR PASSWORD               |\n";
	cout << "             |________________________________________________|\n";
	cout << "\n";

	string newPassword;
	cout << "               >> Enter your NEW PASSWORD: ";
	cin >> newPassword;

	string filePath = "./Admin/ADMIN_PASSWORD.txt";

	ofstream OVERWRITE;
	OVERWRITE.open(filePath.c_str()); // opening in default [over-write] mode, so as to overwrite the previous password
	{
		OVERWRITE << newPassword; // over writing the old password
	}
	OVERWRITE.close();

	ENCRYPT(filePath.c_str()); // encrypting the new password

	cout << "              ________________________________________________\n";
	cout << "             |           PASSWORD CHANGED SUCCESSFULLY.       |\n";
	cout << "             |________________________________________________|\n";
	cout << "\n";
}

bool Admin::CHECK_EXISTING_FILE(const string& FILE_NAME)
{
	fstream READ;
	READ.open(FILE_NAME.c_str(), ios::in);
	{
		if (READ.is_open()) // file exists and thus, can be opened
		{
			READ.close();
			return TRUE; // file found
		}
		return false; // file not found
	}
}

//ENCRYPT
void Admin::ENCRYPT(const string& fileName)
{
	if (eduMode) {
		cout << "Admin-ENCRYPT" << endl;
	}
	string data;

	fstream READ;
	READ.open(fileName.c_str(), ios::in); //read and opne the line in given file name
	{
		getline(READ, data); //write the read line in READ

		for (unsigned int x = 0; x < data.length(); x++)
		{
			data[x] += 3; // by using the simple ceasar cipher algorithm
						  //add a number to each character 
						  //and encrypt the whole string character by character
		}
	}
	READ.close();

	ofstream OVERWRITE;

	OVERWRITE.open(fileName.c_str());
	{
		OVERWRITE << data; // over-write the old data with new encrypted data
	}
	OVERWRITE.close();
}

//DECRYPT
void Admin::DECRYPT(const string& fileName)
{
	if (eduMode) {
		cout << "Admin-DECRYPT" << endl;
	}
	string data;

	fstream READ;
	READ.open(fileName.c_str(), ios::in);
	{
		getline(READ, data);
		for (unsigned int x = 0; x < data.length(); x++)
		{
			data[x] -= 3;// by using the simple ceasar cipher algorithm
						  //subtract a number from each character 
						  //and decrypt the string character by character
		}
	}
	READ.close();

	ofstream OVERWRITE;
	OVERWRITE.open(fileName.c_str());
	{
		OVERWRITE << data;// over-write the old data with new decrypted data
	}
	OVERWRITE.close();
}