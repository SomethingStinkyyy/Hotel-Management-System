#include "Common_Functions.h"

Common_Functions::Common_Functions() {

    if (eduMode) {
        cout << "Common_Functions-Constructor" << endl;
    }
}

Common_Functions::~Common_Functions() {

    if (eduMode) {
        cout << "Common_Functions-Destructor" << endl;
    }
}

//CLEAR THE CONSOLE SCREEN
void Common_Functions::CLS()
{
    if (eduMode) {
        cout << "Common_Functions-CLS" << endl;
    }
	system("cls"); //clearing the console screen by using stdlib.h library
}

//EXIT OR TERMINATE THE PROGRAM
void Common_Functions::EXIT()
{
    if (eduMode) {
        cout << "Common_Functions-EXIT" << endl;
    }
    cout << "\n\n\n";
    cout << "          __________________________________________________\n";
    cout << "         |             Terminating the Program...           |\n";
    cout << "         |__________________________________________________|\n";
    Sleep(1000); // waiting 1s before exiting
}

//TITLE SCREEN
void Common_Functions::TITLE()
{
    if (eduMode) {
        cout << "Common_Functions-TITLE" << endl;
    }
    cout << "\n\n";
    cout << "              ________________________________________________________________\n";
    cout << "             |                     HOTEL MANAGEMENT SYSTEM                    |\n";
    cout << "             |________________________________________________________________|\n";
    cout << "\n\n\n";
}

//RETURN TO MAIN MENU OR EXIT THE PROGRAM
int Common_Functions::MENUS_OR_EXIT(int choice)
{
    if (eduMode) {
        cout << "Common_Functions-MENUS_OR_EXIT" << endl;
    }
    cout << "\n\n";
    cout << "          >> Choose an option:\n\n";
    cout << "           ____________________________________________" << endl;
    cout << "          |1. Return to Previous Menu                  |" << endl;
    cout << "          |2. Go to Main Menu                          |" << endl;
    cout << "          |3. Exit                                     |" << endl;
    {
        cout << "\n          Choice: ";

        
        try     //Exception Handling incase of Wrong Input
        {      
            cin >> choice;
            if ((choice == 2) || (choice == 1) || (choice==3))
            {
                return choice; // returning right choice
            }
            else
            {
                throw choice; // throwing the bad input for choice
            }
        }

        catch (int choice)
        {
            cout << '\a';
            cin.clear();
            cin.ignore(256, '\n'); //ignores first 256 characters or all the characters until it enocounters the delimiter
            choice = 0;
            CLS();
            cout << flush; //buffer flush transfers computer data from temp storage to permanent memory

            for (int i = 3; i > 0; i--)  // incase of wrong input, user must wait for 3 seconds to try again, this prevents spamming
            {
                cout << "\n\n\n";
                cout << "          ___________________________________________________\n";
                cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
                cout << "         |___________________________________________________|\n";
                Sleep(1000);
                CLS();
            }
            TITLE();
            MENUS_OR_EXIT(choice);
        }
    }
}

//RETURN TO LOGIN OR REGISTRATION
int Common_Functions::LOGIN_OR_REGISTER(int choice)
{
    if (eduMode) 
    {
        cout << "Common_Functions-LOGIN_OR_REGISTER" << endl;
    }
    cout << "\n\n";
    cout << "          Your Login Credentials were Incorrect!\n\n";
    cout << "          >> Choose an option:\n\n";
    cout << "           ____________________________________________" << endl;
    cout << "          |1. Return to Login                          |" << endl;
    cout << "          |2. New User? Return to Registration Menu.   |" << endl;
    {
        cout << "\n          Choice: ";


        try     //Exception Handling incase of Wrong Input
        {
            cin >> choice;
            if ((choice == 2) || (choice == 1))
            {
                return choice; // returning right choice
            }
            else
            {
                throw choice; // throwing the bad input for choice
            }
        }

        catch (int choice)
        {
            cout << '\a';
            cin.clear();
            cin.ignore(256, '\n'); //ignores first 256 characters or all the characters until it enocounters the delimiter
            choice = 0;
            CLS();
            cout << flush; //buffer flush transfers computer data from temp storage to permanent memory

            for (int i = 3; i > 0; i--)  // incase of wrong input, user must wait for 3 seconds to try again, this prevents spamming
            {
                cout << "\n\n\n";
                cout << "          ___________________________________________________\n";
                cout << "         |  Wrong Choice, TRY AGAIN in " << i << " seconds...|\n";
                cout << "         |___________________________________________________|\n";
                Sleep(1000);
                CLS();
            }
            TITLE();
            LOGIN_OR_REGISTER(choice);
        }
    }
}
