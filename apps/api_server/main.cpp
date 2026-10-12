#include "config.h"

// Routes
#include "routes/events.h"
#include "routes/health.h"
#include "routes/home.h"

#include <httplib.h>
#include <exception>
#include <iostream>

int main() {
    api_server::Config config;
    try {
        config = api_server::loadConfig();
    } catch (const std::exception &e) {
        std::cerr << "Config error: " << e.what() << std::endl;
        return 1;
    }

    httplib::Server server;

    server.set_logger([](const httplib::Request &req, const httplib::Response &res) {
        std::cout << req.method << " " << req.path << " -> " << res.status << std::endl;
    });
    const std::string apiVersion = "/v1";

    api_server::registerHomeRoutes(server);            // /
    api_server::registerHealthRoutes(server);          // /health
    api_server::registerEventRoutes(server, apiVersion);    // /v1/events

    std::cout << "Listening on http://" << config.host << ":" << config.port << std::endl;
    if (!server.listen(config.host, config.port)) {
        std::cerr << "Failed to start server on " << config.host << ":" << config.port << std::endl;
        return 1;
    }

    return 0;
}
