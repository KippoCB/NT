//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      label.h 
//
// Purpose:
//      Contains the Label class of the cbui Qt wrapper. 
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#pragma once 

#include <memory>
#include <string>

#include <QtWidgets/QLabel>

#include <cbui/widget.h>

class Label {
public:
    //
    // Label text 
    std::string labelText;

    //
    // Create label 
    Label(std::string title);
    ~Label();

    //
    // Set parent
    void setParent(Widget &parent);

    //
    // Set the text
    void setText(std::string text);

    //
    // Return the native qt handle 
    QLabel *qtNativeHandle();

    //
    // Show the label 
    void show();

    //
    // Hide the label 
    void hide();

    //
    // Set the label text size 
    void resize(int size);
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
