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
