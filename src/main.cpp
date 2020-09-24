#include <iostream>
#include <sstream>
#include "http_get.h"
#include "Price_info.h"
#include "Parser.h"


int main(int argc, char** argv)
{
    std::cout << "starting crypto bot" << std::endl;
    std::cout << "connecting to market" << std::endl;


    std::string binance_string = get("api.binance.com", 443, "/api/v3/ticker/bookTicker");
    Parser binance_data;
    binance_data.load(binance_string);

    std::cout << binance_string;


    std::cout << "stopping crypto bot" << std::endl;
}
