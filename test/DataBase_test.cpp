#include <gtest/gtest.h>
#include <openssl/crypto.h>
#include "DataBase.h"

TEST(DataBase_test, 1st_test){
    
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase Data;
    Data.read(vec);
    double resault = Data.calculate_profit_expressed_decimal_number(std::vector<std::string>({"AAA", "BBB", "CCC", "AAA"}));
    double expect_resault = 1*3*5;
    
    EXPECT_EQ(resault, expect_resault);
}

TEST(DataBase_test, 2nd_test){
    
    CrytpoConversionInfo pricebeta_ab = {"BTC", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "BTC", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "BTC", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase Data;
    Data.read(vec);
    double resault = Data.ratio_fromBTC_to_fromtoBTC("BBB", "CCC");
    double expect_resault = 3.0*5.0/2.0;
    
    EXPECT_EQ(resault, expect_resault);
}

TEST(DataBase_test, 3th_test){
    
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase Data;
    Data.read(vec);
    ASSERT_THROW(Data.calculate_profit_expressed_decimal_number(std::vector<std::string>({"AAA", "BBB", "ZZZ", "YYY"})), std::invalid_argument);
}