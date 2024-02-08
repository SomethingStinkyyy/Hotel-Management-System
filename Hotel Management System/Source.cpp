#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Admin.h"
#include "Cabs.h"
#include "Customer_Functions.h"
#include "FirstMenu.h"
#include "AdminEnd.h"
#include "CustomerEnd.h"

using namespace std;

AdminEnd admin_end;
CustomerEnd customer_end;
FirstMenu f;

int main()
{
	First_Menu:
	int f_return = f(); //f() calls the operator function of FirstMenu class

	if (f_return == 1) {
		int admin_return = admin_end(); //admin_end() calls the operator function of AdminEnd class
		return admin_return;
	}

	else if (f_return == 2) 
	{
		int customer_return = customer_end(); //customer_end() calls the operator function of the CustomerEnd class
		return customer_return;
	}
	else 
	{
		return 0;
	}


	
	return 0;
}