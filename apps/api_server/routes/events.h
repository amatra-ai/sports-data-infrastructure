#ifndef INCLUDED_API_SERVER_ROUTES_EVENTS
#define INCLUDED_API_SERVER_ROUTES_EVENTS

#include <httplib.h>

#include <string>

namespace api_server {

    void registerEventRoutes(httplib::Server &server, const std::string &prefix);

} // namespace api_server

#endif
