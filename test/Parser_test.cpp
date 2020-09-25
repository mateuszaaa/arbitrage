#include <gtest/gtest.h>
#include "Parser.h"

TEST(Parser_test, first_test){
    std::vector<PriceInfo> input;
    Parser string;
    input = string.load(
        R"(
            [{"symbol":"AAABBB","bidPrice":"1","bidQty":"2","askPrice":"3","askQty":"4"}]
            )");
    
    std::vector<PriceInfo> output;
    PriceInfo valut1;
    valut1.symbol = "AAABBB";
    valut1.bid_price = 1;
    valut1.bid_quantity = 2;
    valut1.ask_price = 3;
    valut1.ask_quantity = 4;
    output.push_back(valut1);
    
    EXPECT_EQ(input, output);
}

TEST(Parser_test, seccond_test){
    std::vector<PriceInfo> input;
    Parser string;
    input = string.load(
        R"([{"symbol":"ETHBTC","bidPrice":"0.03174400","bidQty":"0.25500000","askPrice":"0.03174900","askQty":"24.00000000"},
            {"symbol":"LTCBTC","bidPrice":"0.00421900","bidQty":"41.02000000","askPrice":"0.00422000","askQty":"0.23000000"},
            {"symbol":"BNBBTC","bidPrice":"0.00230510","bidQty":"1.69000000","askPrice":"0.00230540","askQty":"0.62000000"}])");
    
    PriceInfo valut1;
    valut1.symbol = "ETHBTC";
    valut1.bid_price = 0.03174400;
    valut1.bid_quantity = 0.25500000;
    valut1.ask_price = 0.03174900;
    valut1.ask_quantity =24.00000000;
    PriceInfo valut2;
    valut2.symbol = "LTCBTC";
    valut2.bid_price = 0.00421900;
    valut2.bid_quantity = 41.02000000;
    valut2.ask_price = 0.00422000;
    valut2.ask_quantity =0.23000000;
    PriceInfo valut3;
    valut3.symbol = "BNBBTC";
    valut3.bid_price = 0.00230510;
    valut3.bid_quantity = 1.69000000;
    valut3.ask_price = 0.00230540;
    valut3.ask_quantity =0.62000000;

    EXPECT_EQ(input, std::vector<PriceInfo>({valut1, valut2, valut3}));
}

TEST(Parser_test, third_test){
    std::vector<PriceInfo> input;
    Parser string;
    input = string.load(
        R"([{""}])");
    
    std::vector<PriceInfo> output;
    
    EXPECT_EQ(input, std::vector<PriceInfo>({}));
}


