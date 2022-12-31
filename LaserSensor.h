/**
* @file LaserSensor.h
* @author Fatih Hevesli 152120181037@ogrenci.ogu.edu.tr  - no: 152120181037
* @date January, 2021
* @brief Provides data capture and management for laser distance sensor. Figure 4 shows the laser sensor
* The directions and indices that are measured are seen. .
*/
#pragma once
#include "RangeSensor.h"
/*!
* \class LaserSensor
* \brief Provides data capture and management for laser distance sensor. Figure 4 shows the laser sensor
* The directions and indices that are measured are seen. .
*/
class LaserSensor : public RangeSensor
{
public:
	LaserSensor(PioneerRobotAPI* api);
	float getRange(int index) const;
	void updateSensor(float ranges[]);
	float getMax(int& index);
	float getMin(int& index);
	float getAngle(int index) const;
	float getClosestRange(float startAngle, float endAngle, float& angle);
};