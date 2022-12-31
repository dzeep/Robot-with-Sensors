
/**
* @file Record.h
* @author Fatih Hevesli 152120181037@ogrenci.ogu.edu.tr  - no: 152120181037
* @date January, 2021
* @brief It carries out the save to file operations for use in robot applications.
*/
#pragma once

#include <iostream>
#include <fstream>
using namespace std;

/*!
* \class Record
* \brief It carries out the save to file operations for use in robot applications.
*/
class Record
{	
private:
	string fileName, str;
	fstream file;
public:
	Record();
	string getStr();
	void setStr(string _str);
	bool openFile();
	bool closeFile();
	void setFileName(string name);
	string readLine();
	bool writeLine(string str);
	friend istream& operator >>(istream& in, const Record& rec);
	friend ostream& operator <<(ostream& out, const Record& rec);
};

