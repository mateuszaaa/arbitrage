#include <gtest/gtest.h>
#include "ConvertToPriceInfoBeta.h"

TEST(ConvertToPriceInfoBeta_test, first_test){
    PriceInfo price = {"BTCBBB", 1, 10, 2, 20};
    PriceInfoBeta pricebeta1 = {"BTC", "BBB", 1, 10};
    PriceInfoBeta pricebeta2 = {"BBB", "BTC", 2, 20};

    ConvertToPriceInfoBeta input;
    std::vector<PriceInfo> input_data = {price};
    std::vector<PriceInfoBeta> expected_output = {pricebeta1, pricebeta2};
    EXPECT_EQ(input.convert(input_data), expected_output);
}


TEST(ConvertToPriceInfoBeta_test, second_test){
    PriceInfo price = {"BBBBTC", 1, 10, 2, 20};
    PriceInfoBeta pricebeta1 = {"BTC", "BBB", 2, 20};
    PriceInfoBeta pricebeta2 = {"BBB", "BTC", 1, 10};
    
    ConvertToPriceInfoBeta input;
    auto result_conver = input.convert(std::vector<PriceInfo>({price}));
    auto output = std::vector<PriceInfoBeta>({pricebeta2, pricebeta1});
    EXPECT_EQ(result_conver, output);
}

TEST(ConvertToPriceInfoBeta_test, third_test){
    PriceInfo price1 = {"AAABBB", 1, 10, 2, 20};
    PriceInfo price2 = {"BBBCCC", 1, 10, 2, 20};
    
    ConvertToPriceInfoBeta input;
    auto result_conver = input.convert(std::vector<PriceInfo>({price1, price2}));
    auto output = std::vector<PriceInfoBeta>();
    EXPECT_EQ(result_conver, output);
}

TEST(ConvertToPriceInfoBeta_test, 4th_test){
    PriceInfo price1 = {"BTCBBB", 1, 10, 2, 20};
    PriceInfo price2 = {"AAABTC", 3, 30, 4, 40};
    PriceInfo price3 = {"AAABBB", 5, 50, 6, 60};
    PriceInfo price4 = {"CCCDDD", 5, 50, 6, 60};
    PriceInfoBeta pricebeta1 = {"BTC", "BBB", 1, 10};
    PriceInfoBeta pricebeta2 = {"BBB", "BTC", 2, 20};
    PriceInfoBeta pricebeta3 = {"AAA", "BTC", 3, 30};
    PriceInfoBeta pricebeta4 = {"BTC", "AAA", 4, 40};
    PriceInfoBeta pricebeta5 = {"AAA", "BBB", 5, 50};
    PriceInfoBeta pricebeta6 = {"BBB", "AAA", 6, 60};

    ConvertToPriceInfoBeta input;
    auto result_conver = input.convert(std::vector<PriceInfo>({price4, price1, price2, price3}));
    auto output = std::vector<PriceInfoBeta>({pricebeta1, pricebeta2, pricebeta3, pricebeta4, pricebeta5, pricebeta6});   
    EXPECT_EQ(result_conver, output);
}

TEST(ConvertToPriceInfoBeta_test, 5th_test){

    PriceInfo price1 = {"AAABTC", 3, 30, 4, 40};
    PriceInfo price2 = {"BBBCCC", 5, 50, 6, 60};
    PriceInfo price3 = {"CCCDDD", 5, 50, 6, 60};

    PriceInfoBeta pricebeta1 = {"AAA", "BTC", 3, 30};
    PriceInfoBeta pricebeta2 = {"BTC", "AAA", 4, 40};

    ConvertToPriceInfoBeta input;
    auto result_conver = input.convert(std::vector<PriceInfo>({price1, price2, price3}));
    auto output = std::vector<PriceInfoBeta>({pricebeta1, pricebeta2});   
    EXPECT_EQ(result_conver, output);
}

TEST(ConvertToPriceInfoBeta_test, 6th_test){

    ConvertToPriceInfoBeta input;
    auto result_conver = input.convert(std::vector<PriceInfo>({}));
    auto output = std::vector<PriceInfoBeta>({});   
    EXPECT_EQ(result_conver, output);
}