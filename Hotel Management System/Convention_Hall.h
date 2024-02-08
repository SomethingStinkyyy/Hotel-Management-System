#pragma once
#include "Client.h"
#include "Mode.h"
#include <iomanip>

class Convention_Hall:virtual public Client, public Mode
{
public:
	Convention_Hall();
	~Convention_Hall();
	//check function to check if the hall is empty at the required time
	void check();

	void checkAll();

	//add a booking
	int update();

	virtual void displayCost() {};
};

