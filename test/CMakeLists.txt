add_executable(tests 
Parser_test.cpp 
ConvertToCrytpoConversionInfo_test.cpp 
DataBase_test.cpp
AlgorithmBuyAndSell_test.cpp
)

include_directories(${CMAKE_SOURCE_DIR}/src)
target_link_libraries(tests
    PUBLIC
        sources
        -lgtest
        -lgtest_main
)
