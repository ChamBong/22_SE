#include "hong_ping.h"

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
bool Member::sale(string productName, string brand, int price, int qty)
{
    // 개인별 최대 판매 상품 개수 초과
    if(saleProducts >= MAX_PERSONAL_PRODUCTS)
        return false; // 판매 실패

    // 로그아웃 상태
    if(Admin::getLoginID().empty())
        return false; // 판매 실패

    Product *newProduct = new Product(productName, brand, price, qty, Admin::getLoginID());

    // 회원 개인별 판매 상품 리스트에 등록
    saleList[saleProducts++] = newProduct;

    // 전체 상품 리스트에 등록
    Admin::getAdminInstance()->addProduct(newProduct);

    return true;
}

string Member::listOnSale()
{
    // 로그아웃 상태
    if (Admin::getLoginID().empty())
        return ">\n"; // 판매중 상품 조회 실패

    // 판매 중인 상품 없음
    if (saleProducts == 0)
        return ">\n"; // 판매중 상품 조회 실패

    string listOnSale;
    string productName, brand, price, onSaleQty;
    for (int i = 0; i < saleProducts; i++)
    {
        productName = saleList[i]->getProductName();
        brand = saleList[i]->getBrand();
        price = std::to_string(saleList[i]->getPrice());
        onSaleQty = std::to_string(saleList[i]->getOnSaleQty());

        listOnSale += "> " + productName + " " + brand + " " + price + " " + onSaleQty + "\n";
    }

    return listOnSale;
}

string Member::listSoldOut()
{
    // 로그아웃 상태
    if (Admin::getLoginID().empty())
        return ">"; // 판매중 상품 조회 실패

    // 판매한 상품 없음
    if (saleProducts == 0)
        return ">"; // 판매 완료 상품 조회 실패

    string listSoldOut;
    int cnt_listSoldOut = 0;
    string productName, brand, price, soldOutQty, rating;
    for (int i = 0; i < saleProducts; i++)
    {
        if(saleList[i]->getSoldOutQty() == 0)
            continue;

        productName = saleList[i]->getProductName();
        brand = saleList[i]->getBrand();
        price = std::to_string(saleList[i]->getPrice());
        soldOutQty = std::to_string(saleList[i]->getSoldOutQty());
        rating = std::to_string(saleList[i]->getRating());

        listSoldOut += "> " + productName + " " + brand + " " + price + " " + soldOutQty + " " + rating;
        cnt_listSoldOut++;
    }
    
    if(cnt_listSoldOut == 0)
        return ">";
    
    return listSoldOut;
}

// get Functions
string Member::getName()              { return name; }
string Member::getSSN()               { return SSN; }
string Member::getID()                { return ID; }
string Member::getPassword()          { return password; }
int    Member::getSaleProducts()      { return saleProducts; }
int    Member::getPurchasedProducts() { return purchasedProducts; }

// Constructor and Destructor
Member::Member(string name, string SSN, string ID, string password)
: name(name), SSN(SSN), ID(ID), password(password), saleProducts(0), purchasedProducts(0)
{ }

Member::~Member() {}