#include <iostream>
#include <sstream>
#include "http_get.h"
#include "PriceInfo.h"
#include "Parser.h"
#include "ConvertToPriceInfoBeta.h"
#include <map>



int main(int argc, char** argv){
    std::cout << "starting crypto bot" << std::endl;
    std::cout << "connecting to market" << std::endl;
    std::string binance_string = get("api.binance.com", 443, "/api/v3/ticker/bookTicker");
    Parser binance_data;
    std::vector<PriceInfo> result = binance_data.load(binance_string);

    ConvertToPriceInfoBeta converter;
    auto connections = converter.convert(result);

    std::cout << "found " << connections.size() << std::endl;

    std::cout << "stopping crypto bot" << std::endl;
    return 0;
}
