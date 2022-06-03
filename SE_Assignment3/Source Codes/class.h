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
 *  Author       : �̺���
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
 *  Author       : �̺���
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
 *  Class Name   : DropOutUI
 *  Class Type   : Boundary
 *  Relationship : DropOutUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : LoginUI
 *  Class Type   : Boundary
 *  Relationship : LoginUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : LogoutUI
 *  Class Type   : Boundary
 *  Relationship : LogoutUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : EnrollUI
 *  Class Type   : Boundary
 *  Relationship : EnrollUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : ListOnSaleUI
 *  Class Type   : Boundary
 *  Relationship : ListOnSaleUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : ListSoldOutUI
 *  Class Type   : Boundary
 *  Relationship : ListSoldOutUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : SearchOnSaleUI
 *  Class Type   : Boundary
 *  Relationship : SearchOnSaleUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : PurchaseUI
 *  Class Type   : Boundary
 *  Relationship : PurchaseUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : ListPurchaseHistoryUI
 *  Class Type   : Boundary
 *  Relationship : ListPurchaseHistoryUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : RateUI
 *  Class Type   : Boundary
 *  Relationship : RateUI IS-A UI
 *  Description  :
 *  Author       : �̺���
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
 *  Class Name   : CollectStatisticsUI
 *  Class Type   : Boundary
 *  Relationship : CollectStatisticsUI IS-A UI
 *  Description  : 
 *  Author       : �̺���
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

/*
 *  Class Name   : ExitUI
 *  Class Type   : Boundary
 *  Relationship : ExitUI IS-A UI
 *  Description  :
 *  Author       : �̺���
 */

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
 *  Author       : �̺���
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
 *  Class Name   : DropOut
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
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
 *  Author       : �̺���
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

/*
 *  Class Name   : Logout
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : Enroll
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : ListOnSale
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : ListSoldOut
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : SearchOnSale
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : Purchase
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : ListPurchaseHistory
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : Rate
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : CollectStatistics
 *  Class Type   : Control
 *  Relationship :
 *  Description  :
 *  Author       : �̺���
 */

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

/*
 *  Class Name   : Exit
 *  Class Type   : Control
 *  Relationship :
 *  Description  : 
 *  Author       : �̺���
 */

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
 *  Class Name   : Admin
 *  Class Type   : Entity
 *  Relationship : 
 *  Description  : Admin Ŭ������ ��� ���� �� �Լ� ����
 *  Author       : �̺���
 */

 /*
 *   Revisions :
 *       1. Who : ������
 *          What : added Comments
 */

class Admin
{
public:
    bool addMember(string name, string SSN, string ID, string password); // ȸ�����Ե� ���� Ȯ��
    string deleteMember();                                               // ȸ��Ż��
    bool login(string ID, string password);                              // �α����� ���� Ȯ��
    string logout();                                                     // �α׾ƿ�
    Member* findMember(string ID);                                       // ȸ������Ʈ���� ȸ�� ã��

public:
    void addProduct(Product* newProduct);       // ��ǰ ���
    Product* searchProduct(string productName); // ��ǰ �˻�

public:
    static Admin* getAdminInstance(); // 
    static string getLoginID();       // �α��� ID �ҷ�����

private:
    Admin();
    ~Admin();

private:
    static Admin* admin;                    // ������
    static string loginID;                  // ���� �α������� ȸ���� ID
    
    Member* memberList[MAX_ALL_MEMBERS];    // ��ü ȸ�� ����Ʈ
    int members;                            // ��ü ȸ����

    Product* productList[MAX_ALL_PRODUCTS]; // ��ü ��ǰ ����Ʈ (�Ǹ��� ��ǰ + �ǸſϷ� ��ǰ)
    int products;                           // ��ü ��ǰ�� (�Ǹ��� ��ǰ + �ǸſϷ� ��ǰ)
    
};

/*
 *  Class Name   : Member
 *  Class Type   : Entity
 *  Relationship : Member IS-A Seller
 *                 Member IS-A Buyer
 *  Description  : Member Ŭ������ ��� ���� �� �Լ� ����
 *  Author       : �̺���
 */

 /*
 *   Revisions :
 *       1. Who : ������
 *          What : added Comments
 */

class Member
{
// Use Case Functions
public:
    bool sale(string productName, string brand, int price, int qty); // �Ǹ� �Ƿ� ���
    string listOnSale();                                             // ��� ��ǰ ��ȸ
    string listSoldOut();                                            // �Ǹ� �Ϸ� ��ǰ ��ȸ
    Product* searchOnSale(string productName);                       // ��ǰ ���� �˻�
    bool purchase();                                                 // ��ǰ ����
    string listPurchaseHistory();                                    // ��ǰ ���� ���� ��ȸ
    bool rate(string productName, int rating);                       // ��ǰ ���� ������ ��
    string collectStatistics();                                      // �Ǹ� ��ǰ ���

// get Functions
public:
    string getName();           // �̸� �ҷ�����
    string getSSN();            // �ֹι�ȣ �ҷ�����
    string getID();             // ID �ҷ�����
    string getPassword();       // ��й�ȣ �ҷ�����
    int getSaleProducts();      // �Ǹ����� ��ǰ �ҷ�����
    int getPurchasedProducts(); // �ǸſϷ�� ��ǰ �ҷ�����

// Constructor and Destructor
public:
    Member(string name, string SSN, string ID, string password); // ȸ�� ����
    ~Member();

// ȸ�� ��������
private:
    string name;     // ȸ�� ����
    string SSN;      // �ֹε�Ϲ�ȣ (Social Security Number)
    string ID;       // ȸ�� ID
    string password; // ȸ�� ��й�ȣ

// ȸ���� �Ǹš����� ��ǰ ����
private:
    Product* saleList[MAX_PERSONAL_PRODUCTS];     // �Ǹ��ߡ��ǸſϷ� ��ǰ ����Ʈ
    int saleProducts;                             // ���κ� �Ǹ��� ��ǰ ���� ����

    Product* purchaseList[MAX_PERSONAL_PRODUCTS]; // ���� ��ǰ ����Ʈ
    int purchasedProducts;                        // ���κ� ������ ��ǰ ���� ����
};

/*
 *  Class Name   : Product
 *  Class Type   : Entity
 *  Relationship : Admin  HAS-A Product
 *                 Member HAS-A Product
 *  Description  : Product Ŭ������ ��� ���� �� �Լ��� ����
 *  Author       : �̺���
 */

/*
*   Revisions :
*       1. Who : ������
*          What : added Comments
*/

class Product
{
public:
    int getProductID();         // ��ǰ ID �ҷ�����
    string getProductName();    // ��ǰ �̸� �ҷ�����
    string getBrand();          // ����ȸ��� �ҷ�����
    int getPrice();             // ���� �ҷ�����
    int getOnSaleQty();         // �Ǹ����� ��ǰ�� ���� ���� �ҷ����� 
    int getSoldOutQty();        // �ǸſϷ�� ��ǰ�� �Ǹŵ� ���� �ҷ�����
    string getSellerID();       // �Ǹ��� ID �ҷ�����
    int getAvgRating();         // ��� ���Ÿ����� �ҷ�����

    void setPurchase();         // '�Ǹ���' ���� ����
    void setSoldOut();          // '�ǸſϷ�' ���� ����
    void setRating(int rating); // ���� ������ ��(����)

    bool isOnSale();            // '�Ǹ���' ���� Ȯ��
    bool isSoldOut();           // '�ǸſϷ�' ���� Ȯ��

public:
    Product(string productName, string brand, int price, int qty, string sellerID); // ��ǰ �� ����
    ~Product();

private:
    static int productSN;                   // ��ǰ �ø��� ��ȣ

private:
    int productID;                          // ��ǰ ID
    string productName;                     // ��ǰ �̸�
    string brand;                           // ����ȸ���
    int price;                              // ����
    int onSaleQty;                          // �Ǹ����� ��ǰ�� ���� ����
    int soldOutQty;                         // �Ǹ� �Ϸ�� ��ǰ�� �Ǹŵ� ����
    string sellerID;                        // �Ǹ��� ID
    int ratings[MAX_PERSONAL_PRODUCTS];     // ����
    int avgRating;                          // ��� ���� ������
    bool onSale;                            // '�Ǹ���', '�ǸſϷ�' ���� �Ǻ� ����
};