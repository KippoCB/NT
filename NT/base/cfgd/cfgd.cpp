#include "cfgd.h"

#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <cstring>
#include <stddef.h>
#include <cerrno>
#include <cstdio>

//
// Defaults
//
void ConfigD::initDefaults() {
    printf("[cfgd] Loading defaults\n");

    QSettings regDef("/data/data/com.termux/files/cbde/CBDE/system.inf", QSettings::IniFormat);

    for (const QString &group : regDef.childGroups()) {
        regDef.beginGroup(group);
        std::cout << "[cfgd] Loading section: " << group.toStdString() << " from: " << "system.inf" << std::endl;

        for (const QString &key : regDef.childKeys()) {
            QVariant val = regDef.value(key);

            std::cout << "[cfgd] Set default config: " << key.toStdString() << " to: " << val.toString().toStdString() << std::endl;
            store[key.toStdString()] = val.toString().toStdString();
        }

        regDef.endGroup();
    }
}

//
// Main loop
//
void ConfigD::run() {
    printf("[cfgd] Starting\n");

    server_fd = socket(AF_UNIX, SOCK_STREAM, 0);

    if (server_fd < 0) {
        printf("[cfgd] socket failed errno=%d (%s)\n",
               errno,
               strerror(errno));
        return;
    }

    sockaddr_un addr{};
    addr.sun_family = AF_UNIX;

    const char* name = "cbde_ipc";

    //
    // Abstract socket
    //
    addr.sun_path[0] = '\0';
    memcpy(addr.sun_path + 1, name, strlen(name));

    socklen_t len =
        offsetof(sockaddr_un, sun_path)
        + 1
        + strlen(name);

    printf("[cfgd] Binding socket '%s'\n", name);

    if (bind(server_fd, (sockaddr*)&addr, len) < 0) {
        printf("[cfgd] bind failed errno=%d (%s)\n",
               errno,
               strerror(errno));
        return;
    }

    //
    // Load defaults before accepting clients
    //
    initDefaults();

    if (listen(server_fd, 10) < 0) {
        printf("[cfgd] listen failed errno=%d (%s)\n",
               errno,
               strerror(errno));
        return;
    }

    printf("[cfgd] Listening for clients\n");

    while (true) {
        int client = accept(server_fd, nullptr, nullptr);

        if (client < 0) {
            printf("[cfgd] accept failed errno=%d (%s)\n",
                   errno,
                   strerror(errno));
            continue;
        }

        printf("[cfgd] Client connected\n");

        handleClient(client);

        close(client);
    }
}

//
// Client handler
//
void ConfigD::handleClient(int sock) {
    IPCPacket req{};
    IPCPacket res{};

    res.op = IPC_RESP;

    ssize_t bytes =
        recv(sock, &req, sizeof(req), 0);

    if (bytes <= 0) {
        printf("[cfgd] recv failed\n");
        return;
    }

    printf("[cfgd] recv=%ld op=%d key='%s'\n",
           (long)bytes,
           req.op,
           req.key);

    std::string key(req.key);

    if (req.op == IPC_GET) {
        handleGet(key, res);
    }
    else if (req.op == IPC_SET) {
        handleSet(key, req);

        res = req;
        res.op = IPC_RESP;
    }
    else {
        printf("[cfgd] Unknown operation %d\n",
               req.op);
    }

    printf("[cfgd] sending response type=%d\n",
           res.type);

    send(sock, &res, sizeof(res), 0);
}

//
// GET logic
//
void ConfigD::handleGet(const std::string& key,
                        IPCPacket& res) {

    printf("[cfgd] GET '%s'\n",
           key.c_str());

    auto it = store.find(key);

    if (it == store.end()) {
        printf("[cfgd] Key not found\n");

        res.type = -1;
        return;
    }

    printf("[cfgd] Key found\n");

    if (std::holds_alternative<int>(it->second)) {
        res.type = 0;
        res.value.i = std::get<int>(it->second);

        printf("[cfgd] Returning int=%d\n",
               res.value.i);
    }
    else if (std::holds_alternative<bool>(it->second)) {
        res.type = 1;
        res.value.b = std::get<bool>(it->second);

        printf("[cfgd] Returning bool=%d\n",
               res.value.b);
    }
    else {
        res.type = 2;

        std::string s =
            std::get<std::string>(it->second);

        strncpy(res.value.str,
                s.c_str(),
                sizeof(res.value.str) - 1);

        res.value.str[sizeof(res.value.str) - 1] = '\0';

        printf("[cfgd] Returning str='%s'\n",
               res.value.str);
    }
}

//
// SET logic
//
void ConfigD::handleSet(const std::string& key,
                        const IPCPacket& req) {

    printf("[cfgd] SET '%s' type=%d\n",
           key.c_str(),
           req.type);

    if (req.type == 0) {
        store[key] = req.value.i;

        printf("[cfgd] Value=%d\n",
               req.value.i);
    }
    else if (req.type == 1) {
        store[key] = req.value.b;

        printf("[cfgd] Value=%d\n",
               req.value.b);
    }
    else {
        store[key] =
            std::string(req.value.str);

        printf("[cfgd] Value='%s'\n",
               req.value.str);
    }
}
