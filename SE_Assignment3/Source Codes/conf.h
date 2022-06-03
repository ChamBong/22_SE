#pragma once



/* * * * * * * * * * * * * * * *
 *         Configuration       *
 *                             *
 * * * * * * * * * * * * * * * */

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