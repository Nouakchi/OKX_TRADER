#include "headers.h"

void    placeOrder()
{
    std::string instId;
    std::string tdMode;
    std::string clOrdId;
    std::string side;
    std::string ordType;
    float       px;
    float       sz;

    while (!readString("Enter instId: ", instId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter tdMode: ", tdMode))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter clOrdId: ", clOrdId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter side: ", side))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter ordType: ", ordType))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readFloat("Enter px (float): ", px))
        std::cout << "Invalid input. Please enter a valid float number.\n";
    while (!readFloat("Enter sz (float): ", sz))
        std::cout << "Invalid input. Please enter a valid float number.\n";

    
    std::cout << "Please wait...\n";

    std::stringstream ss;

    ss << R"({"instId":")" << instId
       << R"(","tdMode":")" << tdMode
       << R"(","clOrdId":")" << clOrdId
       << R"(","side":")" << side
       << R"(","ordType":")" << ordType
       << R"(","sz":")" << sz
       << R"(","px":")" << px
       << R"("})";


    std::string url = "/api/v5/trade/order";
    std::string body = ss.str();
    std::string response = send_request("POST", url, body);
    std::cout << "Response (The result code, 0 means success): \n" << response << "\nPress ENTER to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void    cancelOrder()
{
    std::string ordId;
    std::string instId;

    while (!readString("Enter ordId: ", ordId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter instId: ", instId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    

    std::cout << "Please wait...\n";

    std::stringstream ss;

    ss  << R"(","ordId":")" << ordId
        << R"({"instId":")" << instId
        << R"("})";


    std::string url = "/api/v5/trade/order";
    std::string body = ss.str();
    std::string response = send_request("POST", url, body);
    std::cout << "Response (The result code, 0 means success): \n" << response << "\nPress ENTER to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void    modifyOrder()
{
    std::string ordId;
    std::string instId;
    float       newSz;

    while (!readString("Enter ordId: ", ordId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readFloat("Enter newSz: ", newSz))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter instId: ", instId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";

    
    std::cout << "Please wait...\n";

    std::stringstream ss;

    ss  << R"(","ordId":")" << ordId
        << R"({"newSz":")" << newSz
        << R"({"instId":")" << instId
        << R"("})";


    std::string url = "/api/v5/trade/amend-order";
    std::string body = ss.str();
    std::string response = send_request("POST", url, body);
    std::cout << "Response (The result code, 0 means success): \n" << response << "\nPress ENTER to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');    
}

void    getOrderBook()
{
    std::string ordId;
    std::string instId;

    while (!readString("Enter ordId: ", ordId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";
    while (!readString("Enter instId: ", instId))
        std::cout << "Invalid input. Please enter a non-empty string.\n";

    std::cout << "Please wait...\n";

    std::string url = "/api/v5/trade/order?ordId=" + ordId + "&instId=" + instId;
    std::string response = send_request("GET", url, "");
    std::cout << "Order Book: \n" << response << "\nPress ENTER to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void    currentPosition()
{

    std::cout << "Please wait...\n";
    std::string url = "/api/v5/positions";
    std::string response = send_request("GET", url, "");
    std::cout << "Current Position \n" << response << "\nPress ENTER to continue" << std::endl;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    getchar();
}