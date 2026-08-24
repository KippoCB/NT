//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      label.cpp
//
// Purpose:
//      Contains the Label class of the cbui Qt wrapper. 
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

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
void Label::setParent(Widget &parent) {
    impl->label.setParent(parent.qtNativeHandle());
}

//
// Set new text
void Label::setText(std::string text) {
    impl->label.setText(QString::fromStdString(text));
}

//
// Show the label 
void Label::show() {
    impl->label.show();
}

//
// Hide the label 
void Label::hide() {
    impl->label.hide();
}
