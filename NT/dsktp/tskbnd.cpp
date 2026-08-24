//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      tskbnd.cpp
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

#include "tskbnd.h"

Taskband::Taskband() :
    taskBand(WT_BEVEL),
    taskBLayout()
{
    //
    // Make taskbar 40px high
    this->taskBand.setHeight(40);

    //
    // Set layout parent
    this->taskBLayout.setParent(this->taskBand);
}
