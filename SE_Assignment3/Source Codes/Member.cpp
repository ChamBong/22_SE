#include "class.h"

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
bool Member::sale(string productName, string brand, int price, int qty)
{
    // ���κ� �ִ� �Ǹ� ��ǰ ���� �ʰ�
    if(saleProducts >= MAX_PERSONAL_PRODUCTS)
        return false; // �Ǹ� ����

    // �α׾ƿ� ����
    if(Admin::getLoginID().empty())
        return false; // �Ǹ� ����

    Product *newProduct = new Product(productName, brand, price, qty, Admin::getLoginID());

    // ȸ�� ���κ� �Ǹ� ��ǰ ����Ʈ�� ���
    saleList[saleProducts++] = newProduct;

    // ��ü ��ǰ ����Ʈ�� ���
    Admin::getAdminInstance()->addProduct(newProduct);

    return true;
}

string Member::listOnSale()
{
    // �α׾ƿ� ����
    if (Admin::getLoginID().empty())
        return ">\n"; // �Ǹ��� ��ǰ ��ȸ ����

    // �Ǹ� ���� ��ǰ ����
    if (saleProducts == 0)
        return ">\n"; // �Ǹ��� ��ǰ ��ȸ ����

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
    // �α׾ƿ� ����
    if (Admin::getLoginID().empty())
        return ">"; // �Ǹ��� ��ǰ ��ȸ ����

    // �Ǹ��� ��ǰ ����
    if (saleProducts == 0)
        return ">"; // �Ǹ� �Ϸ� ��ǰ ��ȸ ����

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

    // �α׾ƿ� ����
    if(Admin::getAdminInstance()->getLoginID == nullptr)
        return false; // ���� ����

    // ��ǰ ���� �˻� ������ ����
    if(targetProduct == nullptr)
        return false; // ���� ����

    // ��� ����
    if(targetProduct->getOnSaleQty() == 0)
        return false; // ���� ����

    // ���� ó��
    targetProduct->setPurchase();

    // ȸ���� ���� ��ǰ ������ �߰�
    purchaseList[purchasedProducts++] = targetProduct;

    return true; // ���� ����
}

string Member::listPurchaseHistory()
{
    // �α׾ƿ� ����
    if (Admin::getLoginID().empty())
        return ">"; // ��ǰ ���� ���� ��ȸ ����

    // �Ǹ��� ��ǰ ����
    if (purchasedProducts == 0)
        return ">"; // ��ǰ ���� ���� ��ȸ ����

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
    // �� ���� ���� ������ �Է�
    if (rating < 1 || rating > 5)
        return false; // ���Ÿ����� �� ����

    for (int i = 0; i < purchasedProducts; i++)
    {
        if (purchaseList[i]->getProductName() == productName)
        {
            purchaseList[i]->setRating(rating);
            return true; // ���Ÿ����� �� ����
        }
    }

    // ��ġ�ϴ� ��ǰ�� ����
    return false; // ���Ÿ����� �� ����
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