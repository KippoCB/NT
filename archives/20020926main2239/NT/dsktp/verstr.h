//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      verstr.h 
//
// Purpose:
//      Contains the routines to get the system version.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

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
