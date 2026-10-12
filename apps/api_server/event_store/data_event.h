#ifndef INCLUDED_API_SERVER_EVENT_STORE_DATA_EVENT
#define INCLUDED_API_SERVER_EVENT_STORE_DATA_EVENT

#include <cstdint>
#include <string>

namespace api_server {

    struct DataEvent {
        std::string id;
        std::string subject_id;
        std::string type;
        std::string source;

        std::int64_t event_time_ms = 0;
        std::int64_t ingested_at_ms = 0;

        std::string payload;
    };

} // namespace api_server

#endif
