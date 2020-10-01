#include "ExpandToPriceInfoBeta.h"
#include <algorithm>
#include <deque>
#include <unordered_set>



std::vector<PriceInfoBeta> ExpandToPriceInfoBeta::expand(std::vector<PriceInfo> price_infos){
    std::vector<PriceInfoBeta> output;
    std::deque<std::string> crypto_name = {"BTC"};
    PriceInfoBeta beta;
   
    for (std::size_t i=0; i < price_infos.size(); i++){
        std::unordered_set<std::string> crypto_set;
        crypto_set.insert(crypto_name.back());
        
        auto &info = price_infos[i];
        auto crypto = crypto_name.back();
        crypto_name.pop_back();

        auto pos = info.symbol.find(crypto);
        auto temp = info.symbol;
        if(pos != std::string::npos && pos==0){
            // void add_crypto_joins_vol1(std::string)
            beta.from=crypto;
            beta.to=temp.substr(crypto.size(), temp.size());
            beta.bid_price=info.bid_price;
            beta.bid_quantity=info.bid_quantity; 
            output.push_back(beta);

            beta.from=temp.substr(crypto.size(), temp.size());
            beta.to=crypto; 
            beta.bid_price=info.ask_price;
            beta.bid_quantity=info.ask_quantity; 
            output.push_back(beta);

            if(crypto_set.find(beta.to)!=crypto_set.end()){
                crypto_set.insert(beta.from);
                crypto_name.push_front(beta.from);
            }
        }
        if(pos != std::string::npos && pos!=0){
            
            beta.from=crypto;
            beta.to=temp.substr(0, pos);
            beta.bid_price=info.ask_price;
            beta.bid_quantity=info.ask_quantity; 
            output.push_back(beta);

            beta.from=temp.substr(0, pos);
            beta.to=crypto; 
            beta.bid_price=info.bid_price;
            beta.bid_quantity=info.bid_quantity; 
            output.push_back(beta);

            if(crypto_set.find(beta.from)!=crypto_set.end()){
                crypto_set.insert(beta.from);
                crypto_name.push_front(beta.from);
            }
        }
    }
    return output;
}
