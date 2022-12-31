#pragma once
/**
* @file MainMenu.h
* @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Creates Main Menu and gather sub menu's one place.
**/
#include "PioneerRobotAPI.h"
#include "ConnectionMenu.h"
#include "MotionMenu.h"
#include "SensorMenu.h"

/*!
* \class MainMenu.h
* \brief Creates Main Menu and gather sub menu's one place.
*/
typedef class MainMenu : QuitMenu
{
private:
    PioneerRobotAPI* api;
    ConnectionMenu* connection;
    MotionMenu* motion;
    SensorMenu* sensor;
public:
    MainMenu(PioneerRobotAPI* api);
    void Connection();
    void Motion();
    void Sensor();
}MainMenu;