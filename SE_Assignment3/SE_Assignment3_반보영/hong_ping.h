#pragma once

// Header Files
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

// Namespaces
using std::fstream;
using std::ifstream;
using std::ofstream;
using std::string;
using std::stringstream;

// Constants
const int MAX_MEMBERS  = 1000; // 최대 회원수
const int MAX_PRODUCTS = 1000; // 최대 상품수



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

// class ListOnSale : public Control;
// class ListSoldOut : public Control;
// class SearchOnSale : public Control;
// class Purchase : public Control;
// class ListPurchaseHistory : public Control;
// class Rate : public Control;
// class CollectStatistics : public Control;

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
    static Admin* getAdminInstance();
    static string getLoginID();

private:
    Admin();

private:
    static Admin* admin;
    static string loginID;
    Member* memberList[MAX_MEMBERS];
    unsigned int members;
};

/*
 *  Class Name   : 
 *  Class Type   : Entity
 *  Relationship : 
 *  Description  :
 */
class Member{
public:
    bool sale(string productName, string brand, int price, int qty); // 판매 의류 등록
    void listOnSale(); // 등록 상품 조회
    void listSoldOut(); // 판매 완료 상품 조회
    void searchOnSale(); // 상품 정보 검색
    void purchase(); // 상품 구매
    void listPurchaseHistory(); // 상품 구매 내역 조회
    void rate();
    void collectStatistics(); // 판매 상품 통계

public:
    string getName();
    string getSSN();
    string getID();
    string getPassword();

public:
    Member(string name, string SSN, string ID, string password);

private:
    string name;
    string SSN;
    string ID;
    string password;

private:
    Product* onSaleList[MAX_PRODUCTS];
    int onSaleProducts;

    Product* soldOutList[MAX_PRODUCTS];
    int soldOutProducts;

    Product* purchasedList[MAX_PRODUCTS];
    int purchasedProducts;
};

/*
 *  Class Name   : 
 *  Class Type   : Entity
 *  Relationship : 
 *  Description  :
 */
class Product
{
public:
    int getProductID();
    string getProductName();
    string getBrand();
    int getPrice();
    string getSellerID();
    string getBuyerID();
    int getRating();

    void setOnSale();
    void setSoldOut();

    bool isOnSale();
    bool isSoldOut();

public:
    Product(string productName, string brand, int price, string sellerID);
    ~Product();

private:
    static int products;
    int productID;
    string productName;
    string brand;
    int price;
    string sellerID;
    string buyerID;
    int rating;
    bool onSale;

private:
    Product *prev;
    Product *next;
};