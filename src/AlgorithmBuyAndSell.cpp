#include "AlgorithmBuyAndSell.h"
#include <iostream>
#include <map>

std::vector<std::string> AlgorithmBuyAndSell::algorythm_for_search_four_elem_chain(DataBase& data){
    std::vector<std::string> output;
    auto vec_BTC_to = data.get_connections("BTC");
    double profit = 1;
    double threshold = 1.001;
    std::string to;
    std::string from;
    do{
        auto lotto = std::rand()%vec_BTC_to.size();
        from = vec_BTC_to[lotto];

        auto vec_fromto = data.get_connections(from);

        std::map<double, std::string, std::greater<double>> map_for_profit;
        for(auto to : vec_fromto){
            if(to != "BTC"){
                profit = data.profit_for_BTC_from_to_BTC_expressed_decimal_number(from, to);
                map_for_profit.insert({profit, to});
            }
        }
        if(map_for_profit.begin()!=map_for_profit.end()){
            to = map_for_profit.begin()->second;
            profit = map_for_profit.begin()->first;
        }
    } while(profit<threshold);
    output.push_back("BTC");
    output.push_back(from);
    output.push_back(to);
    output.push_back("BTC");

    
    for (auto str : output){
        std::cout<< str <<" ";
    } 
    std::cout<< std::endl << "profit = "<< profit << std::endl;
    
    return output;
}

