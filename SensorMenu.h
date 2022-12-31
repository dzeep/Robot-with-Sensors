/**
* @file SensorMenu.h
* @author Ceyhun Özkan (ceyhunozkan334@gmail.com)  ID:151820173028
* @date January, 2021
* @brief This class includes interface of methods related to sensors.
*/
#pragma once
#include "PioneerRobotAPI.h"
#include "QuitMenu.h"
#include "SonarSensor.h"
#include <iostream>

using namespace std;
/*!
* \class SensorMenu.
* \brief Method includes SensorMenu,Menu,GetRange,GetMin,GetMax,GetAngle,Back.
*/
typedef class SensorMenu : QuitMenu
{
private:
	SonarSensor* sonsen;
	PioneerRobotAPI* prapi;
public:
	SensorMenu(PioneerRobotAPI* prapi);
	void Menu();
	void GetRange();
	void GetMin();
	void GetMax();
	void GetAngle();
	void Back();
}SensorMenu;