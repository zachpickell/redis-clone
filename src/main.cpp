#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>
#include <iostream>
#include <string>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd < 0) { perror("socket"); return 1; }

    int reuse = 1;
    setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    sockaddr_in addr{};
    addr.sin_family = AF_INET;
    addr.sin_addr.s_addr = INADDR_ANY;
    addr.sin_port = htons(6379);   // htons = convert to network byte order

    if (bind(server_fd, (sockaddr*)&addr, sizeof(addr)) < 0) { perror("bind"); return 1; }
    if (listen(server_fd, 16) < 0) { perror("listen"); return 1; }
    std::cout << "Listening on port 6379\n";

    while (true) {
        int client_fd = accept(server_fd, nullptr, nullptr);
        if (client_fd < 0) { perror("accept"); continue; }
        std::cout << "Client connected\n";

        char buf[1024];
        while (true) {
            ssize_t n = read(client_fd, buf, sizeof(buf));
            if (n <= 0) break;  // client disconnected or error
            std::cout << "Got " << n << " bytes: " << std::string(buf, n) << "\n";

            write(client_fd, "+PONG\r\n", 7);  // send a simple PONG response
        }

        close(client_fd);
        std::cout << "Client disconnected\n";
    }
}