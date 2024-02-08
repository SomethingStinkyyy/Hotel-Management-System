#pragma once
#include <iostream>
#include <string>
#include "Mode.h"

using namespace std;

/*Caesar Cipher is an extremely basic encryption method. It is a substitution cipher
where each letter of a given text is replaced by a letter that is a fixed number of
positions down the alphabet.*/


class ENCRYPTION:public Mode //an abstract class used for encryption by using the Caesar Cipher Algorithm
{
public:
	ENCRYPTION() {
		if (eduMode) {
			cout << "ENCRYPTION-Constructor" << endl;
		}
	}
	~ENCRYPTION() {
		if (eduMode) {
			cout << "ENCRYPTION-Destructor" << endl;
		}
	}
	virtual void ENCRYPT(const string& FILE_NAME) = 0; //pure virtual function
};


class DECRYPTION:public Mode //an abstract class used for decryption by using the Caesar Cipher Algorithm
{
public:
	DECRYPTION() {
		if (eduMode) {
			cout << "DECRYPTION-Constructor" << endl;
		}
	}
	~DECRYPTION() {
		if (eduMode) {
			cout << "DECRYPTION-Destructor" << endl;
		}
	}
	virtual void DECRYPT(const string& FILE_NAME) = 0; //pure virtual function
};


