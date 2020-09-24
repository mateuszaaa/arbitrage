cmake_minimum_required(VERSION 3.16)
project(bot)

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} -Wall -fsanitize=address")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})
include_directories(src)
add_subdirectory(src)
add_subdirectory(test)

add_executable(bot src/main.cpp)
target_link_libraries(bot
    PRIVATE
        sources
)

