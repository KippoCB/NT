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
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
