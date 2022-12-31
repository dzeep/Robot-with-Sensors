#include "PioneerRobotInterface.h"
/*!
* \brief Constructor Method.
* @return nothing.
*/
PioneerRobotInterface::PioneerRobotInterface(PioneerRobotAPI* _robotAPI) : robotAPI(_robotAPI) { }
/*!
* \brief It makes the robot turn left.
* @param other is const Pose& variable;
* @return nothing.
*/
void PioneerRobotInterface::turnLeft() {
	this->robot->turnLeft();
}
/*!
* \brief It makes the robot turn right.
* @return nothing.
*/
void PioneerRobotInterface::turnRight() {
	this->robot->turnRight();
}
/*!
* \brief Allows the robot to move at a given speed (mm / s)
* @param speed is float variable;
* @return nothing.
*/
void PioneerRobotInterface::forward(float speed) {
	this->robot->forward(speed);
}
/*!
* \brief Operator Robot also rotates position, angle and direction.
* @return nothing.
*/
void PioneerRobotInterface::print() const {
	this->robot->print();
}
/*!
* \brief Allows the robot to go backward at a given speed (mm / s)
* @param speed is float variable;
* @return nothing.
*/
void PioneerRobotInterface::backward(float speed) {
	this->robot->backward(speed);
}
/*!
* \brief The robot rotates its position.
* @return nothing.
*/
Pose PioneerRobotInterface::getPose() {
	return this->robot->getPose();
}
/*!
* \brief The robot assigns its position. The next moves, the new position relative to that position
* will occur.
* @return nothing.
*/
void PioneerRobotInterface::setPose(Pose position) {
	this->robot->setPose(position);
}
/*!
* \brief It stops the robot from turning.
* @return nothing.
*/
void PioneerRobotInterface::stopTurn() {
	this->robot->stopTurn();
}
/*!
* \brief It stops the robot from moving forward or backward.
* @return nothing.
*/
void PioneerRobotInterface::stopMove() {
	this->robot->stopMove();
}
/*!
* \brief Method uploads the robot's current sensor distance values to the ranges array.
* @param ranges is float variable;
* @return nothing.
*/
void PioneerRobotInterface::updateSensor(float* ranges) {
	this->robot->updateSensor(ranges);
}