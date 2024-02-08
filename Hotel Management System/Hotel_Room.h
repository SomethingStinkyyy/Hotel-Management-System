#pragma once
#include "Client.h"
#include "Mode.h"

using namespace std;

class Hotel_Room:virtual public Client, public Mode
{
public:
	//function to check vacant rooms
	Hotel_Room();
	~Hotel_Room();
	void check();

	//function to check booked rooms
	void checkBooked();

	//function to book a room
	int update();

	//function to check out a customer and free their rooms for booking
	void checkOut();

	//virtual function for polymorphism in derived class cost
	virtual void displayCost() {};
};

