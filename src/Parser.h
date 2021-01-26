#pragma once
#include <iostream>
#include <sstream>
#include <vector>
#include "http_get.h"
#include "PriceInfo.h"
#include <boost/property_tree/json_parser.hpp>
#include <boost/property_tree/ptree_fwd.hpp>


class Parser{
    public:
        /**
         * @brief converts input market price info stream into container of price info
         * 
         * @return prices
         */
        std::vector<PriceInfo> load (const std::string &);
    
};