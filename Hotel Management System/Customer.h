#pragma once
#include "Admin.h"

class Customer: public Admin
{
public:
	string customerPassword;

	Customer(); //default contractor
	~Customer();

	//LOGIN FUNCTION [OVERLOADED}
	bool LOGIN_VALIDATION();

	//REGISTER OR LOGIN
	int REGISTRATION_MENU(int choice);

	//CUSTOMER MAIN MENU[OVERLOADED]
	int MAIN_MENU(int choice);

	//CUSTOMER ROOM BOOKING [OVERLOADED]
	int ROOM_BOOKING_MANAGEMENT(int choice);

	//CUSTOMER CONVENTION HALL BOOKING [OVERLOADED]
	int CONVENTION_HALL_BOOKING_MANAGEMENT(int choice);

	//CUSTOMER RESTAURANT RESERVATION MANAGEMENT [OVERLOADED}
	int RESTAURANT_RESERVATION_MANAGEMENT(int choice);

	//CUSTOMER CAB MANAGEMENT [OVERLOADED]
	int CAB_MANAGEMENT(int choice);

	//CHANGE PASSWORD [OVERLOADED]
	void CHANGE_PASSWORD();
};
