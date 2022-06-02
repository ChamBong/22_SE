#include "hong_ping.h"

int Product::products = 0;


void Product::setOnSale()
{
    this->onSale = true;
}

void Product::setSoldOut()
{
    this->onSale = false;
}

bool Product::isOnSale()
{
    return (this->onSale == true);
}

bool Product::isSoldOut()
{
    return (this->onSale == false);
}

Product::Product(string productName, string brand, int price, string sellerID)
:productID(Product::products), productName(productName), brand(brand), price(price), sellerID(sellerID), buyerID(""), rating(0), onSale(false), prev(nullptr), next(nullptr)
{
    Product::products++;
}