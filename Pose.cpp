/**
* @file Pose.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief This class has the task of holding and managing the robot's location information. "Th" indicates the robot orientation.
*  x and y take values in millimeters. th takes value in degree units.
*/
#include "Pose.h"
#include <iostream>
#include <stdlib.h>
#include <math.h>
using namespace std;

/*!
* \brief Default constructor method.
*/
Pose::Pose()
{
	this->x = 0;
	this->y = 0;
	this->th = 0;
}
/*!
* \brief Constructor method.
* @param x is float variable , @param y is float variable , @param th is float variable.
*/
Pose::Pose(float x, float y, float th)
{
	this->x = x;
	this->y = y;
	this->th = th;
}
/*!
* \brief Method gets x.
* @return this->x.
*/
float Pose::getX() const
{
	return this->x;
}
/*!
* \brief Method sets x.
* @param x is float variable;
* @return nothing.
*/
void Pose::setX(float x)
{
	this->x = x;
}
/*!
* \brief Method gets y.
* @return this->y.
*/
float Pose::getY() const
{
	return this->y;
}
/*!
* \brief Method sets y.
* @param y is float variable;
* @return nothing.
*/
void Pose::setY(float y)
{
	this->y = y;
}
/*!
* \brief Method gets th.
* @return this->th.
*/
float Pose::getTh() const
{
	return this->th;
}
/*!
* \brief Method sets th.
* @param th is float variable;
* @return nothing.
*/
void Pose::setTh(float th)
{
	this->th = th;
}
/*!
* \brief Method checks whether two classes are equal to each other.
* @param other is const Pose& variable;
* @return true or false.
*/
bool Pose::operator ==(const Pose& other)
{
	if (other.getX() == this->getX() && other.getY() == this->getY() && other.getTh() == this->getTh())
		return 1;
	else
		return 0;
}
/*!
* \brief Method adds two classes together
* @param other is const Pose& variable;
* @return Pose.
*/
Pose Pose::operator +(const Pose& other)
{
	Pose* pos = new Pose();
	float angle, x, y;
	angle = this->th + other.getTh();
	x = this->x + other.getX();
	y = this->y + other.getY();
	pos->setPose(x, y, angle);

	return *pos;
}
/*!
* \brief Method substracts two classes.
* @param other is const Pose& variable;
* @return Pose.
*/
Pose Pose::operator -(const Pose& other)
{
	Pose* pos = new Pose();
	float angle, x, y;
	angle = this->th - other.getTh();
	x = this->x - other.getX();
	y = this->y - other.getY();
	pos->setPose(x, y, angle);

	return *pos;
}
/*!
* \brief Method continues to add two classes together.
* @param other is const Pose& variable;
* @return Pose&.
*/
Pose& Pose::operator +=(const Pose& other)
{
	Pose* pos = new Pose();
	float angle, x, y;
	angle = this->th + other.getTh();
	x = this->x + other.getX();
	y = this->y + other.getY();
	pos->setPose(x, y, angle);

	return *pos;
}
/*!
* \brief Method continues to substract two classes.
* @param other is const Pose& variable;
* @return Pose&.
*/
Pose& Pose::operator -=(const Pose& other)
{
	Pose* pos = new Pose();
	float angle, x, y;
	angle = this->th - other.getTh();
	x = this->x - other.getX();
	y = this->y - other.getY();
	pos->setPose(x, y, angle);

	return *pos;
}
/*!
* \brief Method checks whether two classes are smaller than each other.
* @param other is const Pose& variable;
* @return true or false.
*/
bool Pose::operator <(const Pose& other)
{
	if (sqrt(pow(this->x, 2) + pow(this->y, 2)) < sqrt(pow(other.getX(), 2) + pow(other.getY(), 2)))
		return 1;
	else
		return 0;
}
/*!
* \brief Method gets Pose.
* @param _x is float& variable, _y is float& variable and _th is float& variable.
* @return nothing.
*/
void Pose::getPose(float& _x, float& _y, float& _th) const
{
	_x = this->x;
	_y = this->y;
	_th = this->th;
}
/*!
* \brief Method sets Pose.
* @param _x is float variable, _y is float variable and _th is float variable.
* @return nothing.
*/
void Pose::setPose(float _x, float _y, float _th)
{
	this->x = _x;
	this->y = _y;
	this->th = _th;
}
/*!
* \brief Method finds distance with other class.
* @param pos is Pose variable.
* @return distance.
*/
float Pose::findDistanceTo(Pose pos)
{
	float distance;

	distance = sqrt(pow(this->x - pos.getX(), 2) + pow(this->y - pos.getY(), 2));
	return distance;
}
/*!
* \brief Method finds angle between other class.
* @param pos is Pose variable.
* @return angle.
*/
float Pose::findAngleTo(Pose pos)
{
	float distance_x, distance_y, angle;

	distance_x = abs(this->x - pos.getX());
	distance_y = abs(this->y - pos.getY());

	if (this->x < pos.getX() && this->y < pos.getY() || this->x > pos.getX() && this->y > pos.getY())
		angle = atan(distance_y / distance_x) * 180 / 3.14;
	else if (this->x < pos.getX() && this->y > pos.getY() || this->x > pos.getX() && this->y < pos.getY())
		angle = (3.14 - atan(distance_y / distance_x)) * 180 / 3.14;
	else if (this->x == pos.getX() && this->y != pos.getY())
		angle = 90;
	else if (this->y == pos.getY() && this->x != pos.getX())
		angle = 180;
	else
		angle = 0;
	return angle;
}