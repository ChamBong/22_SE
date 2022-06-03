#include "class.h"

// Initializing Static Attribute
EnrollUI* EnrollUI::enrollUI = nullptr;
Enroll* Enroll::enroll = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
EnrollUI* EnrollUI::getUiInstance()
{
    if(EnrollUI::enrollUI == nullptr)
        EnrollUI::enrollUI = new EnrollUI;

    return EnrollUI::enrollUI;
}

EnrollUI::EnrollUI()
{
    // NOP
}

EnrollUI::~EnrollUI()
{
    delete EnrollUI::enrollUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Enroll* Enroll::getControlInstance()
{
    if (Enroll::enroll == nullptr)
        Enroll::enroll = new Enroll;

    return Enroll::enroll;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
EnrollUI* Enroll::getUI()
{
    return this->enrollUI;
}

Enroll::Enroll()
{
    this->enrollUI = EnrollUI::getUiInstance();
}

Enroll::~Enroll()
{
    delete this->enroll;
}
