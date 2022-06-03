#include "class.h"

// Initializing Static Attribute
DropOutUI* DropOutUI::dropOutUI = nullptr;
DropOut* DropOut::dropOut = nullptr;

DropOutUI* DropOutUI::getUiInstance()
{
    if (DropOutUI::dropOutUI == nullptr)
        DropOutUI::dropOutUI = new DropOutUI;

    return DropOutUI::dropOutUI;
}

DropOutUI::DropOutUI()
{
    // NOP
}

DropOutUI::~DropOutUI()
{
    delete DropOutUI::dropOutUI;
}

DropOut* DropOut::getControlInstance()
{
    if (DropOut::dropOut == nullptr)
        DropOut::dropOut = new DropOut;

    return DropOut::dropOut;
}

DropOutUI* DropOut::getUI()
{
    return this->dropOutUI;
}

DropOut::DropOut()
{
    this->dropOutUI = DropOutUI::getUiInstance();
}

DropOut::~DropOut()
{
    delete dropOut;
}