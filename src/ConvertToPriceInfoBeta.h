#pragma once
#include <vector>
#include <string>
#include "PriceInfo.h"
#include "PriceInfoBeta.h"
#include "Parser.h"
#include <unordered_set>

class ConvertToPriceInfoBeta{
public:
  /**
         * @brief converts conteiner "PriceInfo" to PriceInfoBeta"
         * 
         * @return vector of new conteiner "PriceInfoBeta" (every sinlge index of vector conteins join between 2 different valut for expample (from BTC to ADA)
         */
std::vector<PriceInfoBeta> convert(std::vector<PriceInfo>);
private:
std::pair<PriceInfoBeta, PriceInfoBeta> convert_to_PriceInfoBeta_v1(PriceInfo info, std::string crypto);
std::pair<PriceInfoBeta, PriceInfoBeta> convert_to_PriceInfoBeta_v2(PriceInfo info, std::string crypto, int pos);
void search_crypto_valut(std::vector<PriceInfo>& price_infos, std::string& crypto, std::vector<std::string>& crypto_name, std::unordered_set<std::string>& crypto_set);
};