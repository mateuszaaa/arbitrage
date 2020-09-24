#pragma once

#include <string>

struct Price_info{
    std::string symbol;
    float bid_price;
    float bid_quantity;
    float ask_price;
    float ask_quantity; 
};

inline bool operator==(const Price_info& lhs, const Price_info& rhs){
    return 
    lhs.symbol == rhs.symbol && 
    lhs.bid_price == rhs.bid_price &&
    lhs.bid_quantity == rhs.bid_quantity &&
    lhs.ask_price == rhs.ask_price &&
    lhs.ask_quantity == lhs.ask_quantity;
}