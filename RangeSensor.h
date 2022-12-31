/**
* @file RangeSensor.h
* @Author Omer Faruk Öztürk no: 152120171018 (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Implement the function similiar to getrange.
*/

#pragma once
#include "PioneerRobotAPI.h"
#include <iostream>
using namespace std;
/*!
* \class RangeSensor.
* \brief Methods include RangeSensor, getrange, getangle, updateSensor, getMin, getMax, getClosestRange.
*/
class RangeSensor {
protected:
	float* ranges;
	PioneerRobotAPI* robotAPI;
public:
	RangeSensor();
	virtual float getRange(int index) const = 0;
	virtual float getAngle(int index) const = 0;
	virtual void updateSensor(float* ranges) = 0;
	virtual float getMin(int& index) = 0;
	virtual float getMax(int& index) = 0;
	virtual float getClosestRange(float startAngle, float endAngle, float& angle) = 0;
	float operator[](int i);
};