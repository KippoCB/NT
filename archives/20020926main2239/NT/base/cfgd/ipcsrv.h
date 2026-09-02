#pragma once
#include "ipc.h"
#include <unordered_map>
#include <string>

class IPCServer {
public:
    IPCServer();
    void run();

private:
    int server_fd;

    std::unordered_map<std::string, IPCPacket> config;

    void handleClient(int sock);
};
