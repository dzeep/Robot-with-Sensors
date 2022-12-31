#pragma once
/**
 * @file Encryption.h
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Methods of Encrytion class will be used in RobotOperator class
 */
#include <iostream>
using namespace std;

class Encryption {
public:
	/*!
	 \param code 4 digit value for encrypt.
	 \return The encrypted value
	*/
	static int encrypt(int code);
	/*!
	 \param code 4 digit value for decrypt.
	 \return The decrypted value
	*/
	static int decrypt(int code);
};