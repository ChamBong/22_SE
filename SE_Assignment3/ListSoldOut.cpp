#include "class.h"

// Initializing Static Attribute
ListSoldOutUI* ListSoldOutUI::listSoldOutUI = nullptr;
ListSoldOut* ListSoldOut::listSoldOut = nullptr;

ListSoldOutUI* ListSoldOutUI::getUiInstance()
{
    if(ListSoldOutUI::listSoldOutUI == nullptr)
        ListSoldOutUI::listSoldOutUI = new ListSoldOutUI;

    return ListSoldOutUI::listSoldOutUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOutUI::ListSoldOutUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOutUI::~ListSoldOutUI()
{
    delete ListSoldOutUI::listSoldOutUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOut* ListSoldOut::getControlInstance()
{
    if (ListSoldOut::listSoldOut == nullptr)
        ListSoldOut::listSoldOut = new ListSoldOut;

    return ListSoldOut::listSoldOut;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOutUI* ListSoldOut::getUI()
{
    return listSoldOutUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOut::ListSoldOut()
{
    listSoldOutUI = ListSoldOutUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListSoldOut::~ListSoldOut()
{
    delete listSoldOut;
}
