#include "gridLayout.h"

//
// Internal Qt handle 
struct GridLayout::Impl {
    QGridLayout layout;
};

QGridLayout *GridLayout::qtNativeHandle() {
    return &this->impl->layout;
}

//
// Constructor
GridLayout::GridLayout() :
    impl(std::make_unique<Impl>())
{

}

GridLayout::~GridLayout() = default;

//
// Add widget 
void GridLayout::addWidget(Widget widget) {
    impl->layout.addWidget(widget.qtNativeHandle());
}

//
// Set new spacing 
void GridLayout::setSpacing(int spacing) {
    impl->layout.setSpacing(spacing);
}
