add_executable(api_server
    main.cpp
)

target_link_libraries(api_server
    PRIVATE
        sdi::http
)

target_compile_options(api_server PRIVATE -Wall -Wextra -Wpedantic)
