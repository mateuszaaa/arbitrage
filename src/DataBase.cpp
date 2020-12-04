#include "DataBase.h"
#include "CrytpoConversionInfo.h"
#include <map>
#include <iostream>

void DataBase::read(std::vector<CrytpoConversionInfo> input_vec){
    for (auto i : input_vec){
        map_from_to_crytpoconversioninfo.insert({i.from + i.to, i});
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

double DataBase::profit_for_chain_expressed_decimal_number(std::vector<std::string> input_vec){
    double profit = 1;
    for (std::size_t i=1; i<input_vec.size()-1; i++){
        auto from_to = input_vec[i] + input_vec[i+1];
        if(map_from_to_crytpoconversioninfo.find(from_to) == map_from_to_crytpoconversioninfo.end()){
            throw std::invalid_argument("wrong argument");
        }
        else{
            auto ptr_from_to = map_from_to_crytpoconversioninfo.find(from_to);
            profit = profit * ptr_from_to->second.bid_price;
        }
    }
    return profit;
}


double DataBase::profit_for_BTC_from_to_BTC_expressed_decimal_number(std::string from, std::string to){
    std::string btc = "BTC";

    auto ptr_from_BTC= map_from_to_crytpoconversioninfo.find(btc+from);
    auto ptr_from_to = map_from_to_crytpoconversioninfo.find(from+to);
    auto ptr_to_BTC = map_from_to_crytpoconversioninfo.find(to+btc);
    auto profit =  ptr_from_BTC->second.bid_price * ptr_from_to->second.bid_price * ptr_to_BTC->second.bid_price;
    return profit;
}

double DataBase::quantity_for_chain(std::vector<std::string>input){
    if(input.size()<=1){
        return 0;
    }
    std::vector<CrytpoConversionInfo>vec_from_to;
    for(std::size_t i=0; i<input.size()-1; i++){
        auto ptr_from_to = map_from_to_crytpoconversioninfo.find(input[i]+input[i+1]);
        vec_from_to.push_back(ptr_from_to->second);
    }
    std::vector<double> vec_for_quantity{0};
    while (vec_from_to.size()>1){
        double quantity=vec_from_to.back().bid_quantity;
        for(int i = vec_from_to.size()-1; i>0; i--){
            quantity=quantity*(1/vec_from_to[i].bid_price);
        }
        if(vec_for_quantity.back()==0 or vec_for_quantity.back()>quantity){
            vec_for_quantity.push_back(quantity);
        }
        vec_from_to.pop_back();
    }
    return vec_for_quantity.back();
}

