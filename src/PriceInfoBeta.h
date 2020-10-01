#pragma once
#include <string>
struct PriceInfoBeta{
    std::string from;
    std::string to;
    float bid_price;
    float bid_quantity; 

};

inline bool operator==(const PriceInfoBeta& lhs, const PriceInfoBeta& rhs){
    return 
    lhs.from == rhs.from &&
    lhs.to == rhs.to && 
    lhs.bid_price == rhs.bid_price &&
    lhs.bid_quantity == rhs.bid_quantity;
}