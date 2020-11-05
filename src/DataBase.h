#pragma once
#include <vector>
#include <string>
#include <unordered_map>
#include "CrytpoConversionInfo.h"

class DataBase{
    public:
    /**
     * @brief mapping joins between all valut, calculating profit of chain
     * 
     * @return 
     */
        void read(std::vector<CrytpoConversionInfo>);
        std::vector<std::string> get_connections(const std::string&);
        double profit_for_chain_expressed_decimal_number(std::vector<std::string>);
        double profit_for_BTC_from_to_BTC_expressed_decimal_number(std::string from, std::string to);
        double quantity_for_chain(std::vector<std::string>);
        
    private:
        std::unordered_map<std::string, CrytpoConversionInfo> map_from_to_crytpoconversioninfo;
        std::unordered_map<std::string, std::vector<std::string>> map_for_connections;
};