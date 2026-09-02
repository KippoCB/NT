//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      desktop.cpp 
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

#include <string>

#include <public/version.h>

#include "dsktp.h"

Desktop::Desktop() :
    rootWindow(nullptr, Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint),
    rootWidget(WT_BEVEL),
    rootLayout(),
    verstrLyt(),
    tb(),
    vStr("placeholder")
{
    //
    // Override cbui set styles via
    // rootWidget.qtNativeHandle()->setStyleSheet("")
    this->rootWidget.qtNativeHandle()->setStyleSheet(
            "QWidget {"
            "   border: none;"
            "}"
    );
    this->rootWidget.setBackground(std::string(CBDE_INSTALL_DIR) + "/CBDE/img0.jpg");

    //
    // Set spacing for the root layout, this needs to be done via 
    // qtNativeHandle()
    this->rootLayout.qtNativeHandle()->setContentsMargins(0, 0, 0, 0);

    //
    // Set the root layout as the main layout and set the root widget as the central widget
    this->rootWindow.setCentralWidget(this->rootWidget.qtNativeHandle());

    //
    // Set the layout 
    //
    // This is not yet supported in the API
    this->rootWidget.qtNativeHandle()->setLayout(this->rootLayout.qtNativeHandle());

    //
    // Add a stretch to the layout and add the taskbar 
    this->rootLayout.addStretch();
    
    //
    // Add the version string 
    this->rootLayout.qtNativeHandle()->addLayout(this->verstrLyt.qtNativeHandle());

    this->verstrLyt.addStretch();
    this->verstrLyt.addLabel(vStr.label);

    this->rootLayout.addWidget(this->tb.taskBand);

    //
    // Show the window fullscreen
    this->rootWindow.showMaximized();
}
