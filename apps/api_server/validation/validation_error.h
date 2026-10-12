#ifndef INCLUDED_API_SERVER_VALIDATION_VALIDATION_ERROR
#define INCLUDED_API_SERVER_VALIDATION_VALIDATION_ERROR

#include <stdexcept>

namespace api_server {
    
    class ValidationError : 
        public std::runtime_error {
            public:
            using std::runtime_error::runtime_error;
        };

} // namespace api_server

#endif
