#include "class.h"

// Initializing Static Attribute
Admin* Admin::admin = nullptr;
string Admin::loginID = "";

/*
 *  Function Name : addMember
 *  Parameters    : 1) name             (String) ; 이름
                    2) SSN              (String) ; 주민번호
                    3) ID               (string) ; ID
                    4) password         (string) ; 비밀번호
 *  Return Type   : bool
 *  Description   : 회원가입 요청 시 입력받은 정보를 회원리스트에 추가
 */
bool Admin::addMember(string name, string SSN, string ID, string password)
{
    // 최대 회원수 검사
    if (members >= MAX_ALL_MEMBERS)
        return false;

    // 중복 ID 검사
    for (int i = 0; i < members; i++)
    {
        if (memberList[i]->getID() == ID) // ID 중복 발생
            return false;                 // 회원가입 실패
    }

    // 회원가입 성공
    memberList[members++] = new Member(name, SSN, ID, password);

    return true;
}

/*
 *  Function Name : deleteMember
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 회원 탈퇴 요청 시 회원리스트에서 정보 삭제
 */
string Admin::deleteMember()
{
    string currLoginID = Admin::loginID;
    
    // 현재 로그인한 사용자가 없음
    if (Admin::loginID.empty())
        return currLoginID;

    // 로그인 중인 사용자를 탈퇴
    for (int i = 0; i < members; i++)
    {
        if (memberList[i]->getID() == loginID)
        {
            // 사용자 정보 삭제
            delete memberList[i];

            // 회원 배열 Compaction
            for (int j = i + 1; j < members; j++)
            {
                memberList[j - 1] = memberList[j];
                memberList[j] = nullptr;
            }

            members--; // 전체 회원수 차감
            Admin::loginID.clear(); // 로그아웃 처리

            return currLoginID;
        }
    }

    return "";
}

/*
 *  Function Name : login
 *  Parameters    : 1) ID               (string) ; ID
                    2) password         (string) ; 비밀번호
 *  Return Type   : bool
 *  Description   : ID, 패스워드 검사 후 일치하면 로그인 처리
 */
bool Admin::login(string ID, string password)
{
    for (int i = 0; i < members; i++)
    {
        // 일치하는 ID, 패스워드 검사
        if (memberList[i]->getID() == ID && memberList[i]->getPassword() == password)
        {
            // 로그인 처리
            Admin::loginID = ID;
            return true;
        }
    }

    // 로그인 실패
    return false;
}

/*
 *  Function Name : logout
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 로그인한 사용자가 로그아웃 요청시 로그아웃 처리
 */
string Admin::logout()
{
    string currLoginID = Admin::loginID;

    // 로그인한 사용자가 없음
    if(currLoginID.empty())
        return currLoginID;

    // 로그아웃 처리
    Admin::loginID.clear();

    return currLoginID;
}

/*
 *  Function Name : findMember
 *  Parameters    : Member*
 *  Return Type   : 1) ID               (string) ; ID
 *  Description   : 회원리스트에서 전달받은 ID를 가진 객체가 있는지 검사
 */
Member* Admin::findMember(string ID)
{
    // 일치하는 ID 검사
    for (int i = 0; i < members; i++)
    {
        // ID에 해당되는 회원 Object 반환
        if (admin->memberList[i]->getID() == ID)
            return memberList[i];
    }

    // 일치하는 회원 없음
    return nullptr;
}

/*
 *  Function Name : addProduct
 *  Parameters    : 1) newProduct       (Product*) ; 상품
 *  Return Type   : -
 *  Description   : 상품 추가 요청시 상품리스트에 해당 상품 추가
 */
void Admin::addProduct(Product* newProduct)
{
    productList[products++] = newProduct;
}

/*
 *  Function Name : searchProduct
 *  Parameters    : 1) productName       (string) ; 상품 이름
 *  Return Type   : Product*
 *  Description   : 전달받은 상품이름으로 상품리스트에서 상품 검색
 */
Product* Admin::searchProduct(string productName)
{
    for (int i = 0; i < products; i++)
    {
        // 검색어와 일치하는 상품 검사
        if (productList[i]->getProductName() == productName)
        {
            // // 현재 판매중인 상품인지를 검사
            // if (productList[i]->getOnSaleQty() > 0)
                return productList[i]; // 검색 성공
        }
    }

    // 검색 실패
    return nullptr;
}

/*
 *  Function Name : getAdminInstance
 *  Parameters    : -
 *  Return Type   : Admin*
 *  Description   : admin object를 받아옴
 */
Admin* Admin::getAdminInstance()
{
    if(Admin::admin == nullptr)
        Admin::admin = new Admin();

    return Admin::admin;
}

/*
 *  Function Name : getLoginID
 *  Parameters    : -
 *  Return Type   : string
 *  Description   : 로그인 중인 ID를 받아옴
 */
string Admin::getLoginID()
{
    return Admin::loginID;
}

Admin::Admin()
: members(0), products(0)
{

}

Admin::~Admin() { }
