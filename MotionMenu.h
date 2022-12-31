/**
* @file MotionMenu.h
* @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
* @date January, 2021
* @brief Creates Menu for Motion that control robots motion.
*/
#pragma once
#include "PioneerRobotAPI.h"
#include "QuitMenu.h"
#include <iostream>

using namespace std;
/*!
* \class MotionMenu.h
* \brief Creates Menu for Motion that control robots motion.
*/
typedef class MotionMenu : QuitMenu
{
private:
    PioneerRobotAPI* api;
public:
    MotionMenu(PioneerRobotAPI* api);
    void Menu();
    void MoveRobot();
    void TurnLeft();
    void TurnRight();
    void Forward();
    //void MoveDistance();
    void CloseWall();
    //void SafeMoveRobot();
    void Back();
}MotionMenu;