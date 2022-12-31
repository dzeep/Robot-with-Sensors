/**
* @file RobotControlTest.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief Check Test PioneerRobotInterface Class
*/

#if 0
#include "PioneerRobotInterface.h"
#include <iostream>
using namespace std;
int main() {
	RobotInterface* robotAPI = new RobotControl();

	robotAPI->print();

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

	system("pause");
	return 0;
}
#endif