//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      mkdirs.h 
//
// Purpose:
//      This is the file copy dialog page of the CBDE NT(TM) setup
//      application. 
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
#include <cbui/button.h>
#include <cbui/label.h>
#include <cbui/layoutV.h>

class MkdirsPage {
public:
    //
    // Page widget 
    Widget mkdirPage;

    //
    // Info labels 
    Label creatingDirs;
    Label copyingFiles;
    Label doneCopying;

    //
    // Layout 


    //
    // State
    int state; 

    void setState();

    //
    // Next button 
    Button next;

    //
    // Constructor 
    MkdirsPage();
};
