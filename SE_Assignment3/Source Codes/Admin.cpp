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
    // �ִ� ȸ���� �˻�
    if (members >= MAX_ALL_MEMBERS)
        return false;

    // �ߺ� ID �˻�
    for (int i = 0; i < members; i++)
    {
        if (memberList[i]->getID() == ID) // ID �ߺ� �߻�
            return false;                 // ȸ������ ����
    }

    // ȸ������ ����
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
    
    // ���� �α����� ����ڰ� ����
    if (Admin::loginID.empty())
        return currLoginID;

    // �α��� ���� ����ڸ� Ż��
    for (int i = 0; i < members; i++)
    {
        if (memberList[i]->getID() == loginID)
        {
            // ����� ���� ����
            delete memberList[i];

            // ȸ�� �迭 Compaction
            for (int j = i + 1; j < members; j++)
            {
                memberList[j - 1] = memberList[j];
                memberList[j] = nullptr;
            }

            members--; // ��ü ȸ���� ����
            Admin::loginID.clear(); // �α׾ƿ� ó��

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
        // ��ġ�ϴ� ID, �н����� �˻�
        if (memberList[i]->getID() == ID && memberList[i]->getPassword() == password)
        {
            // �α��� ó��
            Admin::loginID = ID;
            return true;
        }
    }

    // �α��� ����
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

    // �α����� ����ڰ� ����
    if(currLoginID.empty())
        return currLoginID;

    // �α׾ƿ� ó��
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
    // ��ġ�ϴ� ID �˻�
    for (int i = 0; i < members; i++)
    {
        // ID�� �ش�Ǵ� ȸ�� Object ��ȯ
        if (admin->memberList[i]->getID() == ID)
            return memberList[i];
    }

    // ��ġ�ϴ� ȸ�� ����
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
        // �˻���� ��ġ�ϴ� ��ǰ �˻�
        if (productList[i]->getProductName() == productName)
        {
            // // ���� �Ǹ����� ��ǰ������ �˻�
            // if (productList[i]->getOnSaleQty() > 0)
                return productList[i]; // �˻� ����
        }
    }

    // �˻� ����
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
