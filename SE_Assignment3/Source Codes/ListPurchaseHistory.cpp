#include "class.h"

// Initializing Static Attribute
ListPurchaseHistoryUI* ListPurchaseHistoryUI::listPurchaseHistoryUI = nullptr;
ListPurchaseHistory* ListPurchaseHistory::listPurchaseHistory = nullptr;

ListPurchaseHistoryUI* ListPurchaseHistoryUI::getUiInstance()
{
    if(ListPurchaseHistoryUI::listPurchaseHistoryUI == nullptr)
        ListPurchaseHistoryUI::listPurchaseHistoryUI = new ListPurchaseHistoryUI;

    return ListPurchaseHistoryUI::listPurchaseHistoryUI;
}

ListPurchaseHistoryUI::ListPurchaseHistoryUI()
{
    // NOP
}

ListPurchaseHistoryUI::~ListPurchaseHistoryUI()
{
    delete ListPurchaseHistoryUI::listPurchaseHistoryUI;
}

ListPurchaseHistory* ListPurchaseHistory::getControlInstance()
{
    if (ListPurchaseHistory::listPurchaseHistory == nullptr)
        ListPurchaseHistory::listPurchaseHistory = new ListPurchaseHistory;

    return ListPurchaseHistory::listPurchaseHistory;
}

ListPurchaseHistoryUI* ListPurchaseHistory::getUI()
{
    return listPurchaseHistoryUI;
}

ListPurchaseHistory::ListPurchaseHistory()
{
    listPurchaseHistoryUI = ListPurchaseHistoryUI::getUiInstance();
}

ListPurchaseHistory::~ListPurchaseHistory()
{
    delete listPurchaseHistory;
}
