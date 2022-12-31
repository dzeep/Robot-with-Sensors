/**
* @file RobotControl.h
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief This class includes accessing information about the robot's movement and location.
* provides. It realizes its functions by making use of functions in the PioneerRobotAPI class.
*/

#pragma once
#include "RobotInterface.h"

#include <iostream>
#include <string>
using namespace std;
/*!
* \class RobotControl
* \briefThis class includes accessing information about the robot's movement and location.
* provides. It realizes its functions by making use of functions in the PioneerRobotAPI class.
*/
typedef class RobotControl : public RobotInterface
{
	RobotOperator* _operator;
	bool accessState;
public:
	RobotControl();
	void turnLeft();
	void turnRight();
	void forward(float speed);
	void print() const;
	void backward(float speed);
	Pose getPose();
	void setPose(Pose position);
	void stopTurn();
	void stopMove();
	bool addToPath();
	bool clearPath();
	bool recordPathToFile();
	bool openAccess(int);
	bool closeAccess(int);
}RobotControl;