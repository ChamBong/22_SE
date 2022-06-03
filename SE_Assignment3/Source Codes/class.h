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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Author       : 이병헌
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
 *  Description  : Admin 클래스의 멤버 변수 및 함수 선언
 *  Author       : 이병헌
 */

 /*
 *   Revisions :
 *       1. Who : 노지석
 *          What : added Comments
 */

class Admin
{
public:
    bool addMember(string name, string SSN, string ID, string password); // 회원가입된 상태 확인
    string deleteMember();                                               // 회원탈퇴
    bool login(string ID, string password);                              // 로그인한 상태 확인
    string logout();                                                     // 로그아웃
    Member* findMember(string ID);                                       // 회원리스트에서 회원 찾기

public:
    void addProduct(Product* newProduct);       // 상품 등록
    Product* searchProduct(string productName); // 상품 검색

public:
    static Admin* getAdminInstance(); // 
    static string getLoginID();       // 로그인 ID 불러오기

private:
    Admin();
    ~Admin();

private:
    static Admin* admin;                    // 관리자
    static string loginID;                  // 현재 로그인중인 회원의 ID
    
    Member* memberList[MAX_ALL_MEMBERS];    // 전체 회원 리스트
    int members;                            // 전체 회원수

    Product* productList[MAX_ALL_PRODUCTS]; // 전체 상품 리스트 (판매중 상품 + 판매완료 상품)
    int products;                           // 전체 상품수 (판매중 상품 + 판매완료 상품)
    
};

/*
 *  Class Name   : Member
 *  Class Type   : Entity
 *  Relationship : Member IS-A Seller
 *                 Member IS-A Buyer
 *  Description  : Member 클래스의 멤버 변수 및 함수 선언
 *  Author       : 이병헌
 */

 /*
 *   Revisions :
 *       1. Who : 노지석
 *          What : added Comments
 */

class Member
{
// Use Case Functions
public:
    bool sale(string productName, string brand, int price, int qty); // 판매 의류 등록
    string listOnSale();                                             // 등록 상품 조회
    string listSoldOut();                                            // 판매 완료 상품 조회
    Product* searchOnSale(string productName);                       // 상품 정보 검색
    bool purchase();                                                 // 상품 구매
    string listPurchaseHistory();                                    // 상품 구매 내역 조회
    bool rate(string productName, int rating);                       // 상품 구매 만족도 평가
    string collectStatistics();                                      // 판매 상품 통계

// get Functions
public:
    string getName();           // 이름 불러오기
    string getSSN();            // 주민번호 불러오기
    string getID();             // ID 불러오기
    string getPassword();       // 비밀번호 불러오기
    int getSaleProducts();      // 판매중인 상품 불러오기
    int getPurchasedProducts(); // 판매완료된 상품 불러오기

// Constructor and Destructor
public:
    Member(string name, string SSN, string ID, string password); // 회원 정보
    ~Member();

// 회원 인적사항
private:
    string name;     // 회원 성명
    string SSN;      // 주민등록번호 (Social Security Number)
    string ID;       // 회원 ID
    string password; // 회원 비밀번호

// 회원별 판매·구매 상품 내역
private:
    Product* saleList[MAX_PERSONAL_PRODUCTS];     // 판매중·판매완료 상품 리스트
    int saleProducts;                             // 개인별 판매한 상품 종류 개수

    Product* purchaseList[MAX_PERSONAL_PRODUCTS]; // 구매 상품 리스트
    int purchasedProducts;                        // 개인별 구매한 상품 종류 개수
};

/*
 *  Class Name   : Product
 *  Class Type   : Entity
 *  Relationship : Admin  HAS-A Product
 *                 Member HAS-A Product
 *  Description  : Product 클래스의 멤버 변수 및 함수들 선언
 *  Author       : 이병헌
 */

/*
*   Revisions :
*       1. Who : 노지석
*          What : added Comments
*/

class Product
{
public:
    int getProductID();         // 상품 ID 불러오기
    string getProductName();    // 상품 이름 불러오기
    string getBrand();          // 제작회사명 불러오기
    int getPrice();             // 가격 불러오기
    int getOnSaleQty();         // 판매중인 상품의 남은 수량 불러오기 
    int getSoldOutQty();        // 판매완료된 상품의 판매된 수량 불러오기
    string getSellerID();       // 판매자 ID 불러오기
    int getAvgRating();         // 평균 구매만족도 불러오기

    void setPurchase();         // '판매중' 상태 설정
    void setSoldOut();          // '판매완료' 상태 설정
    void setRating(int rating); // 구매 만족도 평가(점수)

    bool isOnSale();            // '판매중' 상태 확인
    bool isSoldOut();           // '판매완료' 상태 확인

public:
    Product(string productName, string brand, int price, int qty, string sellerID); // 상품 상세 정보
    ~Product();

private:
    static int productSN;                   // 상품 시리얼 번호

private:
    int productID;                          // 상품 ID
    string productName;                     // 상품 이름
    string brand;                           // 제작회사명
    int price;                              // 가격
    int onSaleQty;                          // 판매중인 상품의 남은 수량
    int soldOutQty;                         // 판매 완료된 상품의 판매된 수량
    string sellerID;                        // 판매자 ID
    int ratings[MAX_PERSONAL_PRODUCTS];     // 평점
    int avgRating;                          // 평균 구매 만족도
    bool onSale;                            // '판매중', '판매완료' 상태 판별 변수
};