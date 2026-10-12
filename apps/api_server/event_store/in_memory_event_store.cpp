#include "in_memory_event_store.h"

namespace {

    bool matches(const api_server::DataEvent &event, const api_server::EventQuery &query) {
        if (query.subject_id && event.subject_id != *query.subject_id) return false;
        if (query.type && event.type != *query.type) return false;
        if (query.from_ms && event.event_time_ms < *query.from_ms) return false;
        if (query.to_ms && event.event_time_ms >= *query.to_ms) return false;
        return true;
    }

} // namespace

namespace api_server {

    void InMemoryEventStore::append(const DataEvent &event) {
        std::lock_guard<std::mutex> lock(m_mutex);
        m_events.push_back(event);
    }

    std::vector<DataEvent> InMemoryEventStore::query(const EventQuery &query) const {
        std::lock_guard<std::mutex> lock(m_mutex);

        std::vector<DataEvent> result;
        for (const DataEvent &event : m_events) {
            if (result.size() >= query.limit) {
                break;
            }
            if (matches(event, query)) {
                result.push_back(event);
            }
        }
        return result;
    }

} // namespace api_server
