#include "health.h"

#include <nlohmann/json.hpp>

namespace {

    void getHealth(const httplib::Request &, httplib::Response &res) {
        nlohmann::json body = {{"status", "ok"}};
        res.set_content(body.dump(), "application/json");
    }

} // namespace

namespace api_server {

    void registerHealthRoutes(httplib::Server &server) {
        server.Get("/health", getHealth);
    }

} // namespace api_server
