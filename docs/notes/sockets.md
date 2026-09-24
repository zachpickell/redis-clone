# Sockets

## Server setup order
1. `socket()`: create the endpoint
2. `bind()`: attach it to a port
3. `listen()`: start accepting connections
4. `accept()`: wait for a client, get its fd
5. `read()` / `write()`: talk to the client
6. `close()`: done with the client

## Notes
-