# Sports Data Infrastructure

## Layout

```
apps/
  api_server/     # executable: HTTP server entry point
libs/
  http/           # reusable HTTP/TCP server library
    include/http/ # public headers (#include "http/tcp_server.h")
    src/          # implementation
```

## Build & run

Requires CMake 3.20+ and a C++17 compiler (`brew install cmake` on macOS).

```bash
cmake -S . -B build
cmake --build build
./build/apps/api_server/api_server
```

Then open http://127.0.0.1:8080.
