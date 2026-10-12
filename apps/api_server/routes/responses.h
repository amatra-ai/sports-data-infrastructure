#ifndef INCLUDED_API_SERVER_ROUTES_RESPONSES
#define INCLUDED_API_SERVER_ROUTES_RESPONSES

#include <httplib.h>

#include <string>

namespace api_server {

    // Sets status and a JSON body of the form {"error": "<message>"}.
    void sendError(httplib::Response &res, int status, const std::string &message);

} // namespace api_server

#endif
