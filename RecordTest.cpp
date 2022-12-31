/**
* @file RecordTest.cpp
* @author Fatih Hevesli (152120181037@ogrenci.ogu.edu.tr)  ID:152120181037
* @date January, 2021
* @brief test code for Record class.
*/
#if 0

#include "Record.h"
#include <iostream>
using namespace std;

void main() {

	Record file;
	file.setFileName("birTane.txt");

	file.openFile();
	cout << file.readLine() << endl;

	
	file.writeLine("\n Deneme Test");

	
	string testi = "Deneme Yazısı";

	file.setStr(testi);
	file.getStr();

	cout << file;
	cout << endl;

	cin >> file;
	cout << file;
	cout << endl;

	file.closeFile();

	cout << endl << endl;
}

#endif