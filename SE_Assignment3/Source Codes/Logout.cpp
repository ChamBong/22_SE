#include "class.h"

// Initializing Static Attribute
LogoutUI* LogoutUI::logoutUI = nullptr;
Logout* Logout::logout = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LogoutUI* LogoutUI::getUiInstance()
{
    if (LogoutUI::logoutUI == nullptr)
        LogoutUI::logoutUI = new LogoutUI;

    return LogoutUI::logoutUI;
}

LogoutUI::LogoutUI()
{
    // NOP
}

LogoutUI::~LogoutUI()
{
    delete LogoutUI::logoutUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Logout *Logout::getControlInstance()
{
        if (Logout::logout == nullptr)
        Logout::logout = new Logout;

    return Logout::logout;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LogoutUI *Logout::getUI()
{
    return this->logoutUI;
}

Logout::Logout()
{
    this->logoutUI = LogoutUI::getUiInstance();
}

Logout::~Logout()
{
    delete logout;
}
