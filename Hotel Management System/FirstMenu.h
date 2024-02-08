#pragma once
#include "Common_Functions.h"

class FirstMenu:public Common_Functions
{
public:
	static int choice;

public:
	FirstMenu();
	~FirstMenu();
	int chooseMode();
	int operator()();
};

