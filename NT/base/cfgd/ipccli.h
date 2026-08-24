#pragma once
#include "ipc.h"

class IpcApi {
public:
    //
    // Get integer value 
    int getInt(const char* key);
    void setInt(const char* key, int val);

    //
    // Get boolean 
    bool getBool(const char* key);
    void setBool(const char* key, bool val);

    //
    // Get a string value
    void setStr(const char* key, const char* val);

private:
    int connectToServer();
};
