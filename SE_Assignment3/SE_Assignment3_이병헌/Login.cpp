#include "hong_ping.h"

// Initializing Static Attribute
LoginUI* LoginUI::loginUI = nullptr;
Login* Login::login = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LoginUI* LoginUI::getUiInstance()
{
    if(LoginUI::loginUI == nullptr)
        LoginUI::loginUI = new LoginUI;

    return LoginUI::loginUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LoginUI::LoginUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LoginUI::~LoginUI()
{
    delete LoginUI::loginUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Login* Login::getControlInstance()
{
    if (Login::login == nullptr)
        Login::login = new Login;

    return Login::login;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
LoginUI* Login::getUI()
{
    return this->loginUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Login::Login()
{
    this->loginUI = LoginUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Login::~Login()
{
    delete this->login;
}