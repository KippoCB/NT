#pragma once 

#include <cbui/widget.h>
#include <cbui/layoutH.h>
#include <cbui/layoutV.h>
#include <cbui/button.h>
#include <cbui/label.h>

#include <cbutil/addLayout.h>

class WelcomePage {
public:
    //
    // Root widget 
    Widget rootWidget;

    //
    // Title text and info text 
    Label titleText;
    Label infoText;
    Label copyrightText;

    //
    // Top layout 
    LayoutV layoutMain;

    //
    // Top and bottom layouts 
    LayoutV layoutTop;
    LayoutH layoutBottom;

    //
    // Next and cancel buttons 
    Button next;
    Button cancel;

    //
    // Show the welcome screen 
    WelcomePage();
    ~WelcomePage();

    //
    // Show the page 
    void show();

    //
    // Hide the page 
    void hide();
};
