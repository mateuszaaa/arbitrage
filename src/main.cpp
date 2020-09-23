#include <iostream>
#include "http_get.h"

int main(int argc, char** argv)
{
    std::cout << "starting crypto bot" << std::endl;

    std::cout << "connecting to market" << std::endl;

    std::string data = get("api.binance.com", 443, "/api/v3/ticker/bookTicker");
    
    std::cout << data << std::endl;

    std::cout << "stopping crypto bot" << std::endl;
}
