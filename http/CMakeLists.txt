find_library(SSL ssl)
find_library(CRYPTO crypto)
find_package (Threads REQUIRED)

add_library(http_requests OBJECT http_get.cpp)

target_link_libraries(http_requests
    PRIVATE
        ${CRYPTO}
        ${SSL}
        Threads::Threads
)

target_include_directories(http_requests PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
        
