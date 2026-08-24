#pragma once

#include <QtWidgets/QApplication>

#include <cbui/window.h>
#include <cbui/widget.h>
#include <cbui/layoutV.h>

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
    // Desktop layout
    LayoutV rootLayout;

    //
    // Desktop 
    Desktop();
};
