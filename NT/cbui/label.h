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
    void setParent(Widget parent);

    //
    // Set the text
    void setText(std::string text);

    //
    // Return the native qt handle 
    QLabel *qtNativeHandle();
private:
    struct Impl;
    std::unique_ptr<Impl> impl;
};
