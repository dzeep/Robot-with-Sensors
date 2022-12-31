/**
* @file pathTest.cpp
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief It is written to test whether the sonar Path class is working correctly.
*/

#include "Path.h"
using namespace std;
#if 0
void main() {
	Pose* pose = new Pose();
	pose->setX(10.5);
	pose->setY(10.5);
	pose->setTh(10.5);

	cout << pose->getX() << endl;
	cout << pose->getY() << endl;
	cout << pose->getTh() << endl;
	cout << endl;
	Path* path = new Path();
	path->addPos(pose);

	Pose* pose2 = new Pose();
	pose2->setX(4);
	pose2->setY(4);
	pose2->setTh(4);

	path->insertPos(0, *pose2);
	path->print();	
	cout << endl;
	Node n = path->operator[](1); //n.pose = (10.5, 10.5, 10.5);
	
	cout << *path;
	cout << endl;

	cin >> *path;
	cout << *path;
	path->print();
	cout << endl;

	path->removePos(0);
	path->print();
	cout << endl;
}
#endif