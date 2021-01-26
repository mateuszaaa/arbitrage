#include "Parser.h"
#include <algorithm>
#include <boost/property_tree/json_parser.hpp>
#include <sstream>
#include <iostream>

std::vector<PriceInfo> Parser::load(const std::string &input_string) {
  std::stringstream input_stream;
  input_stream << input_string; 
  boost::property_tree::ptree pt;
  boost::property_tree::read_json(input_stream, pt);

  std::vector<PriceInfo> result;
  // BOOST_FOREACH( ptree::value_type const& v, pt.get_child("symbol")) {
  // auto x = pt.get_child(0);
  // std::cout << x.first << std::endl;
  for(auto &v : pt){
    PriceInfo temp;
    temp.symbol = v.second.get<std::string>("symbol");
    temp.bid_price = v.second.get<float>("bidPrice");
    temp.bid_quantity = v.second.get<float>("bidQty");
    temp.ask_price = v.second.get<float>("askPrice");
    temp.ask_quantity = v.second.get<float>("askQty");
    result.push_back(temp);
  }
  return result;
}
