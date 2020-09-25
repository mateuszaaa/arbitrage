#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "http_get.h"
#include "PriceInfo.h"

class Parser{
    public:
        /**
         * @brief converts input market price info stream into container of price info
         * 
         * @return prices
         */
        std::vector<PriceInfo> load (const std::string &);
        
    private:
        bool should_be_removed(char data);
        bool matches_string(const std::string& temp, int j, std::string str);
        void fill_with_spaces(std::string& data, int i, int length);
        void prepare_string(std::string& data);
};