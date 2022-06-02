#include "hong_ping.h"

// Initializing Static Attribute
ListPurchaseHistoryUI* ListPurchaseHistoryUI::listPurchaseHistoryUI = nullptr;
ListPurchaseHistory* ListPurchaseHistory::listPurchaseHistory = nullptr;

ListPurchaseHistoryUI* ListPurchaseHistoryUI::getUiInstance()
{
    if(ListPurchaseHistoryUI::listPurchaseHistoryUI == nullptr)
        ListPurchaseHistoryUI::listPurchaseHistoryUI = new ListPurchaseHistoryUI;

    return ListPurchaseHistoryUI::listPurchaseHistoryUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListPurchaseHistoryUI::ListPurchaseHistoryUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
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

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListPurchaseHistory::ListPurchaseHistory()
{
    listPurchaseHistoryUI = ListPurchaseHistoryUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
ListPurchaseHistory::~ListPurchaseHistory()
{
    delete listPurchaseHistory;
}
