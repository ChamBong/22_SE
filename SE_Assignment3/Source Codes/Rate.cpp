#include "class.h"

// Initializing Static Attribute
RateUI* RateUI::rateUI = nullptr;
Rate* Rate::rate = nullptr;

RateUI* RateUI::getUiInstance()
{
    if(RateUI::rateUI == nullptr)
        RateUI::rateUI = new RateUI;

    return RateUI::rateUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
RateUI::RateUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
RateUI::~RateUI()
{
    delete RateUI::rateUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Rate* Rate::getControlInstance()
{
    if (Rate::rate == nullptr)
        Rate::rate = new Rate;

    return Rate::rate;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
RateUI* Rate::getUI()
{
    return rateUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Rate::Rate()
{
    rateUI = RateUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Rate::~Rate()
{
    delete rate;
}
