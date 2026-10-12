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

## Configuration

Settings come from environment variables. See `.env.example` for the full list.

```bash
cp .env.example .env      # once; .env is gitignored
set -a; source .env; set +a
./build/apps/api_server/api_server
```

| Variable | Default     | Description            |
|----------|-------------|------------------------|
| `HOST`   | `127.0.0.1` | Address to listen on   |
| `PORT`   | `8080`      | Port to listen on      |
