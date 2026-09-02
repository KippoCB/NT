#pragma once

#include "ipc.h"
#include "ipcsrv.h"

#include <iostream>

#include <QtCore/QFile>
#include <QtCore/QSettings>

#pragma once

#include <unordered_map>
#include <string>
#include <variant>

#include "ipc.h"

using Value = std::variant<int, bool, std::string>;

class ConfigD {
public:
    void run();

private:
    int server_fd;

    std::unordered_map<std::string, Value> store;

    void initDefaults();
    void handleClient(int sock);

    void handleGet(const std::string& key, IPCPacket& res);
    void handleSet(const std::string& key, const IPCPacket& req);
};
