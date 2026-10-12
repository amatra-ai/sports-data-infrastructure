#include "json_fields.h"

#include "validation_error.h"

#include <limits>

namespace api_server {

    std::string requireString(const nlohmann::json &object, const char *field) {
        auto it = object.find(field);
        if (it == object.end()) {
            throw ValidationError("missing field '" + std::string(field) + "'");
        }
        if (!it->is_string() || it->get_ref<const std::string &>().empty()) {
            throw ValidationError("field '" + std::string(field) + "' must be a non-empty string");
        }
        return it->get<std::string>();
    }

    std::int64_t requireInt64(const nlohmann::json &object, const char *field) {
        auto it = object.find(field);
        if (it == object.end()) {
            throw ValidationError("missing field '" + std::string(field) + "'");
        }
        // is_number_integer() rejects floats like 1.5; the unsigned check rejects values above INT64_MAX.
        bool fits = it->is_number_integer() &&
                    (!it->is_number_unsigned() ||
                     it->get<std::uint64_t>() <= static_cast<std::uint64_t>(std::numeric_limits<std::int64_t>::max()));
        if (!fits) {
            throw ValidationError("field '" + std::string(field) + "' must be an integer");
        }
        return it->get<std::int64_t>();
    }

    std::string optionalObjectAsString(const nlohmann::json &object, const char *field) {
        auto it = object.find(field);
        if (it == object.end()) {
            return "{}";
        }
        if (!it->is_object()) {
            throw ValidationError("field '" + std::string(field) + "' must be a JSON object");
        }
        return it->dump();
    }

} // namespace api_server
