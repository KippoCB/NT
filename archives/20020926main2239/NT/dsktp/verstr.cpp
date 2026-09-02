//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      verstr.cpp 
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

#include "verstr.h"

#include <base/cfgd/ipccli.h>

Verstr::Verstr(std::string title) :
    label(title),
    lytH()
{
    IpcApi ipc;
    //
    // Get version information from version.h
    std::string text = CBDE_SYSNAME;

    if (CBDE_EVALUATION == true) 
        text += "\nEvaluation copy.";

    if (CBDE_SHOWVERSION == true)
    {
        text += "Version ";
        text += CBDE_VERSION;
        text += " ";
        text += CBDE_CONFIGURATION;
    }

    text += "\n";
    text += "/CBDE";

    //
    // Set text 
    this->label.setText(text);

    //
    // Set alignment as right
    //
    // We have to do this via qtNativeHandle as alignment options
    // are not yet implemented in cbui 
    this->label.qtNativeHandle()->setAlignment(Qt::AlignRight);

    //
    // Set text color to white 
    //
    // We again have to use qtNativeHandle for this 
    this->label.qtNativeHandle()->setStyleSheet(
            "QLabel {"
            "   color: white;"
            "}"
    );
}
