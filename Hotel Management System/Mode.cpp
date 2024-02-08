#include "Mode.h"
#include <iostream>
using namespace std;

bool Mode::eduMode;

Mode::Mode() {
	if (eduMode) {
		cout << "Mode-Constructor" << endl;
	}
}

Mode::~Mode() {
	if (eduMode) {
		cout << "Mode-Destructor" << endl;
	}
}
