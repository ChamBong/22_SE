#include "hong_ping.h"

// Initializing Static Attribute
SearchOnSaleUI* SearchOnSaleUI::searchOnSaleUI = nullptr;
SearchOnSale* SearchOnSale::searchOnSale = nullptr;
Product* SearchOnSale::focusOn = nullptr;

SearchOnSaleUI* SearchOnSaleUI::getUiInstance()
{
    if(SearchOnSaleUI::searchOnSaleUI == nullptr)
        SearchOnSaleUI::searchOnSaleUI = new SearchOnSaleUI;

    return SearchOnSaleUI::searchOnSaleUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSaleUI::SearchOnSaleUI()
{
    // NOP
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSaleUI::~SearchOnSaleUI()
{
    delete SearchOnSaleUI::searchOnSaleUI;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSale* SearchOnSale::getControlInstance()
{
    if (SearchOnSale::searchOnSale == nullptr)
        SearchOnSale::searchOnSale = new SearchOnSale;

    return SearchOnSale::searchOnSale;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSaleUI* SearchOnSale::getUI()
{
    return searchOnSaleUI;
}

Product* SearchOnSale::getFocusOn()
{
    return focusOn;
}

void SearchOnSale::setFocusOn(Product* fouceOnProduct)
{
    focusOn = fouceOnProduct;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSale::SearchOnSale()
{
    searchOnSaleUI = SearchOnSaleUI::getUiInstance();
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
SearchOnSale::~SearchOnSale()
{
    delete searchOnSale;
}
