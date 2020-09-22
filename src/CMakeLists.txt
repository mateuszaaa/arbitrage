add_library(sources OBJECT
    market_connector.h
    market_connector.cpp
)
target_include_directories(sources PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
