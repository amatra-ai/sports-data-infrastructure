#include "error_handler.h"

#include "routes/responses.h"
#include "validation/validation_error.h"

#include <exception>
#include <iostream>

namespace api_server {

    void registerErrorHandler(httplib::Server &server) {
        server.set_exception_handler([](const httplib::Request &req, httplib::Response &res, std::exception_ptr ep) {
            // Drop anything the handler set before it threw.
            res.headers.clear();

            try {
                std::rethrow_exception(ep);
            } catch (const ValidationError &e) {
                sendError(res, 400, e.what());
            } catch (const std::exception &e) {
                std::cerr << "Unhandled error in " << req.method << " " << req.path << ": " << e.what() << std::endl;
                sendError(res, 500, "internal server error");
            } catch (...) {
                std::cerr << "Unhandled non-standard error in " << req.method << " " << req.path << std::endl;
                sendError(res, 500, "internal server error");
            }
        });
    }

} // namespace api_server
