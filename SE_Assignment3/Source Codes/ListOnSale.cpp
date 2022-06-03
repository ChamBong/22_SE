#include "class.h"

// Initializing Static Attribute
ListOnSaleUI* ListOnSaleUI::listOnSaleUI = nullptr;
ListOnSale* ListOnSale::listOnSale = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
ListOnSaleUI* ListOnSaleUI::getUiInstance()
{
    if(ListOnSaleUI::listOnSaleUI == nullptr)
        ListOnSaleUI::listOnSaleUI = new ListOnSaleUI;

    return ListOnSaleUI::listOnSaleUI;
}

ListOnSaleUI::ListOnSaleUI()
{
    // NOP
}

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

ListOnSale::ListOnSale()
{
    this->listOnSaleUI = ListOnSaleUI::getUiInstance();
}

ListOnSale::~ListOnSale()
{
    delete this->listOnSale;
}
