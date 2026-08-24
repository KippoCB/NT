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
