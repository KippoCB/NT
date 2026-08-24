#include "widget.h"

struct Widget::Impl {
    QWidget widget;
};  

QWidget* Widget::qtNativeHandle() {
    return &impl->widget;
}

Widget::Widget(int widgetType) :
    impl(std::make_unique<Impl>())
{
        
    //
    // Check what widget type it is to style it 
    if (widgetType == WT_BEVEL) {
        impl->widget.setStyleSheet(
                "QWidget {"
                "   background-color: #d4d0c8;"
                "   border-left: 3px solid white;"
                "   border-top: 3px solid white;"
                "   border-right: 2px solid black;"
                "   border-bottom: 2px solid black;"
                "}"
        );      
    } else if (widgetType == WT_INSET) {
        impl->widget.setStyleSheet(
                "QWidget {"
                "   background-color: white;"
                "   border-left: 2px solid black;"
                "   border-top: 2px solid black;"
                "   border-right: 3px solid white;"
                "   border-bottom: 3px solid white;"
        );
    }
}

Widget::~Widget() = default;

void Widget::setParent(Widget &parent) {
    impl->widget.setParent(Widget::qtNativeHandle());
}
