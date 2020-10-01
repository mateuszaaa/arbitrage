#include <gtest/gtest.h>
#include "ExpandToPriceInfoBeta.h"

TEST(ExpandToPriceInfoBeta_test, first_test){
    PriceInfo price;
    price.symbol = "BTCBBB";
    price.bid_price =1;
    price.bid_quantity =10;
    price.ask_price =2;
    price.ask_quantity=20;
    

    PriceInfoBeta pricebeta1;
    pricebeta1.from="BTC";
    pricebeta1.to="BBB";
    pricebeta1.bid_price =1;
    pricebeta1.bid_quantity=10;
    
    PriceInfoBeta pricebeta2;
    pricebeta2.from="BBB";
    pricebeta2.to="BTC";
    pricebeta2.bid_price =2;
    pricebeta2.bid_quantity=20;
    ExpandToPriceInfoBeta input;
    
    EXPECT_EQ(input.expand(std::vector<PriceInfo>({price})), std::vector<PriceInfoBeta>({pricebeta1, pricebeta2}));
}


TEST(ExpandToPriceInfoBeta_test, second_test){
    PriceInfo price;
    price.symbol = "BBBBTC";
    price.bid_price =1;
    price.bid_quantity =10;
    price.ask_price =2;
    price.ask_quantity=20;

    PriceInfoBeta pricebeta1;
    pricebeta1.from="BTC";
    pricebeta1.to="BBB";
    pricebeta1.bid_price =2;
    pricebeta1.bid_quantity=20;
    
    PriceInfoBeta pricebeta2;
    pricebeta2.from="BBB";
    pricebeta2.to="BTC";
    pricebeta2.bid_price =1;
    pricebeta2.bid_quantity=10;
    ExpandToPriceInfoBeta input;
    
    EXPECT_EQ(input.expand(std::vector<PriceInfo>({price})), std::vector<PriceInfoBeta>({pricebeta1, pricebeta2}));
}