/**
* @file RangeSensorTest.cpp
* @Author Omer Faruk Öztürk no: 152120171018 (152120171018@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Implemention of test program for RangeSensor.
*/


#include "RangeSensor.h"
#include "LaserSensor.h"
#include "SonarSensor.h"

#if 0
void main() {
	PioneerRobotAPI* ranges = new PioneerRobotAPI;

	RangeSensor* laser_sensor = new LaserSensor(ranges);
	RangeSensor* sonar_sensor = new SonarSensor(ranges);

	cout << "Laser Sensor Test\n" << endl;

	cout << laser_sensor->getRange(0) << endl;

	cout << laser_sensor->getAngle(30) << endl;

	float asd[15];

	laser_sensor->updateSensor(asd);

	int l_i = 0;
	float l_min = laser_sensor->getMin(l_i);

	int l_j = 0;
	float l_max = laser_sensor->getMax(l_j);
	cout << "\nMin : " << l_min << "\nMax : " << l_max << endl;

	float l_angle = 30;
	cout << laser_sensor->getClosestRange(-90, 90, l_angle);

	cout << endl << endl;

	///////////////////////////////////////////////

	cout << "Sonar Sensor Test\n" << endl;

	cout << "Angle: " << sonar_sensor->getAngle(0) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(1) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(2) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(3) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(4) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(5) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(6) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(7) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(8) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(9) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(10) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(11) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(12) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(13) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(14) << endl;
	cout << "Angle: " << sonar_sensor->getAngle(15) << endl;

	float range_[15];

	sonar_sensor->updateSensor(range_);
	cout << endl;

	cout << "GetRange: " << sonar_sensor->getRange(0) << endl;
	cout << endl;

	sonar_sensor->updateSensor(range_);

	cout << "Range of 5th index is: " << sonar_sensor->operator[](5);

	int s_i = 0;
	float s_min = sonar_sensor->getMin(s_i);

	int s_j = 0;
	float s_max = sonar_sensor->getMax(s_j);
	cout << "\nMin : " << s_min << "\nMax : " << s_max << endl;

	float s_angle = 30;
	cout << laser_sensor->getClosestRange(-90, 90, s_angle);

	cout << endl << endl;
	system("pause");
}
#endif