#include "ConvertToPriceInfoBeta.h"
#include <algorithm>
#include <deque>
#include <iterator>
#include <unordered_set>

std::pair<PriceInfoBeta, PriceInfoBeta> ConvertToPriceInfoBeta::convert_to_PriceInfoBeta_v1(PriceInfo info, std::string crypto){
    auto temp = info.symbol;

    PriceInfoBeta beta1;
    beta1.from=crypto;
    beta1.to=temp.substr(crypto.size(), temp.size());
    beta1.bid_price=info.bid_price;
    beta1.bid_quantity=info.bid_quantity; 

    PriceInfoBeta beta2;
    beta2.from=temp.substr(crypto.size(), temp.size());
    beta2.to=crypto; 
    beta2.bid_price=info.ask_price;
    beta2.bid_quantity=info.ask_quantity;
    return {beta1, beta2};
}


std::pair<PriceInfoBeta, PriceInfoBeta> ConvertToPriceInfoBeta::convert_to_PriceInfoBeta_v2(PriceInfo info, std::string crypto, int pos){
    auto temp = info.symbol;
    
    PriceInfoBeta beta1;
    beta1.from=crypto;
    beta1.to=temp.substr(0, pos);
    beta1.bid_price=info.ask_price;
    beta1.bid_quantity=info.ask_quantity; 

    PriceInfoBeta beta2;
    beta2.from=temp.substr(0, pos);
    beta2.to=crypto; 
    beta2.bid_price=info.bid_price;
    beta2.bid_quantity=info.bid_quantity; 
    return {beta1, beta2};
}

void ConvertToPriceInfoBeta::search_crypto_valut(std::vector<PriceInfo>& price_infos, std::string& crypto, std::vector<std::string>& crypto_name, std::unordered_set<std::string>& crypto_set){
for(auto info: price_infos){
        auto pos = info.symbol.find(crypto);  
        if (pos != std::string::npos){
            if(crypto_set.find(info.symbol.substr(crypto.size(), info.symbol.size()))==crypto_set.end() && pos==0 ){
                auto new_crypto = info.symbol.substr(crypto.size(), info.symbol.size());
                crypto_set.insert(new_crypto);
                crypto_name.push_back(new_crypto);
            }
            if(crypto_set.find(info.symbol.substr(0, pos))==crypto_set.end() && pos!=0){
                auto new_crypto = info.symbol.substr(0, pos);
                crypto_set.insert(new_crypto);
                crypto_name.push_back(new_crypto);
            }
        }
    }
}

std::vector<PriceInfoBeta> ConvertToPriceInfoBeta::convert(std::vector<PriceInfo> price_infos){
    std::vector<PriceInfoBeta> output;
    std::vector<std::string> crypto_name = {"BTC"};
    std::unordered_set<std::string> crypto_set;
    auto crypto = crypto_name.back();
    crypto_set.insert(crypto);          
    
    search_crypto_valut(price_infos, crypto, crypto_name, crypto_set);

    for(auto info: price_infos){
            for(auto crypto : crypto_name){    
                auto pos= info.symbol.find(crypto);
                auto find_v1= crypto_set.find(info.symbol.substr(crypto.size(), info.symbol.size()));
                auto find_v2= crypto_set.find(info.symbol.substr(0, pos));
                if (pos != std::string::npos && pos==0 && find_v1 !=crypto_set.end()){
                    auto result = convert_to_PriceInfoBeta_v1(info, crypto);
                    auto beta1=result.first;
                    auto beta2=result.second;
                    output.push_back(beta1);
                    output.push_back(beta2);
                }
                if (pos != std::string::npos && pos==0 && find_v2!=crypto_set.end()){
                    auto result = convert_to_PriceInfoBeta_v2(info, crypto, pos);
                    auto beta1=result.first;
                    auto beta2=result.second;
                    output.push_back(beta1);
                    output.push_back(beta2);
                }
            }
        }    
    return output;
}
