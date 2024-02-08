#pragma once
#include "Customer_Functions.h"
#include "Admin.h"
#include "Common_Functions.h"
#include "Client.h"

class Cabs : public Customer_Functions, virtual public Client
{
public:
	float kilometers;
	float cabCost;
	string time;
	string date;
	float lastcabCost=0;
	float stdcab_rate, luxcab_rate;

	Cabs();
	~Cabs();

	int stdCabBooking();
	int luxCabBooking();
	void printRecords();

};

