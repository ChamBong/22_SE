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

int Product::getAvgRating()
{
    return avgRating;
}

void Product::setPurchase()
{
    onSaleQty--;
    soldOutQty++;
}

void Product::setSoldOut()
{
    this->onSale = false;
}

void Product::setRating(int rating)
{
    int sum = 0, cnt = 0;
    for (int i = 0; i < MAX_PERSONAL_PRODUCTS; i++)
    {
        if (ratings[i] == 0)
        {
            ratings[i] = rating;
            sum += rating;
            cnt++;
            break;
        }
        else
        {
            sum += ratings[i];
            cnt++;
        }
    }
    avgRating = round((float)sum / (float)cnt);
}

bool Product::isOnSale()
{
    return (onSaleQty > 0);
}

bool Product::isSoldOut()
{
    return (onSaleQty == 0);
}

Product::Product(string productName, string brand, int price, int qty, string sellerID)
:productID(Product::productSN), productName(productName), brand(brand), price(price), onSaleQty(qty), soldOutQty(0), sellerID(sellerID), avgRating(0), onSale(true)
{
    Product::productSN++;
    memset(ratings, 0, sizeof(int)*MAX_PERSONAL_PRODUCTS);
}