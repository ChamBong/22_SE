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

ListOnSaleUI::ListOnSaleUI()
{
    // NOP
}

ListOnSaleUI::~ListOnSaleUI()
{
    delete ListOnSaleUI::listOnSaleUI;
}

ListOnSale* ListOnSale::getControlInstance()
{
    if (ListOnSale::listOnSale == nullptr)
        ListOnSale::listOnSale = new ListOnSale;

    return ListOnSale::listOnSale;
}

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
