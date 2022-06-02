#include "hong_ping.h"

// Initializing Static Attribute
SignUpUI* SignUpUI::signUpUI = nullptr;
SignUp* SignUp::signUp = nullptr;

/*
 *  Function Name : getSignUpUiInstance
 *  Parameters    : -
 *  Return Type   : 1) SignUpUI ; SignUpUI Object의 Reference
 *  Description   : 'SignUpUI' Singleton Object를 반환
 */
SignUpUI* SignUpUI::getUiInstance()
{
    if(SignUpUI::signUpUI == nullptr)
        SignUpUI::signUpUI = new SignUpUI;

    return SignUpUI::signUpUI;
}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUpUI::SignUpUI()
{

}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUpUI::~SignUpUI()
{
    delete SignUpUI::signUpUI;
}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUp* SignUp::getControlInstance()
{
    if(SignUp::signUp == nullptr)
        SignUp::signUp = new SignUp;

    return SignUp::signUp;
}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUpUI* SignUp::getUI()
{
    return this->signUpUI;
}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUp::SignUp()
{
    this->signUpUI = SignUpUI::getUiInstance();
}

/*
 *  Function Name : 
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
SignUp::~SignUp()
{
    delete signUp;
}
