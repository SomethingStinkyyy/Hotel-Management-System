#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <windows.h>
#include <stdio.h>
#include <filesystem>
#include "Mode.h"
using namespace std;

class Common_Functions: public Mode {
public:
	Common_Functions();
	~Common_Functions();
	//CLEAR THE CONSOLE SCREEN
	void CLS();

	//EXIT OR TERMINATE THE PROGRAM
	void EXIT();

	//PRINT THE TITLE SCREEN
	void TITLE();

	//RETURN TO MAIN MENU OR EXIT THE PROGRAM
	int MENUS_OR_EXIT(int choice);

	//RETURN TO LOGIN OR REGISTER
	int LOGIN_OR_REGISTER(int choice);
};
