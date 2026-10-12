#ifndef INCLUDED_API_SERVER_ROUTES_HOME
#define INCLUDED_API_SERVER_ROUTES_HOME

#include <httplib.h>

namespace api_server {

    void registerHomeRoutes(httplib::Server &server);

} // namespace api_server

#endif
