#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class Client
{
public:

	//the following are the base class member functions for booking and costing functions
	//csv files are used to store and check user data
	//virtual functions are used to enable polymorphism

	virtual void check()
	{
		//placeholder
	};

	//virtual function for polymorphism (for booking)
	virtual int update()
	{
		//placeholder
		return 0;
	};
};

