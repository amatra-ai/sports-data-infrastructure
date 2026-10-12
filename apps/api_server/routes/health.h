#ifndef INCLUDED_API_SERVER_ROUTES_HEALTH
#define INCLUDED_API_SERVER_ROUTES_HEALTH

#include <httplib.h>

namespace api_server {

    void registerHealthRoutes(httplib::Server &server);

} // namespace api_server

#endif
