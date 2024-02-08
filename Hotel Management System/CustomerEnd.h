#pragma once
#include "Common_Functions.h"

class CustomerEnd :public Common_Functions
{
public:
	CustomerEnd();
	~CustomerEnd();
	int operator()();
};
