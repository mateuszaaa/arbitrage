#pragma once
#include <vector>
#include <string>
#include "PriceInfo.h"
#include "CrytpoConversionInfo.h"
#include "Parser.h"
#include <unordered_set>

class ConvertToCryptoConversionInfo{
public:
  /**
         * @brief converts conteiner "PriceInfo" to CrytpoConversionInfo"
         * 
         * @return vector of new conteiner "CrytpoConversionInfo" (every sinlge index of vector conteins join between 2 different valut for expample (from BTC to ADA)
         */
std::vector<CrytpoConversionInfo> convert(std::vector<PriceInfo>);
private:
std::pair<CrytpoConversionInfo, CrytpoConversionInfo> convert_to_CrytpoConversionInfo(PriceInfo info, std::string crypto);
std::vector<std::string> search_crypto_names(std::vector<PriceInfo>& price_infos);
};