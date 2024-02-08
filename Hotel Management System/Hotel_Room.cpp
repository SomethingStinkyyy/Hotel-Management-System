#include "Hotel_Room.h"
#include <iostream>
using namespace std;

Hotel_Room::Hotel_Room() {
	if (eduMode) {
		cout << "Hotel_Room-Constructor" << endl;
	}
}

Hotel_Room::~Hotel_Room() {
	if (eduMode) {
		cout << "Hotel_Room-Destructor" << endl;
	}
}

//extended the check function to check hotel rooms that are booked
void Hotel_Room::checkBooked()
{
	if (eduMode) {
		cout << "Hotel_Room-checkBooked" << endl;
	}
	//opening text file to read
	ifstream inf("./files/Bookings/hotelroom.txt");

	//if the text file is not available
	if (!inf)
	{
		cout << endl << "Unable to open Hotel Room file" << endl;
	}

	int roomNo, roomCost;
	string roomType; string roomBook;

	cout << endl << "Booked Hotel Rooms: " << endl;

	//reading the whole file to print available hotel rooms
	while (!inf.eof())
	{
		inf >> roomNo >> roomType >> roomCost >> roomBook;

		if (roomBook != "NULL")
			cout << roomNo << " " << roomType << " " << "Rs. " << roomCost << endl;
	}
	//closing the file
	inf.close();
}

//extended the check function to check hotel rooms that are vacant 
void Hotel_Room::check()
{
	if (eduMode) {
		cout << "Hotel_Room-check" << endl;
	}
	//opening text file to read
	ifstream inf("./files/Bookings/hotelroom.txt");

	//if the text file is not available
	if (!inf)
	{
		cout << endl << "Unable to open hotelroom file" << endl;
	}

	int roomNo, roomCost;
	string roomType; string roomBook;

	cout << endl << "Available Hotel Rooms: " << endl;

	//reading the whole file to print available hotel rooms
	while (true)
	{
		inf >> roomNo >> roomType >> roomCost >> roomBook;

		if (inf.eof())
		{
			break;
		}

		if (roomBook == "NULL")
			cout << roomNo << " " << roomType << " " << "Rs. " << roomCost << endl;
	}
	//closing the file
	inf.close();
}

//function to book a room
int Hotel_Room::update()
{
	if (eduMode) {
		cout << "Hotel_Room-update" << endl;
	}
	string cusID;
	cout << "Enter Customer ID: ";
	cin >> cusID;

	//taking information to book a specific room
	int target_roomNo;
		
	cout << "Enter Room Number to be booked: ";
	cin >> target_roomNo;

	//opening the text file to read and add booking
	ifstream inf("./files/Bookings/hotelroom.txt");
	ofstream outf("./files/Bookings/hotelroom1.txt");

	if (!inf) //if hotelroom.txt does not exist
	{
		cout << "\nUnable to open Hotel Room file.\n";
	}

	int roomNo, roomCost;
	string roomType, roomBook;

	//loop for accepting all data required to book the room
	while (true) //while loop runs until the end of file is reached
	{
		int x;

		inf >> roomNo >> roomType >> roomCost >> roomBook; //reads information in specific line

		if (inf.eof())
		{
			break;
		}

		if (roomNo == target_roomNo)
		{
			cout << roomNo << " " << roomType << " " << "Rs. " << roomCost << endl;

			//updating the room No with the customer ID to make it booked
			outf << roomNo << " " << roomType << " " << roomCost << " " << cusID << endl;
		}

		else
		{
			//if it is not the required room, then simply rewriting it as it was
			outf << roomNo << " " << roomType << " " << roomCost << " " << roomBook << endl;
		}
	}

	//closing the two files in order to save the update
	outf.close();
	inf.close();

	//deleting the previous text file and renaming the updated textfile to replace the previous 
	remove("./files/Bookings/hotelroom.txt");
	rename("./files/Bookings/hotelroom1.txt","./files/Bookings/hotelroom.txt");

	//return the cost of the client
	return roomCost;
}

//checking out a booked room so as to make it available again
void Hotel_Room::checkOut()
{
	if (eduMode) {
		cout << "Hotel_Room-checkOut" << endl;
	}
	string cusID;
	cout << "Enter the check out Customer ID: ";
	cin >> cusID;

	//read and write to the text file
	ifstream inf("./files/Bookings/hotelroom.txt");
	ofstream outf("./files/Bookings/hotelroom1.txt");

	if (!inf)
	{
		cout << endl << "Unable to open Hotel Room file\n";
	}

	int roomNo, roomCost;

	string roomType, roomBook;

	//updating the rooms which were previously in use to make them available for booking
	while (true)
	{
		inf >> roomNo >> roomType >> roomCost >> roomBook; //reads information in specific line

		if(inf.eof())
		{
			break;
		}

		if (roomBook == cusID)
		{
			cout << roomNo << " " << roomType << " " << "Rs. " << roomCost << endl;
			outf << roomNo << " " << roomType << " " << roomCost << " " << "NULL" << endl;
		}

		else
		{
			outf << roomNo << " " << roomType << " " << roomCost << " " << roomBook << endl;
		}
	}

	//closing the files and replacing the previous file 
	outf.close();
	inf.close();
	remove("./files/Bookings/hotelroom.txt");
	rename("./files/Bookings/hotelroom1.txt","./files/Bookings/hotelroom.txt");
}




