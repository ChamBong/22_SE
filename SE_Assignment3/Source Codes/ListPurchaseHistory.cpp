#include "class.h"

// Initializing Static Attribute
ListPurchaseHistoryUI* ListPurchaseHistoryUI::listPurchaseHistoryUI = nullptr;
ListPurchaseHistory* ListPurchaseHistory::listPurchaseHistory = nullptr;

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   :
 */
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

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListPurchaseHistory* ListPurchaseHistory::getControlInstance()
{
    if (ListPurchaseHistory::listPurchaseHistory == nullptr)
        ListPurchaseHistory::listPurchaseHistory = new ListPurchaseHistory;

    return ListPurchaseHistory::listPurchaseHistory;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
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
