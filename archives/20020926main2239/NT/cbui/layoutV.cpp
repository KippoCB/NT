//========= Coypright (C) CBDE, 2026, All Rights Reserved ==========
//
// File:
//      LayoutV.cpp
//
// Purpose:
//      This is the vertical layout implementation for cbui.
//
// Author:
//      Vilho Salokannel <github.com/KippoCB>
//
// Edits:
//      24-08-26: Create | Vilho Salokannel <github.com/KippoCB>
//
//==================================================================

#include "layoutV.h"

struct LayoutV::Impl {
    QVBoxLayout layout;
};

//
// Get the QT native handle for the layout to not expose it for the dev
QVBoxLayout *LayoutV::qtNativeHandle() {
    return &impl->layout;
}

LayoutV::LayoutV() :
    impl(std::make_unique<Impl>()) 
{
    
}

LayoutV::~LayoutV() = default;

//
// Set the parent
void LayoutV::setParent(Widget &parent) {
    impl->layout.setParent(parent.qtNativeHandle());
}

//
// Add a stretch 
void LayoutV::addStretch() {
    impl->layout.addStretch();
}

//
// Add a widget 
void LayoutV::addWidget(Widget &widget) {
    impl->layout.addWidget(widget.qtNativeHandle());
}

//
// Add layout vert 
void LayoutV::addLayoutV(LayoutV &lyt) {
    impl->layout.addLayout(lyt.qtNativeHandle());
}

//
// Add a label 
void LayoutV::addLabel(Label &label) {
    impl->layout.addWidget(label.qtNativeHandle());
}

//
// Add a button 
void LayoutV::addButton(Button &button) {
    impl->layout.addWidget(button.qtNativeHandle());
}
