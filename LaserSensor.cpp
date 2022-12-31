#include "LaserSensor.h"

/*!
* \brief Constructor method.
* @param api is PioneerRobotAPI* variable.
*/
LaserSensor::LaserSensor(PioneerRobotAPI* api)
{
	this->ranges = new float[16];
	this->robotAPI = api;
	this->robotAPI->getSonarRange(ranges);
	this->updateSensor(ranges);
}

/*!
* \brief i. Returns distance information of the sensor with index.
* @param index is int variable.
* @return  this->ranges[index].
*/
float LaserSensor::getRange(int index) const
{
	return this->ranges[index];
}
/*!
* \brief Returns the angle value of the sensor whose index is given.
* @param index is int variable.
* @return (index - 90).
*/
float LaserSensor::getAngle(int index) const
{
	// index == 0 angle= -90;
	// index == 90 angle = 0;
	// index == 180 angle = 90;
	return (index - 90);
}
/*!
* \brief Uploads the robot's current sensor distance values to the ranges array.
* @param ranges[] is float variable.
* @return nothing.
*/
void LaserSensor::updateSensor(float ranges[])
{
	int i = 0;
	while (!ranges[i])
	{
		this->ranges[i] = ranges[i];
		i++;
	}
}
/*!
* \brief Returns the minimum of the distance values. The index of data with this distance
* returns the variable in parentheses.
* @param &index is int variable.
* @return min.
*/
float LaserSensor::getMin(int& index)
{
	float min = this->ranges[0];
	int ind = 0;
	for (int i = 0; i < 181; i++)
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
* \brief Returns the maximum of the distance values. The index of data with this distance
* returns the variable in parentheses.
* @param &index is int variable.
* @return max.
*/
float LaserSensor::getMax(int& index)
{
	float max = this->ranges[0];
	int ind = 0;
	for (int i = 0; i < 181; i++)
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
float LaserSensor::getClosestRange(float startAngle, float endAngle, float& angle)
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