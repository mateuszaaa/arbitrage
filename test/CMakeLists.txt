add_executable(tests dummy_test.cpp)
target_link_libraries(tests
    PUBLIC
        sources
        -lgtest
        -lgtest_main
)
