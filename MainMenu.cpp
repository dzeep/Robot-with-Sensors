/**
 * @file Encryption.h
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Main Menu
 */
#include "MainMenu.h"

/**!
* \brief Constructor method
* @param *api is PioneerRobotAPI variable.
* @return nothing.
**/
MainMenu::MainMenu(PioneerRobotAPI* api)
{
    this->api = api;

    this->connection = new ConnectionMenu(this->api);
    this->motion = new MotionMenu(this->api);
    this->sensor = new SensorMenu(this->api);

    char rangle;
    cout << "Main Menu" << endl;
    cout << "1. Connection" << endl;
    cout << "2. Motion" << endl;
    cout << "3. Sensor" << endl;
    cout << "4. Quit" << endl;
    cout << "Choose one: ";
    cin >> rangle;

    if ((int)rangle >= 49 && (int)rangle <= 52)
    {
        switch (rangle)
        {
        case 49:
            this->Connection();
            break;
        case 50:
            this->Motion();
            break;
        case 51:
            this->Sensor();
            break;
        case 52:
            this->Quit();
            break;
        }
    }
    else
        cout << "ERROR! Check he input.";
}

/**!
* \brief Creates Connection between Visual Stdio and Mobile Sim.
* @param nothing.
* @return nothing.
**/
void MainMenu::Connection()
{
    this->connection->Menu();
}

/**!
* \brief Makes sub menu for Motion.
* @param nothing.
* @return nothing.
**/
void MainMenu::Motion()
{
    this->motion->Menu();
}

/**!
* \brief Makes sub menu for Sensor.
* @param nothing.
* @return nothing.
**/
void MainMenu::Sensor()
{
    this->sensor->Menu();
}

/**!
* \brief Makes sub menu for Test menu.
* @param nothing.
* @return nothing.
**/