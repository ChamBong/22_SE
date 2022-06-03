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

RateUI::RateUI()
{
    // NOP
}

RateUI::~RateUI()
{
    delete RateUI::rateUI;
}

Rate* Rate::getControlInstance()
{
    if (Rate::rate == nullptr)
        Rate::rate = new Rate;

    return Rate::rate;
}

RateUI* Rate::getUI()
{
    return rateUI;
}

Rate::Rate()
{
    rateUI = RateUI::getUiInstance();
}

Rate::~Rate()
{
    delete rate;
}
