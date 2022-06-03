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

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ExitUI::ExitUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ExitUI::~ExitUI()
{
    delete ExitUI::exitUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Exit* Exit::getControlInstance()
{
    if (Exit::exit == nullptr)
        Exit::exit = new Exit;

    return Exit::exit;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ExitUI* Exit::getUI()
{
    return exitUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Exit::Exit()
{
    exitUI = ExitUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Exit::~Exit()
{
    delete exit;
}
