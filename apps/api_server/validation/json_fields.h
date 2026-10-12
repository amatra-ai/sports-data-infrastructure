#ifndef INCLUDED_API_SERVER_VALIDATION_JSON_FIELDS
#define INCLUDED_API_SERVER_VALIDATION_JSON_FIELDS

#include <nlohmann/json.hpp>

#include <cstdint>
#include <string>

namespace api_server {

    
    std::string requireString(const nlohmann::json &object, const char *field);

    std::int64_t requireInt64(const nlohmann::json &object, const char *field);
    
    std::string optionalObjectAsString(const nlohmann::json &object, const char *field);

} // namespace api_server

#endif
