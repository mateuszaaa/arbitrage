#include <iostream>
#include <sstream>
#include "http_get.h"
#include "PriceInfo.h"
#include "Parser.h"
#include "ConvertToCryptoConversionInfo.h"
#include <map>
#include "DataBase.h"
#include "AlgorithmBuyAndSell.h"



int main(int argc, char** argv){

    std::cout << "starting crypto bot" << std::endl;
    std::cout << "connecting to market" << std::endl;
    std::string binance_string = get("api.binance.com", 443, "/api/v3/ticker/bookTicker");

    Parser binance_data;
    std::vector<PriceInfo> result = binance_data.load(binance_string);

    ConvertToCryptoConversionInfo converter;
    auto connections = converter.convert(result);
    std::cout << "found " << connections.size() << " PriceInfos" << std::endl;

    DataBase database;
    database.read(connections);
    
    AlgorithmBuyAndSell algorithm;
    algorithm.algorythm_for_search_four_elem_chain(database);

    return 0;
}
