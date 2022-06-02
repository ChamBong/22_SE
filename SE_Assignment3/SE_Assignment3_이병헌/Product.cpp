#include "hong_ping.h"

int Product::productSN = 0;

int Product::getProductID()
{
    return this->productID;
}

string Product::getProductName()
{
    return this->productName;
}

string Product::getBrand()
{
    return this->brand;
}

int Product::getPrice()
{
    return this->price;
}

int Product::getOnSaleQty()
{
    return this->onSaleQty;
}

int Product::getSoldOutQty()
{
    return this->soldOutQty;
}

string Product::getSellerID()
{
    return this->sellerID;
}

string Product::getBuyerID()
{
    return this->buyerID;
}

int Product::getRating()
{
    return this->rating;
}

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

Product::Product(string productName, string brand, int price, int qty, string sellerID)
:productID(Product::productSN), productName(productName), brand(brand), price(price), onSaleQty(qty), soldOutQty(0), sellerID(sellerID), buyerID(""), rating(0), onSale(true)
{
    Product::productSN++;
}