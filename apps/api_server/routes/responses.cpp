#include "responses.h"

#include <nlohmann/json.hpp>

namespace api_server {

    void sendError(httplib::Response &res, int status, const std::string &message) {
        res.status = status;
        res.set_content(nlohmann::json{{"error", message}}.dump(), "application/json");
    }

} // namespace api_server
