#include "class.h"

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

LoginUI::LoginUI()
{
    // NOP
}

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

Login::Login()
{
    this->loginUI = LoginUI::getUiInstance();
}

Login::~Login()
{
    delete this->login;
}