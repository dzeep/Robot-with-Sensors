#pragma once
/**
* @file ConnectionMenu.h
* @author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Creating Connection Menu and sub Menu's for Connection.
**/
#include "PioneerRobotAPI.h"
#include "QuitMenu.h"
#include <iostream>

using namespace std;
/*!
* \class ConnectionMenu
* \brief  Creating Connection Menu and sub Menu's for Connection.
**/
typedef class ConnectionMenu : QuitMenu
{
private:
    PioneerRobotAPI* api;
public:
    ConnectionMenu(PioneerRobotAPI* api);
    void Menu();
    void Connect();
    void Disconnect();
    void Back();
}ConnectionMenu;