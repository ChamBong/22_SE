#include "class.h"

// Initializing Static Attribute
ExitUI* ExitUI::exitUI = nullptr;
Exit* Exit::exit = nullptr;

ExitUI* ExitUI::getUiInstance()
{
    if(ExitUI::exitUI == nullptr)
        ExitUI::exitUI = new ExitUI;

    return ExitUI::exitUI;
}

ExitUI::ExitUI()
{
    // NOP
}

ExitUI::~ExitUI()
{
    delete ExitUI::exitUI;
}

Exit* Exit::getControlInstance()
{
    if (Exit::exit == nullptr)
        Exit::exit = new Exit;

    return Exit::exit;
}

ExitUI* Exit::getUI()
{
    return exitUI;
}

Exit::Exit()
{
    exitUI = ExitUI::getUiInstance();
}

Exit::~Exit()
{
    delete exit;
}
