/**
* @file PioneerRobotInterface.h
* @author Fatih Hevesli 152120181037
* @date January, 2021
* @brief Inherited from RobotInterface, this class works directly with PioneerRobotAPI. 
* It also has a connection with the RobotControl class.
*/
#pragma once
#include "RobotInterface.h"
#include "RobotControl.h"
using namespace std;

/*!
* \class PioneerRobotInterface.
* \brief Inherited from RobotInterface, this class works directly with PioneerRobotAPI. 
* It also has a connection with the RobotControl class.
*/
class PioneerRobotInterface : public RobotInterface{
protected:
	PioneerRobotAPI* robotAPI;
	RobotControl* robot;
public:
	PioneerRobotInterface(PioneerRobotAPI* robotAPI);
	void turnLeft();
	void turnRight();
	void forward(float speed);
	void print() const;
	void backward(float speed);
	Pose getPose();
	void setPose(Pose position);
	void stopTurn();
	void stopMove();
	void updateSensor(float* ranges);
};