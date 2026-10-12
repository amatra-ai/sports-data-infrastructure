#include "config.h"

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

    server.Get("/", [](const httplib::Request &, httplib::Response &res) {
        res.set_content("<h1>Sports Data Infrastructure</h1>", "text/html");
    });

    server.Get("/health", [](const httplib::Request &, httplib::Response &res) {
        res.set_content(R"({"status":"ok"})", "application/json");
    });

    std::cout << "Listening on http://" << config.host << ":" << config.port << std::endl;
    if (!server.listen(config.host, config.port)) {
        std::cerr << "Failed to start server on " << config.host << ":" << config.port << std::endl;
        return 1;
    }

    return 0;
}
