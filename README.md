# redis-clone-cpp

A Redis-compatible in-memory key-value store written from scratch in C++20. Built as a learning project.

## How it works

The server listens on port 6379 for TCP connections. Clients like `redis-cli` send commands in **RESP** (the Redis protocol), and the server sends replies back in the same format.

For example, `PING` arrives as `*1\r\n$4\r\nPING\r\n`, and the server replies `+PONG\r\n`.

## Build and run

```bash
cmake -B build
cmake --build build
./build/redis-clone
```

Then in another terminal:

```bash
redis-cli PING
```

## Commands

| Command | Description |
|---------|-------------|
| `PING`  | Returns `PONG` |

## Dev log

**9/24/26:** Set up the project with CMake. Built a TCP server that accepts connections and replies `PONG`.

## AI disclosure

This is a learning project. I used AI (Claude) as a tutor for setup, boilerplate, explanations and debugging. I write try and write majority of the code myself with the help of AI.
