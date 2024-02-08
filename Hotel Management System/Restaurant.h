#pragma once
#include "Client.h"
#include "Mode.h"

class Restaurant:virtual public Client, public Mode
{
public:
	Restaurant();
	~Restaurant();
	//check if the restaurant is booked or not
	void check();

	//booking the restaurant
	int update();

	virtual void displayCost() {};
};

