#include "AdminEnd.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h>
#include "Admin.h"
#include "Cabs.h"
#include "Client.h"
#include "Hotel_Room.h"
#include "Convention_Hall.h"
#include "Restaurant.h"
#include "Cost.h"
#include "Customer_Functions.h"

using namespace std;

AdminEnd::AdminEnd() 
{
	if (eduMode) {
		cout << "AdminEnd-Constructor" << endl;
	}
};

AdminEnd::~AdminEnd() 
{
	if (eduMode) {
		cout << "AdminEnd-Destructor" << endl;
	}
}

int AdminEnd::operator()() 
{

	if (eduMode) 
	{
		cout << "AdminEnd-operator()" << endl;
	}

	bool itsAdmin = true; //identifier to test whether it is the admin or not
	bool itsCustomer;
	int choice = 0;

	Admin admin;
	Customer_Functions customer;
	Cabs cabs;
	Client clientCharge;
	Hotel_Room hotel_room;
	Convention_Hall convention_hall;
	Restaurant restaurant;
	cost c;

	int cabCost=0, roomCost=0, resCost=0, hallCost=0;

	TITLE();

	//the following line "LOGIN_SCREEN:" is a label that can be referred by goto statements. It allows the program execution to 
	// jump to specified location within the funciton, unconditonally.
Login_Screen:
	//ADMIN Related Functions and Implementations
	if (admin.LOGIN(itsAdmin)) //if, the username is admin, then itsAdmin==1 is returned(tested by function)
	{
		if (admin.LOGIN_VALIDATION()) //if, the username and passwords match those stored in encrypted file, then, itsAdmin==1 is returned
		{
			//so
			itsAdmin = TRUE;
			itsCustomer = FALSE;

			//another label for goto functions
		Admin_Main_Menu:
			choice = admin.MAIN_MENU(choice); //returns the choice made by the user from the Main Menu

			switch (choice)
			{
			case 1: //user has selected Customer Management
			{
				//LABEL
			Customer_Management_Menu:
				cout << flush;

				choice = admin.ADMIN_CUSTOMER_MANAGEMENT(choice);

				switch (choice)
				{
				case 1: //user has selected Add Customer
				{
					CLS();
					TITLE();
					customer.addCustomer();

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Customer_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 2: //user has selected Remove Customer
				{
					CLS();
					TITLE();
					
					customer.REMOVE_CUSTOMER();

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Customer_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 3: //user has selected to view the list of Customer IDs
				{
					CLS();
					TITLE();
					customer.showCustomerIDs();

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Customer_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 4: //user has selected to view the details of a Customer ID
				{
					CLS();
					TITLE();
					customer.showCustomerDetails();

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Customer_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 5: //user has selected to return to Main Menu
				{
					goto Admin_Main_Menu;
				}

				case 6: //user has selected to exit the program
				{
					EXIT();
					return 0;
				}

				}
				break;
			}

			case 2: //user has selected booking management
			{
				Booking_Management_Menu:
				cout << flush;
				choice = admin.BOOKING_MANAGEMENT(choice);

				switch (choice)
				{
				case 1: //user has selected Hotel Room Booking
				{
					Room_Booking_Management_Menu:
					CLS();
					TITLE();
					choice = admin.ROOM_BOOKING_MANAGEMENT(choice);

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
								goto Room_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
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
								goto Room_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
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
						roomCost+=hotel_room.update();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Room_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 4: //user has selected to checkout a customer
					{
						CLS();
						TITLE();
						hotel_room.checkOut();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Room_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 5:
					{
						CLS();
						TITLE();
						goto Booking_Management_Menu;
					}

					case 6:
					{
						EXIT();
						return 0;
					}

					}
					break;
				}

				case 2: //user has selected Convention Hall Booking
				{
					Convention_Hall_Booking_Management_Menu:
					CLS();
					TITLE();

					choice = admin.CONVENTION_HALL_BOOKING_MANAGEMENT(choice);

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
								goto Convention_Hall_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
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
								goto Convention_Hall_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to check the records of convention hall booking
					{
						CLS();
						TITLE();
						convention_hall.checkAll();

						choice = 0;
						choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
						{
							if (choice == 1) //user selected previous menu
							{
								goto Convention_Hall_Booking_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 4: //user has selected to return to Booking Management Menu
					{
						CLS();
						TITLE();
						goto Booking_Management_Menu;
					}

					case 5: //exit
					{
						EXIT();
						return 0;
					}
					}
					break;
				}

				case 3: //user has selected Restaurant Reservation Management
				{
					Restaurant_Reservation_Management_Menu:
					CLS();
					TITLE();

					choice = admin.RESTAURANT_RESERVATION_MANAGEMENT(choice);


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
								goto Restaurant_Reservation_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
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
								goto Restaurant_Reservation_Management_Menu;
							}

							else if (choice == 2) //user selected main menu
							{
								goto Admin_Main_Menu;
							}

							else //user selected exit
							{
								EXIT();
								return 0;
							}
						}
						break;
					}

					case 3: //user has selected to return to Booking Management Menu
					{
						CLS();
						TITLE();
						goto Booking_Management_Menu;
					}

					case 4: //exit
					{
						EXIT();
						return 0;
					}
					}
					break;
				}

				case 4: //user has selected to return to main menu
				{
					goto Admin_Main_Menu;
				}

				case 5: //user has selected to exit the program
				{
					EXIT();
					return 0;
				}

				}
				break;
			}

			case 3: //user has selected Cabs Management
			{
				//LABEL
			Cabs_Management_Menu:
				cout << flush;

				choice = admin.CAB_MANAGEMENT(choice);

				switch (choice)
				{
				case 1: //user has selected to rent a standard cab
				{
					CLS();
					TITLE();
					cabCost += cabs.stdCabBooking(); //adding cost to cab cost

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Cabs_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
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
					cabCost += cabs.luxCabBooking(); //adding cost to cost_cnt

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Cabs_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 3: //user has selected to print all cab records
				{
					CLS();
					TITLE();
					cabs.printRecords();

					choice = 0;
					choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
					{
						if (choice == 1) //user selected previous menu
						{
							goto Cabs_Management_Menu;
						}

						else if (choice == 2) //user selected main menu
						{
							goto Admin_Main_Menu;
						}

						else //user selected exit
						{
							EXIT();
							return 0;
						}
					}
					break;
				}

				case 4: //user has selected to return to main menu
				{
					goto Admin_Main_Menu;
				}

				case 5: //user has selected to exit the program
				{
					EXIT();
					return 0;
				}

				}
				break;
			}

			case 4: //user has selected charges and bill
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
						goto Admin_Main_Menu;
					}

					else if (choice == 2) //user selected main menu
					{
						goto Admin_Main_Menu;
					}

					else //user selected exit
					{
						EXIT();
						return 0;
					}
				}
				break;
			}

			case 5: //user has selected change password
			{
				admin.CHANGE_PASSWORD();

				choice = MENUS_OR_EXIT(choice); //returns choice based on whether the user wishes to return to menu or exit
				{
					if (choice == 1) //user selected previous menu
					{
						goto Admin_Main_Menu;
					}

					else if (choice == 2) //user selected main menu
					{
						goto Admin_Main_Menu;
					}

					else //user selected exit
					{
						EXIT();
						return 0;
					}
				}
				break;
			}

			case 6: //user selected to log out
			{
				CLS();
				TITLE();
				goto Login_Screen;
			}

			case 7: //user selected to exit the program
			{
				EXIT();
				return 0;
			}

			}
		}

		else //in case the password was incorrect, we go back to login screen
		{
			goto Login_Screen;
		}
	}
}
