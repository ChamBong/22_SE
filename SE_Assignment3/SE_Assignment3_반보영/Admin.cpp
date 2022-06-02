#include "hong_ping.h"

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
    if (members >= MAX_MEMBERS)
        return false;

    // 중복 ID 검사
    for (int i = 0; i < members; i++)
    {
        if (memberList[i]->getID() == ID)
            return false;
    }

    // 회원가입 성공
    for (int i = 0; i < MAX_MEMBERS; i++)
    {
        if (memberList[i] == nullptr)
        {
            memberList[i] = new Member(name, SSN, ID, password);
            this->members++;
            return true;
        }
    }
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Admin::deleteMember()
{
    string loginID = Admin::loginID;

    // 로그인한 사용자가 없음
    if(loginID.empty())
        return loginID;

    // 로그인 중인 사용자를 탈퇴
    for (int i = 0; i < members; i++)
    {
        if(memberList[i]->getID() == loginID){
            delete memberList[i];
            memberList[i] = nullptr;
            members--;
            Admin::loginID.clear();
            return loginID;
        }
    }
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
        if (memberList[i]->getID() == ID && memberList[i]->getPassword() == password)
        {
            Admin::loginID = ID;
            return true;
        }
    }

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
    string loginID = Admin::loginID;

    // 로그인한 사용자가 없음
    if(Admin::loginID.empty())
        return loginID;

    Admin::loginID.clear();

    return loginID;
}


/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Member* Admin::findMember(string ID)
{
    for (int i = 0; i < members; i++)
    {
        if (admin->memberList[i]->getID() == ID)
            return memberList[i];
    }

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
: members(0)
{

}