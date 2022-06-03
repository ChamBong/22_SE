#include "class.h"

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

SearchOnSaleUI::SearchOnSaleUI()
{
    // NOP
}

SearchOnSaleUI::~SearchOnSaleUI()
{
    delete SearchOnSaleUI::searchOnSaleUI;
}

SearchOnSale* SearchOnSale::getControlInstance()
{
    if (SearchOnSale::searchOnSale == nullptr)
        SearchOnSale::searchOnSale = new SearchOnSale;

    return SearchOnSale::searchOnSale;
}

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

SearchOnSale::SearchOnSale()
{
    searchOnSaleUI = SearchOnSaleUI::getUiInstance();
}

SearchOnSale::~SearchOnSale()
{
    delete searchOnSale;
}
