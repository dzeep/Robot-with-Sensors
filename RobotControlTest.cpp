/**
* @file RobotControlTest.cpp
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief It is written to test whether the sonar robot control class is working correctly.
*/

#if 0

#include "RobotControl.h"
#include "Pose.h"
#include <iostream>
int main() {
	RobotControl* robotAPI = new RobotControl();

	robotAPI->print();

	int accessCode = 0;
	cout << "Enter Access Code : ";
	cin >> accessCode;

	if (robotAPI->openAccess(accessCode))
	{
		robotAPI->print();

		Pose* pose = new Pose();
		pose->setX(4);
		pose->setY(4);
		pose->setTh(45);

		robotAPI->setPose(*pose);
		robotAPI->print();


		robotAPI->turnLeft();
		*pose = robotAPI->getPose();


		robotAPI->stopTurn();


		robotAPI->turnRight();


		robotAPI->stopTurn();


		robotAPI->forward(50);
		*pose = robotAPI->getPose();

		robotAPI->backward(40);


		robotAPI->stopMove();

		while (1)
		{
			int _accessCode = 0;
			cout << "Enter Access Code : ";
			cin >> _accessCode;

			if (robotAPI->closeAccess(_accessCode))
			{
				cout << "Access Closed Successfully." << endl;
				break;
			}
			else
				cout << "Access Close cannot be done." << endl;
		}


		if (robotAPI->addToPath() == 1)
			cout << "Has been Added";
		else
			cout << "Hasn't added";

		if (robotAPI->clearPath() == 1)
			cout << "Has been Cleared";
		else
			cout << "Hasn't Been Cleared";

		if (robotAPI->recordPathToFile() == 1)
			cout << "Has Been Written";
		else
			cout << "Hasn't Been Written";




		system("pause");
		return 0;
	}
	else
	{
		cout << "Wrong Access Code!" << endl;
	}

	system("pause");
	return 0;
}

#endif