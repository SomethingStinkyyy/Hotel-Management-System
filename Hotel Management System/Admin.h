#pragma once
#include "Common_Functions.h"
#include "Caesar_Cipher.h"
#include <filesystem>

class Admin: public ENCRYPTION, public DECRYPTION, public Common_Functions //public access specified inheritance from ENCRYPTION and DECRYPTION classes
{
public:
	string USERNAME;
	string PASSWORD;

public:
	string LOWER_USERNAME; //variable for the username when converted into lower case
	bool LOGIN_SUCCESSFUL; //boolean variable to check success or failiure in login

	Admin(); //Default Constructor
	~Admin();

	void SET_USERNAME(string SET_THIS_USERNAME); //setter for the username

	void SET_PASSWORD(string SET_THIS_PASSWORD); //setter for the password

	string GET_USERNAME(); //getter for the username

	string GET_PASSWORD(); //getter for the password

	//LOGIN FUNCTION
	bool LOGIN(bool ITS_ADMIN); //login function that works based on whether it is the admin or not

	//FUNCTION FOR LOGIN VALIDATION
	virtual bool LOGIN_VALIDATION();

	//FUNCTION TO GET USERNAME AND PASSWORD
	string GET_LOGIN_DATA(const string& FILE_NAME);

	//ADMIN's MAIN MENU
	int MAIN_MENU(int choice);

	//1. ADMIN CUSTOMER MANAGEMENT 
	int ADMIN_CUSTOMER_MANAGEMENT(int choice);

	//1.1 ADD A CUSTOMER

	//1.2 REMOVE A CUSTOMER
	void REMOVE_CUSTOMER();

	//2. ADMIN CAB MANAGEMENT
	int CAB_MANAGEMENT(int choice);

	//3. ADMIN BOOKING MANAGEMENT

	//3.1 HOTEL ROOM MANAGEMENT
	int BOOKING_MANAGEMENT(int choice);

	//3.1.1 
	int ROOM_BOOKING_MANAGEMENT(int choice);

	//3.1.2
	int CONVENTION_HALL_BOOKING_MANAGEMENT(int choice);

	//3.1.3
	int RESTAURANT_RESERVATION_MANAGEMENT(int choice);

	//CHANGE PASSWORD
	virtual void CHANGE_PASSWORD();

	//CHECK IF FILE EXISTS
	bool CHECK_EXISTING_FILE(const string& FILE_NAME);

	//ENCRYPT
	void ENCRYPT(const string& FILE_NAME)override;

	//DECRYPT
	void DECRYPT(const string& FILE_NAME)override;
};

