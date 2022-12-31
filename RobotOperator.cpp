/**
 * @file RobotOperator.cpp
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Source code of RobotOperator class
 */

#include "RobotOperator.h"
 /*!
 * \brief Using the function of the Encryption class, you can generate the 4-digit code.
 * encrypts.
 * @param code is int variable.
 * @return Encryption::encrypt(code).
 */
int RobotOperator::encryptCode(int code) {
	return Encryption::encrypt(code);
}
/*!
 * \brief You can decrypt the 4-digit code using the function of the Encryption class.
 * dissolves.
 * @param code is int variable.
 * @return Encryption::decrypt(code).
 */
int RobotOperator::decryptCode(int code) {
	return Encryption::decrypt(code);
}
/*!
 * \brief For use in robot applications, the operator who will command the robot
 * is a class to be used in authorization
 * @param _name is string variable, @param _surname is string variable,  @param _accessCode is int variable.
 * @return nothing.
 */
RobotOperator::RobotOperator(string _name, string _surname, int _accessCode) {
	this->name = _name;
	this->surname = _surname;
	this->accessCode = encryptCode(_accessCode);
	this->accessState = true;
}
/*!
 * \brief The code entered is the same as the accessCode, which is kept encrypted.
 * checks if it is not.
 * @param code is int variable.
 * @return return true or false.
 */
bool RobotOperator::checkAccessCode(int code) {
	if (code == this->decryptCode(this->accessCode)) return true;
	else return false;
}
/*!
 * \brief Displays the operator's name and access status.
 * checks if it is not.
 * @return return nothing.
 */
void RobotOperator::print() {
	cout << "Name : " << this->name << endl
		<< "Surname : " << this->surname << endl;
	cout << "Access State : ";
	if (this->accessState) cout << "True" << endl;
	else cout << "False" << endl;
}