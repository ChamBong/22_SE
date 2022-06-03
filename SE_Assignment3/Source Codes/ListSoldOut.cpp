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

ListSoldOutUI::ListSoldOutUI()
{
    // NOP
}

ListSoldOutUI::~ListSoldOutUI()
{
    delete ListSoldOutUI::listSoldOutUI;
}

ListSoldOut* ListSoldOut::getControlInstance()
{
    if (ListSoldOut::listSoldOut == nullptr)
        ListSoldOut::listSoldOut = new ListSoldOut;

    return ListSoldOut::listSoldOut;
}

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
