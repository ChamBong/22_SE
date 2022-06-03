#include "class.h"

int Product::productSN = 0; // 상품 시리얼 번호 변수 선언 및 초기화

/*
 *  Function Name : getProductID()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : 상품 ID 반환
 */

int Product::getProductID()
{
    return this->productID;
}

/*
 *  Function Name : getProductName()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 상품명 반환
 */

string Product::getProductName()
{
    return this->productName;
}

/*
 *  Function Name : getBrand()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 제작회사명 반환
 */

string Product::getBrand()
{
    return this->brand;
}

/*
 *  Function Name : getPrice()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : 가격 반환
 */

int Product::getPrice()
{
    return this->price;
}

/*
 *  Function Name : getOnSaleQty()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : 판매중인 상품의 남은 수량 반환
 */

int Product::getOnSaleQty()
{
    return this->onSaleQty;
}

/*
 *  Function Name : getSoldOutQty()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : 판매완료된 상품의 판매된 수량 반환
 */

int Product::getSoldOutQty()
{
    return this->soldOutQty;
}

/*
 *  Function Name : getSellerID()
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 판매자 ID 반환
 */

string Product::getSellerID()
{
    return this->sellerID;
}

/*
 *  Function Name : getAvgRating()
 *  Parameters    : -
 *  Return Type   : int
 *  Description   : 평균 구매만족도 반환
 */

int Product::getAvgRating()
{
    return avgRating;
}

/*
 *  Function Name : setPurchase()
 *  Parameters    : -
 *  Return Type   : -
 *  Description   : 구매 과정에서 남은 수량 -1, 판매된 수량 +1 
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
 *  Description   : 판매중인 상품 상태를 false로 변환
 */

void Product::setSoldOut()
{
    this->onSale = false;
}

/*
 *  Function Name : setRating
 *  Parameters    : 1) rating (int) : 평점
 *  Return Type   : -
 *  Description   : 평균 구매 만족도 구함
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
 *  Description   : 판매중인 상태 확인
 */

bool Product::isOnSale()
{
    return (onSaleQty > 0);
}

/*
 *  Function Name : isSoldOut()
 *  Parameters    : -
 *  Return Type   : bool
 *  Description   : 판매완료 상태 확인
 */

bool Product::isSoldOut()
{
    return (onSaleQty == 0);
}

/*
 *  Class Name    : Product
 *  Parameters    : 1) productName (string) : 상품명
 *                  2) brand (string) : 제작회사명
 *                  3) price (int) : 가격
 *                  4) qty (int) :수량
 *                  5) sellerID (string) : 판매자 ID
 *  Return Type   : -
 *  Description   : 상품 등록
 */

Product::Product(string productName, string brand, int price, int qty, string sellerID)
:productID(Product::productSN), productName(productName), brand(brand), price(price), onSaleQty(qty), soldOutQty(0), sellerID(sellerID), avgRating(0), onSale(true)
{
    Product::productSN++;
    memset(ratings, 0, sizeof(int)*MAX_PERSONAL_PRODUCTS);
}