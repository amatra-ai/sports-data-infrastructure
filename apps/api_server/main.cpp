#include "http/tcp_server.h"

int main() {
    using namespace http;

    http::TcpServer server = http::TcpServer("127.0.0.1", 8080);

    server.startListen();

    return 0;
}