#ifndef INCLUDED_API_SERVER_CONFIG
#define INCLUDED_API_SERVER_CONFIG

#include <string>

namespace api_server {

    struct Config {
        std::string host = "127.0.0.1";
        int port = 8080;
    };

    
    Config loadConfig();

} // namespace api_server

#endif
