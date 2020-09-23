find_library(SSL ssl)
find_library(CRYPTO crypto)
find_package (Threads REQUIRED)

add_library(sources OBJECT
    market_connector.h
    market_connector.cpp
    http_get.h
    http_get.cpp
)
target_link_libraries(sources
PUBLIC
    ${SSL}
    ${CRYPTO}
    Threads::Threads
)
target_include_directories(sources PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
