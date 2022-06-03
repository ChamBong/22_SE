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

PurchaseUI::PurchaseUI()
{
    // NOP
}


PurchaseUI::~PurchaseUI()
{
    delete PurchaseUI::purchaseUI;
}


Purchase* Purchase::getControlInstance()
{
    if (Purchase::purchase == nullptr)
        Purchase::purchase = new Purchase;

    return Purchase::purchase;
}

PurchaseUI* Purchase::getUI()
{
    return purchaseUI;
}

Purchase::Purchase()
{
    purchaseUI = PurchaseUI::getUiInstance();
}

Purchase::~Purchase()
{
    delete purchase;
}
