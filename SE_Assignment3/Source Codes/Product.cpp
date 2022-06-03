#include "class.h"

int Product::productSN = 0; // ��ǰ �ø��� ��ȣ ���� ���� �� �ʱ�ȭ

/*
 *  Function Name : getProductID()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : ��ǰ ID ��ȯ
 */

int Product::getProductID()
{
    return this->productID;
}

/*
 *  Function Name : getProductName()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : ��ǰ�� ��ȯ
 */

string Product::getProductName()
{
    return this->productName;
}

/*
 *  Function Name : getBrand()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : ����ȸ��� ��ȯ
 */

string Product::getBrand()
{
    return this->brand;
}

/*
 *  Function Name : getPrice()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : ���� ��ȯ
 */

int Product::getPrice()
{
    return this->price;
}

/*
 *  Function Name : getOnSaleQty()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : �Ǹ����� ��ǰ�� ���� ���� ��ȯ
 */

int Product::getOnSaleQty()
{
    return this->onSaleQty;
}

/*
 *  Function Name : getSoldOutQty()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : �ǸſϷ�� ��ǰ�� �Ǹŵ� ���� ��ȯ
 */

int Product::getSoldOutQty()
{
    return this->soldOutQty;
}

/*
 *  Function Name : getSellerID()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : �Ǹ��� ID ��ȯ
 */

string Product::getSellerID()
{
    return this->sellerID;
}

/*
 *  Function Name : getAvgRating()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : ��� ���Ÿ����� ��ȯ
 */

int Product::getAvgRating()
{
    return avgRating;
}

/*
 *  Function Name : setPurchase()
 *  Parameters    : -
 *  Return Type   : -
 *  Description   : ���� �������� ���� ���� -1, �Ǹŵ� ���� +1 
 */

void Product::setPurchase()
{
    onSaleQty--;
    soldOutQty++;
}

/*
 *  Function Name : setSoldOut
 *  Parameters    : -
 *  Return Type   : -
 *  Description   : �Ǹ����� ��ǰ ���¸� false�� ��ȯ
 */

void Product::setSoldOut()
{
    this->onSale = false;
}

/*
 *  Function Name : setRating
 *  Parameters    : 1) rating (int) : ����
 *  Return Type   : -
 *  Description   : ��� ���� ������ ����
 */

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

/*
 *  Function Name : isOnSale()
 *  Parameters    : -
 *  Return Type   : bool
 *  Description   : �Ǹ����� ���� Ȯ��
 */

bool Product::isOnSale()
{
    return (onSaleQty > 0);
}

/*
 *  Function Name : isSoldOut()
 *  Parameters    : -
 *  Return Type   : bool
 *  Description   : �ǸſϷ� ���� Ȯ��
 */

bool Product::isSoldOut()
{
    return (onSaleQty == 0);
}

/*
 *  Class Name    : Product
 *  Parameters    : 1) productName (string) : ��ǰ��
 *                  2) brand (string) : ����ȸ���
 *                  3) price (int) : ����
 *                  4) qty (int) :����
 *                  5) sellerID (string) : �Ǹ��� ID
 *  Return Type   : -
 *  Description   : ��ǰ ���
 */

Product::Product(string productName, string brand, int price, int qty, string sellerID)
:productID(Product::productSN), productName(productName), brand(brand), price(price), onSaleQty(qty), soldOutQty(0), sellerID(sellerID), avgRating(0), onSale(true)
{
    Product::productSN++;
    memset(ratings, 0, sizeof(int)*MAX_PERSONAL_PRODUCTS);
}