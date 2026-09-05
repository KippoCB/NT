#pragma once

#include <cbui/window.h>
#include <cbui/widget.h>
#include <cbui/button.h>
#include <cbui/layoutV.h>
#include <cbui/label.h>

#include <cbutil/addLayout.h>

class ErrorBox {
public:
    //
    // Error box window 
    Window errBoxWindow;

    //
    // Central widget 
    Widget central;

    //
    // Close button 
    Button ok;

    //
    // Error box dialogue
    Label errDiag;

    //
    // Window layout 
    LayoutV main;

    //
    // Constructor
    ErrorBox(std::string message);

    //
    // Show the window 
    void show();
private:
    //
    // Close the window 
    void handleClose();
};
