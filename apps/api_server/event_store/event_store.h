#ifndef INCLUDED_API_SERVER_EVENT_STORE_EVENT_STORE
#define INCLUDED_API_SERVER_EVENT_STORE_EVENT_STORE

#include "data_event.h"

#include <cstddef>
#include <cstdint>
#include <optional>
#include <string>
#include <vector>

namespace api_server {


    struct EventQuery {
        std::optional<std::string> subject_id;
        std::optional<std::string> type;
        std::optional<std::int64_t> from_ms;
        std::optional<std::int64_t> to_ms;
        std::size_t limit = 100;
    };

    class EventStore {
    public:
        virtual ~EventStore() = default;

        virtual void append(const DataEvent &event) = 0;

        virtual std::vector<DataEvent> query(const EventQuery &query) const = 0;
    };

} // namespace api_server

#endif
