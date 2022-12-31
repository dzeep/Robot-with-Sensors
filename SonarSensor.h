/**
* @file SonarSensor.h
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief Provides data capture and management for the sonar distance sensor.
*  Figure 3 shows the location and indexes of the sonar sensors on the robot.
*/
#pragma once
#include "RangeSensor.h"
/*!
* \class SonarSensor.
* \brief Method includes SonarSensor,getRange,getAngle,updateSensor,getMin,getMax,operator[].
*/
typedef class SonarSensor : public RangeSensor
{
public:
	SonarSensor(PioneerRobotAPI* api);
	float getRange(int index) const;
	float getAngle(int index) const;
	void updateSensor(float* ranges);
	float getMin(int& index);
	float getMax(int& index);
	float getClosestRange(float startAngle, float endAngle, float& angle);
}SonarSensor;