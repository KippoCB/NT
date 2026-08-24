#include "dsktp.h"

Desktop::Desktop() :
    rootWindow(nullptr, Qt::FramelessWindowHint | Qt::WindowStaysOnBottomHint),
    rootWidget(WT_BEVEL),
    rootLayout()
{
    //
    // Override cbui set styles via
    // rootWidget.qtNativeHandle()->setStyleSheet("")
    this->rootWidget.qtNativeHandle()->setStyleSheet(
            "QWidget {"
            "   background-color: cornflowerblue;"
            "   border: none;"
            "}"
    );

    //
    // Set the root layout as the main layout and set the root widget as the central widget
    this->rootLayout.setParent(this->rootWidget);
    this->rootWindow.setCentralWidget(this->rootWidget.qtNativeHandle());

    //
    // Show the window fullscreen
    this->rootWindow.showMaximized();
}
