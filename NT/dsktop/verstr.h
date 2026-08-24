#pragma once

#include <cbui/label.h>
#include <cbui/layoutH.h>

#include <public/version.h>

class Verstr {
public:
    //
    // Version label 
    Label label;
    LayoutH lytH;

    //
    // Create and show the version string label with placeholder
    Verstr(std::string title);
};
