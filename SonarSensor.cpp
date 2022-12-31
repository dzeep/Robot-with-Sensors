/**
* @file SonarSensor.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief Provides data capture and management for the sonar distance sensor.
*  Figure 3 shows the location and indexes of the sonar sensors on the robot.
*/
#include "SonarSensor.h"
using namespace std;

/*!
* \brief Constructor method.
* @param api is PioneerRobotAPI* variable.
*/
SonarSensor::SonarSensor(PioneerRobotAPI* api)
{
	this->ranges = new float[16];
	this->robotAPI = api;
	this->robotAPI->getSonarRange(ranges);
	this->updateSensor(ranges);
}

/*!
* \brief Method returns distance information of sensor with i'th index
* @param index is int variable.
* @return this->ranges[index]
*/
float SonarSensor::getRange(int index) const
{
	return this->ranges[index];
}
/*!
* \brief Method returns the angle value of the sensor whose index is given.
* @param index is int variable.
* @return angle.
*/
float SonarSensor::getAngle(int index) const
{
	float angle = 0;
	switch (index)
	{
	case 0:
		angle = 90;
		break;
	case 1:
		angle = 50;
		break;
	case 2:
		angle = 30;
		break;
	case 3:
		angle = 10;
		break;
	case 4:
		angle = -10;
		break;
	case 5:
		angle = -30;
		break;
	case 6:
		angle = -50;
		break;
	case 7:
		angle = -90;
		break;
	case 8:
		angle = -90;
		break;
	case 9:
		angle = -130;
		break;
	case 10:
		angle = -150;
		break;
	case 11:
		angle = -170;
		break;
	case 12:
		angle = 170;
		break;
	case 13:
		angle = 150;
		break;
	case 14:
		angle = 130;
		break;
	case 15:
		angle = 90;
		break;
	default:
		break;
	}
	angle += this->robotAPI->getTh();
	if (angle > 180) {
		angle = angle - 180;
	}
	else if (angle < -180) {
		angle = angle + 180;
	}
	return angle;
}
/*!
* \brief Method uploads the robot's current sensor distance values to the ranges array.
* @param ranges is float* variable.
* @return nothing.
*/
void SonarSensor::updateSensor(float* ranges)
{
	int i = 0;
	while (!ranges[i])
	{
		this->ranges[i] = ranges[i];
		i++;
	}
}
/*!
* \brief Method returns the minimum of the distance values. Returns the index of data with this distance to the variable in parentheses
* @param &index is int variable.
* @return min.
*/
float SonarSensor::getMin(int& index)
{
	float min = this->ranges[0];
	int ind = 0;
	for (int i = 0; i < 16; i++)
	{
		if (min > this->ranges[i])
		{
			min = this->ranges[i];
			ind = i;
		}
	}

	index = ind;
	return min;
}
/*!
* \brief Method returns the maximum of the distance values. Returns the index of data with this distance to the variable in parentheses.
* @param &index is int variable.
* @return maximum distance value.
*/
float SonarSensor::getMax(int& index)
{
	float max = this->ranges[0];
	int ind = 0;
	for (int i = 0; i < 16; i++)
	{
		if (max < this->ranges[i])
		{
			max = this->ranges[i];
			ind = i;
		}
	}

	index = ind;
	return max;
}
/*!
* \brief between startAngle and endAngle angles
* Returns the angle of the smallest distance on angle and the distance with return.
* @param startAngle is float variable, @param endAngle is float variable,  @param &angle is float variable.
* @return minRange.
*/
float SonarSensor::getClosestRange(float startAngle, float endAngle, float& angle)
{
	int startIndex = (startAngle)+90;
	int endIndex = (endAngle)+90;

	float minRange = this->ranges[startIndex];
	for (int i = startIndex; i <= endIndex; i++)
	{
		if (minRange > this->ranges[i])
			minRange = this->ranges[i];
	}

	angle = minRange - 90;
	return minRange;
}