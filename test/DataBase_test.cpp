#include <gtest/gtest.h>
#include "DataBase.h"

TEST(DataBase_test, 1st_test){
    
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    double resault = data.profit_for_chain_expressed_decimal_number(std::vector<std::string>({"AAA", "BBB", "CCC", "AAA"}));
    double expect_resault = 1*3*5;
    
    EXPECT_EQ(resault, expect_resault);
}

TEST(DataBase_test, 2nd_test){
    
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    ASSERT_THROW(data.profit_for_chain_expressed_decimal_number(std::vector<std::string>({"AAA", "BBB", "ZZZ", "YYY"})), std::invalid_argument);
}

TEST(DataBase_test, 3th_test){
    
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab}); 

    DataBase data;
    data.read(vec);
    EXPECT_FALSE(data.get_connections("AAA").empty());
}

TEST(DataBase_test, 4th_test){
    
    CrytpoConversionInfo pricebeta_ab = {"BTC", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "BTC", 2, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 3, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 4, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "BTC", 5, 1};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    double resault = data.profit_for_BTC_from_to_BTC_expressed_decimal_number("BBB", "CCC");
    double expect_resault = 1*3*5;
    
    EXPECT_EQ(resault, expect_resault);
}


TEST(DataBase_test, 5th_test){
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 99, 99};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 1, 99};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 2, 5};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    double resault = data.quantity_for_chain(std::vector<std::string>({"AAA", "BBB", "CCC", "AAA"}));
    double expect_resault = 5.0*(1.0/2.0)*(1.0/1.0);
    
    EXPECT_EQ(resault, expect_resault);
}

TEST(DataBase_test, 6th_test){
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 99, 99};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 1, 99};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 2, 5};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    double resault = data.quantity_for_chain(std::vector<std::string>({"AAA"}));
    double expect_resault = 0;
    
    EXPECT_EQ(resault, expect_resault);
}


TEST(DataBase_test, 7th_test){
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 99, 99};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 1, 99};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 99, 99};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 2, 5};
    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca}); 
    
    DataBase data;
    data.read(vec);
    double resault = data.quantity_for_chain(std::vector<std::string>({}));
    double expect_resault = 0;
    
    EXPECT_EQ(resault, expect_resault);
}