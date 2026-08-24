#include "label.h"

struct Label::Impl {
    QLabel label;
};

Label::Label(std::string text) : 
    impl(std::make_unique<Impl>())
{
    //
    // Set text 
    impl->label.setText(QString::fromStdString(text));
}

Label::~Label() = default;

QLabel *Label::qtNativeHandle() {
    return &impl->label;
}

//
// Set parent 
void Label::setParent(Widget parent) {
    impl->label.setParent(parent.qtNativeHandle());
}

//
// Set new text
void Label::setText(std::string text) {
    impl->label.setText(QString::fromStdString(text));
}
