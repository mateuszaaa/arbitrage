cmake_minimum_required(VERSION 3.17)
project(bot)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(src)
add_subdirectory(http)
add_subdirectory(test)

add_executable(bot src/main.cpp)
target_link_libraries(bot
    PRIVATE
        http_requests
        sources
)

