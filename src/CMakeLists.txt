find_library(SSL ssl)
find_library(CRYPTO crypto)
find_package (Threads REQUIRED)

add_library(sources OBJECT
    MarketConnector.h
    MarketConnector.cpp
    http_get.h
    http_get.cpp
    Parser.cpp
    Parser.h
    PriceInfo.h
    CrytpoConversionInfo.h
    ConvertToCryptoConversionInfo.h
    ConvertToCryptoConversionInfo.cpp
    DataBase.h
    DataBase.cpp
    AlgorithmBuyAndSell.h
    AlgorithmBuyAndSell.cpp
)

target_link_libraries(sources
PUBLIC
    ${SSL}
    ${CRYPTO}
    Threads::Threads
)
target_include_directories(sources PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
