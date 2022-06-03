#include "class.h"

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
        rating = std::to_string(saleList[i]->getAvgRating());

        listSoldOut += "> " + productName + " " + brand + " " + price + " " + soldOutQty + " " + rating;
        cnt_listSoldOut++;
    }

    if(cnt_listSoldOut == 0)
        return ">";
    
    return listSoldOut;
}

Product* Member::searchOnSale(string productName)
{
    Admin* admin = Admin::getAdminInstance();
    return admin->searchProduct(productName);
}

bool Member::purchase()
{
    Product* targetProduct = SearchOnSale::getFocusOn();

    // 로그아웃 상태
    if(Admin::getAdminInstance()->getLoginID == nullptr)
        return false; // 구매 실패

    // 상품 정보 검색 미이행 상태
    if(targetProduct == nullptr)
        return false; // 구매 실패

    // 재고 없음
    if(targetProduct->getOnSaleQty() == 0)
        return false; // 구매 실패

    // 구매 처리
    targetProduct->setPurchase();

    // 회원별 구매 상품 내역에 추가
    purchaseList[purchasedProducts++] = targetProduct;

    return true; // 구매 성공
}

string Member::listPurchaseHistory()
{
    // 로그아웃 상태
    if (Admin::getLoginID().empty())
        return ">"; // 상품 구매 내역 조회 실패

    // 판매한 상품 없음
    if (purchasedProducts == 0)
        return ">"; // 상품 구매 내역 조회 실패

    string listPurchaseHistory;
    int cnt_listPurchase = 0;
    string sellerID, productName, brand, price, onSaleQty, rating;

    for (int i = 0; i < purchasedProducts; i++)
    {
        sellerID = purchaseList[i]->getSellerID();
        productName = purchaseList[i]->getProductName();
        brand = purchaseList[i]->getBrand();
        price = std::to_string(purchaseList[i]->getPrice());
        onSaleQty = std::to_string(purchaseList[i]->getOnSaleQty());
        rating = std::to_string(purchaseList[i]->getAvgRating());

        listPurchaseHistory += "> " + sellerID + " " + productName + " " + brand + " " + price + " " + onSaleQty + " " + rating;
        cnt_listPurchase++;
    }

    if(cnt_listPurchase == 0)
        return ">";
    
    return listPurchaseHistory;
}

bool Member::rate(string productName, int rating)
{
    // 평가 범위 밖의 만족도 입력
    if (rating < 1 || rating > 5)
        return false; // 구매만족도 평가 실패

    for (int i = 0; i < purchasedProducts; i++)
    {
        if (purchaseList[i]->getProductName() == productName)
        {
            purchaseList[i]->setRating(rating);
            return true; // 구매만족도 평가 성공
        }
    }

    // 일치하는 상품명 없음
    return false; // 구매만족도 평가 실패
}

string Member::collectStatistics()
{
    string statisticsInfo = "";
    for (int i = 0; i < saleProducts; i++)
    {
        statisticsInfo += saleList[i]->getProductName() + " ";
        statisticsInfo += std::to_string(saleList[i]->getPrice() * saleList[i]->getSoldOutQty()) + " ";
        statisticsInfo += std::to_string(saleList[i]->getAvgRating()) + "\n";

        if (i + 1 < saleProducts)
            statisticsInfo += "> ";
    }

    return statisticsInfo;
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