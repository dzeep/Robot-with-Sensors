/**
* @file Record.cpp
* @author Fatih Hevesli 152120181037@ogrenci.ogu.edu.tr  - no: 152120181037
* @date January, 2021
* @brief It carries out the save to file operations for use in robot applications.
*/


#include "Record.h"
#include <fstream>
#include <iostream>
#include <string>
using namespace std;

Record::Record() {
	this->str = "";
	this->fileName = "";
}


/*!
* \brief Opens a file for printing and reading.
* @return this->file.is_open().
*/
bool Record::openFile() {
	this->file.open(this->fileName, ios::in);

	return this->file.is_open();
}
/*!
* \brief Closes the file to print and read
* @return !(this->file.is_open()).
*/
bool Record::closeFile() {
	this->file.close();

	return !(this->file.is_open());
}
/*!
* \brief print performs the task that the function does.
* @param name is string variable
* @return out.
*/
void Record::setFileName(string name) {
	this->fileName = name;
}
/*!
* \brief It reads one line of data from the file.
* @return line.
*/
string Record::readLine() {
	string line;
	if (this->file.is_open())
		getline(this->file, line);
	else
		cout << "The file is not exist!" << endl;
	return line;
}
/*!
* \brief Writes one line of data to the file.
* @param str is string variable
* @return out.
*/
bool Record::writeLine(string str) {
	ofstream stream = ofstream(this->fileName, ios::app);

	if (stream.is_open())
		stream << str;
	else
		cout << "The data cannot be written into the file.";

	stream.close();

	return stream.is_open();
}
/*!
* \brief It takes the data from the file.
* @param str is operator >> variable
*/
istream& operator >>(istream& in, const Record& rec) {
	string line;
	if (rec.file.is_open()){
		in >> line;
		//rec.str = line; 
		//We take the sitring but cannot save it.
	}
	else
		cout << "The file is not exist!" << endl;
	return in;
}

/*!
* \brief Writes the data to the file.
* @param str is operator << variable
*/
ostream& operator <<(ostream& out, const Record& rec) {
	
	if (rec.file.is_open())
		out << rec.str;
	else
		cout << "The data cannot be written into the file.";
	return out;
}
/*!
* \brief Writes the data to the file.
* @param str is operator << variable
*/
string Record::getStr() {
	return this->str;
}
/*!
* \brief Writes the data to the file.
* @param str is operator << variable
*/
void Record::setStr(string _str) {
	this->str = _str;
}