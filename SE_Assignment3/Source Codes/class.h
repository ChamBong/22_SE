#pragma once

#include "conf.h"



/* * * * * * * * * * * * * * * *
 *  Boundary Class Prototypes  *
 *                             *
 * * * * * * * * * * * * * * * */

/*
 *  Class Name   : UI
 *  Class Type   : Boundary
 *  Relationship : Base Class of All Boundary Classes
 *  Description  : Abstract Base Class
 */
class UI
{
public:
    string getInput(ifstream &inputFile);
    void setOutput(ofstream &outputFile, string output);
};

/*
 *  Class Name   : SignUpUI
 *  Class Type   : Boundary
 *  Relationship : SignUpUI IS-A UI
 *  Description  : Singleton Class�� ������, SignUp Use Case���� ������� ó���ϴ� Ŭ����
 */
class SignUpUI : public UI
{
public:
    static SignUpUI* getUiInstance();

private:
    SignUpUI();
    ~SignUpUI();

private:
    static SignUpUI* signUpUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class DropOutUI : public UI
{
public:
    static DropOutUI* getUiInstance();

private:
    DropOutUI();
    ~DropOutUI();

private:
    static DropOutUI* dropOutUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class LoginUI : public UI
{
public:
    static LoginUI* getUiInstance();
    
private:
    LoginUI();
    ~LoginUI();

private:
    static LoginUI* loginUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class LogoutUI : public UI
{
public:
    static LogoutUI* getUiInstance();
    
private:
    LogoutUI();
    ~LogoutUI();

private:
    static LogoutUI* logoutUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class EnrollUI : public UI
{
public:
    static EnrollUI* getUiInstance();

private:
    EnrollUI();
    ~EnrollUI();

private:
    static EnrollUI* enrollUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class ListOnSaleUI : public UI
{
public:
    static ListOnSaleUI* getUiInstance();
    
private:
    ListOnSaleUI();
    ~ListOnSaleUI();

private:
    static ListOnSaleUI* listOnSaleUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class ListSoldOutUI : public UI
{
public:
    static ListSoldOutUI* getUiInstance();
    
private:
    ListSoldOutUI();
    ~ListSoldOutUI();

private:
    static ListSoldOutUI* listSoldOutUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class SearchOnSaleUI : public UI
{
public:
    static SearchOnSaleUI* getUiInstance();
    
private:
    SearchOnSaleUI();
    ~SearchOnSaleUI();

private:
    static SearchOnSaleUI* searchOnSaleUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class PurchaseUI : public UI
{
public:
    static PurchaseUI* getUiInstance();
    
private:
    PurchaseUI();
    ~PurchaseUI();

private:
    static PurchaseUI* purchaseUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class ListPurchaseHistoryUI : public UI
{
public:
    static ListPurchaseHistoryUI* getUiInstance();
    
private:
    ListPurchaseHistoryUI();
    ~ListPurchaseHistoryUI();

private:
    static ListPurchaseHistoryUI* listPurchaseHistoryUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class RateUI : public UI
{
public:
    static RateUI* getUiInstance();
    
private:
    RateUI();
    ~RateUI();

private:
    static RateUI* rateUI;
};

/*
 *  Class Name   : 
 *  Class Type   : Boundary
 *  Relationship : 
 *  Description  : 
 */
class CollectStatisticsUI : public UI
{
public:
    static CollectStatisticsUI* getUiInstance();
    
private:
    CollectStatisticsUI();
    ~CollectStatisticsUI();

private:
    static CollectStatisticsUI* collectStatisticsUI;
};

class ExitUI : public UI
{
public:
    static ExitUI* getUiInstance();
    
private:
    ExitUI();
    ~ExitUI();

private:
    static ExitUI* exitUI;
};



/* * * * * * * * * * * * * * * *
 *   Control Class Prototypes  *
 *                             *
 * * * * * * * * * * * * * * * */

/*
 *  Class Name   : Control
 *  Class Type   : Control
 *  Relationship : 
 *  Description  :
 */
class Control
{
public:
    virtual UI* getUI() = 0;
};

/*
 *  Class Name   : SignUp
 *  Class Type   : Control
 *  Relationship : 
 *  Description  :
 */
class SignUp : public Control
{
public:
    static SignUp* getControlInstance();
    virtual SignUpUI* getUI() override;

private:
    SignUp();
    ~SignUp();

private:
    static SignUp* signUp;
    SignUpUI* signUpUI;
};



/*
 *  Class Name   : SignUp
 *  Class Type   : Control
 *  Relationship : 
 *  Description  :
 */
class DropOut : public Control
{
public:
    static DropOut* getControlInstance();
    virtual DropOutUI* getUI() override;

private:
    DropOut();
    ~DropOut();

private:
    static DropOut* dropOut;
    DropOutUI* dropOutUI;
};



/*
 *  Class Name   : Login
 *  Class Type   : Control
 *  Relationship : 
 *  Description  :
 */
class Login : public Control
{
public:
    static Login* getControlInstance();
    virtual LoginUI* getUI() override;

private:
    Login();
    ~Login();

private:
    static Login* login;
    LoginUI* loginUI;
};



class Logout : public Control
{
public:
    static Logout* getControlInstance();
    virtual LogoutUI* getUI() override;

private:
    Logout();
    ~Logout();

private:
    static Logout* logout;
    LogoutUI* logoutUI;
};

class Enroll : public Control
{
public:
    static Enroll* getControlInstance();
    virtual EnrollUI* getUI() override;

private:
    Enroll();
    ~Enroll();

private:
    static Enroll* enroll;
    EnrollUI* enrollUI;
};

class ListOnSale : public Control
{
public:
    static ListOnSale* getControlInstance();
    virtual ListOnSaleUI* getUI() override;

private:
    ListOnSale();
    ~ListOnSale();

private:
    static ListOnSale* listOnSale;
    ListOnSaleUI* listOnSaleUI;
};

class ListSoldOut : public Control
{
public:
    static ListSoldOut* getControlInstance();
    virtual ListSoldOutUI* getUI() override;

private:
    ListSoldOut();
    ~ListSoldOut();

private:
    static ListSoldOut* listSoldOut;
    ListSoldOutUI* listSoldOutUI;
};

class SearchOnSale : public Control
{
public:
    static SearchOnSale* getControlInstance();
    virtual SearchOnSaleUI* getUI() override;
    static Product* getFocusOn();
    static void setFocusOn(Product* focusOnProduct);

private:
    SearchOnSale();
    ~SearchOnSale();

private:
    static SearchOnSale* searchOnSale;
    static Product* focusOn;
    SearchOnSaleUI* searchOnSaleUI;
};

class Purchase : public Control
{
public:
    static Purchase* getControlInstance();
    virtual PurchaseUI* getUI() override;

private:
    Purchase();
    ~Purchase();

private:
    static Purchase* purchase;
    PurchaseUI* purchaseUI;
};

class ListPurchaseHistory : public Control
{
public:
    static ListPurchaseHistory* getControlInstance();
    virtual ListPurchaseHistoryUI* getUI() override;

private:
    ListPurchaseHistory();
    ~ListPurchaseHistory();

private:
    static ListPurchaseHistory* listPurchaseHistory;
    ListPurchaseHistoryUI* listPurchaseHistoryUI;
};

class Rate : public Control
{
public:
    static Rate* getControlInstance();
    virtual RateUI* getUI() override;

private:
    Rate();
    ~Rate();

private:
    static Rate* rate;
    RateUI* rateUI;
};

class CollectStatistics : public Control
{
public:
    static CollectStatistics* getControlInstance();
    virtual CollectStatisticsUI* getUI() override;

private:
    CollectStatistics();
    ~CollectStatistics();

private:
    static CollectStatistics* collectStatistics;
    CollectStatisticsUI* collectStatisticsUI;
};

class Exit : public Control
{
public:
    static Exit* getControlInstance();
    virtual ExitUI* getUI() override;

private:
    Exit();
    ~Exit();

private:
    static Exit* exit;
    ExitUI* exitUI;
};



/* * * * * * * * * * * * * * * *
 *   Entity Class Prototypes   *
 *                             *
 * * * * * * * * * * * * * * * */

/*
 *  Class Name   : 
 *  Class Type   : Entity
 *  Relationship : 
 *  Description  :
 */
class Admin
{
public:
    bool addMember(string name, string SSN, string ID, string password);
    string deleteMember();
    bool login(string ID, string password);
    string logout();
    Member* findMember(string ID);

public:
    void addProduct(Product* newProduct);
    Product* searchProduct(string productName);

public:
    static Admin* getAdminInstance();
    static string getLoginID();

private:
    Admin();
    ~Admin();

private:
    static Admin* admin;   // ������
    static string loginID; // ���� �α������� ȸ���� ID
    
    Member* memberList[MAX_ALL_MEMBERS]; // ��ü ȸ�� ����Ʈ
    int members; // ��ü ȸ����

    Product* productList[MAX_ALL_PRODUCTS]; // ��ü ��ǰ ����Ʈ (�Ǹ��� ��ǰ + �ǸſϷ� ��ǰ)
    int products; // ��ü ��ǰ�� (�Ǹ��� ��ǰ + �ǸſϷ� ��ǰ)
    
};

/*
 *  Class Name   : 
 *  Class Type   : Entity
 *  Relationship : 
 *  Description  :
 */
class Member
{
// Use Case Functions
public:
    bool sale(string productName, string brand, int price, int qty); // �Ǹ� �Ƿ� ���
    string listOnSale();          // ��� ��ǰ ��ȸ
    string listSoldOut();         // �Ǹ� �Ϸ� ��ǰ ��ȸ
    Product* searchOnSale(string productName);        // ��ǰ ���� �˻�
    bool purchase();            // ��ǰ ����
    string listPurchaseHistory(); // ��ǰ ���� ���� ��ȸ
    bool rate(string productName, int rating);                // ��ǰ ���� ������ ��
    string collectStatistics();   // �Ǹ� ��ǰ ���

// get Functions
public:
    string getName();
    string getSSN();
    string getID();
    string getPassword();
    int getSaleProducts();
    int getPurchasedProducts();

// Constructor and Destructor
public:
    Member(string name, string SSN, string ID, string password);
    ~Member();

// ȸ�� ��������
private:
    string name;     // ȸ�� ����
    string SSN;      // �ֹε�Ϲ�ȣ (Social Security Number)
    string ID;       // ȸ�� ID
    string password; // ȸ�� ��й�ȣ

// ȸ���� �Ǹš����� ��ǰ ����
private:
    Product* saleList[MAX_PERSONAL_PRODUCTS]; // �Ǹ��ߡ��ǸſϷ� ��ǰ ����Ʈ
    int saleProducts;  // ���κ� �Ǹ��� ��ǰ ���� ����

    Product* purchaseList[MAX_PERSONAL_PRODUCTS]; // ���� ��ǰ ����Ʈ
    int purchasedProducts; // ���κ� ������ ��ǰ ���� ����
};

/*
 *  Class Name   : Product
 *  Class Type   : Entity
 *  Relationship : Admin  HAS-A Product
 *                 Member HAS-A Product
 *  Description  :
 */
class Product
{
public:
    int getProductID();
    string getProductName();
    string getBrand();
    int getPrice();
    int getOnSaleQty();
    int getSoldOutQty();
    string getSellerID();
    int getAvgRating();

    void setPurchase();
    void setSoldOut();
    void setRating(int rating);

    bool isOnSale();
    bool isSoldOut();

public:
    Product(string productName, string brand, int price, int qty, string sellerID);
    ~Product();

private:
    static int productSN;

private:
    int productID;
    string productName;
    string brand;
    int price;
    int onSaleQty;
    int soldOutQty;
    string sellerID;
    int ratings[MAX_PERSONAL_PRODUCTS];
    int avgRating;
    bool onSale;
};
