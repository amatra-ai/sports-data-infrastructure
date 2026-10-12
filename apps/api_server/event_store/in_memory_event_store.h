#ifndef INCLUDED_API_SERVER_EVENT_STORE_IN_MEMORY_EVENT_STORE
#define INCLUDED_API_SERVER_EVENT_STORE_IN_MEMORY_EVENT_STORE

#include "event_store.h"

#include <mutex>
#include <vector>

namespace api_server {

    // Keeps events in a vector, in insertion order. Data is lost on restart.
    class InMemoryEventStore : public EventStore {
    public:
        void append(const DataEvent &event) override;

        std::vector<DataEvent> query(const EventQuery &query) const override;

    private:
        mutable std::mutex m_mutex;
        std::vector<DataEvent> m_events;
    };

} // namespace api_server

#endif
