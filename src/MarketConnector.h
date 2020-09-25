#pragma once
#include <string>

class MarketConnector{
public:
    MarketConnector();
    std::string getMarketData();

private:
    std::string host_;
    std::size_t port_;
    std::string path_;
};
