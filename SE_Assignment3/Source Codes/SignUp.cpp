#include "class.h"

// Initializing Static Attribute
SignUpUI* SignUpUI::signUpUI = nullptr;
SignUp* SignUp::signUp = nullptr;

SignUpUI* SignUpUI::getUiInstance()
{
    if(SignUpUI::signUpUI == nullptr)
        SignUpUI::signUpUI = new SignUpUI;

    return SignUpUI::signUpUI;
}

SignUpUI::SignUpUI()
{

}

SignUpUI::~SignUpUI()
{
    delete SignUpUI::signUpUI;
}

SignUp* SignUp::getControlInstance()
{
    if(SignUp::signUp == nullptr)
        SignUp::signUp = new SignUp;

    return SignUp::signUp;
}

SignUpUI* SignUp::getUI()
{
    return this->signUpUI;
}

SignUp::SignUp()
{
    this->signUpUI = SignUpUI::getUiInstance();
}

SignUp::~SignUp()
{
    delete signUp;
}
