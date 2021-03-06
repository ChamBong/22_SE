#include "class.h"

// Input and Output File Name Configuring
const string INPUT_FILE_NAME  = "input.txt";
const string OUTPUT_FILE_NAME = "output.txt";



void run(ifstream &inputFile, ofstream &outputFile)
{
    int menu_level_1, menu_level_2;
    bool is_program_exit = false;

    while (!inputFile.eof() && !is_program_exit)
    {
        inputFile >> menu_level_1 >> menu_level_2;

        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1: // 1.1. 회원 가입 (SignUp)
            {
                // Call Control Instance
                SignUp* signUp = SignUp::getControlInstance();

                // Call Boundary Instance (Input Processing)
                string signUpInfo = signUp->getUI()->getInput(inputFile);

                // Input String Tokenizing
                stringstream ss(signUpInfo);
                string name, SSN, ID, password;
                ss >> name >> SSN >> ID >> password;

                // Call Boundary Instance (Output Processing)
                signUp->getUI()->setOutput(outputFile, "1.1. 회원가입\n");

                // Try Sign Up
                if(Admin::getAdminInstance()->addMember(name,SSN,ID,password)) // Sign Up Success
                    signUp->getUI()->setOutput(outputFile, "> " + signUpInfo + "\n\n");
                else // Sign Up Failure
                    signUp->getUI()->setOutput(outputFile, ">\n\n");

                break;
            }

            case 2: // 1.2. 회원탈퇴 (DropOut)
            {
                // Call Control Instance
                DropOut* dropOut = DropOut::getControlInstance();

                // Call Boundary Instance (Output Processing)
                dropOut->getUI()->setOutput(outputFile, "1.2. 회원탈퇴\n");

                // Try Drop Out
                string droppedID = Admin::getAdminInstance()->deleteMember();

                if(!droppedID.empty()) // Drop Out Success
                    dropOut->getUI()->setOutput(outputFile, "> " + droppedID + "\n\n");
                else // Drop Out Failure
                    dropOut->getUI()->setOutput(outputFile, ">\n\n");

                break;
            }
            }
            break;
        }

        case 2:
        {
            switch (menu_level_2)
            {
            case 1: // 2.1. 로그인 (Login)
            {
                // Call Control Instance
                Login* login = Login::getControlInstance();

                // Call Boundary Instance (Input Processing)
                string loginInfo = login->getUI()->getInput(inputFile);

                // Input String Tokenizing
                stringstream ss(loginInfo);
                string ID, password;
                ss >> ID >> password;

                // Call Boundary Instance (Output Processing)
                login->getUI()->setOutput(outputFile, "2.1. 로그인\n");

                // Try Login
                if(Admin::getAdminInstance()->login(ID,password)) // Login Success
                    login->getUI()->setOutput(outputFile, "> " + ID + " " + password + "\n\n");
                else // Login Failure
                    login->getUI()->setOutput(outputFile, ">\n\n");

                break;
            }

            case 2: // 2.2. 로그아웃 (Logout)
            {
                // Call Control Instance
                Logout *logout = Logout::getControlInstance();

                // Call Boundary Instance (Output Processing)
                logout->getUI()->setOutput(outputFile, "2.2. 로그아웃\n");

                // Try Logout
                string logoutID = Admin::getAdminInstance()->logout();
                if (!logoutID.empty()) // Logout Success
                    logout->getUI()->setOutput(outputFile, "> " + logoutID + "\n\n");
                else // Logout Failure
                    logout->getUI()->setOutput(outputFile, ">\n\n");

                break;
            }
            }

            break;
        }

        case 3:
        {
            switch (menu_level_2)
            {
            case 1: // 3.1. 판매 의류 등록 (Enroll)
            {
                // Call Control Instance
                Enroll *enroll = Enroll::getControlInstance();

                // Call Boundary Instance (Input Processing)
                string enrollInfo = enroll->getUI()->getInput(inputFile);

                // Input String Tokenizing
                stringstream ss(enrollInfo);
                string productName, brand, price, qty;
                ss >> productName >> brand >> price >> qty;

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                // Call Boundary Instance (Output Processing)
                enroll->getUI()->setOutput(outputFile, "3.1. 판매 의류 등록\n");

                // Try Enroll
                if (member->sale(productName, brand, stoi(price), stoi(qty))) // Enroll Success
                    enroll->getUI()->setOutput(outputFile, "> " + enrollInfo + "\n\n");
                else // enroll Failure
                    enroll->getUI()->setOutput(outputFile, ">\n\n");
                
                break;
            }
            case 2: // 3.2. 등록 상품 조회 (ListOnSale)
            {
                // Call Control Instance
                ListOnSale *listOnSale = ListOnSale::getControlInstance();

                // Call Boundary Instance (Output Processing)
                listOnSale->getUI()->setOutput(outputFile, "3.2. 등록 상품 조회\n");

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                listOnSale->getUI()->setOutput(outputFile, member->listOnSale() + "\n");

                break;
            }
            case 3: // 3.3. 판매 완료 상품 조회 (ListSoldOut)
            {
                // Call Control Instance
                ListSoldOut *listSoldOut = ListSoldOut::getControlInstance();

                // Call Boundary Instance (Output Processing)
                listSoldOut->getUI()->setOutput(outputFile, "3.3. 판매 완료 상품 조회\n");

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                listSoldOut->getUI()->setOutput(outputFile, member->listSoldOut() + "\n");

                break;
            }
            }

            break;
        }

        case 4:
        {
            switch (menu_level_2)
            {
            case 1: // 4.1. 상품 정보 검색 (SearchOnSale)
            {
                // Call Control Instance
                SearchOnSale *searchOnSale = SearchOnSale::getControlInstance();

                // Call Boundary Instance (Input Processing)
                string searchInfo = searchOnSale->getUI()->getInput(inputFile);

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                // Call Boundary Instance (Output Processing)
                searchOnSale->getUI()->setOutput(outputFile, "4.1. 상품 정보 검색\n");

                // Try Search
                Product* searchTarget = member->searchOnSale(searchInfo);
                string sellerID, productName, brand, price, onSaleQty, rating;
                if (searchTarget) // Search Success
                {
                    sellerID = searchTarget->getSellerID();
                    productName = searchTarget->getProductName();
                    brand = searchTarget->getBrand();
                    price = std::to_string(searchTarget->getPrice());
                    onSaleQty = std::to_string(searchTarget->getOnSaleQty());
                    rating = std::to_string(searchTarget->getAvgRating());

                    searchOnSale->getUI()->setOutput(outputFile, "> " + sellerID + " " + productName + " " + brand + " " + price + " " + onSaleQty + " " + rating + "\n\n");
                    SearchOnSale::setFocusOn(searchTarget);
                }
                else // Search Failure
                {
                    searchOnSale->getUI()->setOutput(outputFile, ">\n\n");
                    SearchOnSale::setFocusOn(nullptr);
                }
                
                break;
            }
            case 2: // 4.2. 상품 구매 (Purchase)
            {
                // Call Control Instance
                Purchase *purchase = Purchase::getControlInstance();

                purchase->getUI()->setOutput(outputFile, "4.2. 상품 구매\n");

                // 상품 정보 검색이 선행되지 않은 경우
                if(SearchOnSale::getFocusOn() == nullptr)
                {
                    purchase->getUI()->setOutput(outputFile, ">\n\n");
                    break;
                }

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                // Try Purchase
                if(member->purchase()) // Purchase Success
                    purchase->getUI()->setOutput(outputFile, "> " + Admin::getLoginID() + " " + SearchOnSale::getFocusOn()->getProductName() + "\n\n");
                else // Purchase Failure
                    purchase->getUI()->setOutput(outputFile, ">\n\n");

                // 상품 정보 검색 창 닫기
                SearchOnSale::setFocusOn(nullptr);

                break;
            }
            case 3: // 4.3. 상품 구매 내역 조회 (ListPurchaseHistory)
            {
                // Call Control Instance
                ListPurchaseHistory *listPurchaseHistory = ListPurchaseHistory::getControlInstance();

                // Call Boundary Instance (Output Processing)
                listPurchaseHistory->getUI()->setOutput(outputFile, "4.3. 상품 구매 내역 조회\n");

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                listPurchaseHistory->getUI()->setOutput(outputFile, member->listPurchaseHistory() + "\n");

                break;
            }
            case 4: // 4.4. 상품 구매만족도 평가 (Rate)
            {
                // Call Control Instance
                Rate *rate = Rate::getControlInstance();

                // Call Boundary Instance (Input Processing)
                string rateInfo = rate->getUI()->getInput(inputFile);

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                // Input String Tokenizing
                stringstream ss(rateInfo);
                string productName, rating;
                ss >> productName >> rating;

                // Call Boundary Instance (Output Processing)
                rate->getUI()->setOutput(outputFile, "4.4. 상품 구매만족도 평가\n");

                // Try Rate
                if (member->rate(productName, stoi(rating))) // Rate Success
                {
                    string sellerID = admin->searchProduct(productName)->getSellerID();
                    rate->getUI()->setOutput(outputFile, "> " + sellerID + " " + productName + " " + rating + "\n\n");
                }
                else // Rate Failure
                {
                    rate->getUI()->setOutput(outputFile, ">\n\n");
                }

                break;
            }
            }
                        
            break;
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1: // 5.1. 판매 상품 통계 (CollectStatistics)
            {
                // Call Control Instance
                CollectStatistics *collectStatistics = CollectStatistics::getControlInstance();

                Admin* admin = Admin::getAdminInstance();
                Member* member = admin->findMember(Admin::getLoginID());

                // Call Boundary Instance (Output Processing)
                collectStatistics->getUI()->setOutput(outputFile, "5.1. 판매 상품 통계\n");

                // Try Collect Statistics
                string statisticsInfo = member->collectStatistics();
                
                if (!statisticsInfo.empty()) // Collect Statistics Success
                    collectStatistics->getUI()->setOutput(outputFile, "> " + statisticsInfo + "\n");
                else // Collect Statistics Failure
                    collectStatistics->getUI()->setOutput(outputFile, ">\n\n");
        
                break;
            }
            }

            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1: // 6.1. 종료 (Exit)
            {
                // Call Control Instance
                Exit *exit = Exit::getControlInstance();

                // Call Boundary Instance (Output Processing)
                exit->getUI()->setOutput(outputFile, "6.1. 종료");

                is_program_exit = true;
                return;
            }
            }

            break;
        }
        }
    }
}



int main()
{
    ifstream inputFile;
    inputFile.open(INPUT_FILE_NAME, fstream::in);

    ofstream outputFile;
    outputFile.open(OUTPUT_FILE_NAME, fstream::out);

    run(inputFile, outputFile);

    inputFile.close();
    outputFile.close();

    return EXIT_SUCCESS;
}