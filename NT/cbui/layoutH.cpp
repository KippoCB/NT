//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
//
// File:
//      LayoutH.cpp
//
// Purpose:
//      This is the horizontal layout implementation for cbui.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#include "layoutH.h"

struct LayoutH::Impl {
    QHBoxLayout layout;
};

//
// Get the QT native handle for the layout to not expose it for the dev
QHBoxLayout *LayoutH::qtNativeHandle() {
    return &impl->layout;
}

LayoutH::LayoutH() :
    impl(std::make_unique<Impl>())
{
    
}

LayoutH::~LayoutH() = default;

//
// Set the parent
void LayoutH::setParent(Widget &parent) {
    impl->layout.setParent(parent.qtNativeHandle());
}

//
// Add a stretch 
void LayoutH::addStretch() {
    impl->layout.addStretch();
}

//
// Add a widget
void LayoutH::addWidget(Widget &widget) {
    impl->layout.addWidget(widget.qtNativeHandle());
}

//
// Add layout Hor
void LayoutH::addLayoutH(LayoutH &lyt) {
    impl->layout.addLayout(lyt.qtNativeHandle());
}

//
// Add a label
void LayoutH::addLabel(Label &label) {
    impl->layout.addWidget(label.qtNativeHandle());
}

//
// Add a button 
void LayoutH::addButton(Button &button) {
    impl->layout.addWidget(button.qtNativeHandle());
}

//
// Align items to center 
void LayoutH::alignCenter() {
    impl->layout.setAlignment(Qt::AlignCenter);
}
