#include "hong_ping.h"

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
bool Member::sale(string productName, string brand, int price, int qty)
{
    for(int i=0;i<qty;i++)
    {
        Product* product = new Product(productName, brand, price, Admin::getLoginID());
        product->setOnSale();
        this->onSaleList[onSaleProducts++] = product;
    }
    return true;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Member::getName()
{
    return this->name;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Member::getSSN()
{
    return this->SSN;
}

/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Member::getID()
{
    return this->ID;
}



/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
string Member::getPassword()
{
    return this->password;
}



/*
 *  Function Name :
 *  Parameters    :
 *  Return Type   :
 *  Description   : 
 */
Member::Member(string name, string SSN, string ID, string password)
: name(name), SSN(SSN), ID(ID), password(password), onSaleProducts(0), soldOutProducts(0), purchasedProducts(0)
{

}