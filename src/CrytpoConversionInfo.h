#pragma once
#include <string>
struct CrytpoConversionInfo{
    std::string from;
    std::string to;
    float bid_price;
    float bid_quantity; 
};

inline bool operator==(const CrytpoConversionInfo& lhs, const CrytpoConversionInfo& rhs){
    return 
    lhs.from == rhs.from &&
    lhs.to == rhs.to && 
    lhs.bid_price == rhs.bid_price &&
    lhs.bid_quantity == rhs.bid_quantity;
}