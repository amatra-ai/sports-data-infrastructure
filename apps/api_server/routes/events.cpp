#include "events.h"

#include <iostream>

namespace {

    void createEvent(const httplib::Request &req, httplib::Response &) {
        std::cout << "Received event: " << req.body << std::endl;
    }

} // namespace

namespace api_server {

    void registerEventRoutes(httplib::Server &server, const std::string &prefix) {
        server.Post(prefix + "/events", createEvent);
    }

} // namespace api_server
