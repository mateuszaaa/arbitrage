#include "ConvertToPriceInfoBeta.h"
#include <algorithm>
#include <deque>
#include <iterator>
#include <unordered_set>
using namespace std::string_literals;

std::pair<PriceInfoBeta, PriceInfoBeta> ConvertToPriceInfoBeta::convert_to_PriceInfoBeta(PriceInfo info, std::string crypto){
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

std::vector<std::string> ConvertToPriceInfoBeta::search_crypto_valut(std::vector<PriceInfo>& price_infos){
    std::vector<std::string> crypto_name = {"BTC"};
    for(auto info: price_infos){
            auto pos = info.symbol.find("BTC");  
            if (pos == std::string::npos){
                continue;
            }

            if( pos==0 ){
                auto new_crypto = info.symbol.substr("BTC"s.size(), info.symbol.size());
                crypto_name.push_back(new_crypto);
            }

            if( pos!=0 ){
                auto new_crypto = info.symbol.substr(0, pos);
                crypto_name.push_back(new_crypto);
            }
    }
    return crypto_name;
}

std::vector<PriceInfoBeta> ConvertToPriceInfoBeta::convert(std::vector<PriceInfo> price_infos){
    std::vector<PriceInfoBeta> output;

    auto crypto_name = search_crypto_valut(price_infos);

    std::unordered_set<std::string> crypto_set;
    for(auto str: crypto_name){
        crypto_set.insert(str);  
    }

    for(auto info: price_infos){
            for(auto crypto : crypto_name){    
                auto pos= info.symbol.find(crypto);
                auto find_rest= crypto_set.find(info.symbol.substr(crypto.size(), info.symbol.size()));
                if (pos==0 && find_rest !=crypto_set.end()){
                    auto result = convert_to_PriceInfoBeta(info, crypto);
                    auto beta1=result.first;
                    auto beta2=result.second;
                    output.push_back(beta1);
                    output.push_back(beta2);
                }
            }
        }    
    return output;
}
