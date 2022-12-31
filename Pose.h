/**
* @file Pose.h
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief This class has the task of holding and managing the robot's location information. "Th" indicates the robot orientation.
*  x and y take values in millimeters. th takes value in degree units.
*/
#pragma once
#include <iostream>
#include <math.h>
/*!
* \class Pose.
* \brief Method includes Pose,Pose(float,float,float),getX,getY,getTh,setX,setY,setTh,operator == , operator + ,operator - ,operator += , operator -= ,operator < ,
*  getPose,setPose,findDistanceTo,findAngleTo.
*/
typedef class Pose
{
private:
	float x;
	float y;
	float th;
public:
	Pose();
	Pose(float x, float y, float th);
	float getX() const;
	float getY() const;
	float getTh() const;
	void setX(float x);
	void setY(float y);
	void setTh(float th);
	void getPose(float& x, float& y, float& th) const;
	void setPose(float x, float y, float th);
	float findDistanceTo(Pose pos);
	float findAngleTo(Pose pos);
	bool operator ==(const Pose& other);
	bool operator <(const Pose& other);
	Pose operator +(const Pose& other);
	Pose operator -(const Pose& other);
	Pose& operator +=(const Pose& other);
	Pose& operator -=(const Pose& other);
}Pose;