#ifndef INCLUDED_API_SERVER_ROUTES_ERROR_HANDLER
#define INCLUDED_API_SERVER_ROUTES_ERROR_HANDLER

#include <httplib.h>

namespace api_server {

    // Converts exceptions to JSON error responses (400 for ValidationError, 500 otherwise),
    // and gives bodiless error responses (e.g. 404 for unknown routes) a JSON body too.
    void registerErrorHandler(httplib::Server &server);

} // namespace api_server

#endif
