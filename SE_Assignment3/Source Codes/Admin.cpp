#include "class.h"

// Initializing Static Attribute
Admin* Admin::admin = nullptr;
string Admin::loginID = "";



/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
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
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
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
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
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
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
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
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
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

void Admin::addProduct(Product* newProduct)
{
    productList[products++] = newProduct;
}

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
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Admin* Admin::getAdminInstance()
{
    if(Admin::admin == nullptr)
        Admin::admin = new Admin();

    return Admin::admin;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Admin::getLoginID()
{
    return Admin::loginID;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Admin::Admin()
: members(0), products(0)
{

}

Admin::~Admin() { }
