/**
* @file SensorMenu.cpp
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief This class includes interface of methods related to sensors.
*/
#include "SensorMenu.h"
#include "MainMenu.h"
/*!
* \brief Constructor method.
* @param prapi is PioneerRobotAPI* variable.
*/
SensorMenu::SensorMenu(PioneerRobotAPI* prapi)
{
	this->prapi = prapi;
	sonsen = new SonarSensor(this->prapi);
}
/*!
* \brief Method includes some options about sensor.
* @return nothing.
*/
void SensorMenu::Menu()
{
	char ch;
	cout << "Sensor Menu\n" << endl << "1) Get Range\n" << "2) Get Max\n" << "3) Get Min\n" << "4) Get Angle\n" << "5) Back\n" << "6) Quit\n";
	cin >> ch;

	if ((int)ch > 48 && (int)ch < 55)
	{
		switch (ch)
		{
		case 49:
			this->GetRange();
			break;
		case 50:
			this->GetMax();
			break;
		case 51:
			this->GetMin();
			break;
		case 52:
			this->GetAngle();
			break;
		case 53:
			this->Back();
			break;
		case 54:
			this->Quit();
			break;
		default:
			break;
		}
	}
	else
		cout << "Please enter a number between 0-7!";

	Back();
}
/*!
* \brief Method gets range of received index.
* @return nothing.
*/
void SensorMenu::GetRange()
{
	int index;
	cout << "please enter an index : ";
	cin >> index;
	cout << "Range at " << index << "th index : " << sonsen->getRange(index) << endl;
}
/*!
* \brief Method gets minimum range of received index.
* @return nothing.
*/
void SensorMenu::GetMin()
{
	int index = 0;
	cout << "Minimum range is :" << sonsen->getMin(index) << "   ";
	cout << "Index is : " << index << endl;
}
/*!
* \brief Method gets maximum range of received index.
* @return nothing.
*/
void SensorMenu::GetMax()
{
	int index = 0;
	cout << "Max Range :" << sonsen->getMax(index) << "   ";
	cout << "Index is : " << index << endl;
}
/*!
* \brief Method gets angle of received index.
* @return nothing.
*/
void SensorMenu::GetAngle()
{
	int index;
	cout << "please enter an index : ";
	cin >> index;
	cout << "Angle at " << index << "th index : " << sonsen->getAngle(index) << endl;
}
/*!
* \brief Method backs to last screen.
* @return nothing.
*/
void SensorMenu::Back()
{
	MainMenu menu(this->prapi);
}