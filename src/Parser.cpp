#include "Parser.h"
#include <algorithm>

bool Parser::should_be_removed(char data) {
  return data == '"' or data == '[' or data == '{' or data == ',' or
         data == ':' or data == '}' or data == ']';
}

bool Parser::matches_string(const std::string &temp, int j, std::string str) {
    auto ret = temp.find(str, j);
    return ret == j;
}

void Parser::fill_with_spaces(std::string &data, int i, int length) {
  for (int j = 0; j < length; ++j) {
    data[i+j] = ' ';
  }
}

void Parser::prepare_string(std::string &data) {
  for (std::size_t i = 0; i < data.length(); i++) {
    if (should_be_removed(data[i])) {
      data[i] = ' ';
    }

    if (matches_string(data, i, "symbol")) {
      fill_with_spaces(data, i, std::string("symbol").size());
    }
    if (matches_string(data, i, "bidPrice")) {
      fill_with_spaces(data, i, std::string("bidPrice").size());
    }
    if (matches_string(data, i, "bidQty")) {
      fill_with_spaces(data, i, std::string("bidQty").size());
    }
    if (matches_string(data, i, "askPrice")) {
      fill_with_spaces(data, i, std::string("askPrice").size());
    }
    if (matches_string(data, i, "askQty")) {
      fill_with_spaces(data, i, std::string("askQty").size());
    }
  }
}

std::vector<PriceInfo> Parser::load(const std::string &input_string) {
  std::string data = input_string;
  prepare_string(data);

  std::vector<PriceInfo> result;
  std::stringstream stream;
  stream << data;
  
  while (true) {
    PriceInfo temp;

    if (not(stream >> temp.symbol)) {
      break;
    }
    stream >> temp.bid_price;
    stream >> temp.bid_quantity;
    stream >> temp.ask_price;
    stream >> temp.ask_quantity;
    if(temp.bid_price >= 10E-6 and temp.ask_price >= 10E-6 and temp.symbol.find("UP") == std::string::npos and temp.symbol.find("DOWN") == std::string::npos){
      result.push_back(temp);
    }
  }
  return result;
}
