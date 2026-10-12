#include "events.h"

#include "routes/responses.h"
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

        void createEvent(EventStore &store, const httplib::Request &req, httplib::Response &res) {

            json body;
            
            try {
                body = json::parse(req.body);
            } catch (const json::parse_error &) {
                sendError(res, 400, "request body is not valid JSON");
                return;
            }

            DataEvent event;
            try {
                event = toDataEvent(body, nowMs());
            } catch (const ValidationError &e) {
                sendError(res, 400, e.what());
                return;
            }

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
