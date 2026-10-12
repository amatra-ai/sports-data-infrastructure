#include "home.h"

namespace {

    void getHome(const httplib::Request &, httplib::Response &res) {
        res.set_content("<h1>Sports Data Infrastructure</h1>", "text/html");
    }

} // namespace

namespace api_server {

    void registerHomeRoutes(httplib::Server &server) {
        server.Get("/", getHome);
    }

} // namespace api_server
