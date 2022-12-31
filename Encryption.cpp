/**
 * @file Encryption.cpp
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Source code of Encrytion class
 */
#include "Encryption.h"

int Encryption::encrypt(int code) {
	int _code = code;
	int encrypted = 0;
	if (_code >= 10000) return -1;

	int digits[4];
	for (int i = 0; i < 4; i++) {
		//dividing code to its digits
		digits[i] = _code % 10;
		_code /= 10;
		//encrypting digits
		digits[i] = (digits[i] + 7) % 10;
		//set encrypted values digits
		encrypted += digits[i] * pow(10, i);
	}
	return encrypted;
}
int Encryption::decrypt(int code) {
	int _code = code;
	int decrypted = 0;
	if (_code >= 10000) return -1;

	int digits[4];
	for (int i = 0; i < 4; i++) {
		//dividing code to its digits
		digits[i] = _code % 10;
		_code /= 10;
		//decrypting digits
		digits[i] = (digits[i] + 10 - 7) % 10;
		//set decrypted values digits
		decrypted += digits[i] * pow(10, i);
	}
	return decrypted;
}
