#include "class.h"

// Initializing Static Attribute
LoginUI* LoginUI::loginUI = nullptr;
Login* Login::login = nullptr;

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

Login* Login::getControlInstance()
{
    if (Login::login == nullptr)
        Login::login = new Login;

    return Login::login;
}

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