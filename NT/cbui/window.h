#pragma once

#include <string>
#include <memory>

#include <QtWidgets/QMainWindow>

#include <cbui/widget.h>

#define CW_USEDEFAULT 0x1

class Window : public QWidget {
public:
    //
    // Window dimensions
    int width, height;
    std::string title;

    //
    // Create the window 
    Window(int width, int height, std::string title);
    ~Window();

    //
    // Close the window 
    void close();

    //
    // Show the window 
    void show();

    //
    // Hide the window 
    void hide();

    //
    // Resize
    void resize(int width, int height);

    //
    // Set the central widget
    void setCentral(Widget& central);

    //
    // Return the native qt handle for the window
    QMainWindow *qtNativeHandle();
private:
    //
    // Private implementation containing the Qt object and state
    struct Impl;
    std::unique_ptr<Impl> impl;
};
