#include "class.h"

// Initializing Static Attribute
PurchaseUI* PurchaseUI::purchaseUI = nullptr;
Purchase* Purchase::purchase = nullptr;

PurchaseUI* PurchaseUI::getUiInstance()
{
    if(PurchaseUI::purchaseUI == nullptr)
        PurchaseUI::purchaseUI = new PurchaseUI;

    return PurchaseUI::purchaseUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
PurchaseUI::PurchaseUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
PurchaseUI::~PurchaseUI()
{
    delete PurchaseUI::purchaseUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Purchase* Purchase::getControlInstance()
{
    if (Purchase::purchase == nullptr)
        Purchase::purchase = new Purchase;

    return Purchase::purchase;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
PurchaseUI* Purchase::getUI()
{
    return purchaseUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Purchase::Purchase()
{
    purchaseUI = PurchaseUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Purchase::~Purchase()
{
    delete purchase;
}
