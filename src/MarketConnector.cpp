#include "MarketConnector.h"

MarketConnector::MarketConnector():
    host_("api.binance.com"),
    port_(443),
    path_("/api/v3/ticker/bookTicker")
{
}

std::string getMarketData(){
    return "";
}

