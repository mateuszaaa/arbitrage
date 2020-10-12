#include <vector>
#include <string>
#include <unordered_map>
#include "CrytpoConversionInfo.h"

class DataBase{
    public:
    /**
     * @brief mapping joins between all valut, 
     * calculating profit of vector's valut
     * calculating opportunity of single jump from 1 to next valut
     * 
     * @return 
     */
        void read(std::vector<CrytpoConversionInfo>);
        std::vector<std::string> get_connections(const std::string&);
        double calculate_profit(std::vector<std::string>);
        double convert_crypto(std::string from, std::string to);

    private:
        std::unordered_map<std::string, std::vector<std::string>> map_for_connections;
        std::unordered_map<std::string, CrytpoConversionInfo> map_from_to;
};