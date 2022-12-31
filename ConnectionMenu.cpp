/**
 * @file ConnectionMenu.cpp
 * @Author Yahya Bekir Canevi (152120181030@ogrenci.ogu.edu.tr)
 * @date January, 2021
 * @brief Source code of Connection class
 **/

#include "ConnectionMenu.h"
#include "QuitMenu.h"
#include "MainMenu.h"

 /**!
 * \brief constructor method
 * @param *api is PioneerRobotAPI variable.
 * @return nothing.
 **/
ConnectionMenu::ConnectionMenu(PioneerRobotAPI* api)
{
    this->api = api;
}

/*!
* \brief Writes Connection Menu on Console.
* @param nothing.
* @return nothing.
**/
void ConnectionMenu::Menu() {
    char num;
    cout << "Connection Menu" << endl;
    cout << "1. Connect" << endl;
    cout << "2. Disconnect" << endl;
    cout << "3. Back" << endl;
    cout << "4. Quit" << endl;
    cout << "Choose one: ";
    cin >> num;

    if ((int)num >= 49 && (int)num <= 52)
    {
        switch (num)
        {
        case 49:
            this->Connect();
            break;
        case 50:
            this->Disconnect();
            break;
        case 51:
            this->Back();
            break;
        case 52:
            this->Quit();
            break;
        default:
            break;
        }
    }
    else
        cout << "Error, check the input!";
    //! Back to Main Menu.
    Back();
}

/**!
* \brief Connect api and robot. Checks connection state.
* @param nothing.
* @return nothing.
**/
void ConnectionMenu::Connect()
{
    bool concon = this->api->connect();
    if (concon)
        cout << "Is connected.";
    else
        cout << "Isn't connected.";

    cout << endl;
}

/**!
* \brief Disconnect api and robot. Checks connection state.
* @param nothing.
* @return nothing.
**/
void ConnectionMenu::Disconnect()
{
    bool disconcon = this->api->disconnect();
    if (disconcon)
        cout << "Is disconnected.";
    else
        cout << "Isn't disconnected!";
    cout << endl;
}

/**!
* \brief Back to Main Menu.
* @param nothing.
* @return nothing.
**/
void ConnectionMenu::Back()
{
    MainMenu menu(this->api);
}