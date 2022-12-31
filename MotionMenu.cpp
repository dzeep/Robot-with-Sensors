/**
 * @file EncryptionTest.cpp
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Motion Menu
 */
#include "MotionMenu.h"
#include "SonarSensor.h"
#include "QuitMenu.h"
#include "MainMenu.h"

/*!
* \brief constructor method
* @param *api is PioneerRobotAPI variable.
* @return nothing.
*/
MotionMenu::MotionMenu(PioneerRobotAPI* api)
{
	this->api = api;
}
/*!
* \brief Writes menu on console and call menu elements.
* @param nothing.
* @return nothing.
*/
void MotionMenu::Menu() {
	char c;
	cout << "Motion Menu" << endl <<
		"1. Move Robot" << endl << "2. Safe Move Robot" <<
		endl << "3. Turn Left" << endl << "4. Turn Right" << endl
		<< "5. Forward" << endl << "6. Move Distance" << endl
		<< "7. Close Wall" << endl << "8. Back" << endl << "9. Quit";
	cin >> c;

	if ((int)c >= 49 && (int)c <= 57)
	{
		switch (c)
		{
		case 49:
			this->MoveRobot();
			break;
		case 50:
			//this->SafeMoveRobot();
			break;
		case 51:
			this->TurnLeft();
			break;
		case 52:
			this->TurnRight();
			break;
		case 53:
			this->Forward();
			break;
		case 54:
			//this->MoveDistance();
			break;
		case 55:
			this->CloseWall();
			break;
		case 56:
			this->Back();
			break;
		case 57:
			this->Quit();
			break;
		default:
			break;
		}
	}
	else
		cout << "Error, check the input!";

	Back();
}
/*!
* \brief Determines to robot's speed.
* @param nothing.
* @return nothing.
*/
void MotionMenu::MoveRobot()
{
	float speed = 10;
	cout << "Enter the speed of the robot: ";
	cin >> speed;
	if (speed == 0)
		this->api->stopRobot();
	this->api->moveRobot(speed);

	cout << "Robot is moving with " << speed << "milimeter/sec" << endl;
}

/*!
* \brief Turns Robot to left.
* @param nothing.
* @return nothing.
*/

void MotionMenu::TurnLeft()
{
	this->api->turnRobot(PioneerRobotAPI::DIRECTION::left);
}

/*!
* \brief Turns robot to right.
* @param nothing.
* @return nothing.
*/
void MotionMenu::TurnRight()
{
	this->api->turnRobot(PioneerRobotAPI::DIRECTION::right);
}

/*!
* \brief keeps the robot moving straight.
* @param nothing.
* @return nothing.
*/
void MotionMenu::Forward()
{
	this->api->turnRobot(PioneerRobotAPI::DIRECTION::forward);
}

/*!
* \brief Determine the closest wall.
* @param nothing.
* @return nothing.
*/
void MotionMenu::CloseWall()
{
	SonarSensor* sensor = new SonarSensor(this->api);
	int index = 0;
	cout << "Closest Wall Range: " << sensor->getMin(index);
	cout << "\tIndex is : " << index << endl;
	delete sensor;
}

/*!
* \brief Commands the robot to move back.
* @param nothing.
* @return nothing.
*/
void MotionMenu::Back()
{
	MainMenu menu(this->api);
}