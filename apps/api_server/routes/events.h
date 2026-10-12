#ifndef INCLUDED_API_SERVER_ROUTES_EVENTS
#define INCLUDED_API_SERVER_ROUTES_EVENTS

#include "event_store/event_store.h"

#include <httplib.h>

#include <string>

namespace api_server {

    void registerEventRoutes(httplib::Server &server, const std::string &prefix, EventStore &store);

} // namespace api_server

#endif
