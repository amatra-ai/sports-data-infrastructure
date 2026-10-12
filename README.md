# Sports Data Infrastructure

## Layout

```
apps/
  api_server/     # executable: HTTP API (uses cpp-httplib)
```

## Build & run

Requires CMake 3.20+ and a C++17 compiler (`brew install cmake` on macOS).
Dependencies (cpp-httplib) are downloaded automatically on the first configure.

```bash
cmake -S . -B build
cmake --build build
./build/apps/api_server/api_server
```

Then open http://127.0.0.1:8080.
