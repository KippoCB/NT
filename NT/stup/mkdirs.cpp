//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      mkdirs.cpp
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

#include "mkdirs.h"

//
// Set the current state 
void MkdirsPage::setState() {
    this->state++;
}

//
// Constructor 
MkdirsPage::MkdirsPage() :
    mkdirPage(WT_INSET),
    creatingDirs("Creating directories."),
    copyingFiles("Copying files."),
    doneCopying("Done copying files."),
{

}
