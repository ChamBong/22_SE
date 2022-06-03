#include "class.h"

// Initializing Static Attribute
ListSoldOutUI* ListSoldOutUI::listSoldOutUI = nullptr;
ListSoldOut* ListSoldOut::listSoldOut = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
ListSoldOutUI* ListSoldOutUI::getUiInstance()
{
    if(ListSoldOutUI::listSoldOutUI == nullptr)
        ListSoldOutUI::listSoldOutUI = new ListSoldOutUI;

    return ListSoldOutUI::listSoldOutUI;
}

ListSoldOutUI::ListSoldOutUI()
{
    // NOP
}

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

ListSoldOut::ListSoldOut()
{
    listSoldOutUI = ListSoldOutUI::getUiInstance();
}

ListSoldOut::~ListSoldOut()
{
    delete listSoldOut;
}
