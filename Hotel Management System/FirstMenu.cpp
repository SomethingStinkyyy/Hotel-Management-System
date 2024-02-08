#include "FirstMenu.h"
#include "Mode.h"
#include <Windows.h>
#include <iostream>
using namespace std;

int FirstMenu::choice;

FirstMenu::FirstMenu() 
{
    if (eduMode) {
        cout << "FirstMenu-Constructor" << endl;
    }
}

FirstMenu::~FirstMenu() 
{
    if (eduMode) {
        cout << "FirstMenu-Destructor" << endl;
    }
}

int FirstMenu::chooseMode() 
{

    if (eduMode) {
        cout << "FirstMenu-chooseMode" << endl;
    }

mode_menu:
    TITLE();
    cout << "\n\n";
    cout << "          >> Choose The Mode:\n\n";
    cout << "           ____________________________________________" << endl;
    cout << "          |1. Education Mode                           |" << endl;
    cout << "          |2. Regular Mode                             |" << endl;
    cout << "          |3. Exit                                     |" << endl;

    cout << "\n          Choice: ";

    try     //Exception Handling incase of Wrong Input
    {
        cin >> choice;
        if ((choice == 2) || (choice == 1) || (choice == 3))
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
        goto mode_menu;
    }
}

int FirstMenu::operator()() //using operators for the function call
{

    if (eduMode) {
        cout << "FirstMenu-operator()" << endl;
    }

    int mode = chooseMode();

    if (mode == 1) {
        Mode::eduMode = true;
    }
    else if (mode == 2) {
        Mode::eduMode = false;
    }
    else {
        return 3;
    }

    CLS();
    TITLE();

    first_menu:

    int choice;

    cout << "\n\n";
    cout << "          >> Are you an Admin or a Customer:\n\n";
    cout << "           ____________________________________________" << endl;
    cout << "          |1. Admin Menu                               |" << endl;
    cout << "          |2. Customer Menu                            |" << endl;
    cout << "          |3. Exit                                     |" << endl;
    {
        cout << "\n          Choice: ";

        try     //Exception Handling incase of Wrong Input
        {
            cin >> choice;
            if ((choice == 2) || (choice == 1) || (choice == 3))
            {
                CLS();
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
            goto first_menu;
        }
    }
}
