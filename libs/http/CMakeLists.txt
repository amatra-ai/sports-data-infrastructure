add_library(http
    src/tcp_server.cpp
)
add_library(sdi::http ALIAS http)

target_include_directories(http
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(http PRIVATE -Wall -Wextra -Wpedantic)
