/**
* @file RobotInterface.h
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief RobotInterface is an abstract class, with PioneerRobotAPI
*It creates an interface to the associated PineerRobotInterface. So a different robot
*When an API belonging to the same robot or a different API of the same robot is used, the RobotInterface class
*another class that inherits will be added. The rest of our software will not be affected by this plugin.
*/


#pragma once
#include "Pose.h"
#include "PioneerRobotAPI.h"
#include "RobotOperator.h"
#include "SonarSensor.h"

using namespace std;
/*!
* \class RobotInterface
* \brief Method includes turnleft, turnRight, forward, print, backward, getPose, setpose, stopMove, stopTurn, updateSensor.
*/
class RobotInterface {
protected:
	Pose* position;
	PioneerRobotAPI* robotAPI;
	int state;
public:
	RobotInterface();
	virtual void turnLeft() = 0;
	virtual void turnRight() = 0;
	virtual void forward(float speed) = 0;
	virtual void print() const = 0;
	virtual void backward(float speed) = 0;
	virtual Pose getPose() = 0;
	virtual void setPose(Pose position) = 0;
	virtual void stopTurn() = 0;
	virtual void stopMove() = 0;
	void updateSensor(float* ranges);
};