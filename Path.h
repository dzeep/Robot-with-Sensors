#pragma once
/**
* @file Path.h
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief It is the class that allows managing the road plan in the Linked list form. In Pose type, locations are added to the list.
* can be added.
*/



#include <iostream>
#include "Node.h"
#include <fstream>
using namespace std;

/*!
* \class Path
* \brief It is the class that allows managing the road plan in the Linked list form. In Pose type, locations are added to the list.
* can be added.
*/
class Path
{
	friend ostream& operator<<(ostream& out, Path);
	friend istream& operator>>(istream& in, Path);
private:
	Node* tail;
	Node* head;
	int number;
public:
	Path();
	bool addPos(Pose *pose);
	void print();
	Node operator[](int i);
	Pose getPos(int index);
	bool removePos(int index);
	bool insertPos(int index, Pose pose);
	int getNumber();
};