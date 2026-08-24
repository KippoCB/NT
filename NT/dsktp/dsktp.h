//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      desktop.h 
//
// Purpose:
//      This is the main desktop class for the CBDE NT(TM) desktop.
//      It handles the initialization of the desktop and placement 
//      of the taskbar and version labels.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#pragma once

#include <QtWidgets/QApplication>

#include <cbui/window.h>
#include <cbui/widget.h>
#include <cbui/layoutV.h>
#include <cbui/layoutV.h>

#include "tskbnd.h"
#include "verstr.h"

class Desktop {
public:
    //
    // Desktop root window is not a cbui window as it does not allow for the window 
    // flags we need
    QMainWindow rootWindow;

    //
    // Desktop widget
    Widget rootWidget;

    //
    // Desktop layouts
    LayoutV rootLayout;
    LayoutH verstrLyt;

    //
    // Taskbar 
    Taskband tb;

    //
    // Version string 
    Verstr vStr;

    //
    // Desktop 
    Desktop();
};
