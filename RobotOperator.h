#pragma once
/**
 * @file RobotOperator.h
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Give permission to operator who controls the robot
 */
#include <iostream>
#include "Encryption.h"

using namespace std;

class RobotOperator {
	string name;
	string surname;
	unsigned int accessCode;
	bool accessState;
	/*!
	\param code the 4 digit value which will be encrypted
	\return the encrypted value
	*/ 
	int encryptCode(int code);
	/*!
	\param code the 4 digit value which will be decrypted
	\return the decrypted value
	*/
	int decryptCode(int code);
public :
	RobotOperator(string _name, string _surname, int _accessCode);
	bool checkAccessCode(int code);
	void print();
};