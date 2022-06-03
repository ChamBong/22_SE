#include "class.h"

// Initializing Static Attribute
ListOnSaleUI* ListOnSaleUI::listOnSaleUI = nullptr;
ListOnSale* ListOnSale::listOnSale = nullptr;

ListOnSaleUI* ListOnSaleUI::getUiInstance()
{
    if(ListOnSaleUI::listOnSaleUI == nullptr)
        ListOnSaleUI::listOnSaleUI = new ListOnSaleUI;

    return ListOnSaleUI::listOnSaleUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSaleUI::ListOnSaleUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSaleUI::~ListOnSaleUI()
{
    delete ListOnSaleUI::listOnSaleUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSale* ListOnSale::getControlInstance()
{
    if (ListOnSale::listOnSale == nullptr)
        ListOnSale::listOnSale = new ListOnSale;

    return ListOnSale::listOnSale;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSaleUI* ListOnSale::getUI()
{
    return this->listOnSaleUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSale::ListOnSale()
{
    this->listOnSaleUI = ListOnSaleUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListOnSale::~ListOnSale()
{
    delete this->listOnSale;
}
