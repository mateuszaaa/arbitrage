#include <vector>
#include <string>
#include <unordered_map>
#include "CrytpoConversionInfo.h"

class DataBase{
    public:
        void read(std::vector<CrytpoConversionInfo>);
    
        std::vector<std::string> get_connections(const std::string&);

        double calculate_profit(std::vector<std::string>);
        // TODO przeczytaj o wyjatkach/exceptions
        // jak rzucic i zlapac wyjatek
        // jak testowac rzucenie wujatku "ASSERT_THROW"

        double convert_crypto(std::string from, std::string to);

    private:
        std::unordered_map<std::string, std::vector<std::string>> map_for_connections;
        std::unordered_map<std::string, CrytpoConversionInfo> map_from_to;
};