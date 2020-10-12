#include "DataBase.h"

void DataBase::read(std::vector<CrytpoConversionInfo> input_vec){
    for (auto i : input_vec){
        map_from_to.insert({i.from + i.to, i});
        if (map_for_connections.find(i.from) == map_for_connections.end()){
            std::vector<std::string> vec;
            for (auto j : input_vec){
                if(i.from==j.from){
                    vec.push_back(j.to);
                }
            }
            map_for_connections.insert({i.from, vec});
        }
    }
}

std::vector<std::string> DataBase::get_connections(const std::string& str){
    auto temp = map_for_connections.find(str);
    if (temp != map_for_connections.end()){
        return temp->second; 
    }
    else{
        return std::vector<std::string>({});
    }
}

double DataBase::calculate_profit_expressed_decimal_number(std::vector<std::string> input_vec){
    double profit = 1;
    for (int i=0; i<input_vec.size()-1; i++){
        auto from_to = input_vec[i] + input_vec[i+1];
        if(map_from_to.find(from_to) == map_from_to.end()){
            throw std::invalid_argument("wrong argument");
        }
        else{
            auto ptr_from_to = map_from_to.find(from_to);
            profit = profit * ptr_from_to->second.bid_price;
        }
    }
    return profit;
}

double DataBase::ratio_fromBTC_to_fromtoBTC(std::string from, std::string to){
    double profit = 1;
    std::string btc = "BTC";
    auto ptr_from_btc= map_from_to.find(from+btc);
    auto ptr_from_to = map_from_to.find(from+to);
    auto ptr_to_btc = map_from_to.find(to+btc);
    auto profit1 = profit * ptr_from_btc->second.bid_price;
    auto profit23 = profit * ptr_from_to->second.bid_price * ptr_to_btc->second.bid_price; 
    return profit23/profit1;
}