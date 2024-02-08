#pragma once
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "Admin.h"
#include "Common_Functions.h"

using namespace std;

class Customer_Functions:public Admin
{
public:
	string f_name, l_name, gender; //first and last names
	int age, mobileNo;
	string cusId; //cusId refers to the identity card no.
	int discount_rate; //potential discounts available for the customer
	char all[999]; //for printing lines of text

	Customer_Functions();
	~Customer_Functions();
	void discounts();

	//Admin-1.1 Add Customer
	void addCustomer();

	//Admin-1.3 Show Customer ID list
	void showCustomerIDs();

	//Admin-1.4 Show specific Customer Details
	void showCustomerDetails();
};

