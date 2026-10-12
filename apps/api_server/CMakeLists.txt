add_executable(api_server
    main.cpp
    config.cpp
    routes/home.cpp
    routes/health.cpp
    routes/events.cpp
    routes/responses.cpp
    validation/json_fields.cpp
    event_store/in_memory_event_store.cpp
)

# Lets any file include from the app root, e.g. "event_store/event_store.h"
target_include_directories(api_server PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(api_server
    PRIVATE
        httplib::httplib
        nlohmann_json::nlohmann_json
)

target_compile_options(api_server PRIVATE -Wall -Wextra -Wpedantic)
