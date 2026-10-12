#include <httplib.h>

#include <iostream>

int main() {
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

    const std::string host = "127.0.0.1";
    const int port = 8080;

    std::cout << "Listening on http://" << host << ":" << port << std::endl;
    if (!server.listen(host, port)) {
        std::cerr << "Failed to start server on " << host << ":" << port << std::endl;
        return 1;
    }

    return 0;
}
