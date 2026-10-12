#include "config.h"

#include <cstdlib>
#include <stdexcept>

namespace {

    std::string getEnvString(const char *name, const std::string &fallback) {
        const char *value = std::getenv(name);
        return value ? value : fallback;
    }

    int getEnvInt(const char *name, int fallback, int min, int max) {
        const char *value = std::getenv(name);
        if (!value) {
            return fallback;
        }

        char *end = nullptr;
        long parsed = std::strtol(value, &end, 10);
        if (*value == '\0' || *end != '\0' || parsed < min || parsed > max) {
            throw std::runtime_error("Invalid " + std::string(name) + ": '" + value + "' (expected " +
                                     std::to_string(min) + "-" + std::to_string(max) + ")");
        }
        return static_cast<int>(parsed);
    }

} // namespace

namespace api_server {

    Config loadConfig() {
        const Config defaults;

        Config config;
        config.host = getEnvString("HOST", defaults.host);
        config.port = getEnvInt("PORT", defaults.port, 1, 65535);
        return config;
    }

} // namespace api_server
