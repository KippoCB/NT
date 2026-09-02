#pragma once
#include <cstdint>

enum IPC_OP {
    IPC_GET = 1,
    IPC_SET = 2,
    IPC_RESP = 3
};

struct IPCPacket {
    IPC_OP op;

    char key[64];

    union {
        int i;
        bool b;
        char str[128];
    } value;

    int type; // 0=int,1=bool,2=str
};
