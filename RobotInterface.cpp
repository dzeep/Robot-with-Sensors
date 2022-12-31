/**
* @file RobotInterface.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief RobotInterface is an abstract class, with PioneerRobotAPI
*It creates an interface to the associated PineerRobotInterface. So a different robot
*When an API belonging to the same robot or a different API of the same robot is used, the RobotInterface class
*another class that inherits will be added. The rest of our software will not be affected by this plugin.
*/

#include "RobotInterface.h"
/*!
* \brief Constructor Method. It produces from pose and pioneerrobotapi classes.
* @return nothing.
*/
RobotInterface::RobotInterface()
{
	this->position = new Pose();
	this->robotAPI = new PioneerRobotAPI();
	this->state = 0;
}
/*!
* \brief updateSensor method with parameter of float* ranges.
* @return nothing.
*/

void RobotInterface::updateSensor(float* ranges) {
	PioneerRobotAPI* robot = new PioneerRobotAPI();
	SonarSensor* sonarSensor = new SonarSensor(robot);
	sonarSensor->updateSensor(ranges);
}