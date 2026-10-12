#include "events.h"

#include "validation/json_fields.h"
#include "validation/validation_error.h"

#include <nlohmann/json.hpp>

#include <chrono>
#include <cstdint>

namespace api_server {

    namespace {

        using nlohmann::json;

        std::int64_t nowMs() {
            using namespace std::chrono;
            return duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count();
        }

        // Returns a fully valid DataEvent or throws ValidationError.
        DataEvent toDataEvent(const json &body, std::int64_t ingestedAtMs) {
            if (!body.is_object()) {
                throw ValidationError("request body must be a JSON object");
            }

            DataEvent event;
            event.id = requireString(body, "id");
            event.subject_id = requireString(body, "subject_id");
            event.type = requireString(body, "type");
            event.source = requireString(body, "source");
            event.event_time_ms = requireInt64(body, "event_time_ms");
            event.ingested_at_ms = ingestedAtMs;
            event.payload = optionalObjectAsString(body, "payload");
            return event;
        }

        // Invalid input throws ValidationError, which the global error handler turns into a 400.
        void createEvent(EventStore &store, const httplib::Request &req, httplib::Response &res) {
            DataEvent event = toDataEvent(parseJson(req.body), nowMs());

            store.append(event);

            res.status = 201;
            res.set_content(json{{"id", event.id}}.dump(), "application/json");
        }

    } // namespace

    void registerEventRoutes(httplib::Server &server, const std::string &prefix, EventStore &store) {
        server.Post(prefix + "/events", [&store](const httplib::Request &req, httplib::Response &res) {
            createEvent(store, req, res);
        });
    }

} // namespace api_server
