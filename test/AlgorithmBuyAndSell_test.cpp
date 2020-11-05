#include <gtest/gtest.h>
#include "AlgorithmBuyAndSell.h"
#include "DataBase.h"

TEST(AlgorithmBuyAndSell_test, 1st_test){
    CrytpoConversionInfo pricebeta_BTCa = {"BTC", "AAA", 1, 1};
    CrytpoConversionInfo pricebeta_BTCb = {"BTC", "BBB", 0.01, 1};
    CrytpoConversionInfo pricebeta_BTCc = {"BTC", "CCC", 0.01, 1};
    CrytpoConversionInfo pricebeta_ab = {"AAA", "BBB", 1, 1};
    CrytpoConversionInfo pricebeta_ba = {"BBB", "AAA", 0.01, 1};
    CrytpoConversionInfo pricebeta_bc = {"BBB", "CCC", 0.01, 1};
    CrytpoConversionInfo pricebeta_cb = {"CCC", "BBB", 0.01, 1};
    CrytpoConversionInfo pricebeta_ca = {"CCC", "AAA", 0.01, 1};
    CrytpoConversionInfo pricebeta_aBTC = {"AAA", "BTC", 0.01, 1};
    CrytpoConversionInfo pricebeta_bBTC = {"BBB", "BTC", 2, 1};
    CrytpoConversionInfo pricebeta_cBTC = {"CCC", "BTC", 0.01, 1};

    auto vec = std::vector<CrytpoConversionInfo>({pricebeta_ab, pricebeta_ba, pricebeta_bc, pricebeta_cb, pricebeta_ca,
                                                    pricebeta_aBTC, pricebeta_bBTC, pricebeta_cBTC, pricebeta_BTCa, pricebeta_BTCb,
                                                    pricebeta_BTCc}); 
    
    DataBase data;
    data.read(vec);
    AlgorithmBuyAndSell algorithm;
    auto resault = algorithm.algorythm_for_search_four_elem_chain(data);
    
    auto expect_resault = std::vector<std::string>({"BTC", "AAA", "BBB", "BTC"});
    
    EXPECT_EQ(resault, expect_resault);
}
