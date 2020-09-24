#pragma once

#include <iostream>
#include <sstream>
#include <vector>
#include "http_get.h"
#include "Price_info.h"




class Parser{
    public:
        std::vector<Price_info> data;
        std::vector<Price_info> load (std::string);
};