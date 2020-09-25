#include <iostream>
#include <sstream>
#include "http_get.h"
#include "PriceInfo.h"
#include "Parser.h"


int main(int argc, char** argv)
{
    std::cout << "starting crypto bot" << std::endl;
    std::cout << "connecting to market" << std::endl;


    std::string binance_string = get("api.binance.com", 443, "/api/v3/ticker/bookTicker");



    Parser binance_data;
    std::cout << binance_string << std::endl;
    std::vector<PriceInfo> result = binance_data.load(binance_string);
    for(std::size_t i=0; i < result.size(); i++){
    std::cout << result[i].symbol << std::endl;
    }
    std::cout << "stopping crypto bot" << std::endl;
}
