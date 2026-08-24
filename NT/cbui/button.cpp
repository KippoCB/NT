#include "button.h"


struct Button::Impl {
    QPushButton btn;
};

//
// Get the qt native handle for the button
QPushButton *Button::qtNativeHandle() {
    return &impl->btn;
}

//
// Create the button 
Button::Button(std::string text) :
    impl(std::make_unique<Impl>())
{
    //
    // Style the button 
    impl->btn.setStyleSheet(
            "QPushButton {"
            "   background-color: #d4d0c8;"
            "   border-left: 3px solid white;"
            "   border-top: 3px solid white;"
            "   border-right: 2px solid black;"
            "   border-bottom: 2px solid black;"
            "}"
    );

    //
    // Resize it 
    impl->btn.setFixedSize(60, 30);
}

Button::~Button() = default;

//
// Reparent a button 
void Button::setParent(Widget &parent) {
    impl->btn.setParent(parent.qtNativeHandle());
}

//
// Add a click function 
void Button::onClick(std::function<void()> action) {
    QObject::connect(&impl->btn, &QPushButton::clicked, [action = std::move(action)] {
            action();
    });
}
