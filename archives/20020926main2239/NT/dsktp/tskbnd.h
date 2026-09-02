//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      tskbnd.h 
//
// Purpose:
//      Contains the implementation of the taskbar.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#pragma once

#include <cbui/widget.h>
#include <cbui/layoutH.h>

class Taskband {
public:
    //
    // Taskband widget
    Widget taskBand;

    //
    // Taskband layout
    LayoutH taskBLayout;

    //
    // Taskband 
    Taskband();
};
