/**
* @file LaserSensorTest.cpp
* @author Fatih Hevesli 152120181037@ogrenci.ogu.edu.tr  - no: 152120181037
* @date January, 2021
* @brief It is written to test whether the laser sensor class is working correctly.
*/


#include "LaserSensor.h"

#if 0
void main() {
	PioneerRobotAPI* ranges = new PioneerRobotAPI;
	RangeSensor* laser_sensor = new LaserSensor(ranges);

	cout << laser_sensor->getRange(0) << endl;

	cout << laser_sensor->getAngle(30) << endl;

	float asd[15];

	laser_sensor->updateSensor(asd);

	int i = 0;
	float min;
	min = laser_sensor->getMin(i);

	int j = 0;
	float max;
	max = laser_sensor->getMax(j);
	cout << "Min : " << min << "\nMax : " << max << endl;

	float angle = 30;
	cout << laser_sensor->getClosestRange(-90, 90, angle);

	cout << endl << endl;
}
#endif