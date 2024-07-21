#include "headers.h"

int main()
{
    int         choice;
    std::string input;


    while (true)
    {
        system("clear");
        std::cout << "Choose an action: \n1. Place Order\n2. Cancel Order\n3. Modify Order\n4. Get Orderbook\n5. View Positions\n6. Exit\n";
        std::cin >> input;

        if (isNumber(input))
            choice = std::stoi(input);
        else
        {
            std::cout << "Please choose a Number [1-6] :)\nPress ENTER to continue...";
            // Clear the input buffer
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            getchar();
            continue;
        }

        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        switch(choice)
        {
            case 1:
                placeOrder();
                break;
            case 2:
                cancelOrder();
                break;
            case 3:
                modifyOrder();
                break;
            case 4:
                getOrderBook();
                break;
            case 5:
                currentPosition();
                break;
            case 6:
                std::cout << "Have a good day :)\n";
                exit (0);
            default:
                std::cout << "Invalid choice !!\nPress ENTER to continue...";
                break;
        }
    }

    return (0);
}