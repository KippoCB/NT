//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      button.h 
//
// Purpose:
//      This is the implementation of the cbui button class.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      23-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//      24-08-26: Add show/hide methods | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#pragma once 

#include <memory>
#include <string>
#include <functional>

#include <QtWidgets/QPushButton>

#include <cbui/widget.h>

class Button : public QWidget {
public:
    //
    // Button text 
    std::string text;

    //
    // Create a button with text 
    Button(std::string text);
    ~Button();

    //
    // Execute a function on click 
    void onClick(std::function<void()> action);

    //
    // Set parent 
    void setParent(Widget &parent);

    //
    // Get native Qt handle 
    QPushButton *qtNativeHandle();

    //
    // Show the button 
    void show();

    //
    // Hide the button 
    void hide();
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
