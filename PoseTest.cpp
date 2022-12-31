/**
* @file PoseTest.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief This class has the task of holding and managing the robot's location information. "Th" indicates the robot orientation.
*  x and y take values in millimeters. th takes value in degree units.
*/
#include "Pose.h"
using namespace std;

#if 0
void main()
{
	Pose pos = Pose(1, 2, 3);
	cout << "Pos.getX()-> " << pos.getX() << endl;
	cout << "Pos.getY()-> " << pos.getY() << endl;
	cout << "Pos.getTh()-> " << pos.getTh() << endl;
	cout << "---------------------------------------" << endl;
	cout << "The following pose and otherpose objects are used in operator actions" << endl << endl;

	Pose pose;
	pose.setX(50);
	pose.setY(40);
	pose.setTh(30);

	cout << "Pose.getX()-> " << pose.getX() << endl;
	cout << "Pose.getY()-> " << pose.getY() << endl;
	cout << "Pose.getTh()-> " << pose.getTh() << endl;
	cout << endl;

	Pose otherPose;
	otherPose.setPose(10, 20, 10);

	cout << "OtherPose.getX()-> " << otherPose.getX() << endl;
	cout << "OtherPose.getY()-> " << otherPose.getY() << endl;
	cout << "OtherPose.getTh()-> " << otherPose.getTh() << endl;
	cout << endl;

	float x1 = 5, y1 = 10, z1 = 15;
	float* a = &x1, * b = &y1, * c = &z1;

	cout << "---------------------------------------\nOtherPose.getPose method called and values printed." << endl;
	otherPose.getPose(*a, *b, *c);
	cout << "OtherPose.getX()-> " << otherPose.getX() << endl;
	cout << "OtherPose.getY()-> " << otherPose.getY() << endl;
	cout << "OtherPose.getTh()-> " << otherPose.getTh() << endl;
	cout << endl;

	cout << "Value of *a = " << *a << endl;
	cout << "Value of *b = " << *b << endl;
	cout << "Value of *c = " << *c << endl;
	cout << endl;

	float distance;
	distance = otherPose.findDistanceTo(pose);
	cout << "Distance: " << distance << endl;

	float angle;
	angle = otherPose.findAngleTo(pose);
	cout << "Angle: " << angle << endl;
	cout << endl;

	Pose sum;
	sum = pose.operator+(otherPose);
	cout << "Sum.getX()-> " << sum.getX() << endl;
	cout << "Sum.getY()-> " << sum.getY() << endl;
	cout << "Sum.getTh()-> " << sum.getTh() << endl;
	cout << endl;

	Pose sub;
	sub = pose.operator-(otherPose);
	cout << "Sub.getX()-> " << sub.getX() << endl;
	cout << "Sub.getY()-> " << sub.getY() << endl;
	cout << "Sub.getTh()-> " << sub.getTh() << endl;
	cout << endl;

	Pose opSum;
	opSum = pose.operator+=(otherPose);
	cout << "OpSum.getX()-> " << opSum.getX() << endl;
	cout << "OpSum.getY()-> " << opSum.getY() << endl;
	cout << "OpSum.getTh()-> " << opSum.getTh() << endl;
	cout << endl;

	Pose opSub;
	opSub = pose.operator-=(otherPose);
	cout << "OpSub.getX()-> " << opSub.getX() << endl;
	cout << "OpSub.getY()-> " << opSub.getY() << endl;
	cout << "OpSub.getTh()-> " << opSub.getTh() << endl;
	cout << endl;

	if (pose.operator==(otherPose))
		cout << "Pose is equal to OtherPose" << endl;
	else
		cout << "Pose is not equal to OtherPose" << endl;
	cout << endl;

	if (pose.operator<(otherPose))
		cout << "Pose is smaller than OtherPose" << endl;
	else
		cout << "Pose is not smaller than OtherPose" << endl;
	cout << endl;

	system("pause");
}
#endif