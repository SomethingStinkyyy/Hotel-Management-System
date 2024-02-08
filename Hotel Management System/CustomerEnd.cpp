#include "CustomerEnd.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Customer.h"
#include "Cabs.h"
#include "Client.h"
#include "Hotel_Room.h"
#include "Convention_Hall.h"
#include "Restaurant.h"
#include "Cost.h"
#include "Customer_Functions.h"

CustomerEnd::CustomerEnd() 
{
	if (eduMode) {
		cout << "CustomerEnd-Constructor" << endl;
	}
};

CustomerEnd::~CustomerEnd() {
	if (eduMode) {
		cout << "CustomerEnd-Destructor" << endl;
	}
}

int CustomerEnd::operator()()
{

	if (eduMode)
	{
		cout << "CustomerEnd-operator()" << endl;
	}

	bool itsAdmin = false; //identifier to test whether it is the admin or not
	bool itsCustomer;
	int choice = 0;

	Admin admin;
	Customer_Functions customer_functions;
	Customer customer;
	Cabs cabs;
	Client clientCharge;
	Hotel_Room hotel_room;
	Convention_Hall convention_hall;
	Restaurant restaurant;
	cost c;

	int cabCost = 0, roomCost = 0, resCost = 0, hallCost = 0;

	TITLE();

Registration_Screen:
	choice = customer.REGISTRATION_MENU(choice);

	switch (choice)
	{
	case 2:
	{
		CLS();
		TITLE();

		customer_functions.addCustomer();

		choice = 0;
		choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
		{
			if (choice == 1) //user selected previous menu
			{
				goto Registration_Screen;
			}

			else if (choice == 2) //user selected main menu
			{
				goto Login_Screen;
			}

			else //user selected exit
			{
				EXIT();
				return 0;
			}
		}
		break;
	}

	case 3: //return to previous menu
	{
		goto Registration_Screen;
	}

	case 4: //exit
	{
		EXIT();
		return 0;
	}

	case 1: //Login
	{
		//the following line "LOGIN_SCREEN:" is a label that can be referred by goto statements. It allows the program execution to 
		// jump to specified location within the funciton, unconditonally.
	Login_Screen:
		CLS();
		TITLE();
		//ADMIN Related Functions and Implementations
		if (!admin.LOGIN(itsAdmin)) //if, the username is not admin, then itsAdmin==0 is returned(tested by function)
		{
			customer.SET_USERNAME(admin.GET_USERNAME()); //since its not admin, it will be a customer

			if (customer.LOGIN_VALIDATION()) //if, the username and passwords match those stored in encrypted file, then, true is returned
			{
				//so
				itsAdmin = FALSE;
				itsCustomer = TRUE;

				//another label for goto functions
			Customer_Main_Menu:
				choice = customer.MAIN_MENU(choice); //returns the choice made by the user from the Main Menu

				switch (choice)
				{
				case 1: //user has chosen to book a room
				{
				Customer_Room_Booking_Menu:
					CLS();
					TITLE();
					choice = customer.ROOM_BOOKING_MANAGEMENT(choice);

					switch (choice)
					{
					case 1: //user has selected to check available rooms
					{
						CLS();
						TITLE();
						hotel_room.check();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Room_Booking_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 2: //user has selected to check booked rooms
					{
						CLS();
						TITLE();
						hotel_room.checkBooked();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Room_Booking_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to book a room
					{
						CLS();
						TITLE();
						roomCost += hotel_room.update();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Room_Booking_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 4:
					{
						CLS();
						TITLE();
						goto Customer_Main_Menu;
					}

					case 5:
					{
						EXIT();
						return 0;
					}

					}
					break;
				}

				case 2: //user has chosen to make a restaurant reservation
				{
				Customer_Restaurant_Menu:
					CLS();
					TITLE();

					choice = customer.RESTAURANT_RESERVATION_MANAGEMENT(choice);


					switch (choice)
					{
					case 1: //user has selected to check if restaurant is free or not
					{
						CLS();
						TITLE();
						restaurant.check();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Restaurant_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 2: //user has selected to book the restaurant
					{
						CLS();
						TITLE();
						resCost += restaurant.update();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Restaurant_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to return to Previous Menu
					{
						CLS();
						TITLE();
						goto Customer_Main_Menu;
					}

					case 4: //exit
					{
						EXIT();
						return 0;
					}
					}
					break;

				}

				case 3: //user has chosen to book the Convention Hall
				{
				Customer_Convention_Hall_Menu:
					CLS();
					TITLE();

					choice = customer.CONVENTION_HALL_BOOKING_MANAGEMENT(choice);

					switch (choice)
					{
					case 1: //user has selected to check if convention hall is free or not
					{
						CLS();
						TITLE();
						convention_hall.check();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Convention_Hall_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 2: //user has selected to book the convention hall
					{
						CLS();
						TITLE();
						hallCost += convention_hall.update();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Convention_Hall_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to return to Previous Menu
					{
						CLS();
						TITLE();
						goto Customer_Main_Menu;
					}

					case 4: //exit
					{
						EXIT();
						return 0;
					}
					}
					break;
				}

				case 4: //user has selected Cabs Management
				{
					//LABEL
				Cabs_Management_Menu:
					cout << flush;

					choice = customer.CAB_MANAGEMENT(choice);

					switch (choice)
					{
					case 1: //user has selected to rent a standard cab
					{
						CLS();
						TITLE();
						cabCost += cabs.stdCabBooking();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Cabs_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 2: //user has selected to rent a luxury cab
					{
						CLS();
						TITLE();
						cabCost += cabs.luxCabBooking();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Cabs_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to return to main menu
					{
						goto Customer_Main_Menu;
					}

					case 4: //user has selected to exit the program
					{
						EXIT();
						return 0;
					}

					}
					break;
				}

				case 5: //user has selected charges and bill
				{
					cout << flush;
					CLS();
					TITLE();

					string cusID;
					cout << "Enter Customer ID: ";
					cin >> cusID;
					cout << "\n\n";

					c.printBill(cusID, roomCost, resCost, hallCost, cabCost);

					c.showBill(cusID);

					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Customer_Main_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Customer_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 6: //user has selected to change account details
				{	
						customer.CHANGE_PASSWORD();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Customer_Main_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Customer_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}

						break;


				}

				case 7: //user selected to log out
				{
					CLS();
					TITLE();
					goto Registration_Screen;
				}

				case 8: //user selected to exit the program
				{
					EXIT();
					return 0;
				}

				}
			}

			else //incase the password was incorrect, we go back to login screen
			{

			choice = 0;
			choice = LOGIN_OR_REGISTER(choice);
			{
				if (choice == 1)
				{
					goto Login_Screen;
				}

				else if (choice == 2)
				{
					goto Registration_Screen;
				}


			}

				
			}
		}
	}
	}
}