add_executable(api_server
    main.cpp
    config.cpp
    routes/home.cpp
    routes/health.cpp
)

target_link_libraries(api_server
    PRIVATE
        httplib::httplib
        nlohmann_json::nlohmann_json
)

target_compile_options(api_server PRIVATE -Wall -Wextra -Wpedantic)
