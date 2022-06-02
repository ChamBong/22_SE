#pragma once

// Header Files
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <sstream>
#include <math.h>

// Namespaces
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

// Constants
const int MAX_ALL_MEMBERS  = 1000;     // 최대 전체 회원수
const int MAX_ALL_PRODUCTS = 1000;     // 최대 전체 상품수
const int MAX_PERSONAL_PRODUCTS = 500; // 개인별 최대 구입 및 판매 상품수 



/* * * * * * * * * * * * * * * *
 *     Forward Declarations    *
 *                             *
 * * * * * * * * * * * * * * * */

// Boundary Classes Declarations
class UI;

class SignUpUI;
class DropOutUI;
class LoginUI;
class logoutUI;
class EnrollUI;
class ListOnSaleUI;
class ListSoldOutUI;
class SearchOnSaleUI;
class PurchaseUI;
class ListPurchaseHistoryUI;
class RateUI;
class CollectStatisticsUI;

// Control Classes Declarations
class Control;

class SignUp;
class DropOut;
class Login;
class Logout;
class Enroll;
class ListOnSale;
class ListSoldOut;
class SearchOnSale;
class Purchase;
class ListShoppingHistory;
class Rate;
class CollectStatistics;

// Entity Classes Declarations
class Admin;
class Member;
class Product;



/* * * * * * * * * * * * * * * *
 *       Class Prototypes      *
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
 *  Description  : Singleton Class로 구현된, SignUp Use Case에서 입출력을 처리하는 클래스
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
    static Admin* admin;   // 관리자
    static string loginID; // 현재 로그인중인 회원의 ID
    
    Member* memberList[MAX_ALL_MEMBERS]; // 전체 회원 리스트
    int members; // 전체 회원수

    Product* productList[MAX_ALL_PRODUCTS]; // 전체 상품 리스트 (판매중 상품 + 판매완료 상품)
    int products; // 전체 상품수 (판매중 상품 + 판매완료 상품)
    
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
    bool sale(string productName, string brand, int price, int qty); // 판매 의류 등록
    string listOnSale();          // 등록 상품 조회
    string listSoldOut();         // 판매 완료 상품 조회
    Product* searchOnSale(string productName);        // 상품 정보 검색
    bool purchase();            // 상품 구매
    string listPurchaseHistory(); // 상품 구매 내역 조회
    bool rate(string productName, int rating);                // 상품 구매 만족도 평가
    string collectStatistics();   // 판매 상품 통계

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

// 회원 인적사항
private:
    string name;     // 회원 성명
    string SSN;      // 주민등록번호 (Social Security Number)
    string ID;       // 회원 ID
    string password; // 회원 비밀번호

// 회원별 판매·구매 상품 내역
private:
    Product* saleList[MAX_PERSONAL_PRODUCTS]; // 판매중·판매완료 상품 리스트
    int saleProducts;  // 개인별 판매한 상품 종류 개수

    Product* purchaseList[MAX_PERSONAL_PRODUCTS]; // 구매 상품 리스트
    int purchasedProducts; // 개인별 구매한 상품 종류 개수
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
