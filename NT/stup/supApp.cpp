//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      supApp.cpp 
//
// Purpose:
//      The main setup application for CBDE NT(TM)
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#include <QtWidgets/QApplication>

#include <cbui/window.h>
#include <cbui/widget.h>
#include <cbui/button.h>
#include <cbui/layoutH.h>
#include <cbui/layoutV.h>


int main(int argc, char *argv[]) {
    //
    // Create app
    QApplication app(argc, argv);

    //
    // Create window 
    Window window(640, 480, "Installer");

    //
    // Create central widget 
    Widget central(WT_BEVEL);

    //
    // Create layout for central 
    LayoutV mainL;
    mainL.setParent(central);
     
    //
    // Make the widget central 
    window.setCentral(central);

    //
    // Show window and run loop
    window.show();

    return app.exec();
}   
