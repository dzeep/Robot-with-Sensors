/**
* @file RangeSensor.cpp
* @Author Omer Faruk Öztürk no: 152120171018 (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Implement the function similiar to getrange.
*/

#include "RangeSensor.h"
using namespace std;

/*!
* \brief Constructor Method created.
* @param do not has parameter.
* @return nothing.
*/
RangeSensor::RangeSensor()
{
	this->ranges = NULL;
	this->robotAPI = nullptr;
}
/*!
* \brief Method returns the sensor value given the index. Implements the function similar to getRange (i).
* @param i is int variable.
* @return this->ranges[i].
*/
float RangeSensor::operator[](int i) {
	return this->ranges[i];
}