/**
* @file SonarSensorTest.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief It is written to test whether the sonar sensor class is working correctly.
*/

#include "SonarSensor.h"

#if 0
void main()
{
	PioneerRobotAPI* ranges = new PioneerRobotAPI;
	
	RangeSensor* sonar_sensor = new SonarSensor(ranges);

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

	int i = 0;
	float min;
	min = sonar_sensor->getMin(i);

	int j = 0;
	float max;
	max = sonar_sensor->getMax(j);

	cout << endl << endl;
	system("pause");
}
#endif