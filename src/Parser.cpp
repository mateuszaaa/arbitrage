#include "Parser.h"
std::vector<Price_info> Parser::load (std::string data){

    for (std::size_t i=0; i<=data.length(); i++){
        if(data[i] == '"' or data[i] == '[' or data[i] == '{' or data[i] == ',' or data[i] == ':' or data[i] == '}'|| data[i] == ']' ){
            data[i] = ' ';
        }
        if(data[i]=='s' and data[i+1]=='y' and data[i+2]=='m' and data[i+3]=='b' and data[i+4]=='o' and data[i+5]=='l'){
            data[i]=' ';
            data[i+1]=' ';
            data[i+2]=' ';
            data[i+3]=' '; 
            data[i+4]=' ';
            data[i+5]=' ';
        }
        if(data[i]=='b' and data[i+1]=='i' and data[i+2]=='d' and data[i+3]=='P' and data[i+4]=='r' and data[i+5]=='i'
        and data[i+6]=='c' and data[i+7]=='e'){
            data[i]=' ';
            data[i+1]=' ';
            data[i+2]=' ';
            data[i+3]=' '; 
            data[i+4]=' ';
            data[i+5]=' ';
            data[i+6]=' ';
            data[i+7]=' ';
        }
        if(data[i]=='b' and data[i+1]=='i' and data[i+2]=='d' and data[i+3]=='Q' and data[i+4]=='t' and data[i+5]=='y'){
            data[i]=' ';
            data[i+1]=' ';
            data[i+2]=' ';
            data[i+3]=' '; 
            data[i+4]=' ';
            data[i+5]=' ';
        }   
        if(data[i]=='a' and data[i+1]=='s' and data[i+2]=='k' and data[i+3]=='P' and data[i+4]=='r' and data[i+5]=='i'
        and data[i+6]=='c' and data[i+7]=='e'){
            data[i]=' ';
            data[i+1]=' ';
            data[i+2]=' ';
            data[i+3]=' '; 
            data[i+4]=' ';
            data[i+5]=' ';
            data[i+6]=' ';
            data[i+7]=' ';
        }        
        if(data[i]=='a' and data[i+1]=='s' and data[i+2]=='k' and data[i+3]=='Q' and data[i+4]=='t' and data[i+5]=='y'){
            data[i]=' ';
            data[i+1]=' ';
            data[i+2]=' ';
            data[i+3]=' '; 
            data[i+4]=' ';
            data[i+5]=' ';
        }
    }
    std::stringstream stream;
    stream << data;
    Price_info temp = {};
    while (true){
        if(not (stream >> temp.symbol)){
            break;
        }        stream >> temp.bid_price;
        stream >> temp.bid_quantity;
        stream >> temp.ask_price;
        stream >> temp.ask_quantity;

        Parser::data.push_back(temp);    
    }
    return Parser::data;
}
