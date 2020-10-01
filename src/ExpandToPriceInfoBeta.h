#pragma once
#include <vector>
#include <string>
#include "PriceInfo.h"
#include "PriceInfoBeta.h"
#include "Parser.h"

class ExpandToPriceInfoBeta{
public:
std::vector<PriceInfoBeta> expand(std::vector<PriceInfo>);
};