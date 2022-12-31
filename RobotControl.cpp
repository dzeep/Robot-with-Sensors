
/**
* @file RobotControl.cpp
* @author Ömer Faruk Öztürk (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief This class includes accessing information about the robot's movement and location.
* provides. It realizes its functions by making use of functions in the PioneerRobotAPI class.
*/

#include "RobotControl.h"
#include "Path.h"
#include "Record.h"

/*!
* \brief Constructor Method. It produces from pose and pioneerrobotapi classes.
* @return nothing.
*/
RobotControl::RobotControl()
{
	this->position = new Pose();
	this->robotAPI = new PioneerRobotAPI();
	this->state = 0;
	string name, surname;
	int accessCode;
	cout << "Enter\n Name: ";
	cin >> name;
	cout << " Surname : ";
	cin >> surname;
	cout << " Access Code (4-digits): ";
	cin >> accessCode;
	this->_operator = new RobotOperator(name, surname, accessCode);
	this->accessState = false;
}
/*!
* \brief It makes the robot turn left.
* @return nothing.
*/
void RobotControl::turnLeft(){
	if (this->accessState)
	{
		this->robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::left);
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief It makes the robot turn right.
* @return nothing.
*/
void RobotControl::turnRight()
{
	if (this->accessState)
	{
		this->robotAPI->turnRobot(PioneerRobotAPI::DIRECTION::right);
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief Allows the robot to move at a given speed (mm / s)
* @return nothing.
*/
void RobotControl::forward(float speed)
{
	if (this->accessState)
	{
		this->robotAPI->moveRobot(speed);
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief Allows the robot to go backward at a given speed (mm / s)
* @return nothing.
*/
void RobotControl::backward(float speed)
{
	if (this->accessState)
	{
		this->robotAPI->moveRobot(speed); //If the speed is positive, it can be necessary that is negative.
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief The robot rotates its position.
* @return pos.
*/
Pose RobotControl::getPose()
{
	if (this->accessState)
	{
		Pose pos(this->position->getX(), this->position->getY(), this->position->getTh());
		return pos;
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief The robot assigns its position. The next moves, the new position relative to that position
* will occur.
* @return nothing.
*/
void RobotControl::setPose(Pose position)
{
	if (this->accessState)
	{
		this->position->setPose(position.getX(), position.getY(), position.getTh());
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief It stops the robot from turning.
* @return nothing.
*/
void RobotControl::stopTurn()
{
	if (this->accessState)
	{
		if (this->state == PioneerRobotAPI::DIRECTION::right) {
			this->turnLeft();
		}
		else if (this->state == PioneerRobotAPI::DIRECTION::left) {
			this->turnRight();
		}
		else {
			//forward is forward;
		}
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief Operator Robot also rotates position, angle and direction.
* @return nothing.
*/
void RobotControl::print() const
{
	if (this->accessState)
	{
		cout << "Position (x, y): " << this->position->getX() << ", " << this->position->getY() << endl;
		cout << "Angle : " << this->position->getTh() << endl;
		cout << "Direction : " << this->state << endl << endl;
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}
/*!
* \brief It stops the robot from moving forward or backward.
* @return nothing.
*/
void RobotControl::stopMove()
{
	if (this->accessState)
	{
		this->robotAPI->stopRobot();
	}
	else
	{
		cout << "Access for this operator did not granted." << endl;
	}
}

bool RobotControl::addToPath() {
	Path* path = new Path();
	Pose pos(this->position->getX(), this->position->getY(), this->position->getTh());

	return path->addPos(&pos);
}
bool RobotControl::clearPath() {
	Path* path = new Path();
	int x = path->getNumber();
	for (int i = 0; i < x; i++) {
		path->removePos(i);
	}
	if (path->getNumber() == 0)
		return true;
	else
		return false;
}
bool RobotControl::recordPathToFile() {
	Path* path = new Path();
	Record* record = new Record();
	int x = path->getNumber();
	Pose pos;
	bool hasWritten = false;
	for (int i = 0; i < x; i++) {
		pos = path->getPos(i);
		hasWritten = record->writeLine("x: " + to_string(pos.getX()) + "y: " + to_string(pos.getY()) + "th: " + to_string(pos.getTh()));
	}
	return hasWritten;
}

bool RobotControl::openAccess(int code)
{
	bool state = this->_operator->checkAccessCode(code);
	this->accessState = state;
	return state;
}
bool RobotControl::closeAccess(int code)
{
	bool state = this->_operator->checkAccessCode(code);
	this->accessState = !state;
	return state;
}